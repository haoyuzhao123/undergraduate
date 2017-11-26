#ifndef _SBT_H
#define _SBT_H

#include "const.h"
#include "search.h"
#include "card.h"


void Play_sb(int np, int pi, int r, int n1, int s1[], 
			 int _n[], int _m[], int (*p)[Nc+10])
{
    //ofstream deb;
    //deb.open("maindeb.txt", ios::app);
    srand(clock()*10000);
	
    int num_players, player_index, current_rule;
    Cards palette[2] = {noCards, noCards};
    Cards hand = noCards;
    int hand_size[2];

    num_players=np, player_index=pi, current_rule=r;
    int i,j,n,m;
    n = n1;
    for (i = 0; i < n; i++) {
        m = s1[i];
        hand = pushBack(hand, intToCard(m));
    }
    //deb << " pass entering hand" << endl;

    for (i = 0; i < 2; i++) {
        hand_size[i] = _n[i];
        n = _m[i];
        //deb << "player: " << i << endl;
        //deb << n << endl;
        if (n == 0) continue;
        else
            for (j = 0; j < n; j++) {
                m = p[i][j];
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
                    current_rule, hand_size[1 - player_index], 20);
    else if (hand_size[0] + hand_size[1] == 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 100);
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
}

#endif
