/*
 * Creature.h
 *
 *  Created on: Jun 23, 2016
 *      Author: soaler
 */
#include <array>
#include <string>

#ifndef CREATURE_H_
#define CREATURE_H_


class Creature
{
public:
	Creature(); // constructor

	void setName( std::string ); // set Name
	std::string getName() const; // get Name

	void setHealth( int ); // set Health
	int getHealth() const; // get Health

	void setAttack( int ); // set Attack
	int getAttack() const; // get Attack

	void setDefense( int ); // set Defense
	int getDefense() const; // get Defense

	void setRegen( int ); // set Regen
	int getRegen() const; // get Regen

	void print();//print creature method
	void punch(Creature &) const; // punch method
	void dodge(); // dodge method
	void heal(); // deal method
	bool isDodging; // is dodging variable
	bool isHealing; // is healing variable

private: // private variables
	std::string name;
	int health;
	int attack;
	int defense;
	int regen;
	int maxHealth;
	std::array< std::string, 5>fn;
	std::array< std::string, 5>ln;
};

#endif /* CREATURE_H_ */
