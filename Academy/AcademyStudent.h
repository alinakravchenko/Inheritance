#pragma once
#include<iostream>
#include<string>

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
ostream& operator<<(ostream& os, const Student& obj);
