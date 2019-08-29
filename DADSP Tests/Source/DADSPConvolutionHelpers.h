/*
  ==============================================================================

    DADSPConvolutionHelpers.h
    Created: 3 Jul 2019 8:13:13pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once
/*
  ==============================================================================

    DADSPConvolutionHelpers.h
    Created: 3 Jul 2019 7:07:10pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once


/// class to find the first derivative of incoming buffer of samples
class DADSP_FirstDifference
{
public:
    DADSP_FirstDifference();
    ~DADSP_FirstDifference();
    
    ///process function that returns the first derivative
    void process(float* inBuffer, float* outBuffer, int totalNumOfSamples);
    
    
private:
    
    double* mBuffer = new double(50);
    
    double lastSample;
    
};



///Class to find the runnin sum of the samples
////Both of this implement an efficient method of one sample delay which could be of use in filter design
class DADSP_RunningSum
{
public:
    DADSP_RunningSum();
    ~DADSP_RunningSum();
    
    void process(float* inBuffer, float* outBuffer, int totalNumOfSamples);
    
    
private:
    
    double lastSample;
    
};
