# Debug Interface 

This library allows you to integrate a simple debugging funtionality to your project. It based on different precompiler macros and be configured in many different ways.
The biggest advantage is, that the debug code can still be available in the code, also for the release build. 


## Enable Debugging in the project:

To enable the debugging function in the project, a build debug flag needs to be set  `build_flags = -D DEBUG`


Platform Io Example:

```
[env:nodemcu-32s]
platform = espressif32
board = nodemcu-32s
framework = arduino
build_flags = -D DEBUG

```

## How to integrate DebugIf into code:

The debug interface can be integrated into each module and multiple times in the project. For the integration, there is the template file `Template_Debug_Inc.h`. 

1. Add the compiler flag `-D DEBUG` into your makefile or config file.
2. Copy the `Template_Debug_Inc.h` into a folder
3. Rename the template file. For example for the `main.h`: `main_debug.h`
4. The following steps needs to be done in the debug template file:
```c

    #define DBIF_ENABLED                        //Comment in this line to enable debug output for this file

    #define DBIF_LOGLEVEL LOG_DEBUG_0           //Choose the level of debug output.

    #define DBIF_MODULE_NAME "MAIN"             //Choose a name. This will be displayed in the debug output.

````
### Debug Levels:
For the debugging purpose, there are different debug levels available: 
- LOG_DEBUG_3  - Max debug output [All debug levels + info, warning and errors will be printed]
- LOG_DEBUG_2 
- LOG_DEBUG_1 
- LOG_DEBUG_0 
- LOG_INFO    
- LOG_WARN - Warnings and Errors will be printed
- LOG_ERROR - Only Error messages will be printed
- LOG_NONE    