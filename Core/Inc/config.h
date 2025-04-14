#pragma once

typedef struct {
    int centralHeatingPump_temp_max;     // temperatura włączenia pompy CO
    int centralHeatingPump_temp_min;    // temperatura wyłączenia pompy CO
    int hotWater_temp_max;      		// temperatura wyłączenia pompy CWU
    int temp_alarm_high; 				// alarm zbyt wysokiej temperatury
    int temp_alarm_low;  				// alarm zbyt niskiej temperatury
} ControllerConfig;

extern const ControllerConfig controller_config;

void config_init(void);
