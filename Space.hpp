//
//  Space.hpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Space
{
private:
    string type;
    string message;
    int amount;
public:
    // constructors
    Space();
    Space(string myType, string myMessage, int myAmount);
    // methods
    string getType() const;
    string getMessage() const;
    int getAmount() const;
};
