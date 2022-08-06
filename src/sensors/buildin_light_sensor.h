#ifndef __BUILDIN_LIGHT_SENSOR_H
#define __BUILDIN_LIGHT_SENSOR_H

#include "sensor.h"


class buildin_light_sensor : public sensor_base
{
public:
	buildin_light_sensor();
	void init();
	const char *get_name();
	void read(struct sensor_data *data);
private:
	const char *name = "buildin-light";
	int light_value;

};

#endif