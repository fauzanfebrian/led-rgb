#include <main.h>

#define LED_PIN 2

#define MIC_PIN A0

String jsonStr = "{\"name\":\"John\", \"age\":30, \"data\":{\"car\": \"BMW\", \"price\": 1000000}}";
JsonPerson person = jsonStr;

RGBLed rgbLed(9, 10, 11);

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ; // Wait for the serial port to connect. Needed for native USB port only
    }
    Serial.println("Serial communication started.");

    // set the pins as output
    pinMode(MIC_PIN, INPUT);

    Serial.println("RGB LED is ready");
}

String inputString = "";
bool stringComplete = false;

void loop()
{
    int micValue = analogRead(MIC_PIN);

    // set the color of the LED
    rgbLed.setRGBValue(micValue);

    if (stringComplete)
    {
        inputString.trim();
        if (inputString == "on")
        {
            analogWrite(LED_PIN, 255);
            Serial.println("LED is on");
        }
        else if (inputString == "off")
        {
            analogWrite(LED_PIN, 0);
            Serial.println("LED is off");
        }

        Serial.println(inputString);
        inputString = "";
        stringComplete = false;
    }
}

void serialEvent()
{
    while (Serial.available())
    {
        // Get the new byte
        char inChar = (char)Serial.read();

        if (inChar == '\n')
        {
            Serial.println("Enter");
            stringComplete = true;
        }
        else
        {
            inputString += inChar;
            Serial.print(inChar);
        }
    }
}
