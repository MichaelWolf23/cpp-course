#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>

struct Device {
  std::string name;
  int battery;
};

int main() {
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);
  const std::string fileName{"mission.txt"};
  const std::string fileLogName{"mission.log"};
  const std::string fileCsvName{"fleet.csv"};
  const std::string fileJsonName{"fleet.json"};

  // Файлы и ввод/вывод

  /*
  // Запись информации в файл
  std::ofstream out{ "mission.txt" };


  if (!out) {
    std::cout << "Ошибка открытия файла\n";
    return 1;
  }

  out << "Rover 80\n";
  out << "Scout 45\n";
  std::cout << "Данные сохранены\n";
  */

  // Чтение информации из файла
  /*std::ifstream in{"mission.txt"};

  if (!in) {
    std::cout << "Ошибка чтения файла\n";
    return 1;
  }

  std::string name;
  int battery{0};

  while (in >> name >> battery) {
    std::cout << name << ": " << baterry << "%\n";
  }
*/
  {
    std::ofstream out{fileName};

    if (!out) {
      std::cout << "Ошибка открытия файла\n";
      return 1;
    }

    out << "Igor 100\n";
    out << "Test 0\n";
  }

  std::ifstream in{fileName};

  if (!in) {
    std::cout << "Ошибка чтения файла\n";
    return 1;
  }

  Device device{};

  while (in >> device.name >> device.battery) {
    if (device.battery < 0 || device.battery > 100) {
      std::cout << "Заряд в батареи невалидный\n";
      return 1;
    }

    std::cout << device.name << ": " << device.battery << "%\n";
  }

  {
    std::ofstream log{fileLogName, std::ios::app};
    if (!log) {
      std::cout << "Ошибка открытия файла\n";
      return 1;
    }

    log << "Открыт файл\n";
    log << "Данные добавлены\n";
    log << "Тест\n";
    log << "=======================\n";
  }

  {
    std::ofstream out_csv{fileCsvName};

    if (out_csv) {
      out_csv << "name,battery\n";
      out_csv << "Rover,80\n";
      out_csv << "Scout,45\n";
    }
  }

  {
    std::ofstream out_json{fileJsonName};

    if (out_json) {
      out_json << "{\n";
      out_json << "\"name\": \"Rover\",\n";
      out_json << "\"battery\": \"80\"\n";
      out_json << "}\n";
    }
  }

  return 0;
}