/*
Модуль test_functions.cpp содержит определения функций,
используемых при тестировании программы "Алфавит".
*/

#include <fstream>
#include <iostream>
#include "../src/functions.h"
#include "test_functions.h"

/**
 * Функция сравнивает два вектора из строк.
 * @param frs и snd - сравниваемые векторы.
 */
void compare(std::vector<std::string>* frs, std::vector<std::string>* snd)
{
	if (frs->size() == snd->size())
	{
		// Если размеры векторов одинаковые
		for (unsigned int i = 0; i < frs->size(); i++)
		{
			// Сравниваются элементы векторов с одним и тем же индексом
			if (frs->at(i) != snd->at(i))
			{
				show_test_result(false);
				return;
			}
		}
		show_test_result(true);
	}
	else
	{
		// Если размеры векторов неодинаковые
		show_test_result(false);
	}
}

/**
 * Функция выводит на экран результат теста.
 * @param result - параметр, отвечающий за результат теста:
 * true, если тест пройден, false, если тест провален.
 */
void show_test_result(bool result)
{
	if (result)
	{
		std::cout << "\tfunction passed test.\n";
	}
	else
	{
		std::cout << "\tfunction failed test.\n";
	}
}

/**
 * Функция для тестирования функции dismember_line().
 * @param test_num - номер теста;
 * @param test_line - тестовая строка для проверки работы функции
 * dismember_line();
 * @param test_words - вектор тестовых слов, с которыми нужно сравнить
 * вектор слов, полученных функцией dismember_line() для строки test_line.
 */
void test_dismember_line(int test_num, std::string* test_line,
	std::vector<std::string>* test_words)
{
	std::cout << "Test #" << test_num <<
		". Function under test is dismember_line():\n";

	std::vector<std::string> words; // вектор для слов из строки test_line
	// Применяем функцию dismember_line()
	dismember_line(test_line, &words);
	// Сравниваем результат работы dismember_line() с правильным результатом
	compare(&words, test_words);
}

/**
 * Функция для тестирования функции dismember_text().
 * @param test_num - номер теста;
 * @param test_text - тестовый текст (вектор из строк) для проверки работы
 * функции dismember_text();
 * @param test_words - вектор тестовых слов, с которыми нужно сравнить
 * вектор слов, полученных функцией dismember_text() для текста test_text.
 */
void test_dismember_text(int test_num, std::vector<std::string>* test_text,
	std::vector<std::string>* test_words)
{
	std::cout << "Test #" << test_num <<
		". Function under test is dismember_text():\n";

	std::vector<std::string> words; // вектор для слов из текста test_text
	// Применяем функцию dismember_text()
	dismember_text(test_text, &words);
	// Сравниваем результат работы dismember_text() с правильным результатом
	compare(&words, test_words);
}

/**
 * Функция для тестирования функции read_console().
 * @param test_num - номер теста;
 * @param test_argc - количество параметров в командной строке;
 * @param test_argv - тестовый массив из строк-параметров командной строки;
 * @param test_text - тестовый вектор из строк, который нужно сравнить с
 * вектором из строк, полученным для test_argv функцией read_console().
 */
void test_read_console(int test_num, int test_argc, char* test_argv[],
	std::vector<std::string>* test_text)
{
	std::cout << "Test #" << test_num << ". Test under test is read_console():\n";

	std::vector<std::string> text; // вектор для строк из командной строки
	if (test_argc < 2)
	{
		return;
	}
	// Применяем функцию read_console()
	read_console(test_argc, test_argv, &text);
	// Сравниваем результат работы read_console() с правильным результатом
	compare(&text, test_text);
}

/**
 * Функция для тестирования функции read_file().
 * @param test_num - номер теста;
 * @param test_argc - количество параметров в командной строке;
 * @param test_argv - тестовый массив из строк-параметров командной строки;
 * @param test_text - тестовый вектор из строк, который нужно сравнить с
 * вектором из строк, полученным для test_argv функцией read_file().
 */
void test_read_file(int test_num, int test_argc, char* test_argv[],
	std::vector<std::string>* test_text)
{
	std::cout << "Test #" << test_num << ". Test under test is read_file():\n";

	// Вектор для строк из тестового текстового файла
	std::vector<std::string> text;
	if (test_argc < 2)
	{
		return;
	}
	// Создается текстовый файл
	std::ofstream out(test_argv[2]);
	if (!out.is_open())
	{
		return;
	}
	// Если текстовый файл создан, записываем в него text
	for (unsigned int i = 0; i < test_text->size(); i++)
	{
		out << test_text->at(i) << "\n";
	}
	out.close();
	// Применяем функцию read_file()
	read_file(test_argc, test_argv, &text);
	// Сравниваем результат работы read_file() с правильным результатом
	compare(&text, test_text);
}

/**
 * Функция для тестирования функции sort().
 * @param test_num - номер теста;
 * @param test_words - тестовый вектор из слов для проверки работы функции
 * sort();
 * @param alphabet_words - вектор из слов в алфавитном порядке.
 */
void test_sort(int test_num, std::vector<std::string>* test_words,
	std::vector<std::string>* alphabet_words)
{
	std::cout << "Test #" << test_num << ". Function under test is sort():\n";

	// Применяем функцию sort()
	sort(test_words);
	// Сравниваем результат работы sort() с правильным результатом
	compare(test_words, alphabet_words);
}