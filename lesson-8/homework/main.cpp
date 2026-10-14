#include <fstream>
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

bool isBatteryValid(const Device& device) { return device.battery >= 0 && device.battery <= 100; }

void writeLog(const std::string& message) {
  std::ofstream log{"fleet.log", std::ios::app};

  if (log) {
    log << message << '\n';
  }
}

int inputError(const std::string& message) {
  std::cout << "Input error\n";
  writeLog(message);
  return 1;
}

int main() {
  writeLog("start");

  Device first{};
  Device second{};

  std::cout << "First name: ";
  std::getline(std::cin, first.name);
  std::cout << "First battery: ";
  std::cin >> first.battery;
  std::cin.ignore();
  std::cout << "Second name: ";
  std::getline(std::cin, second.name);
  std::cout << "Second battery: ";
  std::cin >> second.battery;

  if (!std::cin || first.name.empty() || second.name.empty() || !isBatteryValid(first) ||
      !isBatteryValid(second)) {
    return inputError("invalid device data");
  }

  {
    std::ofstream out{"fleet.txt"};

    if (!out) {
      return inputError("error opening fleet.txt");
    }

    out << first.name << ' ' << first.battery << '\n';
    out << second.name << ' ' << second.battery << '\n';
    out.close();

    if (!out) {
      return inputError("error writing fleet.txt");
    }
  }

  {
    std::ofstream csv{"fleet.csv"};

    if (!csv) {
      return inputError("error opening fleet.csv");
    }

    csv << "name,battery\n";
    csv << first.name << ',' << first.battery << '\n';
    csv << second.name << ',' << second.battery << '\n';
    csv.close();

    if (!csv) {
      return inputError("error writing fleet.csv");
    }
  }

  {
    std::ofstream json{"devices.json"};

    if (!json) {
      return inputError("error opening devices.json");
    }

    json << "[\n";
    json << "  {\n";
    json << "    \"name\": \"" << first.name << "\",\n";
    json << "    \"battery\": " << first.battery << '\n';
    json << "  },\n";
    json << "  {\n";
    json << "    \"name\": \"" << second.name << "\",\n";
    json << "    \"battery\": " << second.battery << '\n';
    json << "  }\n";
    json << "]\n";
    json.close();

    if (!json) {
      return inputError("error writing devices.json");
    }
  }

  writeLog("fleet.txt, fleet.csv and devices.json written");
  std::ifstream in{"fleet.txt"};

  if (!in) {
    return inputError("error opening fleet.txt for reading");
  }

  std::vector<Device> fleet{};
  Device device{};

  while (in >> device.name >> device.battery) {
    fleet.push_back(device);
  }

  if (!in.eof()) {
    return inputError("error reading fleet.txt");
  }

  if (fleet.size() != 2) {
    return inputError("invalid fleet size");
  }

  for (const Device& item : fleet) {
    printDevice(item);
  }

  return 0;
}
