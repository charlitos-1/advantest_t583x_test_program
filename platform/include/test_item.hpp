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
    TestItem &SetRunStrategy(RunStrategy *strategy);
    TestItem &ExecuteRun();
    TestItem &SetPassFailStrategy(PassFailStrategy *strategy);
    TestItem &ExecutePassFail();
};