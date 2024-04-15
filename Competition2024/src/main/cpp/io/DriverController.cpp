#include <frc/smartdashboard/SmartDashboard.h>

#include "../../include/io/DriverController.hpp"

 /// @brief Constructor for the DriverController class.
 /// @param swerve - Pointer to the swerve drive class.
DriverController::DriverController(Swerve *swerve)
{
    // Remember the swerve pointer
    this->m_swerve = swerve;
}

// @brief Method called periodically every driver/operator control packet.
void DriverController::Robot_Periodic()
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
 
    // Determine if the reset gyro joystick button was pressed
    if (m_driver_joystick.GetRawButtonPressed(1))
        m_swerve->navx.Reset();

    // Determine if the toggle X wheels button was pressed.
    if (m_driver_joystick.GetRawButtonPressed(2))
        m_swerve->Toggle_X_Wheels();

    // Determine if right bumper is pressed, makes it go faster/slower.
    if (m_driver_joystick.GetRawButtonPressed(6))
        m_swerve->Toggle_Fast_Wheels();
 
    // Get the joystick axis for the robot swerve drive control
    this->m_swerve->Drive(-m_driver_joystick.GetRawAxis(1), 
                           m_driver_joystick.GetRawAxis(0), 
                           m_driver_joystick.GetRawAxis(4), 
                           this->m_swerve->navx.GetYaw());
                           //this->m_swerve->navx.GetRoll() - m_swerve->m_gyro_offset);
}
