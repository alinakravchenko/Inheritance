#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;
//#define WRITE_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	/*cout << "Hello world\n";*/
	ofstream fout; //1) создаЄм поток
	fout.open("File.txt", std::ios_base::app);/*append*/ //2) открываем поток
	fout << "Hello World\t";//3)выводим в поток
	fout.close(); //4) закрываем поток
	//потоки об€зательно нужно закрывать!!! это наравне с удалением пам€ти
	//сколько раз был вызван метод 'OPEN()', столько же раз нужно вызвать метод
	//close();


	system("notepad File.txt");
#endif 
	const int SIZE = 256;
	//sz - string zero
	char sz_filename[SIZE] = {}; // буфер промежуточного хранени€ считываемого из файла текста
	cout << "¬ведите им€ файла";
	cin.getline(sz_filename, SIZE);
	//strcmp() - string compare (сравнение строк) 
	//int strcmp(char* str1, char* str2);
	//если фун-€ вернула 0б значит строки идентичны,
	//значение отличное от нул€ - строки разные
	if (strcmp(sz_filename + strlen(sz_filename) - 4, "txt."))
		//strlen() - возвращает 
	strcat(sz_filename, ".txt");
	ofstream fout;
	fout.open(sz_filename, std::ios_base::app);
	char sz_contents[SIZE] = {};
	cout << "¬ведите содержимое файла";
	cin.getline(sz_contents, SIZE);
	fout << sz_contents;
	fout.close();
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	//функ-€ strcat(char* str1, char* str2) выполн€ет конкатенацию/сли€ние строк
	//к содерж. первой строки доб. содержимое второй строки
	system(sz_command);

	
}

