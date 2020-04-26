/*
Модуль test.cpp содержит тесты для приложения "Алфавит".
*/

#include <iostream>
#include "../src/functions.h"
#include "test_functions.h"

int main(int argc, char* argv[])
{
	int test_num = 0; // номер теста

	// Тест 1. Тестируется функция dismember_line().
	// Тестовая строка
	std::string line("My name! ,is -Timerke., I\tam from?\"Novocheboksarsk\"");
	// Вектор из слов, которые должны быть распознаны функцией dismember_line()
	std::vector<std::string> words = { "My", "name", "is", "Timerke", "I", "am",
		"from", "Novocheboksarsk" };
	test_dismember_line(++test_num, &line, &words);

	// Тест 2. Тестируется функция dismember_line().
	// Тестовая строка
	line = ". !\t?";
	// Вектор из слов, которые должны быть распознаны функцией dismember_line()
	words.clear();
	test_dismember_line(++test_num, &line, &words);

	// Тест 3. Тестируется функция dismember_line().
	// Тестовая строка
	line = "0.783%, 732 батона и -903 градуса.";
	// Вектор из слов, которые должны быть распознаны функцией dismember_line()
	words = { "0", "783%", "732", "батона", "и", "903", "градуса" };
	test_dismember_line(++test_num, &line, &words);

	// Тест 4. Тестируется функция dismember_text().
	// Тестовый текст
	std::vector<std::string> text = { "My name! ,is -Timerke., I\tam from?\"Moscow\"",
		". !\t?",
		"0.783%, 732 батона и -903 градуса." };
	// Вектор из слов, которые должны быть распознаны функцией dismember_text()
	words = { "My", "name", "is", "Timerke", "I", "am", "from", "Moscow", "0",
		"783%", "732", "батона", "и", "903", "градуса" };
	test_dismember_text(++test_num, &text, &words);

	// Тест 5. Тестируется функция read_console().
	// Количество параметров, передаваемых через тестовую командную строку
	int argc_ = 7;
	// Тестовая командная строка
	const char* argv_1[] = { "c:\\main.cpp", "2", "dog,cat", "поселок", "728.90",
		"Новочебоксарск.", "Hot-dog" };
	// Вектор из строк, которые должны быть распознаны функцией read_console()
	words = { "dog,cat", "поселок", "728.90", "Новочебоксарск.", "Hot-dog" };
	test_read_console(++test_num, argc_, (char**)argv_1, &words);

	// Тест 6. Тестируется функция read_file().
	// Путь к файлу, в котором будет записан текст text
	const char* file_path = "test_file.txt";
	text = { "Белеет парус одинокий", "В тумане моря голубом.",
		"Что ищет он в стране далекой?", "Что кинул он в краю родном?" };
	// Количество параметров, передаваемых через тестовую командную строку
	argc_ = 3;
	// Тестовая командная строка
	const char* argv_2[] = { "c:\\main.cpp", "1", file_path };
	test_read_file(++test_num, argc_, (char**)argv_2, &text);

	// Тест 7. Тестируется функция sort().
	// Тестовый вектор из слов
	words = { "yellow", "cat", "Лермонтов", "1991", "Пушкин","dragon" };
	// Вектор из тестовых слов по алфавиту
	std::vector<std::string> alphabet_words = { "1991", "cat", "dragon",
		"yellow", "Лермонтов", "Пушкин" };
	test_sort(++test_num, &words, &alphabet_words);

	return 0;
}