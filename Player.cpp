//
//  Player.cpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#include "Player.hpp"

Player::Player()
{
    position = 0;
    sallary = 0;
    savings = 0;
    lifeCards = 0;
    career = "";
    house = "";
    married = false;
    homeowner = false;
    reachedEnd = false;
}

Player::Player(int pos)
{
    position = pos;
    sallary = 0;
    savings = 0;
    lifeCards = 0;
    career = "";
    house = "";
    married = false;
    homeowner = false;
    reachedEnd = false;
}
void Player::setPosition(int myPos)
{
    position = myPos;
}

void Player::setSallary()
{
     int number = rand() % 3;    // random number between 0 and 9
    
     if (career == "Doctor" || career == "Professional Athlete" || career == "Lawyer" || "Financial Analyst")
     {
         vector<int> sallaries {100000, 120000, 150000, 200000};
         sallary = sallaries[number];
     }
     if (career == "Accountant" || career == "Software Engineer" || career == "Teacher" || career == "Musician")
     {
         vector<int> sallaries {60000, 80000, 95000, 120000};
         sallary = sallaries[number];
     }
         
     if (career == "Artist" || career == "Teacher" || career == "Salesperson" || career == "Carpenter")
     {
         vector<int> sallaries {40000, 60000, 70000, 80000};
         sallary = sallaries[number];
     }
}

void Player::setCards()
{
    lifeCards += 1;
}

void Player::setCareer()
{
    // display cards
    cout << endl;
    cout << "* * *   * * *   * * *   * * *   * * *   * * *" << endl;
    cout << "* 1 *   * 2 *   * 3 *   * 4 *   * 5 *   * 6 *" << endl;
    cout << "* * *   * * *   * * *   * * *   * * *   * * *" << endl;
    cout << endl;
    cout << "* * *   * * *   * * *   * * *   * * *   * * *" << endl;
    cout << "* 7 *   * 8 *   * 9 *   *10 *   *11 *   *12 *" << endl;
    cout << "* * *   * * *   * * *   * * *   * * *   * * *" << endl;
    cout << endl;
    
    // get card choice from user
    cout << "Choose your career card: ";
    int card;
    cin >> card;
    
    // intialize careers vector and add options
    vector<string> careers {"Professional Athlete", "Doctor", "Accountant", "Lawyer", "Software Engineer", "Accountant", "Artist", "Teacher", "Salesperson", "Musician", "Carpenter", "Financial Analyst"};

    career = careers[card-1];
}

void Player::setHouse()
{
    // display cards
    cout << endl;
    cout << "* * *   * * *   * * *   * * *   * * *" << endl;
    cout << "* 1 *   * 2 *   * 3 *   * 4 *   * 5 *" << endl;
    cout << "* * *   * * *   * * *   * * *   * * *" << endl;
    cout << endl;
    cout << "* * *   * * *   * * *   * * *   * * *" << endl;
    cout << "* 6 *   * 7 *   * 8 *   * 9 *   *10 *" << endl;
    cout << "* * *   * * *   * * *   * * *   * * *" << endl;
    cout << endl;
    
    // get card choice from user
    cout << "Choose a house card: ";
    int card;
    cin >> card;
    cout << "Chose another house card: ";
    int card2;
    cin >> card2;
    
    // intialize careers vector and add options
    string beach = "Beach House: only 50 yards from Monsoon Beach, Sun deck, boat dock, hurricane wall. $400,000.";
    string farmhouse = "Farm House: located on 50 rolling acres! Spacious barn with prizewinning dairy cows. $300,000.";
    string colonial = "Dutch Colonial: 8 spacious bedrooms with a study and den. Solid oak floors. $600,000.";
    string cabin = "Log Cabin: rustic charm in a woodland setting. Loft with skylight, stone fireplace. $150,000.";
    string split = "Split-Level: was one level before the 'quake. Now a real fixer-upper for adventurous folks! $70,000.";
    string mobile = "Mobile Home: aluminum-sided little beauty! Great location, lovely view. Trailed hitch included. $100,000.";
    string victorian = "Victorian: library, parlor, servants' quarters, marble floors and wraparound porch. $800,000.";
    string condo = "Cozy Condo: this two level condonminium comes plete with a gourmet kitchen and rooftop garden. $200,000.";
    string tudor = "Tudor: tufloors, tubaths, tucar garage. Perfect for tupeople with tukids or more! $600,000.";
    string apartment = "High-Rise Apartment: located on the fiftieth floor. Brand new two bedroom, view of the city park. $220,000.";
    
    vector<string> houses {beach, farmhouse, colonial, cabin, split, mobile, victorian, condo, tudor, apartment};
    vector<int> prices {400000, 300000, 600000, 150000, 70000, 100000, 800000, 200000, 600000, 220000};
    
    string option1 = houses[card-1];
    string option2 = houses[card2-1];
    
    cout << "Your two options are. . ." << endl;
    cout << endl;
    cout << "1. " << option1 << endl;
    cout << "2. " << option2 << endl;
    cout << endl;
    cout << "Enter the number of your choice: ";
    int choice;
    cin >> choice;
    
    if (choice == 1)
    {
        house = option1;
        savings -= prices[card-1];
    }
    else
    {
        house = option2;
        savings -= prices[card2-1];
    }
}

void Player::setMarried()
{
    married = true;
}

void Player::setHome()
{
    homeowner = true;
}

void Player::setFinished()
{
    reachedEnd = true;
}

int Player::getPosition() const
{
    return position;
}

int Player::getSallary() const
{
    return sallary;
}

int Player::getSavings() const
{
    return savings;
}

int Player::getCards() const
{
    return lifeCards;
}

string Player::getCareer() const
{
    return career;
}

string Player::getHouse() const
{
    return house;
}

bool Player::getMarried() const
{
    return married;
}

bool Player::getHome() const
{
    return homeowner;
}

bool Player::finished() const
{
    return reachedEnd;
}

void Player::operator += (int amount)     // increase a Player's savings with an int
{
    savings += amount;
}
