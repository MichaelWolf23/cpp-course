#include <array>
#include <iostream>
#include <string>
#include <vector>

int main() {
  // std::string - строка
  // std::array - фиксированное кол-во элементов
  // std::vector - список

  int battery1{70};
  int battery2{20};
  int battery3{10};

  std::string name{"Scout"};

  std::cout << "Name: " << name << "\n";
  name += " One";
  std::cout << "Name: " << name << "\n";
  std::cout << "Name size: " << name.size() << "\n"; // size() - показывает длину строки
  std::cout << "Name 0: " << name.at(0) << "\n";     // at() - символ по индексу
  std::cout << "Name 1: " << name.at(1) << "\n";

  std::array<int, 3> batteries{70, 40, 90};

  std::cout << "batteries size: " << batteries.size() << "\n";
  std::cout << "batteries 0: " << batteries.at(0) << "\n";
  std::cout << "batteries 1: " << batteries.at(1) << "\n";
  std::cout << "batteries 2: " << batteries.at(2) << "\n";

  batteries.at(0) = 90;
  std::cout << "batteries 0: " << batteries.at(0) << "\n";

  std::vector<int> reading;
  reading.push_back(10);
  reading.push_back(20);
  reading.push_back(30);
  reading.push_back(40);
  reading.push_back(50);

  std::cout << "vector reading size: " << reading.size() << "\n";
  std::cout << "vector reading 0: " << reading.at(0) << "\n";
  std::cout << "vector reading 1: " << reading.at(1) << "\n";
  std::cout << "vector reading 2: " << reading.at(2) << "\n";
  std::cout << "vector reading last: " << reading.at(reading.size() - 1) << "\n";

  for (int value : reading) {
    std::cout << "value: " << value << "\n";
  }

  for (int value : reading) {
    std::cout << value << ' ';
  }

  for (int& value : reading) {
    value += 10;
  }

  for (int value : reading) {
    std::cout << "value: " << value << '\n';
  }

  return 0;
}