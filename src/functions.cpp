﻿/*
Модуль functions.cpp содержит определения функций,
используемых программой "Алфавит".
*/

#include "functions.h"
#include <fstream>
#include <iostream>

/**
 * Функция определяет способ, которым будет передан входной текст.
 * @param argc - количество параметров, передаваемых в командной строке;
 * @param argv - массив из строк-параметров командной строки.
 * @return символ, который показывает способ передачи входного текста
 * в приложение:
 * '0' - текст вообще не передается в приложение;
 * '1' - текст передается через текстовый файл;
 * '2' - текст передается через консольный ввод.
 */
char determine_way(int argc, char* argv[])
{
	std::string response; // параметр для чтения ответа пользователя
	if (argc > 1)
	{
		// Через командную строку передаются аргументы
		response = argv[1];
		if (response == "0" || response == "1" || response == "2")
		{
			// Через командную строку передаются аргументы в правильной форме
			return response[0];
		}
		else
		{
			// Через командную строку передаются аргументы в неправильной форме
			std::cout << "Ошибка. Повторите ввод.\n";
		}
	}
	std::cout << "Как будет передан текст? (Текстовый файл - 1,"
		" консольный ввод - 2, выход - 0.)\n\t";
	std::getline(std::cin, response);
	while (response != "0" && response != "1" && response != "2")
	{
		std::cout << "Ошибка, повторите ввод:\n\t";
		std::getline(std::cin, response);
	}
	return response[0];
}

/**
 * Функция выводит сообщение при завершении программы.
 */
void finish()
{
	std::cout << "Завершение программы.\n";
}

/**
 * Функция получает текст через консольный ввод.
 * @param argc - количество параметров, передаваемых в командной строке;
 * @param argv - массив из строк-параметров командной строки;
 * @param text - вектор, в который будут записаны строки входного текста.
 */
void read_console(int argc, char* argv[], std::vector<std::string>* text)
{
	if (argc > 2)
	{
		// Через командную строку передается входной текст
		for (int i = 2; i < argc; i++)
		{
			text->push_back(argv[i]);
		}
	}
	else
	{
		// Через командную строку не передается входной текст
		std::cout << "Введите текст. Чтобы завершить ввод, введите пустую строку."
			"\nВаш текст:\n";
		std::string line = " "; // параметр для чтения строки
		while (line.size())
		{
			std::getline(std::cin, line);
			text->push_back(line);
		}
	}
}

/**
 * Функция получает текст через текстовый файл.
 * @param argc - количество параметров, передаваемых в командной строке;
 * @param argv - массив из строк-параметров командной строки;
 * @param text - вектор, в который будут записаны строки входного текста.
 * @return true, если текстовый файл был прочтен, иначе false.
 */
bool read_file(int argc, char* argv[], std::vector<std::string>* text)
{
	std::string file_path; // путь к файлу
	if (argc > 2)
	{
		// Через командную строку передается имя файла
		file_path = argv[2];
	}
	else
	{
		// Через командную строку не передается имя файла
		std::cout << "Введите путь к текстовому файлу: ";
		std::getline(std::cin, file_path);
	}
	// Открываем файл для чтения
	std::ifstream in(file_path.data(), std::ifstream::in);
	if (!in.is_open())
	{
		// Если файл не открыт
		std::cout << "Ошибка. Файл " << file_path << " не открыт.\n";
		return false;
	}
	// Если файл открыт для чтения
	std::string line; // параметр для чтения строки
	while (std::getline(in, line))
	{
		text->push_back(line);
	}
	in.close(); // закрываем файл
	return true;
}