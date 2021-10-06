#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include "card.h"




class DeckT {
    public:

		static const int MAX_CARDS = 70;

		DeckT();
		
		//Debugging Tool
		void ShowMeEverything();

		//transformers
		void CreateCard(int index, string name, int position);
		void FillInCards();
		
		void Shuffle(void);
			void Mix(CardT cards[MAX_CARDS]);
			void Swap(CardT & a, CardT & b);
		void DiscardACard(void);

		//observers
		CardT DrawACard(void);
		
    private:
		CardT cards[MAX_CARDS];
 		int topCard;
};
#endif

