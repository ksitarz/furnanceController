#include "controller.h"
#include "config.h"


bool controller_heatingPump_control(int temp_heater)
{
    return temp_heater >= controller_config.centralHeatingPump_temp_min &&
    		temp_heater <= controller_config.centralHeatingPump_temp_max;
}

bool controller_hotWaterPump_control(int temp_heater, int hotWaterTemp)
{
    return temp_heater > hotWaterTemp &&
    		hotWaterTemp < controller_config.hotWater_temp_max &&
			temp_heater >= controller_config.hotWater_temp_min;
}

