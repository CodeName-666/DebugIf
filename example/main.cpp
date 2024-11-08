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
  DBIF_LOG_WARN("WORKS WAN %i", i);
  DBIF_LOG_ERROR("WORKS ERROR %i", i);
  

  delay(500);
  i++;
}