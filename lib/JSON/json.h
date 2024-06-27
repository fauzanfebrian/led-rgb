#ifndef JSON_CLASS_H
#define JSON_CLASS_H

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

class JsonPerson
{
public:
  String name;
  int age;
  JsonCar data;

  JsonPerson();
  JsonPerson(String jsonStr);
};

#endif