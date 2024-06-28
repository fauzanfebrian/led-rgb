#ifndef RGB_VALUE_H
#define RGB_VALUE_H

struct RGBPin {
  int red;
  int green;
  int blue;
};

class RGBLed {
 public:
  int redValue;
  int greenValue;
  int blueValue;

  RGBLed(RGBPin pin);
  void setRGBValue(int micValue);

 private:
  int redPin;
  int greenPin;
  int bluePin;
};

#endif
