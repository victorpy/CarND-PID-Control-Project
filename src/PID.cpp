#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	
	isFirstTime = false;
	cte_sum = 0;
}

void PID::UpdateError(double cte) {
	double diff_cte;
	
	//count = count + 1;
	
	
	cte_sum = cte_sum + cte;
	diff_cte = cte - prev_cte;
	prev_cte = cte;
	p_error = -Kp * cte;
	d_error = Kd * diff_cte;
	i_error = Ki * cte_sum;
}

double PID::TotalError() {
	return p_error - d_error - i_error;
}

