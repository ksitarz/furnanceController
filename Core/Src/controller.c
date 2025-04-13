#include "controller.h"

void controller_init(void)
{
    // tymczasowa pusta implementacja
}

bool controller_should_enable_pump_co(int temp_kociol)
{
    return temp_kociol > 60;
}
