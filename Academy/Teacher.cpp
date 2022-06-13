#include"AcademyHuman.h"
#include"AcademyStudent.h"
#include"AcademyTeacher.h"
#include"AcademyGraduate.h"
const string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}
//					Constructors:
Teacher::Teacher
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, unsigned int experience
) :Human(last_name, first_name, age)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}

//				Methods:
void Teacher::print()const
{
	{
		Human::print();
		cout << "speciality\t" << speciality + " " << "experience\t" << experience << endl;
	}
}
ostream& operator<<(ostream& os, const Teacher& obj)
{
	return os << (Human&)obj
		<< " специальность " << obj.get_speciality()
		<< " опыт преподавания " << obj.get_experience() << " лет.";
}