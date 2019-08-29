/*
  ==============================================================================

    DADSPConvolution.h
    Created: 5 Jul 2019 4:18:55pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once
#include "memory"

class outputSideConv
{
public:
    
    outputSideConv();
    ~outputSideConv();
    
    void process(float* inBuffer, float* outBuffer, int totalNumSamples, float* impulseREsponse, int impulseSizeInSamps);
    
    
private:
    
    std::unique_ptr<double> convolutionBuffer;
};

class inputSideConv
{
public:
    inputSideConv();
    ~inputSideConv();
    
    void process(float* inBuffer, float* outBuffer, int totalNumSamples, float* impulseResponse, int impulseSize);
    
private:
    
};
class lowPass
{
public:
    
    lowPass();
    ~lowPass();
    
   void process(float* inBuffer, float* outBuffer, int totalNumSamples, float cutOff);
    
private:
    double xh;
    double xh_new;
    double ap_y;
    
    
};

class IirLowpass
{
public:
    IirLowpass();
    ~IirLowpass();
    
    void process(float* inBuffer, float* outBuffer, int totalNumSamples, float cutOff);
    void update();
private:
    float m_del {0.0};
    float m_a{0}, m_b{0};
    float m_sr, m_freq;
    

};
