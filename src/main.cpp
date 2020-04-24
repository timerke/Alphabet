﻿/*
Приложение "Алфавит" читает текст и выводит из него по одному
слову в строке по алфавиту.
*/

#include <clocale>
#include <iostream>
#include "functions.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");

	// Определяем способ передачи входного текста
	char response = determine_way(argc, argv);

	// Получаем исходный текст
	std::vector<std::string> text;
	if (response == '0')
	{
		// Пользователь хочет выйти из программы
		finish();
		return 0;
	}
	else if (response == '1')
	{
		// Входной текст будет передан через текстовый файл
	}
	else if (response == '2')
	{
		// Входной текст будет введен в консоли
		read_console(argc, argv, &text);
	}

	// Выход из приложения
	finish();
	return 0;
}