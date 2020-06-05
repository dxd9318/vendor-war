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
std::string Fighter::GetVendorName() { return vendorName; }

int Fighter::GetCurrentHealth() { return health; }

int Fighter::GetDamage() { return damage; }

int Fighter::GetAttacks() { return attacks; }

int Fighter::GetDodgePerc() { return dodgePerc; }

int Fighter::RollInitiative()
{
	// Modified getter
	// returns (initiative + random value from 1 to 20).
	int initModifier = rand() % 20;

	return (initiative + initModifier);
}


// Setters
void Fighter::SetHealth(int damageTaken) { health -= damageTaken; }

void Fighter::SetDefeated() { defeated = true; }


// Helpers
int Fighter::Attack(Fighter opponent)
{
	int damageDealt = 0;

	// Check opponent's dodge chance
	if (opponent.GetDodgePerc() >= (rand() % 20)) 
	{
		// Opponent successfully dodged this attack
		return damageDealt; // 0
	}

	damageDealt = damage;
	// Roll for crit chance
	if (critPerc >= (rand() % 20)) {
		// Fighter successfully crits!
		damageDealt *= 2;
	}

	// Final calculated damage for this turn
	return damageDealt;
}