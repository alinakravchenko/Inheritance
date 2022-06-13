#pragma once
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
ostream& operator<<(ostream& os, const Graduate& obj);
