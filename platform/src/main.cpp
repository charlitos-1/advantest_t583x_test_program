#include "t583x.hpp"
#include "test_item.hpp"
#include <stdio.h>

int main() {
    printf("A basic test program designed to run on Advantest t583x platforms.\n");
    
    TestItem()
        .setRunStrategy(new RunPattern())
        .executeRun();

    TestItem()
    .setRunStrategy(new RunDcMeasurement())
    .executeRun();

    return 0;
}