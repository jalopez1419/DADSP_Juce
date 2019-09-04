/*
  ==============================================================================

    DADSP_DFT.cpp
    Created: 3 Sep 2019 5:54:18pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#include "DADSP_DFT.h"

DADSP_DFT::DADSP_DFT()
{
    
}

DADSP_DFT::DADSP_DFT( int N ) :
N(N)
{
    
}

DADSP_DFT::~DADSP_DFT()
{
    
}


void DADSP_DFT::process(float *inBuffer, float *outBuffer, double *REX, double *IMX, int windowSize)
{
    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < (N/2 + 1); k++)
        {
            outBuffer[i] = REX[k] * cos((2*M_PI*i*k)/N);
            outBuffer[i] = IMX[k] * sin((2*M_PI*i*k)/N);
        }
    }
}
