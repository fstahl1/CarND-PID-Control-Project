#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // Initialize PID coefficients
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;

  // Initialize PID errors
  p_error = 0;
  d_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error; // substract current proportional error from last one to get differential error
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return - Kp*p_error - Kd*d_error - Ki*i_error;  // TODO: Add your total error calc here!
}