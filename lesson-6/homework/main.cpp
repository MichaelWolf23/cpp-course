#include <array>
#include <iostream>
#include <string>
#include <vector>

void printBatteries(const std::array<int, 3>& batteries) {
  for (int index{0}; index < 3; ++index) {
    std::cout << "Slot " << index << ": " << batteries.at(static_cast<std::size_t>(index)) << "%\n";
  }
}

int sumReadings(const std::vector<int>& readings) {
  int total{0};
  for (int value : readings) {
    total += value;
  }
  return total;
}

int main() {
  std::string name;
  std::array<int, 3> batteries{0, 0, 0};
  std::vector<int> readings;

  int count{0};

  std::cout << "Device name: ";
  std::getline(std::cin, name);
  std::cout << "Battery slots(3 numbers): ";
  std::cin >> batteries.at(0) >> batteries.at(1) >> batteries.at(2);
  std::cout << "Reading count(1 - 5): ";
  std::cin >> count;

  if (!std::cin || name.empty() || count < 1 || count > 5 || batteries.at(0) < 0 ||
      batteries.at(0) > 100 || batteries.at(1) < 0 || batteries.at(1) > 100 ||
      batteries.at(2) < 0 || batteries.at(2) > 100) {
    std::cout << "Input error\n";
    return 1;
  }

  for (int step{0}; step < count; ++step) {
    int value{0};
    std::cout << "Reading " << step << ": ";
    std::cin >> value;

    if (!std::cin || value < 0 || value > 100) {
      std::cout << "Input error\n";
      return 1;
    }

    readings.push_back(value);
  }
  std::cout << "Device: " << name << '\n';
  printBatteries(batteries);
  std::cout << "Readings: ";

  for (int value : readings) {
    std::cout << value << ' ';
  }

  std::cout << '\n';
  std::cout << "Count: " << readings.size() << '\n';
  std::cout << "Sum: " << sumReadings(readings) << '\n';

  return 0;
}