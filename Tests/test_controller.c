#include "unity.h"
#include "controller.h"
#include "config.h"

void setUp(void) {
    config_init();
    //Init config values
	//controller_config.centralHeatingPump_temp_max = 60;
	//controller_config.centralHeatingPump_temp_min = 45;
	//controller_config.hotWater_temp_max = 70;
	//controller_config.temp_alarm_high = 90;
	//controller_config.temp_alarm_low = 5;
}

void tearDown(void) {}

//HEATING PUMP
void test_HeatingPumpOn_tempInRange(void) {
    TEST_ASSERT_TRUE(controller_heatingPump_control(50));
    TEST_ASSERT_TRUE(controller_heatingPump_control(60));
    TEST_ASSERT_TRUE(controller_heatingPump_control(45));
}

void test_HeatingPumpOff_tempBelowRange(void) {
    TEST_ASSERT_FALSE(controller_heatingPump_control(44));
    TEST_ASSERT_FALSE(controller_heatingPump_control(3));
}
void test_HeatingPumpOff_tempAboveRange(void) {
    TEST_ASSERT_FALSE(controller_heatingPump_control(61));
    TEST_ASSERT_FALSE(controller_heatingPump_control(100));
}

//HOT WATER PUMP
void test_HotWaterPumpOn_tempInRange(void) {
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(60, 50));
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(80, 30));
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(45, 44));
}
void test_HotWaterPumpOff_tempBelowRange(void) {					//<--------brak dolnego limitu
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(44,43));
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(50,40));
}
void test_HotWaterPumpOff_tempAboveRange(void) {
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(80,71));
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(50,60));
}

int main(void)
{
    UNITY_BEGIN();
    //HEATING PUMP
    RUN_TEST(test_HeatingPumpOn_tempInRange);
    RUN_TEST(test_HeatingPumpOff_tempBelowRange);
    RUN_TEST(test_HeatingPumpOff_tempAboveRange);
    //HOT WATER PUMP
    RUN_TEST(test_HotWaterPumpOn_tempInRange);
    RUN_TEST(test_HotWaterPumpOff_tempBelowRange);
    RUN_TEST(test_HotWaterPumpOff_tempAboveRange);

    return UNITY_END();

}
