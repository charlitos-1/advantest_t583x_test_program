#include "pass_fail_strategy.hpp"
#include "test_item.hpp"

void FunctionalPassFail::pass_fail(TestItem *test_item)
{
    std::cout << "Performing functional pass/fail on TestItem: " << test_item << std::endl;
}

void RangePassFail::pass_fail(TestItem *test_item)
{
    std::cout << "Performing range pass/fail on TestItem: " << test_item << std::endl;
}