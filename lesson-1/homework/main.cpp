#include <iostream>
#include <string>

int calculateRemainingBattery(int battery, int plannedConsumption)
{
  return battery - plannedConsumption;
}

bool isReadyForMission(int remainingBattery, int successfulChecks, int minimumReserve)
{
  const bool batteryRule{remainingBattery >= minimumReserve};
  const bool checksRule{successfulChecks == 3};
  return batteryRule && checksRule;
}

void printStatus(bool ready)
{
  if (ready)
  {
    std::cout << "Status : ready\n";
  }
  else
  {
    std::cout << "Status : not ready\n";
  }
}

int main()
{
  const int minimumReserve{25};

  std::string deviceName;

  int battery{0};
  int plannedConsumption{0};
  int successfulChecks{0};

  std::cout << "Device name : ";
  std::getline(std::cin, deviceName);
  std::cout << "Battery(0 - 100) : ";
  std::cin >> battery;
  std::cout << "Planned consumption : ";
  std::cin >> plannedConsumption;
  std::cout << "Successful checks(0 - 3) : ";
  std::cin >> successfulChecks;

  if (battery < 0 || battery > 100 || plannedConsumption < 0 || successfulChecks < 0 || successfulChecks > 3)
  {
    std::cout << "Input error\n";
    return 1;
  }

  const int remainingBattery{calculateRemainingBattery(battery, plannedConsumption)};
  const bool ready{isReadyForMission(remainingBattery, successfulChecks, minimumReserve)};

  std::cout << "\nDevice : " << deviceName << '\n';
  std::cout << "Remaining battery : " << remainingBattery << "%\n";
  std::cout << "Checks passed : " << successfulChecks << "/3\n";

  printStatus(ready);
  return 0;
}