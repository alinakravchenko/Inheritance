﻿#include<iostream>
#include<string>
#include<fstream>
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
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//				Methods:
	//без virtual раннее связывание 
	virtual ostream& print(ostream& os/*=cout*/)const
	{
		return os << last_name << " " << first_name << " " << age << "years.\n";

	}
	virtual std::ofstream& write(std::ofstream& fout)const 
	{
		//ofstream fout("File.txt", std::ios_base::app);
		fout << last_name << " " << first_name << " " << age << " лет.";
		//fout.close();
		return fout;
	}
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
ofstream& operator<<(ofstream& os, const Human& obj)
{
	return obj.write(os);
}

#define STUDENT_TAKE_PATAMETERS const string& specialty, const string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty, group, year, rating, attendance
class Student :public Human
{
	string specialty;
	string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	unsigned int  get_year()const
	{
		return year;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//				Constructors:
	Student
	(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PATAMETERS) :Human(HUMAN_GIVE_PARAMETERS)	//Dелегируем конструктор Human класса
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//				Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		return os << specialty + " " + group << " " << year << " " << rating << " " << attendance << endl;
	}
	/*ofstream& print(ofstream& os)const
	{
		Human::print(os);
		return os << specialty + " " + group << " " << year << " " << rating << " " << attendance << endl;
	}*/
	std::ofstream& write(std::ofstream& fout)const
	{
		Human::write(fout);
		fout << specialty + " " + group << " " << year << " " << rating << " " << attendance;
		return fout;
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//					Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//				Methods:
	ostream& print(ostream& os)const
	{
		Human::print(os);
		return os << "speciality\t" << speciality + " " << "experience\t" << experience << endl;
	}
	ofstream& write(ofstream& os)const
	{
		Human::write(os);
		os << "speciality\t" << speciality + " " << "experience\t" << experience;
		return os;
	}
	/*void write()
	{
		Human::write();
		ofstream fout("File.txt", std::ios_base::app);
		fout << "speciality\t" << speciality + " " << "experience\t" << experience << endl;
		fout.close();
	}*/
};
class Graduate :public Student
{
	string diploma;
public:
	const string& get_diploma()const
	{
		return diploma;
	}
	void set_diploma(const string& diploma)
	{
		this->diploma = diploma;
	}
	//			Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, unsigned int year, double rating, double attendance,
		const string& diploma
	) :Student(last_name, first_name, age, speciality, group, year, rating, attendance)
	{
		set_diploma(diploma);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//					Methods:
	ostream& print(ostream& os)const
	{
		//Student::print(os);
		return Student::print(os) << "Тема диплома: " << diploma << endl;
	}
	/*ofstream& print(ofstream& os)const
	{
		return Student::print(os) << "Тема диплома: " << diploma << endl;
	}*/
	std::ofstream& write(std::ofstream& fout)
	{
		Student::write(fout);
		fout << "Тема диплома: " << diploma;
		return fout;
	}
};
//#define INHERITANCE_CHECK
//#define COUT
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Montana", "Antonio", 25);
	human.print();

	Student pinkman("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 85);
	pinkman.print();

	Teacher teacher("Kim", "Jeon", 81, "Chemistry", 35);
	teacher.print();

	Graduate graduate("Stiles", "Stilinski", 22, "Programming", "PV_111", 4, 6, 100, "C++");
	graduate.print();
#endif
#ifdef COUT
	//Generalisation:
	//массив указателя на человека
	//Upcast - приведение к базовому типу
	Human* group[] =
	{
		 new Student("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 95),//upcast
		 new Teacher("White", "Walter", 50, "Chemistry", 25),//upcast
		 new Graduate("Schreder", "Hank", 40,
		 "Criminalystic", "WW_220",5, 95,80, "How to catch Heisenberg"),
		 new Student("Vercetti", "Tomas", 30, "Theft", "Vice", 3, 90, 85),//upcast
		 new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20),
		 new Teacher("Einstein", "Albert", 143, "Astronomy", 100)

	};
	//Specialisation - уточнение
	cout << tab << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//RTTI - Runtime Type Information
		cout << typeid(*group[i]).name() << endl;
		/*group[i]->print();*/
		cout << *group[i] << endl;
		cout << tab << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) //Human*
	{
		delete[] group[i];
	}
#endif
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 95),//upcast
		new Teacher("White", "Walter", 50, "Chemistry", 25),//upcast
		new Graduate("Schreder", "Hank", 40,
		"Criminalystic", "WW_220",5, 95,80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Theft", "Vice", 3, 90, 85),//upcast
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 100)

	};
	ofstream fout("File.txt"/*, std::ios_base::app*/); //создание и открытие потока
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->write();
		fout << *group[i] << endl;
	}
	system("notepad File.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete[] group[i];
	}
	fout.close();
}

//Синтаксис наследования
//class Base
//{
//	//....
//};
//class Derived :public Base
//{
//	//....
//};