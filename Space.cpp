//
//  Space.cpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#include "Space.hpp"

Space::Space()
{
    type = "";
    message = "";
    amount = 0;
}

Space::Space(string myType, string myMessage, int myAmount)
{
    type = myType;
    message = myMessage;
    amount = myAmount;
}

string Space::getType() const
{
    return type;
}

string Space::getMessage() const
{
    return message;
}

int Space::getAmount() const
{
    return amount;
}


