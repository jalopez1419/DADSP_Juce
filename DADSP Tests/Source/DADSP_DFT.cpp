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


void DADSP_DFT::synth_process(float *inBuffer, float *outBuffer, double *REX, double *IMX, int windowSize)
{
    for(int k=0; k <= N/2; k++)
    {
        REX[k] = REX[k]/(N/2);
        IMX[k] = -IMX[k]/(N/2);
    }
    REX[0] = REX[0]/2;
    REX[N/2] = REX[N/2]/2;
    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < (N/2 + 1); k++)
        {
            
            outBuffer[i] = REX[k] * cos((2*M_PI*i*k)/N);
            outBuffer[i] = IMX[k] * sin((2*M_PI*i*k)/N);
        }
    }
}

void DADSP_DFT::an_process(float *inBuffer, double *REX, double *IMX, int windowSize)
{
    for(int k=0; k <= N/2; k++)
    {
        for(int i = 0; i < N; i++)
        {
            REX[k] = REX[k] + inBuffer[i] * cos((2 * M_PI * k * i)/N);
            IMX[k] = IMX[k] - inBuffer[i] * sin((2 * M_PI * k * i)/N);
        }
    }
}
