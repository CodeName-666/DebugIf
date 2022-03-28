// Definitions before include:
// DEBUG_LEVEL - One of LOG_DEBUG_0 = 4, LOG_INFO = 3, LOG_WARN = 2, LOG_ERROR = 1, LOG_NONE = 0, default to LOG_WARN
// DEBUG_MOD_NAME - Name of the module to be debugged, default to "ANON"
// DBIF_PRINTF_FUN - printf function to use to output log messages, default to "Serial.printf"



#if !defined(DBIF_ENABLED)
    #undef DBIF_LOGLEVEL
    #define DBIF_LOGLEVEL 0
#endif

#undef LOG_DEBUG_3
#undef LOG_DEBUG_2
#undef LOG_DEBUG_1
#undef LOG_DEBUG_0
#undef LOG_INFO
#undef LOG_WARN
#undef LOG_ERROR
#undef LOG_NONE

#define LOG_DEBUG_3 7
#define LOG_DEBUG_2 6
#define LOG_DEBUG_1 5
#define LOG_DEBUG_0 4
#define LOG_INFO    3
#define LOG_WARN    2
#define LOG_ERROR   1
#define LOG_NONE    0

#if !defined(DBIF_LOGLEVEL)
    #define DBIF_LOGLEVEL LOG_WARN
#endif

#if !defined(DBIF_MODULE_NAME)
    #define DBIF_MODULE_NAME "ANON"
#endif

#if defined(DBIF_ON_CHANGE_ENABLE)
    #define LOG_ON_CHANGE_ENABLE
#endif

#if !defined(DBIF_PRINTF_FUN)
    #ifdef Arduino_h

        #if !defined(DBIF_STREAM)
            #define DBIF_STREAM Serial
        #endif

        #if !defined(DBIF_PRINT)
            #define DBIF_PRINT printf
        #endif

        #if !defined(DBIF_PRINTF_FUN)
            #define DBIF_PRINTF_FUN DBIF_STREAM.DBIF_PRINT
        #endif

        #if !defined(DBIF_TIMESTAMP_FUN)
            #define DBIF_TIMESTAMP_FUN millis()
        #endif
    #endif

    #if defined(DBIF_FUNCTION_OUTPUT_ENABLE)
        #define DBIF_FUNCTION_OUTPUT "%s - ", __FUNCTION__
    #else 
        #define DBIF_FUNCTION_OUTPUT " "
    #endif
#else
    #if !defined(DBIF_PRINTF_FUN)
        #include <stdio.h>
        #define DBIF_PRINTF_FUN printf
    #endif
#endif

/* A set of convenience macros for common log levels. */
#undef DBIF_LOG_DEBUG_3
#undef DBIF_LOG_DEBUG_2
#undef DBIF_LOG_DEBUG_1
#undef DBIF_LOG_DEBUG_0
#undef DBIF_LOG_INFO
#undef DBIF_LOG_WARN
#undef DBIF_LOG_ERROR

#undef DBIF_IF_DEBUG_3
#undef DBIF_IF_DEBUG_2
#undef DBIF_IF_DEBUG_1
#undef DBIF_IF_DEBUG_0
#undef DBIF_IF_INFO
#undef DBIF_IF_WARN
#undef DBIF_IF_ERROR


// DEBUG_3
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_DEBUG_3 
    #define DBIF_LOG_DEBUG_3(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_LOG_DEBUG_3_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_IF_DEBUG_3(X) X
#else
    #define DBIF_LOG_DEBUG_3(...)  do {} while(0)
    #define DBIF_LOG_DEBUG_3_ONCE(...) do {} while(0)
    #define DBIF_IF_DEBUG_3(...) 
#endif

// DEBUG_2
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_DEBUG_2
    #define DBIF_LOG_DEBUG_2(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_LOG_DEBUG_2_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_IF_DEBUG_2(X) X
#else
    #define DBIF_LOG_DEBUG_2(...)  do {} while(0)
    #define DBIF_LOG_DEBUG_2_ONCE(...) do {} while(0)
    #define DBIF_IF_DEBUG_2(...) 
#endif

// DEBUG_1
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_DEBUG_1 
    #define DBIF_LOG_DEBUG_1(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_LOG_DEBUG_1_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_IF_DEBUG_1(X) X
#else
    #define DBIF_LOG_DEBUG_1(...)  do {} while(0)
    #define DBIF_LOG_DEBUG_1_ONCE(...) do {} while(0)
    #define DBIF_IF_DEBUG_1(...) 
#endif

// DEBUG_0
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_DEBUG_0 
    #define DBIF_LOG_DEBUG_0(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_LOG_DEBUG_0_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"DEBUG", __VA_ARGS__)
    #define DBIF_IF_DEBUG_0(X) X
