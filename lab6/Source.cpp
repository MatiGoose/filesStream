#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>



char * changeMyStr(char * str)
{
	char * my_str;
	my_str = str;
	int counter = strlen(str);
	while (*str != '\n')
	{
		if (((*str<'a' || *str>'z') && *str != ' ') || (*str == ' ' && *(str + 1) == ' '))
		{
			counter--;
		}
		str++;
	}
	str = my_str;
	char *new_str = new char[counter];
	my_str = new_str;
	new_str[counter - 1] = '\n';
	new_str[counter] = '\0';
	while (*str != '\n')
	{
		if (!(((*str<'a' || *str>'z') && *str != ' ') || (*str == ' ' && *(str + 1) == ' ')))
		{
			*new_str = *str;
			new_str++;
		}
		str++;
	}
	return my_str;
}
void createFile()
{
	char name[100];
	std::cout << "File name: ";
	std::cin >> name;
	std::ofstream fout(name);
	std::cout << "Created!" << std::endl;
	fout.close();
}
void showFileData()
{
	char name[100];
	std::cout << "File name: ";
	std::cin >> name;
	std::ifstream fin(name);
	if (!fin.is_open())
	{
		std::cout << "Файл не может быть открыт!\n"; 
		return;
	}
	std::string buf;
	while (getline(fin, buf))
	{
		std::cout << buf;
		std::cout << std::endl;
	}
	fin.close();
}
void writetoFile()
{
	char name[100];
	std::cout << "File name: ";
	std::cin >> name;
	std::ofstream fout(name, std::ios_base::app);
	char choice;
	std::cout << "Press key to add string" << std::endl << "9)Exit" << std::endl;
	choice = _getch();
	char str[100];
	while (choice != '9')
	{
		getchar();
		std::cout << "Your string: ";
		gets_s(str);
		fout << str;
		fout << "\n";
		std::cout << "Done!" << std::endl;
		std::cout << "Press key to add string" << std::endl << "9)Exit" << std::endl;
		choice = _getch();
	}
	fout.close();
}
void updateFile()
{
	char name[100];
	std::cout << "File name: ";
	std::cin >> name;
	std::ofstream fout(name, std::ios_base::trunc);
	char choice;
	std::cout << "Press key to add string" << std::endl << "9)Exit" << std::endl;
	choice = _getch();
	char str[100];
	while (choice != '9')
	{
		getchar();
		std::cout << "Your string: ";
		gets_s(str);
		fout << str;
		fout << '\n';
		std::cout << "Done!" << std::endl;
		std::cout << "Press key to add string" << std::endl << "9)Exit" << std::endl;
		choice = _getch();
	}
	fout.close();
}
void deleteSymbols()
{
	char name[100];
	std::cout << "File name: ";
	std::cin >> name;
	std::ifstream fin(name);
	std::cout << "New file name: ";
	std::cin >> name;
	std::ofstream fout(name);
	if (!fin.is_open())
	{
		std::cout << "Файл не может быть открыт!\n";
		return;
	}
	std::string buf;
	char charBuf[255];
	while (getline(fin, buf))
	{
		strncpy_s(charBuf, buf.c_str(), sizeof(charBuf));
		int size = strlen(charBuf);
		charBuf[size] = '\n';
		charBuf[size + 1] = '\0';
		fout << changeMyStr(charBuf);
	}
	std::cout << "\nDone!";
	fin.close();
	fout.close();
}
int main()
{

	while (true)
	{
		setlocale(LC_ALL, "");
		int choice;
		std::cout << "1)Создание файла" << std::endl;
		std::cout << "2)Просмотр файла" << std::endl;
		std::cout << "3)Добавление текста в файл" << std::endl;
		std::cout << "4)Обновление файла" << std::endl;
		std::cout << "5)Удаление символов" << std::endl;
		std::cout << "6)exit" << std::endl;
		std::cin >> choice;
		while (!std::cin.good())
		{
			std::cin.ignore();
			std::cin.clear();
			system("clear");
			std::cin >> choice;
		}
		switch (choice)
		{
		case 1:
			createFile();
			break;
		case 2:
			showFileData();
			break;
		case 3:
			writetoFile();
			break;
		case 4:
			updateFile();
			break;
		case 5:
			deleteSymbols();
			break;
		case 6:
			return 0;
			break;
		}
	}
}