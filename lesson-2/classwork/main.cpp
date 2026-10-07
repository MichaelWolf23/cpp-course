#include <Windows.h>

#include <iostream>
#include <string>

void chargeByCopy(int battery) {
  battery += 10;
  std::cout << "Inside function chargeByCopy: " << battery << "%\n";
}

//& - меняет смысл параметра, параметр становится ссылкой. ссылка это другое имя уже существующего
//объекта
void chargeByReference(int& battery) {
  battery += 10;
  std::cout << "Inside function chargeByReference: " << battery << "%\n";
}

void chargeByConst(const std::string& name) {
  std::cout << "Inside function chargeByConst: " << name << ".\n";
}

void chargeByConstInt(const int& battery) {
  int b{battery * 10};
  std::cout << "Inside function chargeByConst: " << b << ".\n";
}

void swapBatteries(int& left, int& right) {
  const int saved{left};
  left = right;
  right = saved;
}

int main() {
  // int rover{ 70 };
  // int rover2{ 60 };
  // int& roverRef{ rover };

  // roverRef = 76;

  // chargeByCopy(rover);
  // chargeByReference(rover2);

  // std::cout << "After function rover: " << rover << "%\n";
  // std::cout << "After function rover2: " << rover2 << "%\n";

  // ----------------------------

  // std::string name{ "Michael" };
  // chargeByConst(name);

  // int rover{ 70 };
  // chargeByConstInt(rover);

  // return 0;

  // ----------------------------

  // int rover{ 70 };
  // int scour{ 40 };

  // std::cout << "Before: " << rover << "%/" << scour << "%\n";

  // swapBatteries(rover, scour);

  // std::cout << "After: " << rover << "%/" << scour << "%\n";

  // -----------------------------

  // Облась видимости это участок программы, в которой имя переменной достубно, обычно в {}
}