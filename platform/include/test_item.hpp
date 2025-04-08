#pragma once

#include <iostream>
#include "run_strategy.hpp"
#include "pass_fail_strategy.hpp"

class TestItem
{
private:
    RunStrategy *run_strategy;
    PassFailStrategy *pass_fail_strategy;

public:
    TestItem();
    ~TestItem();
    TestItem &PrintTestItemMembers();
    TestItem &setRunStrategy(RunStrategy *strategy);
    TestItem &executeRun();
    TestItem &setPassFailStrategy(PassFailStrategy *strategy);
    TestItem &executePassFail();
};