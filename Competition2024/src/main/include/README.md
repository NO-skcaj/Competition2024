# The include folder

In the include directory, there is just all the header files (.hpp or .h) for the cpp directory. This is where all of the methods, classes, and varibles are initialized. It is generally easier to plan out code in header files by simply outlining what you want to do then actually doing it in cpp files. The only thing thats an actual difference is the Constants.hpp file

### Constants.hpp

Constants.hpp is where we have all of our (can you guess?) constants. We use this instead of just a bunch of "const static int x = 2;" is that it is easier to organize all of them into one place. It is especially useful when you need to define global variables.
