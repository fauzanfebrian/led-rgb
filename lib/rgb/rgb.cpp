#include <Arduino.h>

struct RGBPin
{
    int red;
    int green;
    int blue;
};

class RGBLed
{
public:
    int redValue;
    int greenValue;
    int blueValue;

    RGBLed(RGBPin pin);

    auto setRGBValue(int micValue) -> void;

private:
    int redPin;
    int greenPin;
    int bluePin;
};

RGBLed::RGBLed(RGBPin pin)
{
    redPin = pin.red;
    greenPin = pin.green;
    bluePin = pin.blue;

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

auto RGBLed::setRGBValue(int micValue) -> void
{
    int brightness = map(micValue, 0, 1023, 90, 255);

    int randomValue = random(1, 3);

    redValue = brightness;
    greenValue = 0;
    blueValue = 0;

    if (randomValue == 1)
    {
        greenValue = brightness;
        blueValue = 0;
        redValue = 0;
    }
    else if (randomValue == 2)
    {
        blueValue = brightness;
        redValue = 0;
        greenValue = 0;
    }

    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
};