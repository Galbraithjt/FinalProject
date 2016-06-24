/*
 * Creature.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: soaler
 */

#include "Creature.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

Creature::Creature()
{
	string fn[5] = {"Bruce", "Clark", "Wade", "Peter", "Tony"}; // array of possible first names
	string ln[5] = {"Wayne", "Kent", "Wilson", "Parker", "Stark"}; // array of possible last names
	string first = fn[0 + (rand() % (int)(5))]; // random first name
	string last = ln[0 + (rand() % (int)(5))]; // random second name
	string n = first + " "+ last; // first and second name put together for full name
	setName (n); // name is set
	int h = 10 + (rand() % (int)(30 - 11)); // random number 10 to 30 for health
	setHealth(h); // health is set
	int a = 10 + (rand() % (int)(20 - 11)); // random number 10 to 20 for attack
	setAttack (a); // attack is set
	int d = 5 + (rand() % (int)(10 - 6)); // random number 5 to 10 for defense
	setDefense (d); // defense is set
	int r = 5 + (rand() % (int)(15 - 6)); // random number 5 to 15 for regen
	setRegen (r); // regen set
	isDodging = false; // is dodging set to false
	isHealing = false; // is healing set to false
	int maxHealth= 0;
}
////////////////////////////////Setters and Getters/////////////////////////////////
void Creature::setName(string n)
{
	name = n;
}

string Creature::getName() const
{
	return name;
}

void Creature::setHealth(int h)
{
	if ((h >= 10)&&(h <= 30)) // bounds check
	{
		health = h;
		maxHealth = h;
	}
	else
	{
		throw invalid_argument("Health must be between 10 and 30"); // bounds check error
	}
}

int Creature::getHealth() const
{
	return health;
}

void Creature::setAttack(int a)
{
	if ((a >= 10)&&(a <= 20)) // bounds check
	{
		attack = a;
	}
	else
	{
		throw invalid_argument("Attack must be between 10 and 20"); // bounds check error
	}
}

int Creature::getAttack() const
{
	return attack;
}

void Creature::setDefense(int d)
{
	if ((d >= 5)&&(d <= 10)) // bounds check
	{
		defense = d;
	}
	else
	{
		throw invalid_argument("Defense must be between 5 and 10"); // bounds check error
	}
}

int Creature::getDefense() const
{
	return defense;
}

void Creature::setRegen(int r)
{
	if ((r >= 5)&&(r <= 15)) // bounds check
	{
		regen = r;
	}
	else
	{
		throw invalid_argument("Regen must be between 5 and 15"); // bounds check error
	}
}

int Creature::getRegen() const
{
	return regen;
}

void Creature::punch(Creature &enemy) const // punch method
{
	cout << name <<" Has Thown A Punch"<< endl;
	if (enemy.isDodging == false) // enemy dodge check
	{
		if(enemy.health > enemy.health - this->attack + enemy.defense) //healing punch check
		{
			enemy.health = enemy.health - this->attack + enemy.defense; //subtracts hit for enemy's health
			cout << enemy.name << " has been hit thats -" << this->attack <<
					" off his Health" << endl << endl;;
		}
	}

	if (enemy.isDodging == true) // enemy dodge check
	{
		cout << "Punch dodged by " << enemy.name << endl << endl; // prints punch dodged
		enemy.isDodging = false; // sets is dodging back to false
	}
}

void Creature::dodge() // dodge method
{
		isDodging = true; // sets is dodging to true
}

void Creature::heal() // heal method
{
	if (isHealing == true) // checks if is healing is true
	{
		cout << " Has Healed\n\n";
		if(this->maxHealth > this->health + this->regen) // heal check
		{
			this->health = this->health + this->regen; // heals if under max
		}
		else
		{
			this->health = this->maxHealth; // sets to max if heal would put health over max
		}
		isHealing = false; // sets is healing to false
	}
}

void Creature::print() // method for printing creature current stats
{
	cout << "Name is: " << name << "\n"
			<< "Health is: " << health << "\n"
			<< "Attack is: " << attack << "\n"
			<< "Defense is: " << defense << "\n"
			<< "Regen is: " << regen << "\n\n";
}
