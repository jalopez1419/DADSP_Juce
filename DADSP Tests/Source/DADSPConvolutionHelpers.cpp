/*
  ==============================================================================

    DADSPConvolutionHelpers.cpp
    Created: 3 Jul 2019 7:07:10pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#include "DADSPConvolutionHelpers.h"

DADSP_FirstDifference::DADSP_FirstDifference()
{
    lastSample = 0.0;
}

DADSP_FirstDifference::~DADSP_FirstDifference()
{
    
}


void DADSP_FirstDifference::process(float *inBuffer, float *outBuffer, int totalNumOfSamples)
{
    if(lastSample == 0)
    {
        outBuffer[0] = inBuffer[0];
    }
    outBuffer[0] = 0.5 * lastSample;
    
    for(int i=1; i < totalNumOfSamples; i++)
    {
        outBuffer[i] = 0.5 * inBuffer[i] - 0.5 * inBuffer[i - 1];
        if( i == totalNumOfSamples -1)
        {
            lastSample = inBuffer[i];
        }
    }
}




DADSP_RunningSum::DADSP_RunningSum()
{
    lastSample = 0.0;
}

DADSP_RunningSum::~DADSP_RunningSum()
{
    
}

void DADSP_RunningSum::process(float *inBuffer, float *outBuffer, int totalNumOfSamples)
{
    if(lastSample == 0)
    {
        outBuffer[0] = inBuffer[0];
    }
    outBuffer[0] = lastSample;
    
    for(int i = 1; i < totalNumOfSamples; i++)
    {
        outBuffer[i] = outBuffer[i - 1] + inBuffer[i];
    }
}
