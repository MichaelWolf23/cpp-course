#include <iostream>
#include <string>

int applyBonusCopy(int battery, int bonus) { return battery + bonus; }

void applyBonusReference(int& battery, int bonus) { battery += bonus; }

void printDevice(const std::string& name, const int& battery) {
  std::cout << name << ": " << battery << "%\n";
}

void printReport(const std::string& firstName,
                 const int& firstBattery,
                 const std::string& secondName,
                 const int& secondBattery) {
  printDevice(firstName, firstBattery);
  printDevice(secondName, secondBattery);
}

int main() {
  const int bonus{20};

  std::string firstName;
  std::string secondName;

  int firstBattery{0};
  int secondBattery{0};

  std::cout << "First name: ";
  std::getline(std::cin, firstName);
  std::cout << "First battery (0-100): ";
  std::cin >> firstBattery;
  std::cout << "Second name: ";
  std::cin.ignore();
  std::getline(std::cin, secondName);
  std::cout << "Second battery (0-100): ";
  std::cin >> secondBattery;

  if (firstBattery < 0 || firstBattery > 100 || secondBattery < 0 || secondBattery > 100) {
    std::cout << "Input error\n";
    return 1;
  }

  std::cout << "Before:\n";
  printReport(firstName, firstBattery, secondName, secondBattery);

  const int copyResult{applyBonusCopy(firstBattery, bonus)};

  applyBonusReference(secondBattery, bonus);

  if (copyResult < 0 || copyResult > 100 || secondBattery < 0 || secondBattery > 100) {
    std::cout << "Bonus result out of range\n";
    return 1;
  }

  std::cout << "Copy result: " << copyResult << "%\n";
  std::cout << "After:\n";

  printReport(firstName, firstBattery, secondName, secondBattery);
  return 0;
}
