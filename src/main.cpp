// main file for ESP32 project
#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void setup() {
  Serial.begin(115200);
  
  // Конфигурация на I2S пинове за PCM5102
  i2s_pin_config_t my_pin_config = {
    .bck_io_num = 26,    // BCK -> GPIO26
    .ws_io_num = 25,     // LCK (LRCK) -> GPIO25
    .data_out_num = 22,  // DIN -> GPIO22
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  
  a2dp_sink.set_pin_config(my_pin_config);
  a2dp_sink.start("ESP32_Speaker");
  
  Serial.println("Bluetooth speaker with PCM5102 started!");
}

void loop() {
  delay(1000);
}
