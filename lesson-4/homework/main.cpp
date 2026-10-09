#include <iostream>

int* makeExtraReserve() { return new int{20}; }

void releaseExtraReserve(int*& extra) {
  if (extra != nullptr) {
    delete extra;
    extra = nullptr;
  }
}

int main() {
  int battery{0};
  int flag{0};
  int* extra{nullptr};

  std::cout << "Battery (0-100): ";
  std::cin >> battery;
  std::cout << "Need extra reserve (0 or 1): ";
  std::cin >> flag;

  if (battery < 0 || battery > 100 || (flag != 0 && flag != 1)) {
    std::cout << "Input error\n";
    return 1;
  }

  if (flag == 1) {
    extra = makeExtraReserve();
  }

  if (extra == nullptr) {
    std::cout << "Battery: " << battery << "%\n";
    std::cout << "No extra reserve\n";

  } else if (battery + *extra > 100) {
    std::cout << "Input error\n";
    releaseExtraReserve(extra);
    return 1;

  } else {
    std::cout << "Battery: " << battery << "%\n";
    std::cout << "Extra: " << *extra << "%\n";
    std::cout << "Total: " << battery + *extra << "%\n";

    releaseExtraReserve(extra);
    std::cout << "Buffer released\n";
  }

  return 0;
}