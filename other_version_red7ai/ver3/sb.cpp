#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "search.h"
#include "card.h"

using namespace std;

int main()
{
    //ofstream deb;
    //deb.open("maindeb.txt", ios::app);
    srand(clock());

    int num_players, player_index, current_rule;
    Cards palette[2] = {noCards, noCards};
    Cards hand = noCards;
    int hand_size[2];

    scanf("%d%d%d", &num_players, &player_index, &current_rule);
    int i,j,n,m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        hand = pushBack(hand, intToCard(m));
    }
    //deb << " pass entering hand" << endl;

    for (i = 0; i < 2; i++) {
        scanf("%d", hand_size + i);
        scanf("%d", &n);
        //deb << "player: " << i << endl;
        //deb << n << endl;
        if (n == 0) continue;
        else
            for (j = 0; j < n; j++) {
                scanf("%d", &m);
                palette[i] = pushBack(palette[i], intToCard(m));
            }
    }

    //deb << "pass entering palette" << endl;

    Move moves_arr[60];
    memset(moves_arr, 0, sizeof(moves_arr));
    //deb << "pass memset" << endl;
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    //deb << "pass possibleMoves" << endl;
    Move v;
    if (hand_size[0] + hand_size[1] >= 7)
        v = moves_arr[0];
    else if (hand_size[0] + hand_size[1] == 7)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 300);
    else if (hand_size[0] + hand_size[1] == 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 200);
    else if (hand_size[0] + hand_size[1] < 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 1000);
    //deb << "pass assignment move" << endl;
    Card f = (Card)(v >> 8);
    Card s = (Card)(v & (0x00FF));
    //deb << "pass entering cards" << endl;
    //deb << cardToInt(f) << " " << cardToInt(s) << endl;
    cout << cardToInt(f) << " " << cardToInt(s) << endl;
    //deb << "pass cout" << endl;
    //deb.close();
    return 0;
}
