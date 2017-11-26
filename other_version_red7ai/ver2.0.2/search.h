#ifndef SEARCH_H_
#define SEARCH_H_

#include "card.h"
#include <cmath>
/*
#include "distr.h"
#include "graph.h"
#include "env.h"
#include "cards.h" 
#include "const.h"

extern Graph graph;
*/
extern Cards palette_global[2];
extern int sc1, sc2;

typedef short Move;

struct MoveScore {
    Move mv;
    int score;
};

const int INF = 1 << 17;

//use a short[60] to denote the possible moves
//the move[59] is the number of the possible moves
void possibleMoves(Move * moves_arr, Cards * palette, Cards hand,
                     int player_index, int current_rule);

//compute lost points
//called if the player do not have the choice to move
double losePoint(Cards * palette, int player_index, int current_rule);

int moveTo(Cards * palette, Cards * hands, Cards * new_palette, Cards * new_hands,
            int player_index, int current_rule, Move mv);

//just return the score of the game, do not consider the move
int alpha_beta(int alpha, int beta, Cards * palette, Cards * hands,
                 int player_index, int current_rule);

Cards randomCards(Cards * palette, Cards hand, int oppo_hand_size);

Move bestMove(Cards * palette, Cards hand, int player_index,
                 int current_rule, int oppo_hand_size, int max_random_time);

int weightrand(int a, int b, int c, int wa, int wb, int wc);

double randomPlay(Cards * palette, Cards * hands, int player_index, int current_rule, int cur_player_index);

Move uct(Cards * palette, Cards hand, int oppo_hand_size, int player_index, 
            int current_rule, int max_random_time, int max_iter_time, double alpha, int lambda, double (* f)(Cards *, Cards *, int, int, int));

void cardsToIntArray(int * array, Cards hand) {
    int sizeofcard = sizeOfCards(hand);
    for (int i = 0; i < sizeofcard; i++) {
        array[i] = cardToInt(getCard(hand, i));
    }
    array[sizeofcard] = 0;
}
/*
double simulFunc(Cards * palette, Cards * hands, int player_index, int current_rule, int cur_player_index) {
    ofstream debug;
    debug.open("simu.txt", ios::app);

    int cardsarray[10];
    int pm[10];
    int po[10];
    Cards new_palette[2];
    Cards new_hands[2];
    int new_rule = current_rule;
    new_palette[0] = palette[0];
    new_palette[1] = palette[1];
    new_hands[0] = hands[0];
    new_hands[1] = hands[1];

    int oppo_palette_size_new = 0;

    debug << sizeOfCards(new_hands[0]) << " " << sizeOfCards(new_hands[1]) << endl;

    if (player_index != cur_player_index) {
        //debug << "enter if" << endl;
        Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hands[cur_player_index], cur_player_index, current_rule);
    int size_of_moves = moves_arr[60];
    
    if (size_of_moves == 0)
        return losePoint(palette, cur_player_index, current_rule);
    
    
    int first = moves_arr[57];
    int second = moves_arr[58];
    int third = moves_arr[59];
    
    //int r = weightrand(first, second, third, 100, 10, 1);
    
    int r = 0;
    if (first > 0)
        r = rand() % first;
    else if (second > 0)
        r = rand() % second;
    else
        r = rand() % third;
        
    Move mv = moves_arr[r];
    new_rule = moveTo(palette, hands, new_palette, new_hands,
                            cur_player_index, current_rule, mv);
    }


    cardsToIntArray(cardsarray, new_hands[player_index]);
    cardsToIntArray(pm, new_palette[player_index]);
    cardsToIntArray(po, new_palette[1 - player_index]);

    oppo_palette_size_new = sizeOfCards(new_palette[1 - player_index]) - sizeOfCards(palette_global[1 - player_index]);
    debug << sizeOfCards(new_hands[1 - player_index]) << endl;
    double s = clock();
    double res = graph.Prb_scr(Cardsl(pm), Cardsl(cardsarray), sizeOfCards(new_hands[1 - player_index]), oppo_palette_size_new, new_rule);
    double e = clock();
    //debug << hex << "new_hands" << new_hands[player_index] << endl;
    //debug << dec << s << " " << e << " " << CLOCKS_PER_SEC << graph.n << endl;
		//fprintf(FOUT, "%.9lf", graph.Prb_scr());
		
		if (player_index == 0) {
            return res;
        }
        else{
            return -res;
        }    
}
*/
using namespace std;

const int MAX_NODES_NUMBER = 300;

double explore_rate = 0.7;

extern bool used_global[49];
extern int allow_resign[2];
extern bool fc[100];
//extern Graph graph;

