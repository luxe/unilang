#ifndef BOARD_SPACE_H
#define BOARD_SPACE_H

#include <string>
#include <iostream>
#include "candyland_colors.h"

using std::string;
using std::cout;
using std::endl;

enum SpaceAttributeT{NOTHING, CHARACTER, PENALTY, SHORTCUT};

class BoardSpaceT{
	public:
		
		//Debugging Tool
		void ShowMeEverything(void);

		//Constructers
		BoardSpaceT(); //empty space

		//transformers
		void CreateBoardSpace(SpaceAttributeT spaceAttribute, string name);
		void CreateBoardSpace(int endPosition, string name);
		void ChangeColor(ColorT newColor);
		
		//observers
		ColorT          GetColor();
		SpaceAttributeT GetSpaceAttribute();
		int             GetEndPosition();
		string          GetName();
		
		string ConvertColorToString(ColorT color);
		string ConvertSpaceAttributeToString(SpaceAttributeT spaceAttribute);

	private:
		ColorT color;
		SpaceAttributeT spaceAttribute;
		int endPosition; //for shortcut spaces
		string name;
	};


#endif