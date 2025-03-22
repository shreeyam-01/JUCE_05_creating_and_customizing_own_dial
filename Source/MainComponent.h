#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/


class OtherLookAndFeel : public juce::LookAndFeel_V4
{
public:
    // virtual methods insider look and feel
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override
    {
        float diameter = juce::jmin(width, height);
        float radius = diameter / 2;
        float centerX = x + width / 2;
        float centerY = y + height / 2;
        float rx = centerX - radius;
        float ry = centerY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle)); // To be looked at


        juce::Rectangle<float> dialArea(rx, ry, diameter, diameter);



        g.setColour(juce::Colours::darkkhaki);
        g.fillEllipse(dialArea);


        g.setColour(juce::Colours::black);
        juce::Path dialTick;
        dialTick.addRectangle(0, -radius,10.0f, radius);
        g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(centerX, centerY)); // To be looked at

        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
    }
};


class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    juce::Slider dial1;
    OtherLookAndFeel otherLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
