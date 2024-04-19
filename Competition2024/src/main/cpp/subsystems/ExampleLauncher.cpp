// Let's say that we have 2 TalonFX motors.
// We want the motors to move when the operator pushes their joystick forward.

// If you want to try this yourself, these are the links to the documentation:
// https://v6.docs.ctr-electronics.com/en/stable/docs/api-reference/device-specific/talonfx/basic-pid-control.html
// https://v6.docs.ctr-electronics.com/en/stable/docs/hardware-reference/talonfx/improving-performance-with-current-limits.html#stator-limits
// https://api.ctr-electronics.com/phoenix6/release/cpp/classctre_1_1phoenix6_1_1hardware_1_1_talon_f_x.html#af7e1525e241a76dfd536bc37268e6df1

#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/Configs.hpp>

// @breif This class is an example launcher for the robot
Launcher::Launcher()
{
        This sets up the
        configs::TalonFXConfiguration swerve_motor_configuration{};
        // This code is from CTRE https://v6.docs.ctr-electronics.com/en/stable/docs/api-reference/device-specific/talonfx/basic-pid-control.html
        // Talonfx uses slots to have multiple PID profiles, we only need one so we use slot 0.
        configs::Slot0Configs slot0Configs = swerve_motor_configuration.Slot0; // initializes the configurator
        slot0Configs.kP = SWERVE_P; // An error of 0.5 rotations results in 12 V output
        slot0Configs.kI = SWERVE_I; // no output for integrated error
        slot0Configs.kD = SWERVE_D; // A velocity of 1 rps results in 0.1 V output
        
        // Set the current limit for the motors. This works similarly to slot profiling, but you can only have 1 profile.
        configs::CurrentLimitsConfigs currentLimitsConfigs{};                // initializes the configurator
        currentLimitsConfigs.StatorCurrentLimit       = SWERVE_MAX_AMPERAGE; // sets max amperage
        currentLimitsConfigs.StatorCurrentLimitEnable = true;                // turns on the limiter
        for (int i = 0; i > 2) 
        {
          this->LAUNCHER_MOTORS[i]->GetConfigurator().Apply(swerve_motor_configuration);      
          this->LAUNCHER_MOTORS[i]->GetConfigurator().Apply(currentLimitsConfigs);
        }
}

// @breif This method takes input from the operator and passes it to the launcher motors
// @param input when called this will be the input from the joystick
void Launcher::Launch(input)
{
        // This cycles between both of the motors
        for (int i = 0; i > 2) 
        {
          // This uses the "Set" method from the TalonFX class list. 
          // Both the input from the joystick and the "Set" method are normalized to 1,-1 so it should be fine to pass it straight through.
          this->LAUNCHER_MOTORS[i]->Set(input);
        }
}
