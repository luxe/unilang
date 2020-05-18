#ifndef STUDENT_H
#define STUDENT_H

//Trevor Hickey
//Dan Bennett
//05/05/11
//Student Header File

#include <ostream>
#include <string>

using std::string;

class StudentT{
	
public:
	//╔══════════════════════╗
	//║     Constructors     ║
	//╚══════════════════════╝
	
	StudentT();
	//default constructor
	//sets the student name to: "no_name"
	//sets next pointer to NULL
	
	StudentT(const StudentT & student);
	//copy constructor
	//will initialize a StudentT by copying the data passed in
	
	StudentT(const string & name, const float & grade);
	//parameterized constructor 
	//creates a student based on the name and grade given
	
	StudentT(const string & name);
	//parameterized constructor
	//creates a student based on the name given
	//sets their grade to zero
	
	
	//╔══════════════════════╗
	//║      Observers       ║
	//╚══════════════════════╝
	
	string Key();
	//returns the name of the student
	
	float Grade();
	//returns the grade of the student
	
	//╔══════════════════════╗
	//║     Transformers     ║
	//╚══════════════════════╝
	
	void Add(const float & addedNumber);
	//changes the students grade by adding to the grade the float passed in
	
	//╔══════════════════════╗
	//║      Destructor      ║
	//╚══════════════════════╝
	
	StudentT & operator= (const StudentT & student);
	
	friend std::ostream & operator<<(std::ostream & stream, const StudentT & student);
	
	StudentT * next;
	
private:
	string name;
	float grade;
	
};

#endif