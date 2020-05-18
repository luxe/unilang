//Trevor Hickey
//Dan Bennett
//05/05/11
//Student Implementation File

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

StudentT::StudentT(){
	
	name = "NO_NAME";
	grade = 0;
	next = NULL;

	return;
}

StudentT::StudentT(const StudentT & student){
	
	name = student.name;
	grade = student.grade;
	next = student.next;
	
	return;
}

StudentT::StudentT(const string & parameterName, const float & parameterGrade){
	
	name = parameterName;
	grade = parameterGrade;
	next = NULL;
}
	
StudentT::StudentT(const string & parameterName){
	
	name = parameterName;
	grade = 0;
	next = NULL;
	
	return;
}

void StudentT::Add(const float & addedNumber){
	
	grade += addedNumber;
	
	return;
}

StudentT & StudentT::operator= (const StudentT & student){
	
	// check for self-assignment by comparing the address of the
	// implicit object and the parameter
	if (this == & student){
		return *this;
	}
	
	name = student.name;
	grade = student.grade;
	next = student.next;
	
	return *this;
}

ostream & operator<<(ostream & stream, const StudentT & student){
	
	stream << student.name;
	stream << " ";
	stream << student.grade;
	
	return stream;
}


string StudentT::Key(){
	
	return name;
}

float StudentT::Grade(){
	
	return grade;
}
