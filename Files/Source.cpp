#include<iostream>
#include<fstream>
using namespace std;
//#define WRITE_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_FILE
	/*cout << "Hello world\n";*/
	ofstream fout; //1) ������ �����
	fout.open("File.txt", std::ios_base::app);/*append*/ //2) ��������� �����
	fout << "Hello World\t";//3)������� � �����
	fout.close(); //4) ��������� �����
	//������ ����������� ����� ���������!!! ��� ������� � ��������� ������
	//������� ��� ��� ������ ����� 'OPEN()', ������� �� ��� ����� ������� �����
	//close();


	system("notepad File.txt");
#endif 
	/*const int SIZE = 256;*/
	char buffer[80]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("File.txt"); 

	if (fin.is_open())// ���� ���� ������
	{
		
			fin >> buffer; // ������� ������ ����� �� �����
			fin.getline(buffer, 50); // ������� ������ �� �����
			cout << buffer << endl; // ���������� ��� �����
	}
	else
	{
		
		cout << "���� ������!\n"; // �������� �� ����
		
		//cout << buffer << endl; // ���������� ��� ������
	}
	fin.close(); // ��������� ����
	/*system("pause");*/
	//return 0;

	
}

