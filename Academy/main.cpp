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
	const string& get_specialty()const;
	const string& get_group()const;
	unsigned int  get_year()const;
	double get_rating()const;
	double get_attendance()const;
	void set_specialty(const string& specialty);
	void set_group(const string& group);
	void set_year(unsigned int year);
	void set_rating(double rating);
	void set_attendance(double attendance);
	//				Constructors:
	Student
	(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PATAMETERS);
	~Student();
	//				Methods:
	void print()const;
};
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
	return os<<(Human&)obj
		<<obj.get_specialty()<<" Specialty " << " Group "
		<< obj.get_group()  << " Year "<< obj.get_year() <<" Rating " <<obj.get_rating()
		<< " Attendance "<< obj.get_attendance();
}
class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const string& speciality);
	void set_experience(unsigned int experience);
	//					Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	);
	~Teacher();
	
	//				Methods:
	void print()const;
};
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
	return os<<(Human&)obj
		<< " специальность " << obj.get_speciality()
		<<  " опыт преподавания " << obj.get_experience() << " лет.";
}
class Graduate :public Student
{
	string diploma;
public:
	const string& get_diploma()const;
	void set_diploma(const string& diploma);
	//			Constructors:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, unsigned int year, double rating, double attendance,
		const string& diploma
	);
	~Graduate();
	//					Methods:
	void print()const;
};
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
//#define INHERITANCE_CHECK
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
		 /* group[i]->print();*/
		 /* cout << *group[i] << endl;*/
		 //dynamic_cast работает только с указателями на классы
		  //dynamic_cast<DerivedCladss*>(BasePointer) - преобраз. указатель на базовый класс
		  //в указатель на дочерний класс (downcast)
		  if (typeid(*group[i]) == typeid(Teacher)) cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		  if (typeid(*group[i]) == typeid(Student)) cout << *dynamic_cast<Student*>(group[i]) << endl;
		  if (typeid(*group[i]) == typeid(Graduate)) cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		  cout << tab << endl;
	  }
	  for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++) //Human*
	  {
		  delete[] group[i];
	  }
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