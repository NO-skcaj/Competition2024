// This tells the compiler to only run this file once.
#pragma once

#include <ctre/phoenix6/TalonFX.hpp>

// More comments on how this code works, and the documentation used is in the cpp file of the same name

// @breif This class is an example launcher for the robot
class Launcher()
{
    // The public keyword means that everything indented past it is available for code outside of the class to use.
    public:
        void Launch(double input);

    // Private is the inverse of public where code outside of the function cant use anything indented past it.
    private:
        // This initializes the motors using 
        ctre::phoenix6::hardware::TalonFX R_MOTOR_LAUNCHER{R_LAUNCHER_CAN_ID, CANBUS_NAME};
        ctre::phoenix6::hardware::TalonFX L_MOTOR_LAUNCHER{L_LAUNCHER_CAN_ID, CANBUS_NAME};

        // This creates an array for easy access of the motors
        ctre::phoenix6::hardware::TalonFX *LAUNCHER_MOTORS[2] = {
            &R_MOTOR_LAUNCHER,
            &L_MOTOR_LAUNCHER,
        };
}
