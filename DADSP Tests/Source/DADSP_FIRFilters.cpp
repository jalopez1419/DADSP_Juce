/*
  ==============================================================================

    DADSP_FIRFilters.cpp
    Created: 20 Sep 2019 4:25:09pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#include "DADSP_FIRFilters.h"

DADSP_movingAverageFIR::DADSP_movingAverageFIR(int acumSize) :
acumSize(acumSize)
{
    acumulator = new double[acumSize];
}

DADSP_movingAverageFIR::~DADSP_movingAverageFIR()
{
    delete[] acumulator;
}

///////////////////////////////////////
/// Call this before using process ////
void DADSP_movingAverageFIR::reset()
{
    for(int i = 0; i < acumSize; i++)
        acumulator[i] = 0.0;
}

//////Implementation of average moving filter
void DADSP_movingAverageFIR::process(float* inBuffer, float* outBuffer, int blockSize, int averageSize)
{
    for(int j = 0; j < blockSize; j++)
    {
        for(int i = 0; i < averageSize; i++)
        {
            outBuffer[j] = outBuffer[j] + inBuffer[j + i];
        }
        //acumulator[j] = acumulator[j]/averageSize;
        outBuffer[j] = outBuffer[j]/averageSize;
    }
    
}
