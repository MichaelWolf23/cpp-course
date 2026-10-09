#include <iostream>
#include <string>
// #include <cstdlib>     // Нужен для работы команды system
// #include "my_input.h"  // Подключаем наш созданный файл

void printTest(const int* test) {
  if (test != nullptr) {
    std::cout << "printTest: " << *test << "\n";
  }
}

int main() {
  int rover{80};

  std::cout << "Value rover: " << rover << "\n";
  std::cout << "Address rover: " << &rover << "\n";

  // Указатель - это адрес нахождения значения переменной в памяти.
  // Для того чтобы узнать адрес перед названием переменной пишем "&"
  // Помимо прямого способа узнать местонахождение значения переменной мы также можем записывать
  // адрес в отдельную переменную.

  int* sensor{&rover}; // Указатель

  std::cout << "Address rover in var: " << sensor << "\n";
  std::cout
    << "Value sensor: " << *sensor
    << "\n"; // Разыменование - получение информации которое хранится по определенному адресу

  *sensor = 90;

  std::cout << "Address rover in var: " << sensor << "\n";
  std::cout << "Value sensor: " << *sensor << "\n";
  std::cout << "Value rover: " << rover << "\n";

  int scout{45};
  sensor = &scout;

  std::cout << "Address scout in var: " << sensor << "\n";
  std::cout << "Value sensor: " << *sensor << "\n";
  std::cout << "Value scout: " << scout << "\n";

  sensor = nullptr; // Сброс указателя

  if (sensor != nullptr) {
    std::cout << *sensor;
  }

  int* test{&scout};   // Указатель
  int& baterry{rover}; // Ссылка

  // Используем ссылку если объект точно существует и нам точно нужно работать с ним
  // Используем указатель если объект может отсутствовать или нужно переключаться на другой объект

  printTest(test);
  printTest(&scout);

  return 0;
}