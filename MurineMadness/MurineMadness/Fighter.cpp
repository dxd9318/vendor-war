#include "Fighter.h"

// Constructor
Fighter::Fighter(std::string vName, int hp, int dmg, int ap, int dp, int cp, int init)
{
	// read in data from json file
	// populate stats with file data

	/* Note to code reviewers:
		// My research has pointed me to use the jsoncpp library for this, but unfortunately I haven't
		// had successing trying to install it following these and other instructions I've googled
		// https://github.com/open-source-parsers/jsoncpp

		// Due to time constraints I will be hardcoding the values from the provided json file.
	*/

	vendorName = vName;
	health = hp;
	damage = dmg;
	attacks = ap;

	dodgePerc = dp;
	critPerc = cp;
	initiative = init;

	// start the seed for random
	srand(time(NULL));
}


// Destructor
Fighter::~Fighter()
{
	// Didn't allocate new data on the heap, nothing to manually deallocate yet
}


// Getters
// Returns the name of the current vendor/fighter.
std::string Fighter::GetVendorName() { return vendorName; }

// Returns the current health of the current vendor/fighter.
int Fighter::GetCurrentHealth() { return health; }

// Returns the damage value the current vendor/fighter deals per turn.
int Fighter::GetDamage() { return damage; }

// Returns the number of attacks/turns the current vendor/fighter can deal per round.
int Fighter::GetAttacks() { return attacks; }

// Returns the dodge chance of the current vendor/fighter.
int Fighter::GetDodgePerc() { return dodgePerc; }

// Modified getter
// Returns the current initiative value of the current vendor/fighter for the round.
int Fighter::RollInitiative()
{
	int initModifier = rand() % 20;

	return (initiative + initModifier);
}


// Setters
// Updates the current health of the current vendor/fighter by subtracting the damage dealt by the opponent. If health falls to or below zero, vendor/fighter becomes marked as defeated.
void Fighter::SetHealth(int damageTaken) 
{ 
	health -= damageTaken; 

	if (health <= 0) 
	{
		SetDefeated();
		std::cout << "\t-- AND IT'S A KNOCKOUT!!" << std::endl;
	}
}

// Marks the current vendor/fighter as defeated.
void Fighter::SetDefeated() { defeated = true; }


// Helpers
// Takes the current vendor/fighter's opponent and returns the damage dealt to them, accounting for chances of the attacker critting or the opponent dodging.
int Fighter::Attack(Fighter* opponent)
{
	int damageDealt = 0;

	// Check opponent's dodge chance
	if (opponent->GetDodgePerc() >= (rand() % 20)) 
	{
		// Opponent successfully dodged this attack
		std::cout << "\t" << GetVendorName() << " tried to attack, but it was DODGED by " << opponent->GetVendorName() << "!" << std::endl;
		return damageDealt; // 0
	}

	damageDealt = damage;
	// Roll for crit chance
	if (critPerc >= (rand() % 20)) {
		// Fighter successfully crits!
		std::cout << "\tCRITICAL HIT by " << GetVendorName() << "!" << std::endl;
		damageDealt *= 2;
	}

	// Final calculated damage for this turn
	return damageDealt;
}