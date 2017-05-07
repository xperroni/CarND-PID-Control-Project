#include "PID.h"

#include <algorithm>
#include <cmath>

/*
* TODO: Complete the PID class.
*/

PID::PID(double K_p, double K_d, double K_i, int cycle) {
    this->K_p = K_p;
    this->K_d = K_d;
    this->K_i = K_i;

    e_p = nan("");
    e_d = 0;
    e_i = 0;
}

PID::~PID() {
    // Nothing to do.
}

double PID::operator () (double cte) {
    if (std::isnan(e_p)) {
        e_p = cte;
    }

    e_d = cte - e_p;
    e_i += cte;
    double a = K_p * cte + K_d * e_d + K_i * e_i;
    e_p = cte;

    return -a;
}
