#pragma once

#include <stdbool.h>


bool controller_heatingPump_control(int temp_heater);

bool controller_hotWaterPump_control(int temp_heater, int hotWaterTemp);
