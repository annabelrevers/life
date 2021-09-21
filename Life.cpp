//
//  Life.cpp
//  FinalProject
//
//  Created by Annie Revers on 8/3/20.
//  Copyright © 2020 Annie Revers. All rights reserved.
//

#include "Life.hpp"

// get size of board by counting lines in file
int boardSize()
{
    // get file
    ifstream inFile("/Users/annie/Desktop/CS 38/FinalProject/TestBoard.txt");
    
    // check if file opened successfully
    if (inFile.fail())
    {
        cout << "Unable to open file." << endl;
        exit(1);
    }
    
    // read file
    string line;
    int lineCount = 0;
    
    while (!inFile.eof())
    {
        getline(inFile, line);
        lineCount++;
    }
    
    inFile.close();

    return lineCount;
}

// build board with one Space for each line in the file
Space * buildBoard(const int SIZE)
{
    // get file
    ifstream inFile("/Users/annie/Desktop/CS 38/FinalProject/TestBoard.txt");

    // check if file opened successfully
    if (inFile.fail())
    {
        cout << "Unable to open file." << endl;
        exit(1);
    }

    // read file
    string line;
    int i = 0;

    // dynamicly allocate memory for board
    Space * board = new Space[SIZE];
    if (! board) exit(-1);
    
    // add each line of file as Space to board
    while (!inFile.eof())
    {
        getline(inFile, line);
        istringstream lineStream(line);
        
        string type;
        string message;
        int amount = 0;
        
        lineStream >> type;

        // check if line is a Pay Day space
        if (type == "P")
        {
            message = "Pay Day!";
        }
        
        // check if line is an event space
        if (type == "E")
        {
            lineStream >> amount;
            amount = amount * 1000;
            while (!lineStream.eof())
            {
                string add;
                lineStream >> add;
                message += add + " ";
            }

        }
        // check if line is LIFE tile space
        if (type == "L")
        {
            while (!lineStream.eof())
            {
                string add;
                lineStream >> add;
                message += add + " ";
            }
        }
        // check if space is marriage space
        if (type == "M")
        {
            message = "STOP. Get married! Collect a LIFE tile.";
        }
        // check is space is house space
        if (type == "H")
        {
            message = "STOP. You may buy a house. Choose a deed.";
        }
        // check is space is start a new career
        if (type == "C")
        {
            message = "Lose your job. Start a new career.";
        }
        
        Space *mySpace;      // create Space
        mySpace = new Space(type, message, amount);
        board[i] = *mySpace;     // add Space to array
        i++;
    }
    
    // close file
    inFile.close();

    // return pointer to board
    return board;
}

// returns number between 1 and 8 to simulate spinning wheel
void spinWheel(Player * myPlayer)
{
    cout << endl;
    cout << "Enter 0 to spin the wheel: ";      // prompt user to spin
    int getSpin;
    cin >> getSpin;
    
    // randomly generate wheel spin
    int spin = rand() % 9 + 1;     // random number between 1-8
    
    cout << endl;
    cout << "Your spin: " << spin << endl;
    int currPosition = myPlayer->getPosition() + spin;
    myPlayer->setPosition(currPosition);
}

// displays introduction
void displayIntro()
{
    cout << "Welcome to the Game of" << endl;
    cout << endl;
    cout << "*          *    * * * *    * * * *" << endl;
    cout << "*          *    *          *      " << endl;
    cout << "*          *    * * * *    * * *  " << endl;
    cout << "*          *    *          *      " << endl;
    cout << "* * * *    *    *          * * * *" << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
}

// creates list of Players
Player * getPlayers(int numPlayers)
{
    // dynamically allocate array of Player objects
    Player * players;
    players = new Player[numPlayers];
    if (! players) exit(-1);

    for (int i=0; i<numPlayers; i++)
    {
        Player *myPlayer;
        myPlayer = new Player(0);
        players[i] = *myPlayer;
    }

    return players;
}

// allows Player to choose one of twelve careers and randomly generates a sallary
void chooseCareer(Player * myPlayer)
{
    myPlayer->setCareer();
    myPlayer->setSallary();
    cout << endl;
    cout << "You are: " << myPlayer->getCareer() << " with a sallary of $" << myPlayer->getSallary() << endl;
}

// performs action based on type of space that Player lands on
void handleSpace(Player * myPlayer, string type, int amount)
{
    if (type == "P")
    {
        *myPlayer += myPlayer->getSallary();
        cout << endl;
        cout << "You now have $" << myPlayer->getSavings() << " saved." << endl;
    }

    if (type == "E")
    {
        *myPlayer += amount;
        cout << endl;
        cout << "You now have $" << myPlayer->getSavings() << " saved." << endl;
    }

    if (type == "L")
    {
        myPlayer->setCards();
        cout << endl;
        cout << "You now have " << myPlayer->getCards() << " LIFE tiles." << endl;
    }

    if (type == "M")
    {   cout << endl;
        cout << "Enter the name of your partner: ";
        string name;
        cin >> name;
        cout << endl;
        cout << "You are now married to " << name << endl;
        myPlayer->setMarried();
        myPlayer->setCards();

    }

    if (type == "H")
    {
        myPlayer->setHouse();
        myPlayer->setHome();
        cout << endl;
        cout << "Your house: " << myPlayer->getHouse() << endl;
        cout << "You now have $" << myPlayer->getSavings() << " saved." << endl;
    }

    if (type == "C")
    {
        chooseCareer(myPlayer);
    }
}

