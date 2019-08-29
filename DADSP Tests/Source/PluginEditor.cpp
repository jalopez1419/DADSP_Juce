/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DadspTestsAudioProcessorEditor::DadspTestsAudioProcessorEditor (DadspTestsAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //auto& params = processor.getParameters();

    
    
    mCutOff.setSliderStyle (Slider::LinearBarVertical);
    mCutOff.setRange(0, 10000, 10);
    mCutOff.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    mCutOff.setPopupDisplayEnabled (true, false, this);
    mCutOff.setTextValueSuffix (" Feedback");
    mCutOff.setValue(900);
    
    addAndMakeVisible(mCutOff);
    
    mCutOff.addListener(this);
}

DadspTestsAudioProcessorEditor::~DadspTestsAudioProcessorEditor()
{
}

//==============================================================================
void DadspTestsAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void DadspTestsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
     mCutOff.setBounds (40, 30, 20, getHeight() - 60);
}

void DadspTestsAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.cutoff = mCutOff.getValue();

}
