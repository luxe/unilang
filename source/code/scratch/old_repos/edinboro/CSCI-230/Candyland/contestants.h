#ifndef CONTESTANTS_H
#define CONTESTANTS_H

#include "player.h"
class ContestantsT {
    public:
		
		static const int MAX_PLAYERS = 20;

		ContestantsT();
		
		//Debugging Tool
		void ShowMeEverything();

		//Observer Functions
		int GetAge();
		int GetPosition();
		string         GetName();

		//Transformers
		void CreatePlayer(int position, int playerAge, string playerName);
		void Sort();
		void SelectionSort(PlayerT contestants[]);
			void Swap(PlayerT & a, PlayerT & b);
		void MovePlayer(int charPosition);
		void ChangePlayer();


    private:
		PlayerT contestants[MAX_PLAYERS];
		int currentPlayer;

};




#endif