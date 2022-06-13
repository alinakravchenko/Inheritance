#include"AcademyHuman.h"
#include"AcademyStudent.h"
#include"AcademyTeacher.h"
#include"AcademyGraduate.h"


const string& Human::get_last_name()const
{
	return last_name;
}
const string& Human::get_first_name()const
{
	return first_name;
}
unsigned int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	this->age = age;
}
//					Constructors:
Human::Human(HUMAN_TAKE_PARAMETERS)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
//				Methods:
void Human::print()const //без virtual раннее связывание 
{
	cout << last_name << " " << first_name << " " << age << "years.\n";
}
ostream& operator<<(ostream& os, const Human& obj)
{
	return
		os << obj.get_last_name() << " " << obj.get_first_name()
		<< " " << obj.get_age() << " years.\n";
}