//#define UNITY_PRINT_TEST_NAMES
#include "unity_fixture.h"
#include "controller.h"
#include "config.h"

TEST_GROUP(HPump);
TEST_GROUP(HWPump);


//===========================HEATING PUMP===========================
TEST_SETUP(HPump) {
    config_init();
    //Init config values
	//controller_config.centralHeatingPump_temp_max = 60;
	//controller_config.centralHeatingPump_temp_min = 45;
	//controller_config.hotWater_temp_max = 70;
	//controller_config.temp_alarm_high = 90;
	//controller_config.temp_alarm_low = 5;
}

TEST_TEAR_DOWN(HPump) {}


TEST(HPump, TurnsOn_WhenTempInRange) {
    TEST_ASSERT_TRUE_MESSAGE(controller_heatingPump_control(45), "Pompa CO powinna sie wlaczyc przy 45C");
    TEST_ASSERT_TRUE_MESSAGE(controller_heatingPump_control(50), "Pompa CO powinna sie wlaczyc przy 50C");
    TEST_ASSERT_TRUE_MESSAGE(controller_heatingPump_control(600), "Pompa CO powinna sie wlaczyc przy 60C");
}

TEST(HPump, test_HeatingPumpOff_tempBelowRange) {
    TEST_ASSERT_FALSE(controller_heatingPump_control(44));
    TEST_ASSERT_FALSE(controller_heatingPump_control(3));
}
TEST(HPump, test_HeatingPumpOff_tempAboveRange) {
    TEST_ASSERT_FALSE(controller_heatingPump_control(61));
    TEST_ASSERT_FALSE(controller_heatingPump_control(100));
}

//===========================HOT WATER PUMP===========================
TEST_SETUP(HWPump) {
    config_init();
    //Init config values
	//controller_config.centralHeatingPump_temp_max = 60;
	//controller_config.centralHeatingPump_temp_min = 45;
	//controller_config.hotWater_temp_max = 70;
	//controller_config.temp_alarm_high = 90;
	//controller_config.temp_alarm_low = 5;
}

TEST_TEAR_DOWN(HWPump) {}

TEST(HWPump, test_HotWaterPumpOn_tempInRange) {
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(60, 50));
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(80, 30));
    TEST_ASSERT_TRUE(controller_hotWaterPump_control(45, 44));
}
TEST(HWPump, test_HotWaterPumpOff_tempBelowRange) {
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(44,43));
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(39,1));
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(50,40));
}
TEST(HWPump, test_HotWaterPumpOff_tempAboveRange) {
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(80,71));
    TEST_ASSERT_FALSE(controller_hotWaterPump_control(50,60));
}

TEST_GROUP_RUNNER(HPump) {
    RUN_TEST_CASE(HPump, TurnsOn_WhenTempInRange);
    RUN_TEST_CASE(HPump, test_HeatingPumpOff_tempBelowRange);
    RUN_TEST_CASE(HPump, test_HeatingPumpOff_tempAboveRange);
}

TEST_GROUP_RUNNER(HWPump) {
    RUN_TEST_CASE(HWPump, test_HotWaterPumpOn_tempInRange);
    RUN_TEST_CASE(HWPump, test_HotWaterPumpOff_tempBelowRange);
    RUN_TEST_CASE(HWPump, test_HotWaterPumpOff_tempAboveRange);
}

void RunAllTests(void) {
    RUN_TEST_GROUP(HPump);
    RUN_TEST_GROUP(HWPump);
}


int main(int argc, const char* argv[]) {
    return UnityMain(argc, argv, RunAllTests);
}



