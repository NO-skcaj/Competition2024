# CPP, Include, and Deploy

### Include

The Include folder has all of the header files (.hpp and .h) that are required for your .cpp files. In Include there is also Constants.hpp. This is the file where all of your constants are. When you need to make a constant, use "#define NAME_OF_VARABLE value". The value here is always a basic type (int, double, float, string, etc.).

### CPP

The CPP folder is where all of the CPP files are. This is the main code where you will be defining methods and the values of non-const variables. You can think of this as the code that is executed and the Include folder as code that is read.

### Deploy

You can put code in here that is immedietly sent to the roborio. This is mostly used for testing, although there is no working template since we haven't used it before.
