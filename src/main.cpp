/*
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

	// Выход из приложения
	finish();
	return 0;
}