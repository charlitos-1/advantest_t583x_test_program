#include <iostream>
#include "run_strategy.hpp"

class TestItem
{
private:
    RunStrategy *run_strategy;

public:
    TestItem();
    ~TestItem();
    TestItem &setRunStrategy(RunStrategy *strategy);
    TestItem &executeRun();
};