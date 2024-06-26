#include <Arduino.h>

void setRGBValue(int micValue, int redPin, int greenPin, int bluePin)
{
    int brightness = map(micValue, 0, 1023, 90, 255);

    int randomValue = random(1, 3);

    int redValue = brightness;
    int greenValue = 0;
    int blueValue = 0;

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
}