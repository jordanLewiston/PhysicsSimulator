#include "TestBench.h"
#include <iostream>


//Test 1
OverheatResult TestBench::runOverheatTest(Engine &engine, double dt) {
    double time = 0.0;

    while (!engine.isOverheated()) {
        engine.step(dt);
        time += dt;
    }
    std::cout << "Overheat time: " << time << " seconds\n";
    return OverheatResult{time};
}

//Test 2
MaxPowerResult TestBench::runMaxPowerTest(Engine &engine, double dt) {
    double maxPower = 0.0;
    double omegaAtMax = 0.0;
    double maxSimTime = 1000; // seconds
    double time = 0.0;

    while (engine.isAccelerating() && time < maxSimTime) {
        engine.step(dt);
        time += dt;


        double power = engine.getPower();
        if (power > maxPower) {
            maxPower = power;
            omegaAtMax = engine.getOmega();
        }
    }
    std::cout << "MaxPower: " << maxPower << "kW\n";
    std::cout << "Angular velocity at max power:  " << omegaAtMax << " rad/s\n";

    return MaxPowerResult{maxPower, omegaAtMax};
}
