#include "card.h"

//Debugging Tool
void CardT::ShowMeEverything(void){

	cout << "[" << ConvertColorToString(color)
	     << " " << colorCount
	     << " " << name
	     << " " << position << "]" << endl;
}

//Constructors

CardT::CardT(){

	color = NO_COLOR;
	colorCount = 0;
	name = "NoNAME";
	position = 0;
	
}

//observers
ColorT CardT::GetColor(void){

	return color;

}
int CardT::GetColorCount(void){

	return colorCount;

}
string CardT::GetName(void){

	return name;

}
int CardT::GetPosition(void){

	return position;

}
string CardT::ConvertColorToString(ColorT color){

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
			str = "NoCOLOR";
			break;
	}

	return str;
}

//transformers
void CardT::CreateCard(string newName, int newPosition){

		name = newName;
		position = newPosition;
		color = PINK;
		colorCount = 1;

	return;
}
void CardT::BuildColorCard(ColorT currentColor, int count){
	color = currentColor;
	colorCount = count;

	return;
}






