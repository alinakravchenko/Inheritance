#include"AcademyHuman.h"
#include"AcademyStudent.h"
#include"AcademyTeacher.h"
#include"AcademyGraduate.h"

const string& Student::get_specialty()const
{
	return specialty;
}
const string& Student::get_group()const
{
	return group;
}
unsigned int  Student::get_year()const
{
	return year;
}
double Student::get_rating()const
{
	return rating;
}
double Student::get_attendance()const
{
	return attendance;
}
void Student::set_specialty(const string& specialty)
{
	this->specialty = specialty;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_year(unsigned int year)
{
	this->year = year;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
void Student::set_attendance(double attendance)
{
	this->attendance = attendance;
}
//				Constructors:
Student::Student
(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PATAMETERS) :Human(HUMAN_GIVE_PARAMETERS)	//Dелегируем конструктор Human класса
{
	set_specialty(specialty);
	set_group(group);
	set_year(year);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}
//				Methods:
void Student::print()const
{
	Human::print();
	cout << specialty + " " + group << " " << year << " " << rating << " " << attendance << endl;
}
ostream& operator<<(ostream& os, const Student& obj)
{
	/*os << (Human&)obj;*/
	return os << (Human&)obj
		<< obj.get_specialty() << " Specialty " << " Group "
		<< obj.get_group() << " Year " << obj.get_year() << " Rating " << obj.get_rating()
		<< " Attendance " << obj.get_attendance();
}
