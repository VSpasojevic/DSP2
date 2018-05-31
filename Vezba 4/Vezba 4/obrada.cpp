#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "obrada.h"
#include "mdct.h"

double time_buffer[MDCT_SIZE];
double mdct_buffer[MDCT_SIZE/2];
double in_delay[MDCT_SIZE/2];
double out_delay[MDCT_SIZE/2];
extern double window[MDCT_SIZE];


void rad(double *signal,int b) {
	int i;
	
	
	
	for (i = 0; i < MDCT_SIZE; i++) {
		signal[i] = (signal[i] >= 0) ? sqrt(signal[i]) : -sqrt(-signal[i]);
		signal[i] = static_cast<int>( round(signal[i])) >> (13 - b);
	}

	for (i = 0; i < MDCT_SIZE; i++) {
		signal[i] = static_cast<int>(signal[i]) << (13 - b);
		signal[i] = (signal[i] >= 0) ? signal[i]*signal[i] : -signal[i] * signal[i];
		
	}
}


void obrada(double *in, double *out, int N)
{
	int i, j;

	for (i = 0; i < N; i++) {
		time_buffer[i] = in_delay[i];
		in_delay[i] = in[i];

	}

	for (j = N; j < 2 * N; j++) {

		time_buffer[j] = in[j];

	}
		
		

	mdct(time_buffer, mdct_buffer);

	rad(mdct_buffer,3);

	imdct(mdct_buffer,time_buffer);

	

	for (i = 0; i < N; i++) {
		out[i] = time_buffer[i] + out_delay[i];
		out[i] /= 2;

	}
		
	for (i = 0; j < 2 * N; i++) {
		out_delay[i] = time_buffer[N+i];

	}
		
}

void statistika()
{
}
