#include "player.h"

PlayerT::PlayerT(){

	age = 1000;
	position = 0;
	name = "NoNAME";
}
	


void PlayerT::ShowMeEverything(){

	cout << "[" << age
	     << " " << position
	     << " " << name << "]" << endl;

	return;
}

//Observer Functions
int PlayerT::GetAge(){
	return age;
}
int PlayerT::GetPosition(){
	return position;
}
string PlayerT::GetName(){
	return name;
}

//transformers
void PlayerT::MovePlayer(int newPosition){

	position = newPosition;
	return;
}

void PlayerT::CreatePlayer(int newAge, string newName){

	name = newName;
	age = newAge;
	position = 0;

	return;
}