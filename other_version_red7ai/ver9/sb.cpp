#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "search.h"
#include "card.h"

#include "distr.h"
#include "graph.h"
#include "env.h"
#include "cards.h"

using namespace std;

extern bool used_global[49];
extern int allow_resign[2];
extern bool fc[100];
extern Graph graph;

bool used_global[49];
int allow_resign[2];
bool fc[100];

Graph graph;

int main()
{
    //ofstream deb;
    //deb.open("maindeb.txt", ios::app);
    srand(time(0));

    memset(used_global, 0, sizeof(used_global));

    allow_resign[0] = 1;
    allow_resign[1] = 1;

    freopen("p1.in", "r", stdin);

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

    int a;
    int b;
    scanf("%d", &a);
    while (a--) {
        scanf("%d", &b);
        fc[b] = 1;
    }

    int sizetemp;
    sizetemp = sizeOfCards(palette[0]);
    for (int i = 0; i < sizetemp; i++) {
        int a = getNum(getCard(palette[0], i));
        int b = getCol(getCard(palette[0], i));
        used_global[7 * (a - 1) + b - 1] = true;
    }
    sizetemp = sizeOfCards(palette[1]);
    for (int i = 0; i < sizetemp; i++) {
        int a = getNum(getCard(palette[1], i));
        int b = getCol(getCard(palette[1], i));
        used_global[7 * (a - 1) + b - 1] = true;
    }
    sizetemp = sizeOfCards(hand);
    for (int i = 0; i < sizetemp; i++) {
        int a = getNum(getCard(hand, i));
        int b = getCol(getCard(hand, i));
        used_global[7 * (a - 1) + b - 1] = true;
    }

    for (int i = 0; i < 49; i++) {
        if (used_global[i]) {
            fc[10 * (int)(i / 7 + 1) + (i % 7 + 1)] = 0;
        }
    }


    distr.Init(fc);
    
    //deb << "pass entering palette" << endl;

    Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    //deb << "pass memset" << endl;
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    //deb << "pass possibleMoves" << endl;
    Move v;

    if (hand_size[0] + hand_size[1] > 14 && hand_size[0] + hand_size[1] > 0)
        v = moves_arr[0];
    /*
    else if (hand_size[0] + hand_size[1] > 7) {
        MoveScore ms = mcts(palette, hand, hand_size[1-player_index],
                            player_index, current_rule, 100);
        v = ms.mv;
    }
    */
    else if (hand_size[0] + hand_size[1] > 7) {
        v = uct(palette, hand, hand_size[1-player_index],
                player_index, current_rule, 50, 200, randomPlay);
    }
    
    //if (hand_size[0] + hand_size[1] >= 7)
    //    v = bestMove(palette, hand, player_index,
    //                current_rule, hand_size[1 - player_index], 20);
    //else if (hand_size[0] + hand_size[1] == 8)
    //    v = bestMove(palette, hand, player_index,
    //                current_rule, hand_size[1 - player_index], 5000);
    
    else if (hand_size[0] + hand_size[1] == 7)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 300);
    else if (hand_size[0] + hand_size[1] == 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 200);
    else if (hand_size[0] + hand_size[1] < 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 200);
    
    else
        v = moves_arr[0];



    //deb << "pass assignment move" << endl;
    Card f = (Card)(v >> 8);
    Card s = (Card)(v & (0x00FF));
    //deb << "pass entering cards" << endl;
    //deb << cardToInt(f) << " " << cardToInt(s) << endl;
    cout << cardToInt(f) << " " << cardToInt(s) << endl;
    //deb << "pass cout" << endl;
    //deb.close();
    fclose(stdin);
    return 0;
}