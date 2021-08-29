#pragma once

#include <map>

enum Memory {
    MAIN_ERROR = 0,
    ERROR_VECTOR_1 = 1,
    ERROR_VECTOR_2 = 2,
    INPUT_REGISTER = 3,
    STATE_MACHINE_CODE = 4,
    FAN_VALUE = 5,
    FAN_SPEED = 6,
    VOLTAGE_BATTERY_1 = 7,
    VOLTAGE_BATTERY_2 = 8,
    VOLTAGE_BATTERY_3 = 9,
    OUTER_THERMISTOR_1 = 10,
    OUTER_THERMISTOR_2 = 11,
    INNER_THERMISTOR_1 = 12,
    INNER_THERMISTOR_2 = 13,
    INNER_THERMISTOR_3 = 14,
    VOLTAGE_LINE_5V = 15,
    VOLTAGE_LINE_12V = 16,
    CURRENT_LINE_12V = 17
};

map <Memory, uint16_t> memoryMap{
        {MAIN_ERROR,         0},
        {ERROR_VECTOR_1,     0},
        {ERROR_VECTOR_2,     0},
        {INPUT_REGISTER,     0},
        {STATE_MACHINE_CODE, 0},
        {FAN_VALUE,          0},
        {FAN_SPEED,          0},
        {VOLTAGE_BATTERY_1,  0},
        {VOLTAGE_BATTERY_2,  0},
        {VOLTAGE_BATTERY_3,  0},
        {OUTER_THERMISTOR_1, 0},
        {OUTER_THERMISTOR_2, 0},
        {INNER_THERMISTOR_1, 0},
        {INNER_THERMISTOR_2, 0},
        {INNER_THERMISTOR_3, 0},
        {VOLTAGE_LINE_5V,    0},
        {VOLTAGE_LINE_12V,   0},
        {CURRENT_LINE_12V,   0}
};
