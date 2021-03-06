package nl.tue.robotsupervisorycontrollerdsl.validation.rules;

import java.util.List;
import java.util.stream.Collectors;

import javax.inject.Inject;

import org.eclipse.xtext.validation.Check;

import nl.tue.robotsupervisorycontrollerdsl.generator.common.data.EliminationChecker;
import nl.tue.robotsupervisorycontrollerdsl.generator.common.util.ModelHelper;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.CommunicationType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ComplexDataTypeReference;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.IntegerDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Message;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ObjectDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ObjectProperty;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Robot;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.RobotSupervisoryControllerDSLPackage;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Variable;
import nl.tue.robotsupervisorycontrollerdsl.validation.common.AbstractValidationRule;

public class IntegerRangeRequiredRule extends AbstractValidationRule {
	@Inject EliminationChecker eliminationChecker;
	public static final String INTEGER_RANGE_REQUIRED = "integerRangeRequired";

	@Check
	public void checkVariableIntegerRangeRequired(Variable entity) {
		if (!(entity.getType() instanceof IntegerDataType)) return;
		
		IntegerDataType integer = (IntegerDataType) entity.getType();
		
		if (integer.getFrom() != null && integer.getTo() != null) return;
		
		Robot robot = ModelHelper.findParentOfType(entity, Robot.class);

		if (robot == null || this.eliminationChecker.variableRequiredInSynthesis(robot, entity)) {
			error("This integer type requires you to specify a range of values.",
					RobotSupervisoryControllerDSLPackage.Literals.VARIABLE__TYPE,
					INTEGER_RANGE_REQUIRED);
		}
	}

	@Check
	public void checkObjectPropertyIntegerRangeRequired(ObjectProperty entity) {
		if (!(entity.getType() instanceof IntegerDataType)) return;
		
		IntegerDataType integer = (IntegerDataType) entity.getType();
		
		if (integer.getFrom() != null && integer.getTo() != null) return;
		
		Robot robot = ModelHelper.findParentOfType(entity, Robot.class);
		ObjectDataType object = ModelHelper.findParentOfType(entity, ObjectDataType.class);
		boolean required = robot == null;
		
		if (robot != null) {
			List<CommunicationType> used = findAllCommunicationTypesReferencingObject(robot, object);
			
			for (CommunicationType type : used) {
				if (this.eliminationChecker.communicationTypeWithPropertyInputRequiredInSynthesis(robot, type, entity)) {
					required = true;
					break;
				}
			}
		}

		if (required) {
			error("This integer type requires you to specify a range of values.",
					RobotSupervisoryControllerDSLPackage.Literals.OBJECT_PROPERTY__TYPE,
					INTEGER_RANGE_REQUIRED);
		}
	}

	@Check
	public void checkMessageIntegerRangeRequired(Message entity) {
		if (!(entity.getType() instanceof IntegerDataType)) return;
		
		IntegerDataType integer = (IntegerDataType) entity.getType();
		
		if (integer.getFrom() != null && integer.getTo() != null) return;
		
		Robot robot = ModelHelper.findParentOfType(entity, Robot.class);

		if (robot == null || this.eliminationChecker.communicationTypeInputRequiredInSynthesis(robot, entity)) {
			error("This integer type requires you to specify a range of values.",
					RobotSupervisoryControllerDSLPackage.Literals.MESSAGE__TYPE,
					INTEGER_RANGE_REQUIRED);
		}
	}
	
	private List<CommunicationType> findAllCommunicationTypesReferencingObject(Robot robot, ObjectDataType object) {
		return ModelHelper.findWithinRobot(robot, CommunicationType.class)
				.stream()
				.filter(it -> ModelHelper.findChildren(it, ComplexDataTypeReference.class)
						.stream()
						.anyMatch(reference -> reference.getType() == object)
				)
				.collect(Collectors.toList());
	}
}
