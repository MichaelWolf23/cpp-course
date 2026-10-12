#include <iostream>
#include <string>
#include <vector>

struct Device {
  std::string name;
  int battery;
};

void printDevice(const Device& device) {
  std::cout << device.name << ": " << device.battery << "%\n";
}

void chargeDevice(Device& device, int bonus) { device.battery += bonus; }

bool isBatteryValid(const Device& device) { return device.battery >= 0 && device.battery <= 100; }

int main() {
  Device first{};
  Device second{};

  int bonus{0};

  std::cout << "First name: ";
  std::getline(std::cin, first.name);
  std::cout << "First battery: ";
  std::cin >> first.battery;
  std::cin.ignore();
  std::cout << "Second name: ";
  std::getline(std::cin, second.name);
  std::cout << "Second battery: ";
  std::cin >> second.battery;
  std::cout << "Bonus for second (0-20): ";
  std::cin >> bonus;

  if (!std::cin || first.name.empty() || second.name.empty() || !isBatteryValid(first) ||
      !isBatteryValid(second) || bonus < 0 || bonus > 20) {
    std::cout << "Input error\n";
    return 1;
  }

  chargeDevice(second, bonus);

  if (!isBatteryValid(second)) {
    std::cout << "Input error\n";
    return 1;
  }

  std::vector<Device> fleet{first, second};

  std::cout << "Fleet size: " << fleet.size() << '\n';

  for (const Device& device : fleet) {
    printDevice(device);
  }

  return 0;
}