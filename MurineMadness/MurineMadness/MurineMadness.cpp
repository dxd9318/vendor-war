// MurineMadness.cpp : This file contains the 'main' function.

#include "Fighter.h"
#include <fstream>
#include <vector>

int main()
{
    // File Input
    std::ifstream inFile;
    std::string line;

    std::cout << "LADIES AND GENTLEMEN, WELCOME TO MURINE MADNESS (not sponsored by Gnostech Inc.)\n\nPress enter to continue: ";
    std::cin.get();

    inFile.open("Assets/vendor_fighters.json");
    if (inFile.is_open()) 
    {
        std::cout << "\tFile opened successfully." << std::endl;
        // Instead of the following, I'd skip down the file to where the list of vendors starts, 
        // then read, parse, and save the properties of each vendor 'object' in the list. Then it's
        // a matter of feeding these parsed values into the Fighter constructor to create my Figher*
        // objects.

        /*
        std::cout << "\tPrinting out contents: " << std::endl;
        while (getline(inFile, line)) 
        {
            std::cout << line << std::endl;
        }
        */
        inFile.close();
    }
    else 
    {
        std::cout << "\tUnable to open file. Will use pre-set fighter roster." << std::endl;
    }


    // Vendors/fighters set up
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

    std::vector<Fighter*> fightersVector = {};
    fightersVector.push_back(f1);
    fightersVector.push_back(f2);
    fightersVector.push_back(f3);
    fightersVector.push_back(f4);
    fightersVector.push_back(f5);
    fightersVector.push_back(f6);
    fightersVector.push_back(f7);
    fightersVector.push_back(f8);
    fightersVector.push_back(f9);
    fightersVector.push_back(f10);

    //// Would want to store the following variables in a game manager class
    Fighter* fighterA = nullptr;
    Fighter* fighterB = nullptr;
    Fighter* tournamentWinner = nullptr;
    Fighter* matchWinner = nullptr;
    int numOfCurrentContestants = 0;
    int fighterIndex = -1;
    int defeatedCounter = 0;
    int matchCounter = 1, roundCounter = 1;
    int turnsTakenA = 0, turnsTakenB = 0, turnDamageA = 0, turnDamageB = 0;

    std::cout << "\n\nLEEEEEEETSGETREADYTORUMBLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLE\n\n";


    std::cout << "Press enter to continue: ";
    std::cin.get();
    
    // Executes each match of the tournament
    while (defeatedCounter < 9) 
    {
        std::cout << "And we'll ready for the next match!\n\n";
        // Clear out last match's fighter's set up
        fighterA = nullptr;
        fighterB = nullptr;
        numOfCurrentContestants = 0;

        // Selects next match's fighters
        while (numOfCurrentContestants < 2) 
        {
            // roll a number from 0-9
            fighterIndex = (rand() % 9);
            // Grab that number's fighter from the array
            // If that fighter's not yet defeated, and is not already listed as fighterA for this match
            if (fightersVector[fighterIndex]->GetCurrentHealth() > 0 && fightersVector[fighterIndex] != fighterA)
            {
                if (fighterA == nullptr) {
                    fighterA = fightersVector[fighterIndex];
                    numOfCurrentContestants++;
                }
                else {
                    fighterB = fightersVector[fighterIndex];
                    numOfCurrentContestants++;
                }
            }
        }

        // States current match number
        std::cout << "Match " << matchCounter << std::endl;
        // Lists stats of current two fighters
        std::cout << "Fighter 1: " << fighterA->GetVendorName() << "\n\tHealth: " << fighterA->GetCurrentHealth() << "\n\tDamage: " << fighterA->GetDamage() << "\n\tAttacks per Round: " << fighterA->GetAttacks() << "\n\n";
        std::cout << "Fighter 2: " << fighterB->GetVendorName() << "\n\tHealth: " << fighterB->GetCurrentHealth() << "\n\tDamage: " << fighterB->GetDamage() << "\n\tAttacks per Round: " << fighterB->GetAttacks() << "\n\n";

        std::cout << "Ring the bell! ";
        std::cin.get();
    
        // Executes each round of a match (while both fighters still have health left for the match)
        while (fighterA->GetCurrentHealth() > 0 && fighterB->GetCurrentHealth() > 0) 
        {
            // States current round number for the match
            std::cout << "~RIIING~ Round " << roundCounter << ", FIGHT!!!" << std::endl;
        
            // Executes sets of turns for a round (while both fighters still have health and turns left for the round)
            while (fighterA->GetCurrentHealth() > 0 && fighterB->GetCurrentHealth() > 0 && (turnsTakenA < fighterA->GetAttacks() || turnsTakenB < fighterB->GetAttacks()))
            {
                if (turnsTakenA < fighterA->GetAttacks()) 
                {
                    turnDamageA = fighterA->Attack(fighterB);
                    fighterB->SetHealth(turnDamageA);
                    std::cout << "\t" << fighterA->GetVendorName() << " hits " << fighterB->GetVendorName() << " for " << turnDamageA << " damage. " << fighterB->GetVendorName() << "'s remaining Health: " << fighterB->GetCurrentHealth() << "\n\n";
                    // if A knocks out B before end of round, set A as winner and break out of this loop level
                    if (fighterB->GetCurrentHealth() <= 0) 
                    {
                        matchWinner = fighterA;
                        continue;
                    }
                    turnsTakenA++;
                }

                if (turnsTakenB < fighterB->GetAttacks()) 
                {
                    turnDamageB = fighterB->Attack(fighterA);
                    fighterA->SetHealth(turnDamageB);
                    std::cout << "\t" << fighterB->GetVendorName() << " hits " << fighterA->GetVendorName() << " for " << turnDamageB << " damage. " << fighterA->GetVendorName() << "'s remaining Health: " << fighterA->GetCurrentHealth() << "\n\n";
                    // if B knocks out A, set B as winner
                    if (fighterA->GetCurrentHealth() <= 0)
                    {
                        matchWinner = fighterB;
                    }
                    turnsTakenB++;
                }
            }
            std::cout << "End of round " << roundCounter << "\n\n";
            turnsTakenA = 0;
            turnsTakenB = 0;
            roundCounter++;

            std::cout << "Ring the bell! ";
            std::cin.get();
        }

        std::cout << "~DING~DING~DING~ WE HAVE A WINNER! THE WINNER OF MATCH " << matchCounter << " IS: " << matchWinner->GetVendorName() << "!! CONGRATULATIONS!!" << std::endl;
        if (matchCounter == 8) 
        {
            tournamentWinner = matchWinner;
            std::cout << "COOOOOOOOOOOOONGRATULATIONS " << tournamentWinner->GetVendorName() << "! YOU ARE THIS YEAR'S MURINE MADNESS TOURNAMENT WINNER!!!" << std::endl;
            break;
        }

        // Updates tracker values for the next match
        matchWinner = nullptr;
        roundCounter = 1;
        defeatedCounter++;
        matchCounter++;

        std::cout << "Press enter to continue: ";
        std::cin.get();
    }

    //// Initiative checking
    //int contestant1Init = f1->RollInitiative();
    //int contestant2Init = f2->RollInitiative();
    //std::cout << "Fighter 1 (" << f1->GetVendorName() << ")'s Initiative Roll: " << f1->RollInitiative() << std::endl;



    // Deallocate and prevent memory leaks
    fighterA = nullptr;
    //delete fighterA;

    fighterB = nullptr;
    //delete fighterB;

    tournamentWinner = nullptr;
    //delete tournamentWinner;

    matchWinner = nullptr;
    //delete matchWinner;

    delete f1;
    f1 = nullptr;

    delete f2;
    f2 = nullptr;

    delete f3;
    f3 = nullptr;

    delete f4;
    f4 = nullptr;

    delete f5;
    f5 = nullptr;

    delete f6;
    f6 = nullptr;

    delete f7;
    f7 = nullptr;

    delete f8;
    f8 = nullptr;

    delete f9;
    f9 = nullptr;

    delete f10;
    f10 = nullptr;

    fightersVector.clear();
}

