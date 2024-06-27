#include <Arduino.h>

class RGBLed
{
public:
    int redValue;
    int greenValue;
    int blueValue;

    RGBLed();
    RGBLed(int redPin, int greenPin, int bluePin);

    setRGBValue(int micValue);

private:
    int redPin;
    int greenPin;
    int bluePin;
};

RGBLed::RGBLed(int redPin, int greenPin, int bluePin)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

RGBLed::RGBLed()
{
}

RGBLed::setRGBValue(int micValue)
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