#include <main.h>

const int min = 0;
const int max = 255;

int setRGBValue(int micValue, int redPin, int greenPin, int bluePin)
{
    int brightness = map(micValue, 0, 1023, 0, 255);

    int randomValue = random(1, 3);

    int redValue = brightness;
    int greenValue = 255 - brightness;
    int blueValue = brightness / 2;

    if (randomValue == 1)
    {
        greenValue = brightness;
        blueValue = 255 - brightness;
        redValue = brightness / 2;
    }
    else if (randomValue == 2)
    {
        blueValue = brightness;
        redValue = 255 - brightness;
        greenValue = brightness / 2;
    }

    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
}