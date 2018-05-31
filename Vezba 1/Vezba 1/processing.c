/*
 * processing.c
 *
 *  Created on: 29.02.2016.
 *      Author: Dejan Bokan (dejan.bokan@rt-rk.com)
 */

#include "processing.h"
#include "fir.h"
#include "filter_coeff.h"

void downsample(Int16 *input, Int16 *output, int M, int N)
{
	/* your code here... */


	int i,j;
	for(i=0,j=0;i<N;i=i+M,j++){

		output[j]=input[i];
	}


}


void decimate(Int16 *input, Int16 *output, int M, int N)
{
	/* your code here... */


	Int16 his[N_COEFF];
	int i;


	for(i=0;i<N_COEFF;i++){
		his[i]=0;

	}


	for(i=0;i<N;i+=M){
		output[i]=fir_basic(input[i],lp_filter,his,N);

	}
	downsample(input,output,M,N);

}

void upsample(Int16 *input, Int16 *output, int L, int N)
{
	/* your code here... */
	int i,j;
		for(i=0;i<N;i++){
			output[L * i]=input[i];

			for(j=0;j<L;j++){
				output[i+j+1]=0;

			}

		}


}

void interpolate(Int16 *input, Int16 *output, int L, int N)
{
	/* your code here... */


	Int16 his[N_COEFF];
		int i;


		for(i=0;i<N_COEFF;i++){
			his[i]=0;

		}

		upsample(input,output,L,N);

		for(i=0;i<L*N;i++){

			output[i]=fir_basic(input[i],lp_filter,his,N);
		}



}

void resample(Int16 *input, Int16 *output, int L, int M, int N)
{
	/* your code here... */
}
