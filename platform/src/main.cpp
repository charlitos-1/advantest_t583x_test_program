#include "t583x.hpp"
#include "test_item.hpp"
#include <stdio.h>

int main()
{
    printf("A basic test program designed to run on Advantest t583x platforms.\n");

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