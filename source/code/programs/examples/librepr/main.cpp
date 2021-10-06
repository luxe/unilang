//this only works if you build it in debug mode
#include <iostream>
#include "librepr.hpp"

using librepr::repr;

enum class Suit { Clubs, Diamonds, Hearts, Spades };
enum class Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

struct CardBase
{
    int foo = 5;
};

struct Card : CardBase
{
    Suit suit;
    Rank rank;
    double bar = 3.14;
};

int main()
{
    Card c;
    c.suit = Suit::Spades;
    c.rank = Rank::Ace;

    // prints "{.foo=5, .suit=Suit::Spades, .rank=Rank::Ace, .bar=3.14}"
    std::cout << repr(c) << "\n";
};