void possibleMoves(Move * moves_arr, Cards * palette, Cards hand,
                    int player_index, int current_rule) {
    int handsize = sizeOfCards(hand);
    short count = 0;
    short firstkind = 0;
    short secondkind = 0;
    short thirdkind = 0;
    for (int i = 0; i < handsize; i++) {
        Card c = getCard(hand, i);
        short c1 = c;
        Cards newpalette[2];
        newpalette[0] = palette[0];
        newpalette[1] = palette[1];
        newpalette[player_index] = pushBack(palette[player_index], c);
        if (winning(newpalette, current_rule) == player_index) {
            moves_arr[count++] = c1;
            firstkind++;
        }
    }

    for (int i = 0; i < handsize; i++) {
        Card c = getCard(hand, i);
        if (winning(palette, getCol(c)) == player_index) {
            short colorcard = c;
            moves_arr[count++] = (colorcard << 8);
            secondkind++;
        }
    }

    for (int i = 0; i < handsize; i++)
        for (int j = 0; j < handsize; j++)
            if (i != j) {
                Cards newpalette[2];
                newpalette[0] = palette[0];
                newpalette[1] = palette[1];
                Card p = getCard(hand, i);
                Card c = getCard(hand, j);
                newpalette[player_index] = pushBack(palette[player_index], p);
                if (winning(newpalette, getCol(c)) == player_index) {
                    short f = c;
                    short s = p;
                    moves_arr[count++] = (f << 8 | p);
                    thirdkind++;
                }
            }

    moves_arr[60] = count;
    moves_arr[59] = thirdkind;
    moves_arr[58] = secondkind;
    moves_arr[57] = firstkind;
}

double losePoint(Cards * palette, int player_index, int current_rule) {
    Cards top;
    Cards win_palette = palette[1 - player_index];
    switch (current_rule) {
        case 7: top=red(win_palette); break;
        case 6: top=orange(win_palette); break;
        case 5: top=yellow(win_palette); break;
        case 4: top=green(win_palette); break;
        case 3: top=blue(win_palette); break;
        case 2: top=indigo(win_palette); break;
        case 1: top=violet(win_palette); break;
    }
        
    int win_size = sizeOfCards(top);
    int res = 0;
    for (int j = 0; j < win_size; j++)
        res += getNum(getCard(top, j));
    
    double sc;
    if (player_index == 0) sc = sc2;
    else sc = sc1;
    
    if (res + sc > 40.0) res = 40.0 - sc;
    
        
    return (double)((2 * player_index - 1) * res);
}

int moveTo(Cards * palette, Cards * hands, Cards * new_palette, Cards * new_hands,
            int player_index, int current_rule, Move mv) {

    new_palette[0] = palette[0];
    new_palette[1] = palette[1];
    new_hands[0] = hands[0];
    new_hands[1] = hands[1];
    int new_rule = current_rule;
    if (mv >> 8 != 0) {
        new_rule = getCol((Card)(mv >> 8));
        new_hands[player_index] = removeCard(new_hands[player_index], (Card)(mv >> 8));
    }
    if ((mv & 0x00FF) != 0) {
        Card new_card = (Card)(mv & 0x00FF);
        new_palette[player_index] = pushBack(palette[player_index], new_card);
        new_hands[player_index] = removeCard(new_hands[player_index], new_card);
    }
    if (mv == 0) {
        new_palette[player_index] = noCards;
        new_hands[player_index] = noCards;
    }
    return new_rule;
}

int alpha_beta(int alpha, int beta, Cards * palette, Cards * hands, 
                int player_index, int current_rule) {
    Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hands[player_index], player_index, current_rule);
    //set up the best
    int best;
    if (player_index == 0)
        best = alpha;
    else
        best = beta;
    
    int size_of_moves = moves_arr[60];
    if (palette[1 - player_index] == noCards) {
        return losePoint(palette, 1 - player_index, current_rule);
    }
    if (size_of_moves == 0) {       
        return losePoint(palette, player_index, current_rule);
    }

    int total_moves = size_of_moves + allow_resign[player_index];
    for (int i = 0; i < total_moves; i++) {
        Move mv = moves_arr[i];
        Cards new_palette[2];
        Cards new_hands[2];
        int new_rule = moveTo(palette, hands, new_palette, 
                                new_hands, player_index, current_rule, mv);
        
        int res = alpha_beta(alpha, beta, new_palette, new_hands,
                                 1 - player_index, new_rule);

        if (player_index == 0 && res > best) {
            alpha = res;
            best = res;
        }
        else if (player_index == 1 && res < best) {
            beta = res;
            best = res;
        }
        
        if (alpha >= beta)
            return best;

    }
    return best;
}

