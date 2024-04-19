#include <frc/smartdashboard/SmartDashboard.h>

#include "../../include/io/OperatorController.hpp"
#include "../../include/subsystems/ExampleLauncher.hpp"

/// @brief Constructor for the OperatorController class.
OperatorController::OperatorController()
{
}

void OperatorController::Robot_Periodic()
{
    // Examples:
    // d-pad: returns boolean
    // m_operator_joystick.getPOV() == JOYSTICK_POV_0
    //                                 JOYSTICK_POV_90
    //                                 JOYSTICK_POV_180
    //                                 JOYSTICK_POV_270

    // A B Y X buttons: returns boolean
    // m_operator_joystick.GetRawButtonPressed(JOYSTICK_BUTTON_A)
    //                                         JOYSTICK_BUTTON_B
    //                                         JOYSTICK_BUTTON_X
    //                                         JOYSTICK_BUTTON_Y

    // Variables for joysticks have not been created, but are used for the example.
    // Joysticks: returns 1,-1
    // m_driver_joystick.GetRawAxis(LEFT_JOYSTICK_X)
    //                              LEFT_JOYSTICK_Y
    //                              RIGHT_JOYSTICK_X
    //                              RIGHT_JOYSTICK_Y
    // I'm also fairly certain that m_driver_joystick.GetY() also works

    // This is the code for the example launcher
    // WARNING this has not yet been compiled, so there might be some minor problems.
    this->LAUNCHER_MOTORS->Set(m_driver_joystick.GetRawAxis(LEFT_JOYSTICK_Y));
}
