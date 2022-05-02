package nl.tue.robotsupervisorycontrollerdsl.tests.validation.rules

import com.google.inject.Inject
import org.eclipse.xtext.testing.InjectWith
import org.eclipse.xtext.testing.extensions.InjectionExtension
import org.eclipse.xtext.testing.util.ParseHelper
import org.junit.jupiter.api.Test
import org.junit.jupiter.api.^extension.ExtendWith
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Base
import nl.tue.robotsupervisorycontrollerdsl.tests.RobotSupervisoryControllerDSLInjectorProvider
import org.eclipse.xtext.testing.validation.ValidationTestHelper
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.RobotSupervisoryControllerDSLPackage
import nl.tue.robotsupervisorycontrollerdsl.validation.rules.SingleInitialStateRule

@ExtendWith(InjectionExtension)
@InjectWith(RobotSupervisoryControllerDSLInjectorProvider)
class SingleInitialStateRuleTest {
	@Inject extension ParseHelper<Base>
	@Inject extension ValidationTestHelper

	@Test
	def void checkValid() {
		"
			robot UnitTestRobot {
				component Component {
					behaviour {
						initial state idle {}
					}
				}
			}
		".parse.assertNoErrors
	}

	@Test
	def void checkErrorMultipleInitialStates() {
		"
			robot UnitTestRobot {
				component Component {
					behaviour {
						initial state idle {}
						initial state start {}
					}
				}
			}
		".parse.assertError(
			RobotSupervisoryControllerDSLPackage.Literals.AUTOMATON,
			SingleInitialStateRule.MULTIPLE_INITIAL_STATES
		)
	}

	@Test
	def void checkErrorNoInitialState() {
		"
			robot UnitTestRobot {
				component Component {
					behaviour {
					}
				}
			}
		".parse.assertError(
			RobotSupervisoryControllerDSLPackage.Literals.AUTOMATON,
			SingleInitialStateRule.NO_INITIAL_STATE
		)
	}
}