Cards randomCards(Cards * palette, Cards hand, int oppo_hand_size) {
    Cards res = noCards;
    bool used[49];
    memcpy(used, used_global, sizeof(used));

    for (int i = 0; i < oppo_hand_size; i++) {
        int ran;
        while (true) {
            ran = rand() % 49;
            if (!used[ran]) {
                used[ran] = true;
                break;
            }
        }
        int c = ((int)(ran / 7) + 1 ) * 10 + ran % 7 + 1;
        res = pushBack(res, intToCard(c));
    }
    
    return res;
}

Move bestMove(Cards * palette, Cards hand, int player_index,
                 int current_rule, int oppo_hand_size, int max_random_time) {
    Move moves_arr[61];
    int moves_val[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    memset(moves_val, 0, sizeof(moves_val));
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    int size_of_moves = moves_arr[60];

    if (size_of_moves == 0) {
        Move m = 0;
        return m;
    }

    int total_moves = size_of_moves + allow_resign[player_index];

    for (int i = 0; i < max_random_time; i++) {
        Cards oppo_hand = randomCards(palette, hand, oppo_hand_size);
        Cards hands[2];
        hands[player_index] = hand;
        hands[1 - player_index] = oppo_hand;
        Cards new_palette[2];
        Cards new_hands[2];
        for (int j = 0; j < total_moves; j++) {
            int new_rule = moveTo(palette, hands, new_palette, new_hands,
                                    player_index, current_rule, moves_arr[j]);
            moves_val[j] += alpha_beta(-INF, INF, new_palette, new_hands,
                                        1 - player_index, new_rule);
        }
    }

    int maxi, mini, maxidx, minidx;
    maxi = -INF;
    mini = INF;
    for (int i = 0; i < total_moves; i++) {
        if (moves_val[i] > maxi) {
            maxi = moves_val[i];
            maxidx = i;
        }
        if (moves_val[i] < mini) {
            mini = moves_val[i];
            minidx = i;
        }
    }

    if (player_index == 0) {
        return moves_arr[maxidx];
    }
    else {
        return moves_arr[minidx];
    }
}


int weightrand(int a, int b, int c, int wa, int wb, int wc) {
    int total = a * wa + b * wb + c * wc;
    int p = rand() % total;
    int p1 = a * wa;
    int p2 = a * wa + b * wb;
    if (p >= p2)
        return a + b + (int)((p - p2) / wc);
    else if (p >= p1)
        return a + (int)((p - p1) / wb);
    else
        return (int)(p / wa);
}

double randomPlay(Cards * palette, Cards * hands, int player_index, int current_rule, int cur_player_index) {
    Move moves_arr[61];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hands[cur_player_index], cur_player_index, current_rule);
    int size_of_moves = moves_arr[60];
    
    if (size_of_moves == 0)
        return losePoint(palette, cur_player_index, current_rule);
    
    
    int first = moves_arr[57];
    int second = moves_arr[58];
    int third = moves_arr[59];
    
    int r = 0;
    if (first > 0)
        r = rand() % first;
    else if (second > 0)
        r = rand() % second;
    else
        r = rand() % third;
        

    Move mv = moves_arr[r];
    Cards new_palette[2], new_hands[2];
    int new_rule = moveTo(palette, hands, new_palette, new_hands,
                            cur_player_index, current_rule, mv);
    return randomPlay(new_palette, new_hands, player_index, new_rule, 1 - cur_player_index);
}

struct Node {
    Move moves_arr[61];
    bool visited[61];
    int child[61];
    int par;
    int num_child;
    int visit_num;
    double value;
    int player_index;
    int current_rule;
    int mv_idx;
    Cards hands[2];
    Cards palette[2];
};

int getUnTried(Node * tn, int num) {
    int c = 0;
    int untried[61];
    int size_of_moves = tn[num].moves_arr[60];
    int total_moves = size_of_moves + allow_resign[tn[num].player_index];
    ofstream debug;
    debug.open("getUntried.txt", ios::app);
    for (int i = 0; i < total_moves; i++) {
        if (!tn[num].visited[i]) {
            untried[c++] = i;
        }
    }
    if (c == 0)
        return -1;
    else {
        int r = rand() % c;
        tn[num].visited[untried[r]] = true;
        return untried[r];
    }
    debug << "return" << endl;
    debug.close();
}

int getUCB(Node * tn, int num) {
    ofstream debug;
    debug.open("getUCB.txt", ios::app);
    debug << num << endl;
    int c = -1;
    double temp;
    if (tn[num].player_index == 0)
        temp = -10000.0;
    else
        temp = 10000.0;

    for (int i = 0; i < tn[num].num_child; i++) {
        int ch = tn[num].child[i];
        double mean = (1.0 * (double)tn[ch].value) / tn[ch].visit_num;
        double bound = explore_rate * sqrt(log(tn[num].visit_num) / tn[ch].visit_num);
        if (tn[num].player_index == 0 && (mean + bound > temp)) {
            temp = mean + bound;
            c = tn[num].child[i];
        }
        else if (tn[num].player_index == 1 && (mean - bound < temp)) {
            temp = mean - bound;
            c = tn[num].child[i]; 
        }
    }
    debug.close();
    return c;
}

