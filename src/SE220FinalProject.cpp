//============================================================================
// Name        : SE220FinalProject.cpp
// Author      : Joshua Galbraith
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include "Creature.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // random number seed
	int round = 0; // round count
	Creature * a = new Creature(); // creates first creatur with no input
	a->print(); // prints first creatures stats
	cout << "VS\n\n"; //prints VS
	Creature * b = new Creature(); // creates second creature
	b->print(); // prints second creatures sats

	while ((a->getHealth() > 0) && (b->getHealth() > 0))
	{ // fight loop
		round ++; // incruments round number
		cout << "Round " << round << " FIGHT \n\n"; // prints round and fight
		int rn =  1 + (rand() % (int)(10 -1)); // random number for first creatures move selection
		cout << a->getName() << " will make his move ";
		if (rn >= 7)
		{
			a->isHealing = true; // sets is healing to true
			a->heal(); // first creature heal move
		}
		if ((rn <= 6) && (rn >=3))
		{
			a->punch(*b); // first creature punches second
		}
		if(rn <=2)
		{
			cout << a->getName() << " is set to dodge\n\n"; // prints to see creature set to dodge
			a->dodge(); // sets isDodging to true
		}

		int rnn =  1 + (rand() % (int)(10-1)); // random number for second creatures move selection
		cout << b->getName() << " will make his move "; // prints creaure name
		if (rnn >= 7)
		{
			b->isHealing = true; //sets is healing to true
			b->heal(); // calls heal method in creature class
		}
		if ((rnn <= 6) && (rnn >=3))
		{
			b->punch(*a); // set second creature to punch first
		}
		if(rnn <=2)
		{
			cout << b->getName() << " is set to dodge\n\n";
			b->dodge(); // sets is dodging to true
		}
		a->print(); // prints first creature stats after round is over
		b->print(); // prints second creature stats after round is over
	}

	cout << "It's over folks ";
	if(a->getHealth() > 0) // check if first creature wins
	{
		cout << a->getName() <<" is the winner!"; // prints if first creature wins
	}
	if(b->getHealth() > 0) // check if second creature is the winner
	{
		cout << b->getName() << " is the winner!"; // prints if second creature wins
	}
	delete a; // cleans first creature out
	delete b; // cleans second creature out
}
