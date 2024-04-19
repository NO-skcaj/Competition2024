# 3824 template code
This is based on 3824's Robot Code for 2023-2024

Developed by:
Luke Smith, Jackson Case, and Mr.Young

## How does this work?

This repo uses [WPIlib](https://docs.wpilib.org/en/stable/index.html), [Rev Robotics](https://www.revrobotics.com/), [CTRE](https://store.ctr-electronics.com/), and more to make our robot work. As a base, we used WPIlib to create a template for our robot, which means that most C++ bots are coded similarly to ours. The robot is divided into sections called "subsystems" that drive individual parts of the robot, eg: "Swerve", "Intake", "Launcher", etc. These subsystems are pulled together by a main "Robot.cpp" file that runs functions designated mainly by WPIlib. Then, the I/O is mainly handled in the aptly named "io" directory, where we point controller input into the robot subsystems.

If you're looking for a beginner approach to cpp, it is highly encouraged to learn cpp [here](https://learncpp.com), before continuing.

## What do I need to install?

There are a few things that you need to develop and run code. You can use the guide provided by FRC, [here](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/frc-game-tools.html). OR you can download everything you need in these two links: [Game Tools](https://www.ni.com/en/support/downloads/drivers/download.frc-game-tools.html#500107), and [WPIlib dev tools](https://github.com/wpilibsuite/allwpilib/releases/tag/v2024.3.2).

## What OS can I use?

Generally, Windows. I hate having to use that steaming pile of garbage as much as the next Unix nerd, and I know it's contradictory to develop on Windows when Linux exists, but you'll have to deal with it. That's not to say you can't use Linux, WPI even has separate releases for Linux. It's that it's fairly difficult, even if you're using Ubuntu. That all being said, my previous programming captain got it to work on (my beloved) Arch Linux, so we know it's possible.

No MacOS, nerd.

## Subsystems

When programming the robot, most of it would be in a subsystem file. A subsystem is any part that moves, sees, twists, or turns. It can even be an abstraction of other subsystems. An example would be a swerve class module subsystem with a swerve drive abstraction subsystem. Although, we normally do not have that kind of abstraction. However, it's important to distinguish your subsystems between different files. If you have a launcher that is (for some reason) on a turret, then you will want the turret and the launcher in separate files. We do this because it makes abstractions within the code easier, and more verbose. Where are the launcher methods? in the launcher class; pickup methods in the pickup class; etc. 

A subsystem has two files (just the same as other cpp files): a regular .cpp file, and a header .hpp or .h file. A header file is just an extension for the cpp file. So we can think of them as one big file. In a header file, you will find the base initializations for all the classes and methods (one class per file), and in a regular cpp file, you will find the definitions for the initialized classes and methods. A general convention for header files is that you don't write any data in the header file. That means all variable initializations in header files will be empty, ie: "int x;".

## How to connect code to hardware

Hardware is fairly simple. You find the documentation, and you implement those methods. The hard part is finding what you need and deciphering how they want you to implement it.

* [ctre phoenix](https://api.ctr-electronics.com/phoenix/release/cpp/)
* [ctre phoenix 6](https://api.ctr-electronics.com/phoenix6/release/cpp/)
* [REVlib](https://codedocs.revrobotics.com/cpp/classrev_1_1_spark_max_p_i_d_controller)

These are similarly laid out, which makes finding things simple, and seeing which one you're on confusing. The main things we need are called "classes" and "namespace". The class list is where you can find all you need to use the motors. We use namespaces when you don't want to type out "rev::hardware::sparkmax::etc::etc" when you want to use that method. You can use it as an implied shortcut. If you have something like "ctre::phoenix6::hardware::TalonFX()", then you can use "using namespace ctre::pheonix6::hardware;" to shorten the definition to just "TalonFX()". CPP can assume that you want a class from that library.

CTRE Phoenix 6 is the newest library available, and we use this for everything. The only time you would use the old phoenix lib is if you have something, or are using something old.

## Smart Dashboard

The Smart dashboard pops up when you run the driver station and is installed by default. It allows you to put input into the robot, and see data from it. I can't keep saying this, but it's fairly simple. You use "SmartDashboard::PutInt("Name of thing", value);" to put some data type into the Smart Dashboard, and you can switch PutInt to anything else. It's also the same with input via "SmartDashboard::PutString("Name of thing", default_value);". You can also put video output there, which is extremely useful for driving.

## P.I.D. (F.S.V.)

PID or Proportional–integral–derivative, is how we alter motor movement to be better than simple 1,0 inputs. I currently don't *exactly* know how it works. I'm going to work on that, but for now, CTRE has a fairly good definition [here](https://v6.docs.ctr-electronics.com/en/stable/docs/api-reference/device-specific/talonfx/basic-pid-control.html)

## Joysticks

Joysticks use the standard FRC library. Some great documentation and a tutorial can be found [here](https://docs.wpilib.org/en/stable/docs/software/basic-programming/joystick.html). You can use almost any controller including DualShock and Xbox controllers. I have also seen custom driver stations that use homemade controllers. We made one of these a few years back and should still have it. However, I don't know if there's any reuseable code.

## Swerve

Swerve is the preferred drive train for our team, and we've used it for multiple years. The math behind Swerve code is deceptively difficult, it requires lots and lots of trigonometry. That is why we use papers written by people who have spent many more hours than they'd probably like to admit. Particularly, you can find almost everything that you need in these two Chef Delphi threads:

* [LOTS of papers](https://www.chiefdelphi.com/t/paper-4-wheel-independent-drive-independent-steering-swerve/107383)
* [3 papers that are extremely useful](https://www.chiefdelphi.com/t/math-and-programming-behind-swerve/130241/9_)
thx Ether

If you want the base swerve code you would copy and paste the paper on the second link labeled "How to use the equations:"; which we've already done. However, these aren't exactly perfect. The turning while moving works, but not that well; you can only go in one direction; and the wheels always go back to zero. These are all very fixable problems that have been solved before, and that we will work on.

## Contributing

To contribute, you need to be part of the HVA Robotics organization. Then, you can create a branch, work on that, then merge once everything is ready. However, you can commit the tested code directly to the main branch when on the drive laptop. 

Writing and testing code can take some time to set up, but after that, it's a matter of writing good code (as opposed to fighting the compiler). You need the dev tools that can be installed (if you haven't already): [WPIlib dev tools](https://github.com/wpilibsuite/allwpilib/releases/tag/v2024.3.2).

A good way of contributing is updating all the libraries to the newest. You can do that by running the code and trying to clear up the page and a half of "warning!" messages. As 
a quick note: It will still build with these warnings.

## Testing

Testing is the fun part. The process is as follows: Connect the laptop to the robot via a cable (USB-A or Ethernet directly into the RoboRIO), or through the radio; then open up the driver station and verify that you have robot communication and joysticks; finally, you can deploy the code.
Some of these aren't very simple so here are instructions for some of them:
**Deploying Code**
You should've already installed VS code in the "What do I need to install step", but if you haven't you can do that [here](https://github.com/wpilibsuite/allwpilib/releases/tag/v2024.3.2).
1. When in VS code, press ctrl+p or click the WPIlib logo in the top right.
2. Search for "Build code" then, select that.
3. That should've opened up a terminal that compiles that code, which you can debug from.
4. Make sure you are connected to the robot in the Driver Station.
5. Go to the WPIlib menu (ctrl+p or click the logo) and "select deploy code".
6. Once it compiles, it pushes the code to the RoboRIO. After that, all the init functions should've been called and the controllers should now work.

**Connecting to the Radio**
1. Connect the roboRIO directly into the radio with an Ethernet cable (make sure that it's plugged into the middle port)
2. Open up the radio utility put in your team number and set "Radio:" to "OpenMesh".
3. Connect to the robot through WIFI.
4. Deploy from WPI VS code extension.
NOTE: make sure to update firmware from time to time

## Troubleshooting

When a silly build member walks up to you and says the code is broken, remain calm. If the code has been tested before, and it works, pretend to do something that looks like code, and have them also try troubleshooting on their end. Half the time it's a build problem, half the time you wrote bad code or bad math. If it's not a problem on either end, it's likely a problem with the hardware/firmware. Don't be afraid to ask for help if you suspect it's a programming problem, no one knows how to do this when they have just started

on a more serious note:
**Chef Delphi**

Chef Delphi is *the* forum for FRC programming. Most problems that aren't already in stack overflow can be found here. It's a forum like any other that people in robotics use. It's essential for troubleshooting and generally has a lot of general guides. However, a lot of it is in Java, so you might have to try and interpret Java code when working in C++.
