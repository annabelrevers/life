//
//  Life.hpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#pragma once

#include "Player.hpp"
#include "Space.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int boardSize();
Space * buildBoard(const int SIZE);
int spinWheel();
string chooseCareer();
string chooseHouse();
void displayIntro();
void playLife();
Player * getPlayers(int numPlayers);


