#include <iostream>
#include <fstream> // файловый поток. Подключение библиотеки , 
// хранящей в себе классы для работы с файловыми потоками.
// ofstream - output file stream (поток вывода в файл)
#include <string>

bool statistic(std::string str);

void print_file(std::string path);

void clear_file(std::string path);

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	std::string path = "file.txt";

	// Запись в файл ( класс ofstream)
	std::ofstream out;// std::ofstream out(path);-можно открыть файл сразу же
	out.open(path, std::ios::app);

	if (out.is_open()) { // Проверка открытия файла
		std::cout << "Файл открыт для записи.\n";

		std::cout << "Введите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		out << str << '\n';//записываем строку в текстовый файл

		out.close();
	}
	else
		std::cout << "Ошибка отркытия файла!\n";

	// Возможные причины ошибки при открытии 
	// файла для записи
	// 1. Файл уже открыт.
	// 2. Некорректный путь к файлу.
	// 3. Нет доступа к файлу.
	
	
	// Чтение из файла ( класс ifstream)
	std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		std::cout << " Содержимое файла:\n";
        
		// Посимвольное считывание
		// char sym;
		// while (in.get(sym))
		// std::cout << sym;
		
		// Пословное считывание
		
		    // while (!in.eof()) {//(!in.eof())-пока мы не в конце файла
			// std::string word;
			// in >> word;
			// std::cout << word << std::endl;
		//}

		// Построчное считывание
		std::string str;
		while (std::getline(in, str))//in откуда считывание, str куда считывание
			std::cout << str << std::endl;

		in.close();
	}
	else
		std::cout << " Ошибка открытия файла!\n";
// Возможные причины ошибки при открытии файла для чтения:
// 1. Некорректный путь к файлу.
// 2. Нет доступа к файлу.
// 3. Файла не существет.

	// Удаление из файла ( класса ifstream)
	
	if (remove(path.c_str()) == 0)// c_str возвращает указать на char
	    std::cout << "Файл удален.\n";
	else
		std::cout << "Ошибка удаления файла!\n";
    // Возможные причины ошибки при удалении файла:
	// 1. Файл открыт.
	// 2. Файла не существует .
	// 3. Некорректный путь к файлу.
	// 4. Нет доступа к файлу.
	


	// ЗАДАЧА 1. Статистика в файле
	
	std::cout << "Задача1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	if (statistic(str1))
		std::cout << "Запись добавленна.\n\n";
	else
		std::cout << "Ошибка!\n\n";
		
		// ЗАДАЧА 2. Усложнение
	std::cout << "Задача2.\n";
	int operation;
	do {
		std::cout << "Выберите действие:\n";
		std::cout << "1. Добавить статистику в файл;\n";
		std::cout << "2. Вывести содержимое в файл;\n";
		std::cout << "3. Очистить файл;\n";
		std::cout << "4. Завершить работу;\n";
		std::cout << "Ввод -> ";
		std::cin >> operation;

		switch(operation) {
		case 1: {
			std::cout << "Введите строку -> ";
			std::string str2;
			std::cin.ignore();
			std::getline(std::cin, str2);
			statistic(str2);
			std::cout << "Статистика внесена.\n\n";
			break;
		}
		case 2:
			std::cout << "Содержимое файла:\n";
			print_file("stats.txt");
			break;

		case 3: {
			std::cout << "Вы уверены, что хотите очистить файл? (y/n)\n";
			char answer;
			std::cin >> answer;
			if (answer == 'y') {
				clear_file("stats.txt");
					std::cout << "Файл очищен.\n\n";
			}
			else 
				std::cout << "Отмена операции.\n\n";
			break;
		}
		case 4:
			std::cout << "Завершение работы...\n";
			break;
		default:
			std::cout << "Ошибка ввода!\n\n";
		}

	} while (operation != 4);



	return 0;





}
bool statistic(std::string str) {
	static std::ofstream out;
	out.open("stats.txt", std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	return false;

}

void print_file(std::string path) {
	static std::ifstream in;
	in.open(path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();

	}
}

void clear_file(std::string path) {
	static std::ofstream out;
	out.open(path);
	if (out.is_open())
		out.close();
}