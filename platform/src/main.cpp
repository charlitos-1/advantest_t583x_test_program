#include "t583x.hpp"
#include "test_item.hpp"
#include <stdio.h>

int main()
{
    TestItem()
        .SetRunStrategy(new RunPattern())
        .SetPassFailStrategy(new FunctionalPassFail())
        .ExecuteRun()
        .ExecutePassFail();

    TestItem()
        .SetRunStrategy(new RunDcMeasurement())
        .SetPassFailStrategy(new RangePassFail())
        .ExecuteRun()
        .ExecutePassFail();

    return 0;
}