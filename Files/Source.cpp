#include<iostream>
#include<fstream>
using namespace std;
//#define A
void main()
{
	setlocale(LC_ALL, "");
#ifdef A
	/*cout << "Hello world\n";*/
	ofstream fout; //1) создаём поток
	fout.open("File.txt", std::ios_base::app/*append*/); //2) открываем поток
	fout << "Hello World\t";//3)выводим в поток
	fout.close(); //4) закрываем поток
	//потоки обязательно нужно закрывать!!! это наравне с удалением памяти
	//сколько раз был вызван метод 'OPEN()', столько же раз нужно вызвать метод
	//close();


	system("notepad File.txt");
#endif A
}
