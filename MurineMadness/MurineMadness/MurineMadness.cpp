// MurineMadness.cpp : This file contains the 'main' function.
//

#include <iostream>
#include "Fighter.h"

int main()
{
    // Vendor Fighters set up
    //// would want to put these all in an array, sort them by initiative, then pair them off March Madness style
    Fighter* f1 = new Fighter("Panasonic", 136, 6, 4, 10, 10, 4);
    Fighter* f2 = new Fighter("Dell", 110, 4, 5, 12, 12, 5);
    Fighter* f3 = new Fighter("Getac", 175, 8, 3, 2, 8, 3);
    Fighter* f4 = new Fighter("HP", 112, 2, 8, 4, 16, 2);
    Fighter* f5 = new Fighter("Gateway", 108, 7, 4, 12, 18, 4);
    Fighter* f6 = new Fighter("Apple", 220, 12, 2, 4, 10, 2);
    Fighter* f7 = new Fighter("Asus", 116, 4, 6, 14, 14, 6);
    Fighter* f8 = new Fighter("Lenovo", 96, 16, 2, 16, 15, 6);
    Fighter* f9 = new Fighter("Toshiba", 280, 24, 1, 0, 0, 0);
    Fighter* f10 = new Fighter("Acer", 124, 6, 4, 8, 12, 4);

    //// would want to store the following members in some sort of game manager class
    int defeatedCounter = 0;
    int roundCounter = 0;


    std::cout << "LEEEEEEETSGETREADYTORUMBLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLE\n\n";

    std::cout << "Fighter 1: " << f1->GetVendorName() << "\n\tHealth: " << f1->GetCurrentHealth() << "\n\tDamage: " << f1->GetDamage() << "\n\tAttacks per Round: " << f1->GetAttacks() << "\n\n";
    std::cout << "Fighter 2: " << f2->GetVendorName() << "\n\tHealth: " << f2->GetCurrentHealth() << "\n\tDamage: " << f2->GetDamage() << "\n\tAttacks per Round: " << f2->GetAttacks() << "\n\n";

    // Initiative checking
    /*int contestant1Init = f1->RollInitiative();
    int contestant2Init = f2->RollInitiative();

    std::cout << "Fighter 1 (" << f1->GetVendorName() << ")'s Initiative Roll: " << f1->RollInitiative() << std::endl;*/

    //int turnsTaken = 0;
    //while (f1->GetCurrentHealth() > 0 || f2->GetCurrentHealth() > 0 || turnsTaken < (f1->GetAttacks() + f2->GetAttacks())) 
    //{
        int damageTaken = f1->Attack(f2);
        f2->SetHealth(damageTaken);
        std::cout << "Fighter 1 hits Fighter 2 for " << damageTaken << " damage. Fighter 2's remaining Health: " << f2->GetCurrentHealth() << std::endl;
    //}

    //// Loop until there is one winner left
    
    //while (defeatedCounter < 9)
    //{
    //    


    //    //whenever a fighter is defeated, set fighter's defeated to true, then increment defeatedCounter by 1.
    //}

    // Deallocate and prevent memory leaks
    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete f5;
    delete f6;
    delete f7;
    delete f8;
    delete f9;
    delete f10;
}