#else
    #define DBIF_LOG_DEBUG_0(...)  do {} while(0)
    #define DBIF_LOG_DEBUG_0_ONCE(...) do {} while(0)
    #define DBIF_IF_DEBUG_0(...) 
#endif

// DEBUG
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_INFO
    #define DBIF_LOG_INFO(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"INFO ", __VA_ARGS__)
    #define DBIF_LOG_INFO_ONCE(VAR,...) DBIF_ON_CHANGE_LOG_MACRO(VAR,DBIF_MODULE_NAME,"INFO ", __VA_ARGS__)
    #define DBIF_IF_INFO(X) X
    
#else
    #define DBIF_LOG_INFO(...)  do {} while(0)
    #define DBIF_LOG_INFO_ONCE(...) do {} while(0)
    #define DBIF_IF_INFO(...) 
#endif

// DEBUG
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_WARN
    #define DBIF_LOG_WARN(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"WARN ", __VA_ARGS__)
    #define DBIF_LOG_WARN_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"WARN ", __VA_ARGS__)
    #define DBIF_IF_WARN(X) X
#else
    #define DBIF_LOG_WARN(...)  do {} while(0)
    #define DBIF_LOG_WARN_ONCE(...)  do {} while(0)
    #define DBIF_IF_WARN(...) 
#endif

// DEBUG
#if defined(DEBUG) && DBIF_LOGLEVEL >= LOG_ERROR
    #define DBIF_LOG_ERROR(...) DBIF_LOG_MACRO(DBIF_MODULE_NAME,"ERROR", __VA_ARGS__)
    #define DBIF_LOG_ERROR_ONCE(OC_VAR,...) DBIF_ON_CHANGE_LOG_MACRO(OC_VAR,DBIF_MODULE_NAME,"ERROR", __VA_ARGS__)

    #define DBIF_IF_ERROR(X) X
#else
    #define DBIF_LOG_ERROR(...)  do {} while(0)
    #define DBIF_LOG_ERROR_ONCE(OC_VAR,...) do {} while(0)
    #define DBIF_IF_ERROR(...) 
#endif

#if defined(DBIF_TIMESTAMP_FUN)
    #define DBIF_LOG_TIMESTAMP_MACRO                          \
        do                                                    \
        {                                                     \
            DBIF_PRINTF_FUN("%010lu - ", DBIF_TIMESTAMP_FUN); \
        } while(0)
#else
    #define DBIF_LOG_TIMESTAMP_MACRO do {} while(0)
#endif

#undef DBIF_LOG_MACRO
#define  DBIF_LOG_MACRO(NAME, DEBUG_LEVEL, ...)       \
    do {                                              \
        DBIF_LOG_TIMESTAMP_MACRO;                     \
        DBIF_PRINTF_FUN(NAME " - " );                 \
        DBIF_PRINTF_FUN(DBIF_FUNCTION_OUTPUT);        \
        DBIF_PRINTF_FUN(DEBUG_LEVEL ": " );           \
        DBIF_PRINTF_FUN(__VA_ARGS__);                 \
        DBIF_PRINTF_FUN("\n");                        \
    } while(0)

#if defined(LOG_ON_CHANGE_ENABLE)                       
    #define DBIF_SET_ON_CHANGE_VAR(OC_VAR, DATA_TYPE)                 \
            static DATA_TYPE DBIF_ON_CHANGE_##OC_VAR = OC_VAR;        \
            
    #define DBIF_GET_ON_CHANGE_VAR(OC_VAR)                    \
            DBIF_ON_CHANGE_##OC_VAR

    #define DBIF_ON_CHANGE_LOG_MACRO(ON_CHANGE_VAR, NAME, DEBUG_LEVEL, ...)    \
    do                                                                 \
    {                                                                  \
                                                                       \
       if(DBIF_GET_ON_CHANGE_VAR(ON_CHANGE_VAR) != ON_CHANGE_VAR)      \
       {                                                               \
            DBIF_LOG_MACRO(NAME,DEBUG_LEVEL,__VA_ARGS__);              \
            DBIF_ON_CHANGE_##ON_CHANGE_VAR = ON_CHANGE_VAR;            \
            Serial.printf("Static OC_VAR = %i | Local OC_VAR = %i\n",DBIF_GET_ON_CHANGE_VAR(ON_CHANGE_VAR), ON_CHANGE_VAR);\
       }                                                               \
    }while(0)
#else
    #define DBIF_SET_ON_CHANGE_VAR(...) do {} while(0)
    
    #define DBIF_GET_ON_CHANGE_VAR(...) do {} while(0)

    #define DBIF_ON_CHANGE_LOG_MACRO(...) do {} while(0)

#endif


#undef DBIF_LOGLEVEL
