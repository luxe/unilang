#include "deck.h"

void DeckT::ShowMeEverything(){

	for (int i = 0; i < MAX_CARDS; i++){
		cards[i].ShowMeEverything();
	}
	
	return;
}

DeckT::DeckT(){
	topCard = 0;

	return;
}

//transformers
void DeckT::CreateCard(int index, string name, int position){

	cards[index].CreateCard(name, position);
	
	return;
}

void DeckT::FillInCards(){

	ColorT currentColor = RED;
	int colorIteration = 0;
	for (int i = 1; colorIteration < colorCount; i++){
		
		//single color cards
		for (int amount = 0; amount < 8; i++, amount++){
			if (cards[i].GetColor() != PINK){
				cards[i].BuildColorCard(currentColor, 1);
			}
			else{
				amount--;
				}
			}
		
		//double color cards
		for (int amount = 0; amount < 2; i++, amount++){
			if (cards[i].GetColor() != PINK){
				cards[i].BuildColorCard(currentColor, 2);
			}
			else{
				amount--;
			}
		}
		currentColor = ColorT(currentColor+1);
		colorIteration++; i--;
	}

	return;
}
	

void DeckT::Shuffle(void){

 	Mix(cards);

	return;
}

void DeckT::Mix(CardT cards[MAX_CARDS]){

	int swapPos;

    for(int i=0;i<MAX_CARDS;i++) {
		swapPos = rand() % MAX_CARDS;
        Swap(cards[i], cards[swapPos]);
    }

	return;
}

void DeckT::Swap(CardT & a, CardT & b){

	CardT tmp;

    tmp =a;
    a = b;
    b = tmp;
	
    return;
}

void DeckT::DiscardACard(void){

	return;
}

//observers
CardT DeckT::DrawACard(void){

	CardT card;
	
	if (topCard > MAX_CARDS){
		Shuffle();
		topCard = 0;
	}
	
	card = cards[topCard];
	
	
	while(card.GetColor() == NO_COLOR){
		
		topCard++;
		if (topCard > MAX_CARDS){
			Shuffle();
			topCard = 0;
		}
		card = cards[topCard];
		
	}
	topCard++;

	return card;

}