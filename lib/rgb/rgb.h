#ifndef RGB_VALUE_H
#define RGB_VALUE_H

class RGBLed
{
public:
  int redValue;
  int greenValue;
  int blueValue;

  RGBLed(int redPin, int greenPin, int bluePin);
  setRGBValue(int micValue);

private:
  int redPin;
  int greenPin;
  int bluePin;
};

#endif
