#include"AcademyHuman.h"
#include"AcademyStudent.h"
#include"AcademyTeacher.h"
#include"AcademyGraduate.h"
const string& Graduate::get_diploma()const
{
	return diploma;
}
void Graduate::set_diploma(const string& diploma)
{
	this->diploma = diploma;
}
//			Constructors:
Graduate::Graduate
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, unsigned int year, double rating, double attendance,
	const string& diploma
) :Student(last_name, first_name, age, speciality, group, year, rating, attendance)
{
	set_diploma(diploma);
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
//					Methods:
void Graduate::print()const
{
	Student::print();
	cout << "Тема диплома: " << diploma << endl;
}
ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os << (Student&)obj << obj.get_diploma();
}