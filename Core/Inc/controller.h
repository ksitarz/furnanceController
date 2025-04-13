#pragma once

#include <stdbool.h>

void controller_init(void);

bool controller_should_enable_pump_co(int temp_kociol);
