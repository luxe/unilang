#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "board_space.h"

using std::string;



class BoardT {
    public:
		static const int MAX_SPACES = 200;
		static const int MAX_CHARACTERS = 10;

		//Debugging Tool
		void ShowMeEverything(void);

		//Constructers
		BoardT();

		//transformers
		void CreateBoardSpace(int position, SpaceAttributeT spaceAttribute, string name);
		void CreateBoardSpace(int position, int endPosition, string name);
		void FillInColors();

		//observers
		BoardSpaceT GetBoardSpace(int space);
		ColorT GetColor(int space);
		
    private:
		BoardSpaceT candyPath [MAX_SPACES];  //an array of space enums
};
#endif