#include "test_item.hpp"

TestItem::TestItem()
{
    run_strategy = nullptr;
    pass_fail_strategy = nullptr;
}

TestItem::~TestItem()
{
    delete run_strategy;
}

TestItem &TestItem::setRunStrategy(RunStrategy *strategy)
{
    if (run_strategy != nullptr)
    {
        delete run_strategy;
    }
    run_strategy = strategy;
    return *this;
}

TestItem &TestItem::executeRun()
{
    if (run_strategy != nullptr)
    {
        run_strategy->run(this); // Pass the current TestItem instance
    }
    else
    {
        std::cout << "No run strategy set." << std::endl;
    }
    return *this;
}

TestItem &TestItem::setPassFailStrategy(PassFailStrategy *strategy)
{
    if (pass_fail_strategy != nullptr)
    {
        delete pass_fail_strategy;
    }
    pass_fail_strategy = strategy;
    return *this;
}

TestItem &TestItem::executePassFail()
{
    if (pass_fail_strategy != nullptr)
    {
        pass_fail_strategy->pass_fail(this); // Pass the current TestItem instance
    }
    else
    {
        std::cout << "No pass/fail strategy set." << std::endl;
    }
    return *this;
}