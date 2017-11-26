#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "search.h"
#include "card.h"


using namespace std;

extern bool used_global[49];
extern int allow_resign[2];
extern bool fc[100];
extern Cards palette_global[2];
extern int sc1, sc2;

bool used_global[49];
int allow_resign[2];
bool fc[100];
Cards palette_global[2];
int sc1, sc2;


int main()
{
    srand(time(0));
    memset(used_global, 1, sizeof(used_global));

    allow_resign[0] = 1;
    allow_resign[1] = 1;


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

    for (i = 0; i < 2; i++) {
        scanf("%d", hand_size + i);
        scanf("%d", &n);
        if (n == 0) continue;
        else
            for (j = 0; j < n; j++) {
                scanf("%d", &m);
                palette[i] = pushBack(palette[i], intToCard(m));
            }
    }

    scanf("%d%d", &sc1, &sc2);


    memset(fc, 0, sizeof(fc));

    int a;
    int b;
    scanf("%d", &a);
    while (a--) {
        scanf("%d", &b);
        int x = (int)b / 10;
        int y = b % 10;
        used_global[7*(x-1)+(y-1)] = false;
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

    Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    Move v;

    if (hand_size[0] + hand_size[1] > 10 && hand_size[0] + hand_size[1] > 0) {
        palette_global[0] = palette[0];
        palette_global[1] = palette[1]; 
        v = uct(palette, hand, hand_size[1-player_index],
                player_index, current_rule, 1000, 500, 0.3, 1, randomPlay);
    }
    else if (hand_size[0] + hand_size[1] > 7 && hand_size[0] + hand_size[1] > 0) {
        palette_global[0] = palette[0];
        palette_global[1] = palette[1];
        v = uct(palette, hand, hand_size[1-player_index],
                player_index, current_rule, 1000, 500, 0.6, 1, randomPlay);
    }
    else if (hand_size[0] + hand_size[1] == 7)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index],500);
    else if (hand_size[0] + hand_size[1] == 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 400);
    else if (hand_size[0] + hand_size[1] < 6)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index], 1000);
    
    else
        v = moves_arr[0];



    Card f = (Card)(v >> 8);
    Card s = (Card)(v & (0x00FF));
    cout << cardToInt(f) << " " << cardToInt(s) << endl;
    return 0;
}
