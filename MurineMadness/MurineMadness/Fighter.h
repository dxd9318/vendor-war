#ifndef FIGHTER__H
#define FIGHTER__H
#pragma once		//supported by VS but not standard.

#include <string>
//#include "json/json.h"
#include <stdlib.h> // supports random
#include <time.h>	// provides seeding for random

class Fighter 
{
public:
	// Constructor
	Fighter();
	// Destructor
	~Fighter();


	// Getters
	std::string GetVendorName();
	int GetCurrentHealth();
	int GetDamage();
	int GetAttacks();	// For calculating number of turns in rounds

	// Setters
	void UpdateHealth();	// do i incorporate dodge here?
	void MarkDefeated();

	// Actions
	int RollInitiative();	// returns (initiative + random value from 1 to 20).
	int Attack();	// Damage (+ Damage if roll higher than critPerc)
private:

	// Has this vendor/fighter lost?
	bool defeated;

	// Stats
	std::string vendorName;
	int health;
	int damage;
	int attacks;
	int dodgePerc;
	int critPerc;
	int initiative;
	
};
#endif FIGHTER__H
