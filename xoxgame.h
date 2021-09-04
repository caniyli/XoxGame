#ifndef XOXGAME_H
#define XOXGAME_H

#include <iostream>

using namespace std;

class XoxGame
{
public:
    XoxGame();
    void setMove(int position);
    int getPlayer();
    bool isEndGame();
    bool checkWin();

private:
    int player = 1;
    int counter = 0;
    char shape;
    char data[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    void drawBackGround();
};

#endif // XOXGAME_H
