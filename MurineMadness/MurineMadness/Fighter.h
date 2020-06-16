#ifndef FIGHTER__H
#define FIGHTER__H
#pragma once		//supported by VS but not standard.

#include <string>
//#include "json/json.h"
#include <iostream>
#include <stdlib.h> // supports random
#include <time.h>	// provides seeding for random

class Fighter
{
public:
	// Constructor
	Fighter(std::string vName, int hp, int dmg, int ap, int dp, int cp, int init);
	// Destructor
	~Fighter();

	/// Getters
	// Returns the name of the current vendor/fighter.
	std::string GetVendorName();
	// Returns the current health of the current vendor/fighter.
	int GetCurrentHealth();
	// Returns the damage value the current vendor/fighter deals per turn.
	int GetDamage();
	// Returns the number of attacks/turns the current vendor/fighter can deal per round.
	int GetAttacks();
	// Returns the dodge chance of the current vendor/fighter.
	int GetDodgePerc();

	/// Modified getter
	// Returns the current initiative value of the current vendor/fighter for the round.
	int RollInitiative();

	/// Setters
	// Updates the current health of the current vendor/fighter by subtracting the damage dealt by the opponent. If health falls to or below zero, vendor/fighter becomes marked as defeated.
	void SetHealth(int damageTaken);
	// Marks the current vendor/fighter as defeated.
	void SetDefeated();

	/// Helpers
	// Takes the current fighter's opponent and returns the damage dealt to them, accounting for chances of the attacker critting or the opponent dodging.
	int Attack(Fighter* opponent);
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
