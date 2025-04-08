#pragma once

#include <iostream>

class TestItem; // Forward declaration to avoid circular dependency

class PassFailStrategy
{
public:
    virtual ~PassFailStrategy() = default;

    virtual void pass_fail(TestItem *test_item) = 0;
};

class FunctionalPassFail : public PassFailStrategy
{
public:
    void pass_fail(TestItem *test_item) override;
};

class RangePassFail : public PassFailStrategy
{
public:
    void pass_fail(TestItem *test_item) override;
};