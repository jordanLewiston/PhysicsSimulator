#pragma once
#include <vector>


class Engine {
public:
    //Constructor
    Engine(double inertia,
           const std::vector<double>& vPoints,
           const std::vector<double>& mPoints,
           double overheatTemp,
           double hm,
           double hv,
           double coolingCoeff,
           double ambientTemp);
    //Simulation
    void step(double dt);
    //Getters
    double getOmega() const;
    double getTemperature() const;
    double getPower() const;

    //State queries
    bool isOverheated() const;
    bool isAccelerating() const;

private:
    //Parameters
    double I;
    std::vector<double> V;
    std::vector<double> M;

    double T_overheat;
    double HM;
    double HV;
    double C;
    double T_env;

    double omega;
    double temperature;

    double interpolateTorque(double v) const;

};

