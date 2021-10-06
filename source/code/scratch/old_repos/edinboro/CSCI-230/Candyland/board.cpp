#include "board.h"

BoardT::BoardT(){



}

//Debugging Tool
void BoardT::ShowMeEverything(){

	for (int i; i < MAX_SPACES; i++){
		candyPath[i].ShowMeEverything();
	}
		
	return;
}

void BoardT::CreateBoardSpace(int position, SpaceAttributeT spaceAttribute, string name){

	candyPath[position].CreateBoardSpace(spaceAttribute, name);

	return;
}

void BoardT::CreateBoardSpace(int position, int endPosition, string name){

	candyPath[position].CreateBoardSpace(endPosition, name);

	return;
}

void BoardT::FillInColors(){

	ColorT currentColor = RED;
	for (int i = 1; i < MAX_SPACES; i++){

			if (candyPath[i].GetColor() != PINK){
			candyPath[i].ChangeColor(currentColor);
			currentColor = ColorT(currentColor+1);

			if (currentColor > colorCount){
				currentColor = RED;
			}
		}
	}
	return;
}

BoardSpaceT BoardT::GetBoardSpace(int space){

	return candyPath[space];
}

ColorT BoardT::GetColor(int space){

	return candyPath[space].GetColor();
}