#include <FastLED.h>

#define NUM_LEDS 64

const uint8_t LED_PIN = D3;

CRGB leds[NUM_LEDS];

bool ledReady = false;

void setupLeds() {
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  ledReady = true;
}

void setLedsColor(int r, int g, int b) {
  if (!ledReady) {
    return;
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();
}