#include <WString.h>
#include <ArduinoJson.h>

class JsonCar
{
public:
  String car;
  int price;

  JsonCar();
  JsonCar(String jsonStr);
};

JsonCar::JsonCar() : car(""), price(0) {};

JsonCar::JsonCar(String jsonStr)
{
  JsonDocument doc;

  DeserializationError error = deserializeJson(doc, jsonStr);

  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  car = doc["car"].as<String>();
  price = doc["price"].as<int>();
};

class JsonPerson
{
public:
  String name;
  int age;
  JsonCar data;

  JsonPerson();
  JsonPerson(String jsonStr);
};

JsonPerson::JsonPerson() : name(""), age(0) {};

JsonPerson::JsonPerson(String jsonStr)
{
  JsonDocument doc;

  DeserializationError error = deserializeJson(doc, jsonStr);

  if (error)
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  name = doc["name"].as<String>();
  age = doc["age"].as<int>();
  data = doc["data"].as<String>();
};
