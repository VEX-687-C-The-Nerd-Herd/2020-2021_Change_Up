// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         4               
// frontRight           motor         11              
// backLeft             motor         19              
// backRight            motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Miguel VF                                                 */
/*    Created:      Sun Apr 26 2020                                           */
/*    Description:  X-drive go X-fly!!!                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*Drive used: Holonomic Drive/X Drive
  X-drive configuration:
          X FRONT X
        X           X
      X  FL       FR  X
              X
             AXIS
              X
      X  BL       BR  X
        X           X
          X  BACK  X
*/

#include "vex.h"
using namespace vex;

// Competition
competition Competition;

void pre_auton(void) {}
// Autonomous Robot Movement
void autonomous(void) {
  while (true) // While true is true, repeat the commands in the next {}
  {
    while (
        !Brain.Screen.pressing()) { // While NOT (!) the screen is being pressed
                                  // repeat the commands in the next {}
    }
      // Do nothing. Will only get out of this loop when the screen is pressed.
    // Say 'Ouch' where the screen was pressed
    Brain.Screen.printAt(Brain.Screen.xPosition(), Brain.Screen.yPosition(), "Ouch");
  } // Go back to while (true) to repeat forever
}

void drivercontrol(void) {
  // get the controller values
  //double turnVal = Controller1.Axis4.position(percent); // how much we want the robot to turn (turn)
  //double forwardVal = Controller1.Axis2.position(percent); // how much we want the robot to go forward (y)
  //double horizontalVal = Controller1.Axis1.position(percent); // how much we want the robot to go sideways (x)
  // set the motor percntages

  //frontLeft.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  //frontRight.spin(vex::directionType::fwd, Controller1.Axis2.value() + Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  //backLeft.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  //backRight.spin(vex::directionType::fwd, Controller1.Axis2.value() - Controller1.Axis4.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  //double frontLeftVelocity = ((-1 * forwardVal) - (horizontalVal) - (turnVal));
  //double frontRightVelocity = ((forwardVal) - (horizontalVal) - (turnVal));
  //double backLeftVelocity = ((-1 * forwardVal) + (horizontalVal) - (turnVal));
  //double backRightVelocity = ((forwardVal) + (horizontalVal) - (turnVal));
  while (true) {
    // spin to win
    frontLeft.spin(directionType::fwd,Controller1.Axis3.value()+Controller1.Axis4.value()+Controller1.Axis1.value() , velocityUnits::pct);
    frontRight.spin(directionType::rev,Controller1.Axis3.value()-Controller1.Axis4.value()-Controller1.Axis1.value() , velocityUnits::pct);
    backLeft.spin(directionType::fwd,Controller1.Axis3.value()-Controller1.Axis4.value()+Controller1.Axis1.value() , velocityUnits::pct);
    backRight.spin(directionType::rev,Controller1.Axis3.value()+Controller1.Axis4.value()-Controller1.Axis1.value() , velocityUnits::pct);
  }
}

// Set up  competition and callbacks
int main() {
  Brain.Screen.print("Hello World!\n");
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Callbacks for autonomous and driver control
  // Run pre-autonomous function.
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);
}
