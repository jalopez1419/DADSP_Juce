/*
  ==============================================================================

    DADSP_DFT.h
    Created: 3 Sep 2019 5:54:18pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once
#include "math.h"

#define DEFAULT_WINDOW_SIZE 512
#define DEFAULT_HALF_WINDOW (DEFAULT_WINDOW_SIZE/2 + 1)

#ifndef M_PI
#define M_PI 3.14159265359
#endif


class DADSP_DFT
{
public:
    
    DADSP_DFT();
    DADSP_DFT(int N);
    ~DADSP_DFT();
    
    void synth_process(float* inBuffer, float* outBuffer, double* REX, double* IMX, int windowSize);
    
    void an_process(float*inBuffer, double* REX, double* IMX, int windowSize);
    
private:
    double mSynthesized[DEFAULT_WINDOW_SIZE] = {0};
    int N = DEFAULT_WINDOW_SIZE;
    
};
