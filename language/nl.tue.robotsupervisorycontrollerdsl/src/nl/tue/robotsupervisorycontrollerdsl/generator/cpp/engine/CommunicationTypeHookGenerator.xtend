package nl.tue.robotsupervisorycontrollerdsl.generator.cpp.engine

import javax.inject.Singleton
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Action
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Service
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Robot
import javax.inject.Inject
import nl.tue.robotsupervisorycontrollerdsl.generator.cpp.naming.TransitionNames
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Message
import nl.tue.robotsupervisorycontrollerdsl.generator.cpp.naming.MethodNames
import nl.tue.robotsupervisorycontrollerdsl.generator.cif.synthesis.CifSynthesisTool
import nl.tue.robotsupervisorycontrollerdsl.generator.common.util.ModelHelper
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.CommunicationType
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.MessageTo

@Singleton
class CommunicationTypeHookGenerator {
	@Inject extension TransitionNames
	@Inject extension MethodNames

	def compileHooks(Robot robot) '''
		void «CifSynthesisTool.codePrefix»_InfoEvent(«CifSynthesisTool.codePrefix»_Event_ event, BoolType pre) {
		    if (pre) return;
		    
		    switch (event) {
		    «FOR communication : ModelHelper.findWithinRobot(robot, CommunicationType)»
	    	«communication.compileHook»
		    «ENDFOR»
		
		    default:
				return;	
		   	}
		}
	'''

	private def dispatch compileHook(Message entity) '''
		«IF entity.direction instanceof MessageTo»
		case «entity.triggerTransitionName»:
			fprintf(stderr, "[debug] Triggering message «entity.name».\n");
			node_controller->«entity.callMethod»();
		break;
		«ENDIF»
	'''

	private def dispatch compileHook(Action entity) '''
		case «entity.triggerTransitionName»:
			fprintf(stderr, "[debug] Triggering action «entity.name».\n");
			node_controller->«entity.callMethod»();
		break;
	'''

	private def dispatch compileHook(Service entity) '''
		case «entity.triggerTransitionName»:
			fprintf(stderr, "[debug] Triggering service «entity.name».\n");
			node_controller->«entity.callMethod»();
		break;
	'''
}
