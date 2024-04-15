#pragma once 

#include "../Constants.hpp"

#include <frc/Joystick.h>
#include <frc2/command/SubsystemBase.h>

class OperatorController : frc2::SubsystemBase
{
    public:
        /// @brief Constructor for the OperatorController class.
        /// @param intake - Pointer to the intake class to allow calling intake methods.
        /// @param climb - Pointer to the climb class to allow calling climb methods.
        OperatorController();

        /// @brief Method called periodically every dirver/operator control packet.
        void Robot_Periodic(); 

    private:

        /// @brief The operator controller (joystick).
        frc::Joystick m_operator_joystick{OPERATOR_CONTROLLER};
};
