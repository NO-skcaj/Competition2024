#pragma once

// CAN bus name (specifically for TalonFX)
#define CANBUS_NAME                          "rio"

// Swerve CAN IDs Driver Motors
#define FR_M_CAN_ID                              7
#define FL_M_CAN_ID                             12
#define RL_M_CAN_ID                             13
#define RR_M_CAN_ID                             10

// Swerve CAN IDs Angle Motors
#define FR_A_CAN_ID                              8
#define FL_A_CAN_ID                              4
#define RL_A_CAN_ID                              6
#define RR_A_CAN_ID                              9

// Swerve CAN IDs Encoders
#define FR_E_CAN_ID                             41
#define FL_E_CAN_ID                             43
#define RL_E_CAN_ID                             40
#define RR_E_CAN_ID                             42

// 180 / Pi
#define MAGIC_NUMBER                      57.29577f
#define ANTIMAGIC_NUMBER                   0.01745f
 
// ### Controller constants ###
#define OPERATOR_CONTROLLER                      1
#define DRIVER_CONTROLLER                        0

#define JOYSTICK_BUTTON_A                        1
#define JOYSTICK_BUTTON_B                        2
#define JOYSTICK_BUTTON_X                        3
#define JOYSTICK_BUTTON_Y                        4

#define JOYSTICK_BUMPER_LEFT                     5
#define JOYSTICK_BUMPER_RIGHT                    6

#define JOYSTICK_POV_0                           0
#define JOYSTICK_POV_90                         90
#define JOYSTICK_POV_180                       180
#define JOYSTICK_POV_270                       270

#define LEFT_TRIGGER_AXIS                         2
#define RIGHT_TRIGGER_AXIS                        3
#define TRIGGER_THRESHOLD_VALUE                 0.5

// #### Swerve ####
#define CHASSIS_LENGTH                          30
#define CHASSIS_WIDTH                           30

#define SWERVE_MODULES                           4

// Hardware Constants
#define SWERVE_MAX_AMPERAGE                     30

// Swerve Constants
#define DEADZONE_THRESHOLD                     0.1   // Raise to counter joystick drift this number is on a controller to controller basis

// The amount of raw sensor units to complete one full rotation
#define SWERVE_WHEEL_COUNTS_PER_REVOLUTION      21

// PID Values for the motorcontrollers
#define SWERVE_P                             0.700
#define SWERVE_I                             0.000
#define SWERVE_D                             0.001

// PID Values for angle controller
#define ANGLES_SWERVE_P                       0.05
#define ANGLES_SWERVE_I                       0.00
#define ANGLES_SWERVE_D                       0.00

// ### Autonomous Variables ###
// Autonomous Move
#define AUTO_DRIVE_FORWARD_SPEED              -0.4
#define AUTO_DRIVE_FORWARD_TIME        2000 * 1000  // Two seconds

// Autonomous place AMP and move
#define AUTO_SCOOT_TO_AMP_SPEED                0.2
#define AUTO_SCOOT_TO_AMP_TIME          800 * 1000

#define AUTO_DRIVE_TO_AMP_SPEED                0.2
#define AUTO_DRIVE_TO_AMP_TIME         1200 * 1000

#define AUTO_PLACE_NOTE                        1.0
#define AUTO_PLACE_NOTE_TIME           1200 * 1000

#define AUTO_DRIVE_ACROSS_LINE_SPEED           0.2
#define AUTO_DRIVE_ACROSS_LINE_TIME    1000 * 1000
