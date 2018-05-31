#include <math.h>
#include <stdlib.h>
#include "obrada.h"
#include "sr_fft.h"

double time_buffer[FFT_SIZE];
double fft_buffer[FFT_SIZE];
double in_delay[FFT_SIZE/2];
double out_delay[FFT_SIZE/2];

extern double window[FFT_SIZE];


void rad(){

}




void obrada(double *in, double *out, int N)
{
  int i,j;

  for (i = 0; i < N; i++) {
	  time_buffer[i] = in_delay[i];
	  in_delay[i] = in[i];

  }
	  
  for (j = N; j < 2 * N; j++) 
	  time_buffer[j] = in[j];
  
  
//prozoriranje
  for (i = 0; i < 2*N; i++) {
	  time_buffer[i] = time_buffer[i] * window[i];
   
  }

  fft(time_buffer, fft_buffer, FFT_ORDER);

  rad();

  ifft(fft_buffer, time_buffer, FFT_ORDER);
 

  //prozoriranje
  for (i = 0; i < 2 * N; i++) {
	  time_buffer[i] = time_buffer[i] * window[i];
  }


  for (i = 0; i < N; i++)
	  out[i]=time_buffer[i] + out_delay[i];

  for (i = 0, j = N; j < 2 * N; i++, j++)
	  out_delay[i] = time_buffer[j];
	  

  /*for (i = 0; i <  N; i++)
	  out[i] = in[i];
	  */

}

