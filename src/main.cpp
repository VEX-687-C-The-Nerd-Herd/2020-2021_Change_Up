/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\works                                            */
/*    Created:      Sun Apr 26 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         10              
// frontRight           motor         11              
// backLeft             motor         19              
// backRight            motor         20              
// ---- END VEXCODE CONFIGURED DEVICES ----
/*Drive used: Holonomic Drive/X Drive
//looks noice, dosen't it?
/ X-drive configuration:
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


void pre_auton(void) {

}
// Autonomous Robot Movement
void autonomous(void) {

}
void drivercontrol(void) {
  while (true) //While true is true, repeat the commands in the next {}
  {
    while (!Brain.Screen.pressing()) //While NOT (!) the screen is being pressed repeat the commands in the next {}
    {
      //Do nothing. Will only get out of this loop when the screen is pressed.
    } 
    //Say 'Ouch' where the screen was pressed
    Brain.Screen.printAt(Brain.Screen.xPosition(),Brain.Screen.yPosition(),"Ouch");
    } //Go back to while (true) to repeat forever


    //get the controller values
    double turnVal = Controller1.Axis4.position(percent); //how much we want the robot to turn (turn)
    double forwardVal = -1 * Controller1.Axis2.position(percent); //how much we want the robot to go forward (y)
    double horizontalVal = Controller1.Axis1.position(percent); //how much we want the robot to go sideways (x)
    //set the motor percntages 
    double frontLeftVelocity = ((-1*forwardVal) - (horizontalVal) - (turnVal)); 
    double frontRightVelocity = ((forwardVal) - (horizontalVal) - (turnVal));
    double backLeftVelocity = ((-1*forwardVal) + (horizontalVal) - (turnVal));
    double backRightVelocity = ((forwardVal) + (horizontalVal) - (turnVal));
    //spin to win
    frontLeft.spin(directionType::fwd, frontLeftVelocity, velocityUnits::pct);
    frontRight.spin(directionType::fwd, frontRightVelocity, velocityUnits::pct);
    backLeft.spin(directionType::fwd, backLeftVelocity, velocityUnits::pct);
    backRight.spin(directionType::fwd, backRightVelocity, velocityUnits::pct);
    //motor syntax:
    //motor.spin(directionType dir, double velocity, velocityUnits units)
    
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
//if you read all the way here, either thank you kind stranger or tl;dr, hopefully it works (x-drive)
