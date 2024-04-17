# CPP folder 

This directory has 3 main components that are also mirrored in the Include directory. Those components are: the io directory, the subsystems directory, and the Robot.cpp file.

### IO

The IO folder checks all input from either of the 2 controllers. Then it calls methods from the subsystems folder (generally) to make the robot move.

### Subsystems

The subsystems folder is where all of the moving components' methods are defined. This defines the behavior of almost every part of the bot, and most of your code will be here.

### Robot.cpp

The Robot.cpp file is the main file that calls other functions. Normally how it works is that Robot.cpp overrides a few WPI functions that already get called by the robot. (eg teleopPeriodic which is called every 20ms while in teleop) Then, we put in our IO methods that check joystick positions and call the methods to move the bot.

Robot.cpp                  IO                    Subsystems
Overridden WPI methods --> checks for input -->  does things on the robot itself
