#include <iostream>
#include <vector>

using namespace std;

class XoxGame
{
public:
    XoxGame() { drawBackGround(); }

    void setMove(int position)
    {
        if (player == 1) {
            shape = 'X';
        }else {
            shape = 'O';
        }
        data[position / 3][(position % 3) - 1] = shape;
        system("clear");
        drawBackGround();
        counter++;
        if (counter % 2 == 0)
            player = 1;
        else
            player = 2;
    }

    int getPlayer()
    {
        return player;
    }

    bool isEndGame()
    {
        if (counter > 8) {
            return false;
        }
        return true;
    }

    bool checkWin()
    {
        for (int i = 0; i < 3; ++i)
            if(data[i][0] == data[i][2] && data[i][0] == data[i][1])
                return true;
            else if (data[0][i] == data[1][i] && data[1][i] == data[2][i])
                return true;
        if(data[0][0] == data[1][1] && data[1][1] == data[2][2])
            return true;
        if(data[0][2] == data[1][1] && data[1][1] == data[2][0])
            return true;

        return false;
    }

private:
    int player = 1;
    int counter = 0;
    char shape;
    char data[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    void drawBackGround()
    {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 25; ++i)
                    cout << "-";
            cout << endl;
            if (j < 3)
                for (int i = 0; i < 3; ++i) {
                    if (i == 1)
                        cout << "|   " << data[j][0] << "   |   " << data[j][1] << "   |   " << data[j][2] << "   |" << endl;
                    else
                        cout << "|       |       |       |" << endl;
                }
        }
    }
};

int main()
{
    int buf;
    int player;
    XoxGame Game;
    while(Game.isEndGame()){
        player = Game.getPlayer();
        cout << "Sıra " << player << ". Oyuncuda" << endl
             << "Hamle yapmak istediğiniz kutuyu seçin.";
        cin >> buf;
        Game.setMove(buf);
        if (Game.checkWin()) {
            cout  << player << ". Oyuncu oyunu kazandı. Tebrikler" << endl;
            break;
        }
    }
    if (!Game.checkWin()){
        cout << "Berabere bitti." << endl;
    }
    return 0;
}
