#include "test_item.hpp"

TestItem::TestItem()
{
    run_strategy = nullptr;
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