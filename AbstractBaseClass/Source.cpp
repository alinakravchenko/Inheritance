/*
type name(parameters);

virtual type name(parameters)=0;
=0; - ����������, ��� ����� ������� ��� �����������


*/
#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() const = 0;
	//�����. ����� 
};
class GroundVehicle :public Vehicle
{};
class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "������ ���� �� ������� ������� ��� �������" << endl;
	}
	//���������� �����
};
class Bike :public GroundVehicle
{
public:
	void move() const
	{
		cout << "�������� ���� �� ���� ������" << endl;
	}
};
class AirVehicle :public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
};
class Helicopter :public AirVehicle
{
public:
	void move() const
	{
		cout << "������� ����� �� �����" << endl;
	}
	void take_off()
	{
		cout << "������������ ����" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v; //���������� ������� ��������� �����.������
	//GroundVehicle gv; 
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();

	Helicopter apache;
	apache.take_off();
	apache.move();
}