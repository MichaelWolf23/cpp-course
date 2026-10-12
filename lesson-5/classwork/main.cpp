#include <iostream>
#include <memory>
#include <string>

void printReserve(const std::unique_ptr<int>& test) {
  if (!test) {
    std::cout << "No reserve\n";
  } else {
    std::cout << "Reserve: " << *test << "%\n";
    std::cout << "Address: " << test.get() << '\n';
  }
}

int main() {
  int* reserve{new int{25}};

  std::cout << reserve << '\n';
  std::cout << *reserve << '\n';

  delete reserve;
  reserve = nullptr;

  // unique_ptr - хозяин одного объекта (умный указатель)

  std::unique_ptr<int> test{std::make_unique<int>(25)};

  // std::unique_ptr<int> - умный указатель с типом данных int
  // test - имя указателя
  // std::make_unique<int>(25) - создаем объект int со значением 25 и передает его под упровление
  // unique_ptr.

  std::cout << test.get() << '\n';
  std::cout << *test << '\n';

  *test = 35;

  std::cout << test.get() << '\n';
  std::cout << *test << '\n';

  std::unique_ptr<int> zero{};

  // std::cout << zero << '\n';
  // std::cout << *zero << '\n';

  if (!zero) {
    std::cout << "No value\n";
  }

  std::unique_ptr<int> first{std::make_unique<int>(25)};

  // ::unique_ptr<int> second{ first };
  // unique_ptr - нельзя копировать инфу

  std::unique_ptr<int> second{
    std::move(first) // std::move - смена хозяина
  };

  printReserve(second);
  std::cout << "Resever: " << *second << "%\n";

  second.reset(); // удаление объекта раньше

  printReserve(second);

  int* raw{second.get()};

  // std::shared_ptr - позволяет задать несколько владельцов для значения
  std::shared_ptr<int> test1{std::make_unique<int>(40)};

  std::shared_ptr<int> test2{test1};

  return 0;
}