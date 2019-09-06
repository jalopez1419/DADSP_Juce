/*
  ==============================================================================

    Rect_Pol_Convert.h
    Created: 6 Sep 2019 9:03:13am
    Author:  Johnny Lopez

  ==============================================================================
*/

#pragma once

#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265359
#endif
void rect_to_pol(double* REX, double* IMX, double* MAG, double* PHASE, int size)
{
    for(int k = 0; k <= size; k++)
    {
        MAG[k] = sqrt(pow(REX[k], 2) + pow(IMX[k],2));
        ///To avoid division by zero
        if(REX[k] == 0)
        {
            if(IMX[k] > 0)
            {
                PHASE[k] = M_PI/2;
            }else
            {
                PHASE[k] = -M_PI/2;
            }
        }
        ///
        PHASE[k] = atan(IMX[k]/REX[k]);
        
        ///Correcting Arctangent nuissance
        if(REX[k] < 0 && IMX[k] < 0)
            PHASE[k] = PHASE[k] - M_PI;
        else if(REX[k] < 0 && IMX[k] > 0)
            PHASE[k] = PHASE[k] + M_PI;
    }
}
