#include <iostream>

void printThroughSensor(const int* sensor) {
  if (sensor == nullptr) {
    std::cout << "Sensor offline\n";
    return;
  }
  std::cout << "Telemetry: " << *sensor << "%\n";
}

int* selectSensor(int command, int& firstBattery, int& secondBattery) {
  switch (command) {
    case 1:
      return &firstBattery;
    case 2:
      return &secondBattery;
    default:
      return nullptr;
  }
}

int main() {
  int firstBattery{0};
  int secondBattery{0};
  int command{0};
  int* sensor{nullptr};
  std::cout << "First battery (0-100): ";
  std::cin >> firstBattery;
  std::cout << "Second battery (0-100): ";
  std::cin >> secondBattery;
  std::cout << "Command (0-2): ";
  std::cin >> command;

  if (firstBattery < 0 || firstBattery > 100 || secondBattery < 0 || secondBattery > 100 ||
      (command != 0 && command != 1 && command != 2)) {
    std::cout << "Input error\n";
    return 1;
  }

  sensor = selectSensor(command, firstBattery, secondBattery);

  if (sensor != nullptr) {
    *sensor += 5;

    if (*sensor > 100) {
      std::cout << "Input error\n";
      return 1;
    }
  }

  std::cout << "First: " << firstBattery << "%\n";
  std::cout << "Second: " << secondBattery << "%\n";
  printThroughSensor(sensor);
  return 0;
}