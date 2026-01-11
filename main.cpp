#include <iostream>
#include <vector>


#include "Engine.h"
#include "Constants.h"
#include "TestBench.h"

int main() {
    double ambientTemp;
    std::cout << "Enter ambient temperature (C): " << std::endl;
    std::cin >> ambientTemp;

    double I = 10.0;
    std::vector<double> V = {0, 75, 150, 200, 250, 300};
    std::vector<double> M = {20, 75, 100, 105, 75, 0};

    double T_overheat = 110.0;
    double HM = 0.01;
    double HV= 0.0001;
    double C = 0.1;

    Engine engine (
      I,
      V,
      M,
      T_overheat,
      HM,
      HV,
      C,
      ambientTemp

    );

    TestBench bench;

    double dt = 0.01; //controls error

    std::cout << "\n--- Overheat Test ---\n";
    bench.runOverheatTest(engine, dt);

    std::cout << "\n--- Max Power ---\n";
    bench.runMaxPowerTest(engine, dt);

    return 0;
}