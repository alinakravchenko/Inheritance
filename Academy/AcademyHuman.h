#pragma once
#include<iostream>
#include<string>
using namespace std;
#define tab "\n-----------------------\n"
//Generalisation - обобщение
//Polymorphism (многоформенность) - способность объектов вести себя по разному
//в зависимости об обстоятельств.
//Inclusion polymorphism (RinTime polymorphism) - возможен только при наследовании.
#define HUMAN_TAKE_PARAMETERS const string& last_name, const string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
class Human
{
protected:
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const;
	const string& get_first_name()const;
	unsigned int get_age()const;
	void set_last_name(const string& last_name);
	void set_first_name(const string& first_name);
	void set_age(unsigned int age);
	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS);
	virtual~Human();
	//				Methods:
	virtual void print()const;
};
ostream& operator<<(ostream& os, const Human& obj);
