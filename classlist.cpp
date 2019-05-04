ECE222
#include <iostream>
#include <string>
using namespace std;

class Instructor
{
public:
	string name;
	int DTN;
};


class Student
{
public:
	string name;
	int DTN;
	int grade;
};

class Course
{
public:
	string name;
	Student list[10];
	Instructor inst;
};


int main()
{
	Course ECE_222;

	ECE_222.name = "Introduction to digital computation";
	ECE_222.inst.name = "Gibbens";
	ECE_222.inst.DTN = 8988558;

	for (int i = 0; i < 10; i++)
	{
		ECE_222.list[i].name = "student";
		ECE_222.list[i].DTN = 8000000 + i;
		ECE_222.list[i].grade = 100 - i * 4;

	}


	//Printing my variable fields, It's not necessory for this exercise.
	cout << "Course name: " << ECE_222.name << endl;
	cout << "Course Instructor name: " << ECE_222.inst.name << endl;
	cout << "Course Instructor DTN: " << ECE_222.inst.DTN << endl;
	cout << "Students list:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "- " << ECE_222.list[i].name << ", DTN = " << ECE_222.list[i].DTN << " Grade: " << ECE_222.list[i].grade << endl;
	}
	return 0;
}
