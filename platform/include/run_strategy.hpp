#include <iostream>

class RunStrategy {
public:
    virtual ~RunStrategy() = default;

    // Method to be implemented by derived classes
    virtual void run() = 0;
};

class RunPattern : public RunStrategy {
public:
    void run() override;
};

class RunDcMeasurement : public RunStrategy {
public:
    void run() override;
};