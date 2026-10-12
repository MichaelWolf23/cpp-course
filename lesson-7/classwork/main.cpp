#include <iostream>
#include <string>
#include <vector>

struct Device {
  std::string name;
  int battery;
};

void printDevice(const Device& device) {
  std::cout << "Name: " << device.name << '\n';
  std::cout << "Battery: " << device.battery << '\n';
}

void changeDevice(Device& device, int bonus) { device.battery += bonus; }

bool isBatteryValid(const Device& device) { return device.battery >= 0 && device.battery <= 100; }

int main() {
  std::string roverName{"Rover"};
  int roverBattery{80};

  std::string scoutName{"Scout"};
  int scoutBattery{80};

  // struct - это способ создать собственный тип данных, в котором объеденены несколько полей.

  Device rover{"Rover", 80};
  printDevice(rover);
  changeDevice(rover, 10);
  printDevice(rover);

  Device scout{"Scout", 70};
  printDevice(scout);

  std::cout << "Vector:\n";

  std::vector<Device> fleet{{"Rover", 80}, {"Scout", 110}};
  // fleet.push_back({ "Rover", 80 });
  // fleet.push_back({ "Scout", 70 });

  for (const Device& device : fleet) {
    printDevice(device);
    if (isBatteryValid(device)) {
      std::cout << "Good!\n";
    } else {
      std::cout << "Not Good!\n";
    }
  }

  return 0;
}