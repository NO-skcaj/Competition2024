#pragma once

#include <unistd.h>

/// @brief Class to support autonomous commands.
class AutoCommands
{
    public:
        /// @brief Constructor for the AutoCommands class.
        /// @param swerve - Pointer to the robot swerve subsystem.
        /// @param intake - Pointer to the robot intake subsystem.
        AutoCommands(Swerve *swerve, Intake *intake);

        /// @brief Autonomous command to do nothing.
        void Auto_Do_Nothing();

        /// @brief Autonomous command to drive forward.
        void Auto_Move();

    private:
        /// @brief Pointer to the robot swerve subsystem.
        Swerve *m_swerve;
};
