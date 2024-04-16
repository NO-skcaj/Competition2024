# 3824 template code
This is based on 3824's Robot Code for 2023-2024

Developed by:
Luke Smith, Jackson Case, and Mr.Young

## How does this work?

This repo uses [WPIlib](https://docs.wpilib.org/en/stable/index.html), [Rev Robotics](https://www.revrobotics.com/), [CTRE](https://store.ctr-electronics.com/), and more to make our robot work. As a base, we used WPIlib to create a template for our robot, and this provided the general structure of it. The robot is divided into sections called "subsystems" that drive individual parts of the robot, eg: "Swerve", "Intake", "Launcher", etc. These subsystems are pulled together by a main "Robot.cpp" file that runs functions designated mainly by WPIlib. Then, the I/O is mainly handled in the aptly named "io" directory, where we point controller input into the robot subsystems.

If you're looking for a beginner approach to cpp, it is highly encouraged to learn cpp [here](https://learncpp.com), before continuing.

### Subsystems

When writing robot code, most of it would be in a subsystem file. A subsystem is any part that moves, sees, twists, or turns. It can even be an abstraction of other subsystems. An example of that would be a swerve class module subsystem with a swerve drive abstraction subsystem. Although, we normally do not have that kind of abstraction. However, it's important to distinguish your subsystems between different files. If you have a launcher that is (for some reason) on a turret, then you will want the turret and the launcher in seperate files. We do this because it makes abstractions within the code easier, and more verbose. Where are the launcher methods, in the launcher class; pickup methods in the pickup class; etc. 

A subsystem has two files associated with it (just the same as other cpp files): a regular .cpp file, and a header .hpp or .h file. A header file is just an extension for the cpp file, so you can think of it as one big file between them. In a header file, you will find the base initializations for all the classes and methods (one class per file), and in a regular cpp file, you will find the definitions for the initialized classes and methods. A general convention for header files is that you don't write any data in the header file. That means that all variable initializations will be empty, ie: "int x;".

### How to connect to hardware

Hardware is fairly simple. You find the documentation, and you implement those methods. However, you have a lot of difference "class lists" that you have to pull from.

* [ctre phoenix](https://api.ctr-electronics.com/phoenix/release/cpp/)
* [ctre phoenix 6](https://api.ctr-electronics.com/phoenix6/release/cpp/)
* [REVlib](https://codedocs.revrobotics.com/cpp/classrev_1_1_spark_max_p_i_d_controller)

These are similarly laid out, which makes finding things simple, and seeing which one you're on (or supposed to be on) confusing. The main things that you need are called "classes" and "namespace". The class list is where you can find all you need to use the motors. Namespaces are what you use when you don't want to type out "rev::hardware::sparkmax::etc::etc" every time you want to use a method from there. You can use it as an implied shortcut. If you have something like "ctre::phoenix6::hardware::TalonFX()", then you can use "using namespace ctre::pheonix6::hardware;" to shorten the definition to just "TalonFX()". CPP will be able to assume that you want a class from that library.

CTRE Phoenix 6 is the newest library available, and use this for everything. The only time you would use the old phoenix lib is if you have something, or are using something old.

### Smart Dashboard

The Smart dashboard pops up when you start to run the driver station and is installed by default. It allows you to put input into the robot, and see data from it. I can't keep saying this, but it's fairly simple. You use "SmartDashboard::PutInt("Name of thing", value);" to put some data type into the Smart Dashboard, and you can switch PutInt to anything else. It's also the same with input via "SmartDashboard::PutString("Name of thing", default_value);". You can also put video output there, which is extremely useful for driving.

### P.I.D. (F.S.V.)

PID or Proportional–integral–derivative, is a way that we alter motor movement to be better than simple 1,0 inputs. I currently don't *exactly* know how it works. I'm going to work on that, but for now, CTRE has a fairly good definition [here](https://v6.docs.ctr-electronics.com/en/stable/docs/api-reference/device-specific/talonfx/basic-pid-control.html)

### Joysticks

Joysticks use the standard FRC library. Some great documentation and a tutorial can be found [here](https://docs.wpilib.org/en/stable/docs/software/basic-programming/joystick.html). You can use almost any controller including DualShock and Xbox controllers. I have also seen custom driver stations that use home made controllers. We made one of these a few years 
