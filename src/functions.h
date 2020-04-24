/*
Заголовочный файл functions.h содержит объявления функций,
используемых в программе "Алфавит".
*/

#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>

char determine_way(int, char* []);
void dismember_line(std::string*, std::vector<std::string>*);
void dismember_text(std::vector<std::string>*, std::vector<std::string>*);
void finish();
void print_words(std::vector<std::string>*);
void read_console(int, char* [], std::vector<std::string>*);
bool read_file(int, char* [], std::vector<std::string>*);
void sort(std::vector<std::string>*);

#endif