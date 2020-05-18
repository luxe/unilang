#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include "candyland_colors.h"

using std::string;
using std::cout;
using std::endl;


class CardT {
    public:
		static const int MAX_SPACES = 200;

		//Debugging Tool
		void ShowMeEverything(void);

		//Constructors
		CardT(); //empty card
		
		//transformers
		void CreateCard(string name, int position);
 		void BuildColorCard(ColorT currentColor, int count);

		//observers
		ColorT GetColor(void);
		int GetColorCount(void);
		string GetName(void);
		int GetPosition(void);

		string ConvertColorToString(ColorT color);

    private:
		ColorT color;
		int colorCount;
		string name;
		int position;
};


#endif