//Trevor Hickey
//Dan Bennett
//05/05/11
//This Program maintains 3 lists for students.
//students are stored in each list depending on their grades
//a file contains various commands on how to manipulate, and observe the lists

#include <iostream>
#include <fstream>

#include "list.h"

using namespace std;

//lists to store students based on grade
struct listsT{
	ListT goodList;
	ListT averageList;
	ListT poorList;
};

void OpenGradesFile (ifstream & gradesFile, bool & successOpeningGradesFile, string GRADE_FILE_NAME);
void PerformGrade(ifstream & gradesFile, listsT & lists);
	void AddStudentToList(listsT & lists, ItemT student);
void PerformAdd(ifstream & gradesFile, listsT & lists);
	ItemT CreateNewStudentItem(ListT & list, string name, float addNumber);
void PerformQuery(ifstream & gradesFile, listsT & lists);
	void OutputStudentFromList(ListT & list, string name, string fromList);
void PerformPrint(ifstream & gradesFile, listsT & lists);
	void PrintList(ListT & list);
void PerformPrintAll(ifstream & gradesFile, listsT & lists);
void PerformUnknown(string gradeCommand);

int main(){
	
	listsT lists; //contains lists for students with good, average, and poor grades
	
	const string GRADE_FILE_NAME = "grades.dat";    //outside file this program will interact with
	ifstream gradesFile;                           //declares a filestream to open a file of computation commands
	bool successOpeningGradesFile = true;
	string gradeCommand;
	
	OpenGradesFile (gradesFile,successOpeningGradesFile,GRADE_FILE_NAME); //opens the file holding the grade commands
	if (successOpeningGradesFile){                                       //continues if the file opened successfully
		gradesFile >> gradeCommand;                                     //take in first command from grade file
		while(!gradesFile.eof()) {                                     //loop until the end of the grades file is reached
			
			//decide what action needs to be performed
			if (gradeCommand == "grade"){
				PerformGrade(gradesFile, lists);
			}
			else if (gradeCommand == "add"){
				PerformAdd(gradesFile, lists);
			}
			else if (gradeCommand == "query"){
				PerformQuery(gradesFile, lists);
			}
			else if (gradeCommand == "print"){
				PerformPrint(gradesFile, lists);
			}
			else if (gradeCommand == "printall"){
				PerformPrintAll(gradesFile, lists);
			}
			else{
				PerformUnknown(gradeCommand);
			}
			gradesFile >> gradeCommand;
		}
	}
	
	gradesFile.close();
	
	return 0;
}

void OpenGradesFile (ifstream & gradesFile, bool & successOpeningGradesFile, string GRADE_FILE_NAME){
	
	//opens file which contains a list of grade commands
	//*files must be in the program's directory
	gradesFile.open(GRADE_FILE_NAME.c_str());
	
	//tests to make sure the file was opened
	if(!gradesFile) {
		cout << endl << "ERROR: Failed to open " << "'"<< GRADE_FILE_NAME <<"'." << endl
		<< "*please make sure that the file '" << GRADE_FILE_NAME <<"' " << "in the same directory as this program." <<endl << endl;
		
		successOpeningGradesFile = false;
	}
	return;
}
void PerformGrade(ifstream & gradesFile, listsT & lists){
	
	float grade;
	string name;
	
	gradesFile >> grade;       //store the student's grade
	getline(gradesFile, name); //store the students's name
	name.erase(0,1);
	
	//create a student item
	ItemT student(name, grade);
	
	//based on grade, decide what list to put the student in
	AddStudentToList(lists, student);
	
	return;
}

