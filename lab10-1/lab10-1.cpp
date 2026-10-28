/*
Lab 10-1
Current date here
Your name here
*/

#include <iostream>
#include <string>

using namespace std;

class student
{
public:
	static const int MAX_GRADES = 3;
private:
	string name = "";
	int grades[MAX_GRADES] = {}; 
public:
	student() {}
	~student() { cout << name << " has graduated!" << endl; }
	student(string name, const int* grades)
	{
		student::name = name;
		for (int i = 0; i < MAX_GRADES; ++i)
		{
			student::grades[i] = grades[i];
		}
	}

	string getName() const { return name; }
	const int* getGrades() const { return grades; }
	void setName(string name) { student::name = name; }
	void setGrade(int grade, int index) { grades[index] = grade; }
	void output_student() const;
	void input_student();
};

int main()
{
	const int MAX_STUDENTS = 3;

	student students[MAX_STUDENTS];
	
	for (int i = 0; i < MAX_STUDENTS; ++i)
	{
		cout << "Enter student " << (i + 1) << ":" << endl;
		students[i].input_student();
		cout << endl;
	}

	for (int i = 0; i < MAX_STUDENTS; ++i)
	{
		students[i].output_student();
	}

	/* Test constructor
	int my_grades[] = { 100, 100, 100 }; 
	student me = student("Joe", my_grades);
	me.output_student();
	*/
	return 0;
}

void student::output_student() const
{
	cout << name << ":\t";
	for (int j = 0; j < student::MAX_GRADES; ++j)
	{
		if (j != 0)
		{
			cout << "\t";
		}
		cout << "\t" << grades[j] << "%\n";
	}
}

void student::input_student()
{
	cout << "Enter student name " << ": ";
	cin >> name;
	for (int j = 0; j < student::MAX_GRADES; ++j)
	{
		cout << "Enter grade " << (j + 1) <<
			" for " << name << ": ";
		cin >> grades[j];
	}
}