/*
  ==============================================================================

    DADSPConvolution.cpp
    Created: 5 Jul 2019 4:18:55pm
    Author:  Johnny Lopez

  ==============================================================================
*/

#include "DADSPConvolution.h"
#include "JuceHeader.h"

outputSideConv::outputSideConv()
{
    
}

outputSideConv::~outputSideConv()
{
    
}

void outputSideConv::process(float *inBuffer, float *outBuffer, int totalNumSamples, float *impulseREsponse, int impulseSizeInSamps)
{
    convolutionBuffer = std::make_unique<double>();
    
    for(int i = 0; i< totalNumSamples; i++)
    {
        
    }
}

inputSideConv::inputSideConv()
{
    
}
inputSideConv::~inputSideConv()
{
    
}

void inputSideConv::process(float *inBuffer, float *outBuffer, int totalNumSamples, float *impulseResponse, int impulseSize)
{
    for (int i = 0; i < totalNumSamples; i++) {
        for (int j = 0; j < impulseSize; j++) {
            outBuffer[i + j] = outBuffer[i +j] + inBuffer[i]*impulseResponse[j];
        }
    }
}

lowPass::lowPass() : xh(0.0)
{
    
}

lowPass::~lowPass()
{
    
}

void lowPass::process(float* inBuffer, float* outBuffer, int totalNumSamples, float cutOff)
{
    double c;
    c = (tan(M_PI*cutOff/2)-1) / (tan(M_PI*cutOff/2)+1);
    for(int i = 0; i < totalNumSamples; i++)
    {
        xh_new = inBuffer[i] - c*xh;
        ap_y = c * xh_new + xh;
        outBuffer[i] = 0.5 * (inBuffer[i] - ap_y);
    }
    
}

IirLowpass::IirLowpass() : m_sr(44100.0), m_freq(900)
{
    update();
}

IirLowpass::~IirLowpass()
{
    
}

void IirLowpass::update()
{
    double costh = 2.0 - cos(2.0 * M_PI * m_freq / m_sr);
    m_b = sqrt(costh * costh - 1.0) - costh;
    m_a = (1.0 + m_b);
}

void IirLowpass::process(float *inBuffer, float *outBuffer, int totalNumSamples, float cutOff)
{
    
    if (cutOff != m_freq)
    {
        m_freq = cutOff;
        update();
    }
    for(int i = 0; i < totalNumSamples; i++) {
        m_del = m_a * inBuffer[i] - m_b * m_del;
        outBuffer[i] = m_del;
    }
}