void AddStudentToList(listsT & lists, ItemT student){
	
	float grade = student.Grade();
	
	//based on grade, decide what list to put the student in
	if (grade >= 3){
		lists.goodList.Insert(student);
	}
	else if (grade >= 2 && grade <= 2.99){
		lists.averageList.Insert(student);
	}
	else if (grade < 2){
		lists.poorList.Insert(student);
	}
	
	return;
}
void PerformAdd(ifstream & gradesFile, listsT & lists){
	
	float addNumber;
	
	string name;
	ItemT student;
	
	gradesFile >> addNumber;   //store the number that will be added to the student's grade
	getline(gradesFile, name); //store the students's name
	name.erase(0,1);
	
	//find out what list the student is in
	//set the index to that student
	//recreate the student with a changed grade and delete them from the list
	if (lists.goodList.IsPresent(name)){
		student = CreateNewStudentItem(lists.goodList, name, addNumber);
	}
	else if (lists.averageList.IsPresent(name)){
		student = CreateNewStudentItem(lists.averageList, name, addNumber);
	}
	else if (lists.poorList.IsPresent(name)){
		student = CreateNewStudentItem(lists.poorList, name, addNumber);
	}
	
	//based on grade, decide what list to put the student in
	AddStudentToList(lists, student);
	
	return;
}

ItemT CreateNewStudentItem(ListT & list, string name, float addNumber){
	
	ItemT student; //return value of a student with a changed grade
	
	//move index to the desired student whose grade needs changed
	list.ResetIndex();
	while (list.Key() != name){
		list.NextItem();
	}
	
	//make a copy of the student and change the grade
	student = list.GetIndex();
	student.Add(addNumber);
	
	//delete the student from the list(they may or may not be placed back into the same list)
	list.Delete(name);
	
	return student;
}
void PerformQuery(ifstream & gradesFile, listsT & lists){
	
	string name;
	string fromList;
	getline(gradesFile, name); //store the students's name
	name.erase(0,1);
	
	//find out what list the student is in
	if (lists.goodList.IsPresent(name)){
		fromList = "good";
		OutputStudentFromList(lists.goodList, name, fromList);
	}
	else if (lists.averageList.IsPresent(name)){
		fromList = "average";
		OutputStudentFromList(lists.averageList, name, fromList);
	}
	else if (lists.poorList.IsPresent(name)){
		fromList = "poor";
		OutputStudentFromList(lists.poorList, name, fromList);
	}
	else{
		cout << name << " is not a member of any lists." << endl;
	}
	
	return;
}

void OutputStudentFromList(ListT & list, string name, string fromList){
	
	ItemT student; //return value of a student with a changed grade
	
	//move index to the desired student whose grade needs changed
	list.ResetIndex();
	while (list.Key() != name){
		list.NextItem();
	}
	//make a copy of the student
	student = list.GetIndex();
	
	//print student information
	cout << student.Key() << ", " << student.Grade() << ", " << fromList << endl;
	
	return;
}
void PerformPrint(ifstream & gradesFile, listsT & lists){
	
	string listToPrint;
	getline(gradesFile, listToPrint);
	listToPrint.erase(0,1);
	
	if (listToPrint == "good"){
		cout << "good list:" << endl;
		PrintList(lists.goodList);
	}
	else if (listToPrint == "average"){
		cout << "average list:" << endl;
		PrintList(lists.averageList);
	}
	else if (listToPrint == "poor"){
		cout << "poor list:" << endl;
		PrintList(lists.poorList);
	}
	
	return;
}
void PrintList(ListT & list){
	
	ItemT student;
	
	for(list.ResetIndex();!list.IsLast();list.NextItem()) {
		student = list.GetIndex(); //hold the student from the particular index
		
		//print student information
		cout << student.Key() << ", " << student.Grade() << endl;
	}
	
	if (list.ValidIndex()) {
		student = list.GetIndex(); //hold the student from the particular index
		
		//print student information
		cout << student.Key() << ", " << student.Grade() << endl;
	}
	
	return;
}
void PerformPrintAll(ifstream & gradesFile, listsT & lists){

	//print all the lists
	cout << "good list:" << endl;
	PrintList(lists.goodList);
	cout << endl <<  "average list:" << endl;
	PrintList(lists.averageList);
	cout << endl <<  "poor list:" << endl;
	PrintList(lists.poorList);
	
	return;
}
void PerformUnknown(string gradeCommand){
	
	cout << "ERROR: " << "'" << gradeCommand << "'" << " is not a known command!" << endl;
	
	return;
}