#include<iostream>
#include<fstream>
using namespace std;
//#define A
void main()
{
	setlocale(LC_ALL, "");
#ifdef A
	/*cout << "Hello world\n";*/
	ofstream fout; //1) ������ �����
	fout.open("File.txt", std::ios_base::app/*append*/); //2) ��������� �����
	fout << "Hello World\t";//3)������� � �����
	fout.close(); //4) ��������� �����
	//������ ����������� ����� ���������!!! ��� ������� � ��������� ������
	//������� ��� ��� ������ ����� 'OPEN()', ������� �� ��� ����� ������� �����
	//close();


	system("notepad File.txt");
#endif A
}
