# Debug Interface

This library allows you to integrate simple debugging functionality into your project. It is based on different precompiler macros and can be configured in many different ways. The biggest advantage is that the debug code can remain in the code, even for the release build.

## Enable Debugging in the Project:

To enable the debugging function in the project, a build debug flag needs to be set: `build_flags = -D DEBUG`

### PlatformIO Example:

```
[env:nodemcu-32s]
platform = espressif32
board = nodemcu-32s
framework = arduino
build_flags = -D DEBUG
```

## How to Integrate DebugIf into the Code:

The debug interface can be integrated into each module and used multiple times in the project. For integration, there is a template file `Template_Debug_Inc.h`.

1. Add the compiler flag `-D DEBUG` to your makefile or configuration file.
2. Copy the `Template_Debug_Inc.h` file into a folder.
3. Rename the template file. For example, for `main.h`, rename it to `main_debug.h`.
4. Complete the following steps in the debug template file:

```c
    #define DBIF_ENABLED                        // Uncomment this line to enable debug output for this file

    #define DBIF_LOGLEVEL LOG_DEBUG_0           // Choose the level of debug output.

    #define DBIF_MODULE_NAME "MAIN"             // Choose a module name. This will be displayed in the debug output.
```

### Debug Levels:
For debugging purposes, there are different debug levels available:
- LOG_DEBUG_3  - Maximum debug output [All debug levels + info, warnings, and errors will be printed]
- LOG_DEBUG_2 
- LOG_DEBUG_1 
- LOG_DEBUG_0 
- LOG_INFO    
- LOG_WARN - Warnings and errors will be printed
- LOG_ERROR - Only error messages will be printed
- LOG_NONE    

## Special Debug Options:

There are some special options that can be used to configure the debug interface. All defines have their own default values, and normally they do not need to be changed.

### 1. Macro to Initialize DebugIf:
This macro allows you to use a different initialization function if needed.

```c
#define DBIF_INIT(args...)                      Serial.begin(args)
```
**DEFAULT:** The function `Serial.begin` is used for Arduino.

### 2. Macro to Use Another Message Output Function:
This macro allows you to use a different function to print out your debug messages.

```c
#define DBIF_PRINTF_FUN                         Serial.printf
```
**DEFAULT:** The function `Serial.printf` is used for Arduino.

### 3. Macro to Output Timestamps:
Each debug message includes a timestamp. This macro can be used to change the timestamp function.

**DEFAULT:** The function `millis()` is used for Arduino.

```c
#define DBIF_TIMESTAMP_FUN                      millis()
```

### 4. Macro to Output the Function or Method Name:
To use this feature, simply uncomment this macro. It enables the output of the function where the debug macro was called. This can be helpful to identify which function caused a `LOG_ERROR` message, for example.

```c
#define DBIF_FUNCTION_OUTPUT_ENABLE
```

### 5. Enable Debug Output Only on Change:
This macro enables some macros that allow you to output debug messages only when a change occurs. This can be helpful when a function is called frequently and cyclically.

```c
#define DBIF_ON_CHANGE_ENABLE
```

## Example: How to Use It in Code:

### ***main_debug.h***

```c
#ifndef FILE_DEBUG_IF_H
#define FILE_DEBUG_IF_H

#if defined (DEBUG)
/*--- Required DBIF Flags ------------------------------------------------*/
      
      #define DBIF_ENABLED

      #define DBIF_LOGLEVEL LOG_DEBUG_0

      #define DBIF_MODULE_NAME "MAIN"

     /**
      * @brief Print function interface definition for the whole debug interface
      * This flag is the main debug function definition. This means this flag 
      * combines DBIF_STREAM and DBIF_PRINT to:
      *          DBIF_STREAM.DBIF_PRINT
      * If another print function is required, this flag can be used.
      */
      // #define DBIF_PRINTF_FUN DBIF_STREAM.DBIF_PRINT
      
     /**
      * @brief Timestamp definition function
      * This flag can be used to modify the timestamp function, which will be used 
      * each time the DBIF_LOG... function is called.
      */
      // #define DBIF_TIMESTAMP_FUN millis()

     /**
      * @brief Debug function output enable flag
      * Flag to output the function name where the debug function was called.
      */
      // #define DBIF_FUNCTION_OUTPUT_ENABLE   

       /**
       * @brief Debug macro output on change
       * This flag enables the debug output on change functionality.
       */
      // #define DBIF_ON_CHANGE_ENABLE

  #include "Debug_If.h"
#endif
#endif
```

### ***main.c***

```c
#include <Arduino.h>
#include "main_debug.h"

void setup() {
    DBIF_INIT(9600);
}

uint8_t i = 0;

void loop() {
  DBIF_LOG_DEBUG_3("WORKS  Debug_3 %i", i);
  DBIF_LOG_DEBUG_2("WORKS  Debug_2 %i", i);
  DBIF_LOG_DEBUG_1("WORKS  Debug_1 %i", i);
  DBIF_LOG_DEBUG_0("WORKS Debug_0 %i", i);
    
  DBIF_LOG_INFO("WORKS INFO %i", i);
  DBIF_LOG_WARN("WORKS WARN %i", i);
  DBIF_LOG_ERROR("WORKS ERROR %i", i);
  
  delay(500);
  i++;
}
```

### Änderungen:
- Grammatik- und Rechtschreibfehler wurden korrigiert.
- Syntax wurde angepasst, um konsistent zu sein.
```