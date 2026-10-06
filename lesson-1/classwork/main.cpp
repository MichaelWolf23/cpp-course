#include <iostream>
#include <Windows.h>
#include <string>

int calculate(int a, int b) {
	return a - b;
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);


	//std::cout << "Меня зовут Михаил\n";
	//std::cout << "Я изучаю C++!\n";
	//std::cout << "Это моя первая программа\n";

	//int a{ 80 };
	//std::cout << a;

	//double b{ 24.5 };
	//bool q{ true };
	//char p{ 'a' };
	//std::string name{ "Michael" };

	//std::string name{ "Михаил" };
	//int age{ 15 };

	//std::cout << "Привет, меня зовут " << name << "\n";
	//std::cout << "Мне " << age << " лет\n";

	//bool a{ true };
	//std::cout << a;

	//std::string userName{};
	//std::string userAge{};
	//std::cout << "Как тебя зовут\n";
	//std::cin >> userName;

	//std::cout << "Сколько тебе лет?\n";
	//std::cin >> userAge;

	//std::cout << "Привет, тебя зовут " << userName << "\n";
	//std::cout << "тебе " << userAge << "\n лет";

	//std::string userAge;
	//std::cout << "Сколько тебе лет?\n";
	//std::getline(std::cin, userAge);
	//std::cout << "тебе " << userAge << "\n лет";

	//const double P = 3.14;

	//int result{ 3 / 2 };
	//std::cout << result << "\n";

	//double result1{ 3.0 / 2.0 };
	//std::cout << result1 << "\n";

	//int reserve{ calculate(100,30) };

	//std::cout << calculate(100, 30);

	//if (reserve >= 20) {
	//	std::cout << "готов\n";
	//}
	//else {
	//	std::cout << "разряжен\n";

	//}

	for (int i = 1; i <= 5; i++) {
		std::cout << i << "\n";
	}

	return 0;
}

