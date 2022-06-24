#ifndef DEBUG_IF_ARDUINO_H
#define DEBUG_IF_ARDUINO_H

    #if !defined(DBIF_INIT)
        #define DBIF_INIT(args...)                                  Serial.begin(args)
    #endif

    #if !defined(DBIF_PRINTF_FUN)
        #define DBIF_PRINTF_FUN                                     Serial.printf
    #endif

    #if !defined(DBIF_TIMESTAMP_FUN)
        #define DBIF_TIMESTAMP_FUN                                  millis()
    #endif

    #if defined(DBIF_FUNCTION_OUTPUT_ENABLE)
        #define DBIF_FUNCTION_OUTPUT                                "%s - ", __FUNCTION__
    #else 
        #define DBIF_FUNCTION_OUTPUT                                " "
    #endif
#endif