#pragma once

#include "Engine.h"

struct OverheatResult {
    double timeToOverheat;

};
struct MaxPowerResult {
    double maxPower;
    double omegaAtMaxPower;

};
class TestBench {
public:
    OverheatResult runOverheatTest(Engine &engine, double dt);
    MaxPowerResult runMaxPowerTest(Engine &engine, double dt);
};


