/*
type name(parameters);

virtual type name(parameters)=0;
=0; - показывает, что така€ функци€ без определени€


*/
#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() const = 0;
	//абстр. класс 
};
class GroundVehicle :public Vehicle
{};
class Car :public GroundVehicle
{
public:
	void move() const
	{
		cout << "машина едит на четырех колесах как минимум" << endl;
	}
	//конкретный класс
};
class Bike :public GroundVehicle
{
public:
	void move() const
	{
		cout << "мотоцикл едит на двух колЄсах" << endl;
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
		cout << "вертолЄт летит на винте" << endl;
	}
	void take_off()
	{
		cout << "вертикальный взлЄт" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v; //невозможно создать экземпл€р абстр.класса
	//GroundVehicle gv; 
	Bike HD;
	HD.move();
	Car bmw;
	bmw.move();

	Helicopter apache;
	apache.take_off();
	apache.move();
}