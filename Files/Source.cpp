#include<iostream>
#include<fstream>
using namespace std;
//#define WRITE_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_FILE
	/*cout << "Hello world\n";*/
	ofstream fout; //1) создаём поток
	fout.open("File.txt", std::ios_base::app);/*append*/ //2) открываем поток
	fout << "Hello World\t";//3)выводим в поток
	fout.close(); //4) закрываем поток
	//потоки обязательно нужно закрывать!!! это наравне с удалением памяти
	//сколько раз был вызван метод 'OPEN()', столько же раз нужно вызвать метод
	//close();


	system("notepad File.txt");
#endif 
	/*const int SIZE = 256;*/
	char buffer[80]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("File.txt"); 

	if (fin.is_open())// если файл открыт
	{
		
			fin >> buffer; // считали первое слово из файла
			fin.getline(buffer, 50); // считали строку из файла
			cout << buffer << endl; // напечатали это слово
	}
	else
	{
		
		cout << "Файл открыт!\n"; // сообщить об этом
		
		//cout << buffer << endl; // напечатали эту строку
	}
	fin.close(); // закрываем файл
	/*system("pause");*/
	//return 0;

	
}