// checks if player has passed STOP point; resets their position to the STOP point if so
void checkStop(Player * myPlayer)
{
    if (myPlayer->getPosition()>11 && myPlayer->getPosition()<19 && !myPlayer->getMarried())
    {
        myPlayer->setPosition(11);
    }
    if (myPlayer->getPosition()>19 && !myPlayer->getHome())
    {
        myPlayer->setPosition(19);
    }
}

// checks if game is done (all players have finished board)
bool gameDone(Player * players, int numPlayers)
{
    int count = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].finished())
        {
            count++;
        }
    }

    if (count==numPlayers)
    {
        return true;
    }
    
    return false;
}

// takes care of end of game calculations and determines winner
void determineWinner(Player * players, int numPlayers)
{
    cout << "-------------------------------" << endl;
    for (int i = 0; i < numPlayers; i++)
    {
        int totalCards = players[i].getCards();
        cout << "Player " << (i+1) << ": you have have " << totalCards << " LIFE tiles. Enter 0 to redeem your tiles: ";
        int getLife;
        cin >> getLife;
        cout << endl;
        int sum = 0;
        for (int i = 0; i < totalCards; i++)
        {
            int number = rand() % 6 + 1;     // random number between 1-5
            number *= 10000;
            cout << "LIFE tile #" << (i+1) << " was worth $" << number << "." << endl;
            sum += number;
        }
        players[i] += sum;
        cout << "-------------------------------" << endl;
    }
    
    // determine winner of game
    int highest = players[0].getSavings();
    int winner = 1;
    for (int i = 0; i < numPlayers-1; i++)
    {
        if (players[i].getSavings() > highest)
        {
            winner = i+1;
        }
    }
    
    cout << "                     *" << endl;
    cout << "                   *" << endl;
    cout << "                 * " << endl;
    cout << "               * " << endl;
    cout << "    AND THE WINNER IS . . . " << endl;
    cout << "            * " << endl;
    cout << "          * " << endl;
    cout << "        *   " << endl;
    cout << "      *   " << endl;
    cout << "   (Enter 0 to reveal the winner): ";
    int reveal;
    cin >> reveal;
    cout << endl;
    cout << "The winner is Player " << winner << " with $" << players[winner-1].getSavings() << "." << endl;
}

// wrap function to play game
void playLife()
{
    // introduction
    displayIntro();
    
    // create board
    const int SIZE = boardSize();
    Space *board = buildBoard(SIZE);

    // seed random number generation
    srand(time(0));

    // create array of Player objects
    cout << "Enter number of players: ";      // ask user how many players
    int numPlayers;
    cin >> numPlayers;
    Player * players = getPlayers(numPlayers);
        
    bool play = true;
    int turn = 1;

    while (play)
    {
        // reset back to first plauer once everyone has had turn
        if (turn == numPlayers + 1)
        {
            turn = 1;
        }
        
        // get current player
        Player * myPlayer;
        myPlayer = players + (turn-1);
        
        // check to see if all players have reached end of board and game is over
        if (gameDone(players, numPlayers))
        {
            play = false;
            break;
        }
        
        // check to see if current player is finished
        if (myPlayer->finished())
        {
            turn++;
            continue;
        }
        
        cout << "-------------------------------" << endl;

        // print out current player's information
        cout << "* * * * * * PLAYER " << turn << " * * * * * * " << endl;
        cout << endl;
        int currPosition = myPlayer->getPosition();
        cout << "Your current position is: " << currPosition << endl;
        cout << "Your current savings are: $" << myPlayer->getSavings() << endl;
        
        // choose career and sallary if beginning of game
        if (currPosition == 0)
        {
            chooseCareer(myPlayer);
        }

        // spin wheel and get player's new position
        spinWheel(myPlayer);
        currPosition = myPlayer->getPosition();
        
        // check if player passed STOP point
        checkStop(myPlayer);
        currPosition = myPlayer->getPosition();
        
        // set player to finished if spin takes them past the end of the board and move to next player
        if (myPlayer->getPosition() > SIZE)
        {
            myPlayer->setFinished();
            cout << endl;
            cout << "You've reached the end of the board!" << endl;
            continue;
        }

        // get space at player's current position
        Space mySpace = board[currPosition-1];
        string type = mySpace.getType();
        int amount = mySpace.getAmount();
        cout << endl;
        cout << "Landed on: " << mySpace.getMessage() << endl;

        // handle type of space
        handleSpace(myPlayer, type, amount);
        
        // increment turn
        turn++;
    }
    
    // redeem LIFE tiles and determine winner
    determineWinner(players, numPlayers);
    
    // deallocate memory used for board and player array
    delete[] board;
    delete[] players;
}
