
#include "Engine.h"
#include <algorithm>

Engine::Engine(
    double inertia,
    const std::vector<double>& vPoints,
    const std::vector<double>& mPoints,
    double overheatTemp,
    double hm,
    double hv,
    double coolingCoeff,
    double ambientTemp

    ) : I(inertia),
        V(vPoints),
        M(mPoints),
        T_overheat(overheatTemp),
        HM(hm),
        HV(hv),
        C(coolingCoeff),
        T_env(ambientTemp),
        omega(0.0),
        temperature(ambientTemp) {}

double Engine::interpolateTorque(double v) const {
    if (v <= V.front())
        return M.front();
    if (v >= V.back())
        return M.back();
    for (size_t i = 1; i < V.size(); i++) {
        if (v < V[i]) {
            double t = (v - V[i-1]) / (V[i] - V[i-1]);
            return M[i-1] + t * (M[i] - M[i-1]);
        }
    }
    return 0.0;
}


void Engine::step(double dt) {
    double torque = interpolateTorque(omega);

    //Angular acceleration
    double accelearation = torque / I;
    omega += accelearation * dt;

    //Heating and cooling
    double heating = torque * HM + omega * omega * HV;
    double cooling = C * (T_env - temperature);
    temperature += (heating + cooling) * dt;
}
//Getters
double Engine::getOmega() const {
    return omega;
}

double Engine::getTemperature() const {
    return temperature;
}

double Engine::getPower() const {
    double torque = interpolateTorque(omega);
    return torque * omega / 1000.0;
}

bool Engine::isOverheated() const {
    return temperature >= T_overheat;
}

bool Engine::isAccelerating() const {
    return interpolateTorque(omega) > 0.0;
}
