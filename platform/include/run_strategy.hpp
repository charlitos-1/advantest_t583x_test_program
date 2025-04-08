#pragma once

#include <iostream>

class TestItem; // Forward declaration to avoid circular dependency

class RunStrategy
{
public:
    virtual ~RunStrategy() = default;

    virtual void run(TestItem *test_item) = 0;
};

class RunPattern : public RunStrategy
{
public:
    void run(TestItem *test_item) override;
};

class RunDcMeasurement : public RunStrategy
{
public:
    void run(TestItem *test_item) override;
};