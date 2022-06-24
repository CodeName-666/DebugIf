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

## Spezial Debug Options:

There are some spezial options which can be used to configure the debug interface. All defines have a own default values and normaly they don't need to be changes


1. Macro to initialize the DebugIf:
This macro allwos you to use a diffrent init function as conficured. 

***DEFAULT:*** The function `Serial.begin` is used for Arduino.

`#define DBIF_INIT(args...)                      Serial.begin(args)`

2. Macro to use a other message ouptut function: 
This macro allows you to use a different function to print out your debug messages. 

***DEFAULT:*** The function `Serial.printf` is used for Arduino.

`#define DBIF_PRINTF_FUN                          Serial.printf `

3. Macro to ouput time stamps: 
Each debug messages includes also a time stamp. With this macro this function can be changed.

***DEFAULT:*** The function `millis()` is used for Arduino.

#define DBIF_TIMESTAMP_FUN                        millis()

4. Macro to output the function or methode name:
To use this feature, it is enough to comment in this macro only. This macro enables the output of the function 
where the debug macro was called. It can be helpfully to idenfiy wich function cause an for example `LOG_ERROR` messge.

#define DBIF_FUNCTION_OUTPUT_ENABLE

5. Enable debug ouput only on change:

This macro enables some macros which allows you to ouput debug messages only on change. This can be helpfull when a function will be called fast and cyclic. 

#define DBIF_ON_CHANGE_ENABLE

```