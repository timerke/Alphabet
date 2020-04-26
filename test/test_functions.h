/*
Заголовочный файл test_functions.h содержит объявления функций,
используемых при тестировании приложения "Алфавит".
*/

#pragma once
#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

void compare(std::vector<std::string>*, std::vector<std::string>*);
void show_test_result(bool);
void test_dismember_line(int, std::string*, std::vector<std::string>*);
void test_dismember_text(int, std::vector<std::string>*,
	std::vector<std::string>*);
void test_read_console(int, int, char* [], std::vector<std::string>*);
void test_read_file(int, int, char* [], std::vector<std::string>*);
void test_sort(int, std::vector<std::string>*, std::vector<std::string>*);

#endif

