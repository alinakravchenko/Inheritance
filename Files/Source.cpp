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
	ofstream fout; //1) ������ �����
	fout.open("File.txt", std::ios_base::app);/*append*/ //2) ��������� �����
	fout << "Hello World\t";//3)������� � �����
	fout.close(); //4) ��������� �����
	//������ ����������� ����� ���������!!! ��� ������� � ��������� ������
	//������� ��� ��� ������ ����� 'OPEN()', ������� �� ��� ����� ������� �����
	//close();


	system("notepad File.txt");

	const int SIZE = 256;
	//sz - string zero
	char sz_filename[SIZE] = {}; // ����� �������������� �������� ������������ �� ����� ������
	cout << "������� ��� �����";
	cin.getline(sz_filename, SIZE);
	//strcmp() - string compare (��������� �����) 
	//int strcmp(char* str1, char* str2);
	//���� ���-� ������� 0� ������ ������ ���������,
	//�������� �������� �� ���� - ������ ������
	if (strcmp(sz_filename + strlen(sz_filename) - 4, "txt."))
		//strlen() - ���������� 
	strcat(sz_filename, ".txt");
	ofstream fout;
	fout.open(sz_filename, std::ios_base::app);
	char sz_contents[SIZE] = {};
	cout << "������� ���������� �����";
	cin.getline(sz_contents, SIZE);
	fout << sz_contents;
	fout.close();
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	//����-� strcat(char* str1, char* str2) ��������� ������������/������� �����
	//� ������. ������ ������ ���. ���������� ������ ������
	system(sz_command);
#endif
	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		//TODO: read file
		const int n = 256;
		char buffer[n] = {};
		while (!fin.eof()) //eof() - end of file
		{
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found!" << endl;
	}
	fin.close();
	system("notepad File.txt");
}

