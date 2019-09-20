/*
  ==============================================================================

    DADSP_FIRFilters.h
    Created: 20 Sep 2019 4:25:09pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once

class DADSP_movingAverageFIR
{
public:
    
    DADSP_movingAverageFIR(int acumSize);
    ~DADSP_movingAverageFIR();
    
    void process(float* inBuffer, float* outBuffer, int blockSize, int averageSize);
    void reset();
    
private:
    
    double *acumulator;
    
    int acumSize;
};