void updateNode(Node * tn, int num, int score) {
    tn[num].visit_num += 1;
    tn[num].value += score;
    int par = tn[num].par;
    if (par != -1)
        updateNode(tn, par, score);
}

void addChild(Node * tn, int par, int ch, int mv) {
    tn[ch].current_rule = moveTo(tn[par].palette, tn[par].hands, tn[ch].palette, 
                tn[ch].hands, tn[par].player_index, tn[par].current_rule, tn[par].moves_arr[mv]);
    tn[ch].player_index = 1 - tn[par].player_index;
    possibleMoves(tn[ch].moves_arr, tn[ch].palette, tn[ch].hands[tn[ch].player_index], 
                        tn[ch].player_index, tn[ch].current_rule);
         
    tn[ch].par = par;
    tn[par].child[tn[par].num_child ++] = ch;
    tn[ch].value = 0.0;
    tn[ch].mv_idx = mv;
}

void initNode(Node * tn, int num, int par, Cards * palette, Cards * hands, 
                    int player_index, int current_rule) {
    tn[num].par = par;
    tn[num].palette[0] = palette[0];
    tn[num].palette[1] = palette[1];
    tn[num].hands[0] = hands[0];
    tn[num].hands[1] = hands[1];
    tn[num].player_index = player_index;
    tn[num].current_rule = current_rule;
    possibleMoves(tn[num].moves_arr, palette, hands[player_index], player_index, current_rule);
}


Move uct(Cards * palette, Cards hand, int oppo_hand_size, int player_index, 
            int current_rule, int max_random_time, int max_iter_time, double alpha, int lambda, double (* f)(Cards *, Cards *, int, int, int)) {

    Node tn[MAX_NODES_NUMBER];
    Move possible_moves[61];
    Cards hands[2];
    hands[player_index] = hand;
    possibleMoves(possible_moves, palette, hand, player_index, current_rule);
    int size_of_moves = possible_moves[60];
    int total_moves = size_of_moves + allow_resign[player_index];
    int visitcount[61];
    memset(visitcount, 0, sizeof(visitcount));

    for (int i = 0; i < max_random_time; i++) {
        Cards oppo_hand = randomCards(palette, hand, oppo_hand_size);
        memset(tn, 0, sizeof(tn));
        hands[1 - player_index] = oppo_hand;
        int node_count = 0;
        initNode(tn, node_count++, -1, palette, hands, player_index, current_rule);

        for (int j = 0; j < max_iter_time; j++) {
            //select
            int cur = 0;
            int temp = -3;
            int resign = 0;
            while(true) {
                
                if (tn[cur].palette[1 - tn[cur].player_index] == noCards) {
                    resign = 1;
                    temp = -2;
                    break;
                }
                

                if (tn[cur].moves_arr[60] == 0) {
                    temp = -2;
                    break;
                }
                else if ((temp = getUnTried(tn, cur)) == -1) {
                    cur = getUCB(tn, cur);
                }
                else
                    break;
            }
            //expand
            if (temp != -2) {
                addChild(tn, cur, node_count++, temp);
            }
            //simulate
            int t;
            if (temp == -2) {
                t = cur;
            }
            else
                t = node_count - 1;

            double score;
            if (resign == 1) {
                score = losePoint(tn[cur].palette, 1 - tn[cur].player_index, tn[cur].current_rule);
            }
            
            score = 0;
            for (int ct = 0; ct < lambda; ct++) {
            score += f(tn[t].palette, tn[t].hands, player_index, tn[t].current_rule, tn[t].player_index);
            }
            score = score / lambda;            
            
            //back-propogate
            updateNode(tn, t, score);
            //penalize the resign
            int chpar = tn[t].par;
            short mv = tn[chpar].moves_arr[tn[t].mv_idx];
            if (mv == 0) 
                tn[t].value += alpha * score;
        }

        for (int j = 0; j < tn[0].num_child; j++) {
            visitcount[tn[tn[0].child[j]].mv_idx] += tn[tn[0].child[j]].visit_num;
        }

    }


    int max_idx = -1;
    int max_visit = -1;
    for (int j = 0; j < total_moves; j++) {
        if (visitcount[j] > max_visit) {
            max_idx = j;
            max_visit = visitcount[j];
        }
    }
    return possible_moves[max_idx];

}

#endif
