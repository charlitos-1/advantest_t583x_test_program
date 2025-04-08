#include "t583x.hpp"
#include "test_item.hpp"
#include <stdio.h>

int main()
{
    TestItem()
        .setRunStrategy(new RunPattern())
        .setPassFailStrategy(new FunctionalPassFail())
        .executeRun()
        .executePassFail();

    TestItem()
        .setRunStrategy(new RunDcMeasurement())
        .setPassFailStrategy(new RangePassFail())
        .executeRun()
        .executePassFail();

    return 0;
}