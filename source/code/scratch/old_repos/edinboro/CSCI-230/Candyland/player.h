#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;



class PlayerT {
    public:
		//constructors
		PlayerT();

		//Debugging Tool
		void ShowMeEverything();

		//Observer Functions
		int GetAge();
		int GetPosition();
		string         GetName();

		//transformers
		void MovePlayer(int position);

		void CreatePlayer(int playerAge, string playerName);
		

    private:
		int age;
		int position;
		string         name;
};
#endif