// Files_Operations_Test_VS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include <cstdio>
#include <string>

bool stdioFileWriteRead()
{
	FILE *file;
	fopen_s(&file, "test.txt", "w");

	if (file == nullptr) {
		std::cout << "Can't create 'test.txt'!" << std::endl;
		return false;
	}

	fprintf_s(file, "%s", "test");
	fclose(file);

	fopen_s(&file, "test2.txt", "r");

	if (file == nullptr) {
		std::cout << "Can't open 'test2.txt'!" << std::endl;
		fopen_s(&file, "test.txt", "r");

		if (file == nullptr) {
			std::cout << "Can't open 'test.txt'!" << std::endl;
			return false;
		}
	}

	std::cout << "file.txt content:" << std::endl;
	int fileContentLength = 5;
	char *fileContent = new char[fileContentLength];
	fscanf_s(file, "%s", fileContent, fileContentLength);
	std::cout << fileContent << std::endl;
	fclose(file);

	return true;
}

bool fstreamFileWriteRead()
{
	std::ofstream writer("test.txt");
	std::ifstream reader;
	
	if (!writer.is_open()) {
		std::cout << "Can't create 'test.txt'!" << std::endl;
		return false;
	}

	writer << "test";
	writer.close();

	reader.open("test2.txt");

	if (!reader.is_open()) {
		std::cout << "Can't open 'test2.txt'!" << std::endl;
		reader.open("test.txt");

		if (!reader.is_open()) {
			std::cout << "Can't open 'test.txt'!" << std::endl;
			return false;
		}
	}

	std::string fileContent;
	reader >> fileContent;
	std::cout << "file.txt content:" << std::endl;
	std::cout << fileContent << std::endl;
	reader.close();

	return true;
}

//TODO: реализовать функции ниже

//Создаёт файл со случайным массивом размера numbersCount и диапазоном значений [0, maxNumberValue].
//Возвращает true, если файл был успешно создан.
//Функция должна быть способна сгенерировать файл размера больше, чем доступная оперативная память.
bool createFileWithRandomNumbers(const std::string &fileName, const int numbersCount, const int maxNumberValue);

//Проверяет массив в файле на упорядоченность.
//Возвращает true, если массив в файле упорядочен.
//Функция должна быть способна проверить файл размера больше, чем доступная оперативная память.
bool isFileContainsSortedArray(const std::string &fileName);

int main()
{
	fstreamFileWriteRead();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
