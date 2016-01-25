/*
 * NewtonRaphsonMethodCPUCode.c
 *
 *  Created on: Jan 11, 2016
 *      Author: demo
 */

#include <stdio.h>
#include <math.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

double f(double x) {
	return x * x * x - x - 1;
}

double df(double x) {
	return 3 * x * x - 1;
}

int main() {
	int maxmitr = 10;
	int itr;
	double allerr = 0.0000000000001;
	double x0 = 1.5;
	double h, x1;
	double *x1_out = malloc(maxmitr * sizeof(double));

	for (itr = 1; itr <= maxmitr; itr++) {
		h = f(x0) / df(x0);
		x1 = x0 - h;
		printf("At Iteration no. %3d, x = %15.13f\n", itr, x1);
		x0 = x1;
	}

	if (fabs(h) < allerr) {
		printf("After %3d iterations, root = %15.13f\n", itr - 1, x1);
	} else {
		printf("The required solution does not converge or iterations are insufficient\n");
	}

	printf("Running on DFE.\n");
	NRM(maxmitr, x0, x1_out);
	printf("Checking data read from DFE.\n");

	if (x1 == x1_out[0]) {
		printf("The test is OK!\n");
		return 0;
	} else {
		printf("The test is NOT OK!\n");
		return 1;
	}
}
