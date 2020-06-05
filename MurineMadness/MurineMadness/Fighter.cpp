#include "Fighter.h"

// Constructor
Fighter::Fighter() 
{
	// read in data from json file
	// populate stats with file data

	// start the seed for random
}
// Destructor
Fighter::~Fighter() 
{

}

// Getters
std::string Fighter::GetVendorName() { return vendorName; }
int Fighter::GetCurrentHealth() { return health; }
int Fighter::GetDamage() { return damage; }
int Fighter::GetAttacks() { return attacks; }	// For calculating number of turns in rounds

// Setters
void Fighter::UpdateHealth() 
{
	// do i incorporate dodge here?

}	
void Fighter::MarkDefeated() { defeated = true; }

// Actions
int Fighter::RollInitiative() 
{
	// returns (initiative + random value from 1 to 20).



}	
int Fighter::Attack() 
{
	// Damage (+ Damage if roll higher than critPerc)

}	