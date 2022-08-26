#ifndef __GROVE_SOIL_SENSOR_H
#define __GROVE_SOIL_SENSOR_H

#include "sensor.h"
#include "utils.h"
#include "Arduino.h"

#define SOILPIN A0
#define READ_NUM 10
#define SOIL_DATA_MAX 1000
#define DATA_VARIANCE_MAX 20


class grove_soil_sensor : public sensor_base {
  public:
    grove_soil_sensor();
    void        init();
    const char *get_name();
    bool        read(struct sensor_data *data);

  private:
    const char *name = "soil sensor"; /// buildin-light
    int         soil_value;
};

#endif