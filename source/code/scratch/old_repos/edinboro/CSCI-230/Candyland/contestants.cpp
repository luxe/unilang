#include "contestants.h"

ContestantsT::ContestantsT(){

	currentPlayer = 0;
}
//Debugging Tool
void ContestantsT::ShowMeEverything(){

	for (int i = 0; i < MAX_PLAYERS; i++){
		contestants[i].ShowMeEverything();
	}

	return;
}

int ContestantsT::GetPosition(){

	int position = contestants[currentPlayer].GetPosition();
	
	return position;
}
void ContestantsT::MovePlayer(int newcharPosition){

	int charPosition = newcharPosition;
	contestants[currentPlayer].MovePlayer(charPosition);

	return;
}

string ContestantsT::GetName(){
	
	string name = contestants[currentPlayer].GetName();

	return name;
}
void ContestantsT::CreatePlayer(int position, int playerAge, string playerName){

	contestants[position].CreatePlayer(playerAge, playerName);

	return;
}

void ContestantsT::Sort(){

	SelectionSort(contestants);

	return;
}

void ContestantsT::SelectionSort(PlayerT contestants[]) {
    int current, smallPos, comparePos;

    for(current = 0; current < MAX_PLAYERS-1;current++) {
       smallPos = current;
       for(comparePos=current+1; comparePos < MAX_PLAYERS; comparePos ++) {
           if (contestants[smallPos].GetAge() > contestants[comparePos].GetAge()) {
              smallPos = comparePos;
           }
       }
       if(smallPos != current) {
          Swap(contestants[smallPos], contestants[current]);
       }
    }

    return;
}


void ContestantsT::Swap(PlayerT & a, PlayerT & b){

	PlayerT tmp;

    tmp =a;
    a = b;
    b = tmp;

    return;
}

void ContestantsT::ChangePlayer(){
	if (currentPlayer == MAX_PLAYERS - 1){
		currentPlayer = 0;
	}
	else{
	currentPlayer++;
	}
	
	while(contestants[currentPlayer].GetName() == "NoNAME"){
		currentPlayer++;
		if (currentPlayer == MAX_PLAYERS - 1){
			currentPlayer = 0;
		}
			currentPlayer = 0;
	}
}

