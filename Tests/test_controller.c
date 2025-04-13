#include "unity.h"
#include "controller.h"

void setUp(void) {
    controller_init();
}

void tearDown(void) {}


void test_pompa_co_wlacza_sie_pow_60(void) {
    TEST_ASSERT_TRUE(controller_should_enable_pump_co(65));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_pompa_co_wlacza_sie_pow_60);
    return UNITY_END();
}
