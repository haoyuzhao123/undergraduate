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
//extern Graph graph;
extern Cards palette_global[2];
extern int sc1, sc2;

bool used_global[49];
int allow_resign[2];
bool fc[100];
Cards palette_global[2];
int sc1, sc2;

//Graph graph;

int main()
{
    //ofstream deb;
    //deb.open("maindeb.txt", ios::app);
    srand(time(0));
    //Init();

    memset(used_global, 1, sizeof(used_global));

    allow_resign[0] = 0;
    allow_resign[1] = 1;

    //freopen("p1.in", "r", stdin);

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

    int sc1, sc2;

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


    //distr.Init(fc);
    
    //deb << "pass entering palette" << endl;
    
    //resign
    int cardsarray[10];
    int pm[10];
    int po[10];

    Cards new_palette[2];

    new_palette[0] = palette[0];
    new_palette[1] = palette[1];

    cardsToIntArray(cardsarray, hand);
    cardsToIntArray(pm, palette[player_index]);
    cardsToIntArray(po, palette[1 - player_index]);

    
        graph.Init(Cardsl(pm), Cardsl(po), Cardsl(cardsarray), sizeOfCards(hand), current_rule);
		fprintf(FOUT, "%.9lf", graph.Prb_scr());

        //if resign
        new_palette[player_index] = noCards;
        double temp = fabs(losePoint(new_palette, player_index, current_rule));

        int sc;

        if (player_index == 0) {
            sc = sc1;
        }
        else 
            sc = sc2;

        if (graph.Prb_scr()-6<-temp && sc+temp<40){
			printf("0 0\n");
			cerr<<"GG"<<endl;
			return 0;
		}
		


    //end resign
    

    Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    Move v;

    
    //deb << "pass the first point" << endl;
    /*
    if (hand_size[0] + hand_size[1] > 20 && hand_size[0] + hand_size[1] > 0) {
        int tmp=graph.Action();
		printf("%d %d\n", tmp/100, tmp%100);
    }
	*/
    if (hand_size[0] + hand_size[1] > 10 && hand_size[0] + hand_size[1] > 0) {
        palette_global[0] = palette[0];
        palette_global[1] = palette[1]; 
        v = uct(palette, hand, hand_size[1-player_index],
                player_index, current_rule, 1000, 1000, 0.5, 1, randomPlay);
    }
    else if (hand_size[0] + hand_size[1] > 7 && hand_size[0] + hand_size[1] > 0) {
        palette_global[0] = palette[0];
        palette_global[1] = palette[1];
        v = uct(palette, hand, hand_size[1-player_index],
                player_index, current_rule, 1000, 1000, 0.8, 1, randomPlay);
    }
    else if (hand_size[0] + hand_size[1] <= 7)
        v = bestMove(palette, hand, player_index,
                    current_rule, hand_size[1 - player_index],10000);
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
