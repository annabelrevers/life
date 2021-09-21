//
//  Player.hpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    int position;
    int sallary;
    int savings;
    int lifeCards;
    string career;
    string house;
    bool married;
    bool homeowner;
    bool reachedEnd;
public:
    // constructors
    Player();
    Player(int pos);
    // set methods
    void setPosition(int myPos);
    void setSallary();
    void setCards();
    void setCareer();
    void setHouse();
    void setMarried();
    void setHome();
    void setFinished();
    // get methods
    int getPosition() const;
    int getSallary() const;
    int getSavings() const;
    int getCards() const;
    string getCareer() const;
    string getHouse() const;
    bool getMarried() const;
    bool getHome() const;
    bool finished() const;
    // overloaded operators
    void operator += (int amount);
};
