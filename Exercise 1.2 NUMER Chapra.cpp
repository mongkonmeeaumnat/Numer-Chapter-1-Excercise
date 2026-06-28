#include <stdio.h>
	// This program calculates the velocity of an object falling from a height by Euler's method.
	// Assumption: the initial velocity is zero.  Value is approximation . ;
	
int main() {
	double vi = 0 , v_next ,  g = 9.81 , c = 12.5 , m = 68.1 , dt = 0.5 ;
	// vi = initial velocity , v_next = final velocity by dt , dt = time interval 
	// g = gravitational force , c = drag coefficient , m = mass 
	double endtime = 8.0 ;
		// from t = 0.5 to 8 second ; increase t by 0.5 per step ;
		
	int steps = (int)(endtime/dt) ; // for calculate round of step;
	int showAllSteps = 1; // use 1 for show all step  and 0 for only last step
	
	int i ;
	for(i = 0; i < steps ; i++ ) {
		double t = ( i+1 ) * dt ; // for write V(t) ;
		v_next = vi + (g - (c/m) * vi ) * dt ;
		if (showAllSteps) {
    		printf("v%.1f = %.2f\n", t, v_next);
		} 
		vi = v_next ; // Use the current velocity as the initial velocity for the next step.
	}	
	if (!showAllSteps) {
    printf("v(%.1f) = %.2f\n", endtime, v_next);
}
}
