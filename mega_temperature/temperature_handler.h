#define num_sensors 10
#define temp_sensor_const 0.049

float temperatures[num_sensors];
int pin[num_sensors] = { A2, A3, A4, A5, A6, A7, A8, A9, A10, A11 };

void temp_init() {
  for (uint8_t i = 0; i < num_sensors; i++) {
    pinMode(pin[i], INPUT);
  }
}
void read_temperature() {
  int adc_val;
  for (uint8_t i = 0; i < num_sensors; i++) {
    adc_val = analogRead(pin[i]);
    temperatures[i] = 1.0 * adc_val * temp_sensor_const;
  }
}

String get_temp() {
  read_temperature();
  delay(100);

  String tString = "";
  for (int i = 0; i < num_sensors; i++) {
    tString += String(temperatures[i]);
    if (i != num_sensors - 1)
      tString += ",";
  }

  return tString;
}

String temp_data(uint8_t i){
  return String(temperatures[i]) + " C";
}



