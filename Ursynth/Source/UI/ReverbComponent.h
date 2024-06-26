/*
  ==============================================================================

    ReverbComponent.h
    Created: 15 Mar 2024 3:26:02pm
    Author:  Matthew

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MyLookAndFeel.h"

//==============================================================================
/*
*/
class ReverbComponent  : public juce::Component
{
public:
    ReverbComponent()
    {
        createKnob(dtSlider, dtLabel, 0.1, 0.1, 60, 0.01);
        createKnob(dampSlider, dampLabel, 0, 0, 1, 0.01);
        createKnob(sizeSlider, sizeLabel, 1, 0.5, 3, 0.01);
        createKnob(earlyDiffSlider, earlyDiffLabel, 0.5, 0, 1, 0.01);
        createKnob(feedbackSlider, feedbackLabel, 0.5, 0, 1, 0.01);
        createKnob(modDepthSlider, modDepthLabel, 0.0, 0.0, 1, 0.01);
        createKnob(modFreqSlider, modFreqLabel, 1, 0, 10, 0.01);
        createKnob(dryWetMixSlider, dryWetMixLabel, 0.5, 0, 1, 0.01);
        createLabel(dtLabel, "Time");
        createLabel(dampLabel, "Damp");
        createLabel(sizeLabel, "Size");
        createLabel(earlyDiffLabel, "Diffusion");
        createLabel(feedbackLabel, "Feedback");
        createLabel(modDepthLabel, "Mod Depth");
        createLabel(modFreqLabel, "Mod Freq");
        createLabel(dryWetMixLabel, "Dry/Wet");
    }

    ~ReverbComponent() override
    {
        dtSlider.setLookAndFeel(nullptr);
        dampSlider.setLookAndFeel(nullptr);
        sizeSlider.setLookAndFeel(nullptr);
        earlyDiffSlider.setLookAndFeel(nullptr);
        feedbackSlider.setLookAndFeel(nullptr);
        modDepthSlider.setLookAndFeel(nullptr);
        modFreqSlider.setLookAndFeel(nullptr);
        dryWetMixSlider.setLookAndFeel(nullptr);
    }

    void paint (juce::Graphics& g) override
    {
        g.setColour(juce::Colours::grey);
        //g.drawRect(getLocalBounds(), 1);   // draw an outline around the component
    }

    void resized() override
    {
        float reverbSliderSize = 90;
       
        dtSlider.setBounds(0, 90, reverbSliderSize, reverbSliderSize);
        dtLabel.setBounds(dtSlider.getX(), dtSlider.getY() + dtSlider.getHeight(), 90, 20);
        
        sizeSlider.setBounds(125, 90, reverbSliderSize, reverbSliderSize);
        sizeLabel.setBounds(sizeSlider.getX(), sizeSlider.getY() + sizeSlider.getHeight(), 90, 20);

        earlyDiffSlider.setBounds(250, 90, reverbSliderSize, reverbSliderSize);
        earlyDiffLabel.setBounds(earlyDiffSlider.getX(), earlyDiffSlider.getY() + earlyDiffSlider.getHeight(), 90, 20);

        feedbackSlider.setBounds(0, 200, reverbSliderSize, reverbSliderSize);
        feedbackLabel.setBounds(feedbackSlider.getX(), feedbackSlider.getY() + feedbackSlider.getHeight(), 90, 20);

        modDepthSlider.setBounds(125, 200, reverbSliderSize, reverbSliderSize);
        modDepthLabel.setBounds(modDepthSlider.getX(), modDepthSlider.getY() + modDepthSlider.getHeight(), 90, 20);

        modFreqSlider.setBounds(250, 200, reverbSliderSize, reverbSliderSize);
        modFreqLabel.setBounds(modFreqSlider.getX(), modFreqSlider.getY() + modFreqSlider.getHeight(), 90, 20);

        dryWetMixSlider.setBounds(375, 200, reverbSliderSize, reverbSliderSize);
        dryWetMixLabel.setBounds(dryWetMixSlider.getX(), dryWetMixSlider.getY() + dryWetMixSlider.getHeight(), 90, 20);
    }

    void createKnob(juce::Slider& slider, juce::Label& label, double initialValue, double minRange, double maxRange, double increment) 
    {
        addAndMakeVisible(slider);
        slider.setLookAndFeel(&reverbLookAndFeel);
        slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        slider.setRange(minRange, maxRange, increment);
        slider.setValue(initialValue);
        slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 80, 20);
    }

    void createLabel(juce::Label& label, juce::String text)
    {
        addAndMakeVisible(label);
        label.setText(text, juce::NotificationType::dontSendNotification);
        label.setJustificationType(juce::Justification::centredTop);
    }

    juce::Slider dtSlider;
    juce::Slider dampSlider;
    juce::Slider sizeSlider;
    juce::Slider earlyDiffSlider;
    juce::Slider feedbackSlider;
    juce::Slider modDepthSlider;
    juce::Slider modFreqSlider;
    juce::Slider dryWetMixSlider;

    juce::Label dtLabel;
    juce::Label dampLabel;
    juce::Label sizeLabel;
    juce::Label earlyDiffLabel;
    juce::Label feedbackLabel;
    juce::Label modDepthLabel;
    juce::Label modFreqLabel;
    juce::Label dryWetMixLabel;

private:
    ReverbLookAndFeel reverbLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)
};
