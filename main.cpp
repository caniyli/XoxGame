#include <iostream>
#include <vector>
#include <xoxgame.h>

using namespace std;

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
