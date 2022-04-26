/*
 * generated by Xtext 2.26.0
 */
package nl.tue.robotsupervisorycontrollerdsl.generator

import org.eclipse.emf.ecore.resource.Resource
import org.eclipse.xtext.generator.AbstractGenerator
import org.eclipse.xtext.generator.IFileSystemAccess2
import org.eclipse.xtext.generator.IGeneratorContext
import nl.tue.robotsupervisorycontrollerdsl.generator.cif.CifGenerator
import javax.inject.Inject
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Robot
import nl.tue.robotsupervisorycontrollerdsl.generator.ros2.Ros2Generator

/**
 * Generates code from your model files on save.
 * 
 * See https://www.eclipse.org/Xtext/documentation/303_runtime_concepts.html#code-generation
 */
class RobotSupervisoryControllerDSLGenerator extends AbstractGenerator {
	@Inject CifGenerator cifGenerator
	@Inject Ros2Generator ros2Generator

	override void doGenerate(Resource resource, IFileSystemAccess2 fsa, IGeneratorContext context) {
		resource.findInstancesOfRobot.forEach[
			cifGenerator.generate(it, fsa)
			ros2Generator.generate(it, fsa)
		]
	}
	
	private def findInstancesOfRobot(Resource resource) {
		return resource.allContents.toIterable.filter(Robot)
	}
}
