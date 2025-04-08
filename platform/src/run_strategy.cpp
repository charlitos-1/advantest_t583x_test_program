#include "run_strategy.hpp"

void RunPattern::run(TestItem *test_item)
{
    std::cout << "Running pattern strategy on TestItem: " << test_item << std::endl;
}

void RunDcMeasurement::run(TestItem *test_item)
{
    std::cout << "Running DC measurement strategy on TestItem: " << test_item << std::endl;
}