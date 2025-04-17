#include "config.h"

const ControllerConfig controller_config = {
    .centralHeatingPump_temp_max = 60,
    .centralHeatingPump_temp_min = 45,
    .hotWater_temp_max = 70,
	.hotWater_temp_min = 40,
    .temp_alarm_high = 90,
    .temp_alarm_low = 5
};

void config_init(void){}
