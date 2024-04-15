#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

#include "../../include/subsystems/AutoCommands.hpp"

using namespace frc;

/// @brief Constructor for the AutoCommands class.
/// @param swerve - Pointer to the robot swerve subsystem.
/// @param intake - Pointer to the robot intake subsystem.
AutoCommands::AutoCommands(Swerve *swerve)
{
    // Remember the swerve and intake subsystem pointers
    m_swerve = swerve;
}

/// @brief Autonomous command to do nothing.
void AutoCommands::Auto_Do_Nothing()
{
    SmartDashboard::PutString("AutoName: ", "Do Nothing");
}

/// @brief Autonomous to drive forward.
void AutoCommands::Auto_Move()
{
    // Drive forward
    m_swerve->Drive(AUTO_DRIVE_FORWARD_SPEED, 0, 0, -999.0);
    usleep(AUTO_DRIVE_FORWARD_TIME);  // Timed drive
    m_swerve->Drive(0, 0, 0, -999.0);   // Stop
}
