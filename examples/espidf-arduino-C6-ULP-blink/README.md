# Arduino ULP Example for the ESP32-C6

This example shows how to run a C program on the ESP32-C6 ULP core with Arduino (as an component of ESP-IDF) 

## Two programs run parallel

1. **Arduino on the High Power Core (HP Core):** The Arduino program blinks the onboard RGB
2. **C Program on the Ultra-Low Power Core (ULP):** The ULP C program blinks an external LED connected to GPIO3

