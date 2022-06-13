
#include"AcademyHuman.h"
#include"AcademyStudent.h"
#include"AcademyTeacher.h"
#include"AcademyGraduate.h"
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