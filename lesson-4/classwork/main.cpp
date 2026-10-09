#include <iostream>
#include <string>

int main() {
  // Куча - это когда система просит выделить память для временной переменной. Для этого мы
  // используем оперетор new

  int* extra{new int{25}};
  // int* - указатель
  // new int{25} - создай в куче число типа int и полохи туда 25

  std::cout << "Address: " << extra << "\n";
  std::cout << "Value: " << *extra << "\n";

  delete extra; // Удаление объекта (уничтожен)
  extra = nullptr;

  std::cout << "Address: " << extra << "\n";

  // new - создание кучи
  // Куча работает
  // delete
  // Присваеваем указателю nullptr

  int* values{new int[5]};

  std::cout << "Address: " << values << "\n";
  std::cout << "Value: " << *values << "\n";

  delete[] values;
  values = nullptr;

  return 0;
}