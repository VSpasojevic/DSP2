//////////////////////////////////////////////////////////////////////////////
// * File name: main.c
// *
// * Description:  Vezba 1 - Interpolacija i decimacija
// *
// * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
// * Copyright (C) 2011 Spectrum Digital, Incorporated
// *
//////////////////////////////////////////////////////////////////////////////

#include "tistdtypes.h"
#include <cstdio>
#include "ezdsp5535.h"
#include "math.h"
#include "signal.h"
#include "filter_coeff.h"
#include "processing.h"

/*
 *
 *  main( )
 *
 */
Int16 out[SIGNAL1_LENGTH/4];
Int16 out1[SIGNAL1_LENGTH/4];

Int16 out2[SIGNAL2_LENGTH * 4];
Int16 out3[SIGNAL2_LENGTH * 4];


void main( void )
{

	printf("\n Vezba 1 - Interpolacija i decimacija \n");
	
	/* Your code here */



	downsample(signal1,out,4,SIGNAL1_LENGTH);
	decimate(signal1,out1,4,SIGNAL1_LENGTH/4);

	upsample(signal2,out2,4,SIGNAL2_LENGTH);
	interpolate(signal2,out3,4,SIGNAL2_LENGTH);

	printf( "\n***Program has Terminated***\n" );
	SW_BREAKPOINT;
}

