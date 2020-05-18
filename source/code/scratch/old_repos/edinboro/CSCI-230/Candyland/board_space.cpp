#include "board_space.h"

//Debugging Tool
void BoardSpaceT::ShowMeEverything(void){

	cout << "[" << ConvertColorToString(color)
	     << " " << ConvertSpaceAttributeToString(spaceAttribute)
	     << " " << endPosition
	     << " " << name << "]" << endl;

	return;
}

//Constructers
BoardSpaceT::BoardSpaceT(){

		color = NO_COLOR;
		spaceAttribute = NOTHING;
		endPosition = 0;
		name = "NoName";
		
}

//transformers
void BoardSpaceT::CreateBoardSpace(SpaceAttributeT newSpaceAttribute, string newName){

	if (newSpaceAttribute == CHARACTER){
		color = PINK;
		spaceAttribute = CHARACTER;
		endPosition = 0;
		name = newName;
	}

	else if (newSpaceAttribute == PENALTY){
		color = NO_COLOR;
		spaceAttribute = PENALTY;
		endPosition = 0;
		name = newName;
	}

	return;

}
void BoardSpaceT::CreateBoardSpace(int newEndPosition, string newName){

		color = NO_COLOR;
		spaceAttribute = SHORTCUT;
		endPosition = newEndPosition;
		name = newName;

	return;
}	
void BoardSpaceT::ChangeColor(ColorT newColor){

	color = newColor;
	return;
}

//observers
ColorT BoardSpaceT::GetColor(){
	
	return color;
}
SpaceAttributeT BoardSpaceT::GetSpaceAttribute(){

	return spaceAttribute;
}
int BoardSpaceT::GetEndPosition(){

	return endPosition;
}
string BoardSpaceT::GetName(){

	return name;
}
string BoardSpaceT::ConvertColorToString(ColorT color){

	string str;

	switch (color){
		
		case RED:
			str = "red";
			break;
		case ORANGE:
			str = "orange";
			break;
		case YELLOW:
			str = "yellow";
			break;
		case GREEN:
			str = "green";
			break;
		case BLUE:
			str = "blue";
			break;
		case PURPLE:
			str = "purple";
			break;
		case PINK:
			str = "pink";
			break;
		case NO_COLOR:
			str = "NoColor";
			break;
	}

	return str;
}
string BoardSpaceT::ConvertSpaceAttributeToString(SpaceAttributeT spaceAttribute){

	string str;

	switch (spaceAttribute){

		case NOTHING:
			str = "NoATTRIBUTE";
			break;
		case CHARACTER:
			str = "character";
			break;
		case PENALTY:
			str = "penalty";
			break;
		case SHORTCUT:
			str = "shortcut";
			break;
	}

	return str;
}






