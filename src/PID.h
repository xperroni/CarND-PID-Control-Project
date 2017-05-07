#ifndef PID_H
#define PID_H

#include <vector>

struct PID {
    /*
     * Errors
     */

    /** @brief Previous instantaneous error. */
    double e_p;

    /** @brief Differential error. */
    double e_d;

    /** @brief Integral error. */
    double e_i;

    /*
     * Coefficients
     */

    /** @brief Instantaneous coefficient. */
    double K_p;

    /** @brief Differential coefficient. */
    double K_d;

    /** @brief Integral coefficient. */
    double K_i;

    /**
     * @brief Create a new PID controller with given coefficients.
     */
    PID(double K_p, double K_d, double K_i, int cycle = -1);

    /*
     * Destructor.
     */
    virtual ~PID();

    /*
     * Compute the steering response in the range `[-1, 1]` given the cross track error.
     */
    double operator () (double cte);
};

#endif /* PID_H */
