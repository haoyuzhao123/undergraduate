#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

#include "card.h"
#include "search.h"

using namespace std;

void possibleMoves(Move * moves_arr, Cards * palette, Cards hand,
                    int player_index, int current_rule) {
    //debug
    /*
    ofstream debug;
    debug.open("possiblemove.txt", ios::app);
    debug << "palette 0: " << hex << palette[0] << endl;
    debug << "palette 1: " << hex << palette[1] << endl;
    debug << "hands: " << hex << hand << endl;
    */
    int handsize = sizeOfCards(hand);
    short count = 0;
    short firstkind = 0;
    short secondkind = 0;
    short thirdkind = 0;
    for (int i = 0; i < handsize; i++) {
        Card c = getCard(hand, i);
        short c1 = c;
        //debug << "card" << hex << c1 << endl;
        Cards newpalette[2];
        newpalette[0] = palette[0];
        newpalette[1] = palette[1];
        newpalette[player_index] = pushBack(palette[player_index], c);
        if (winning(newpalette, current_rule) == player_index) {
            moves_arr[count++] = c1;
            //debug << hex << c1 << " " << moves_arr[count-1] << endl;
            firstkind++;
        }
    }

    for (int i = 0; i < handsize; i++) {
        Card c = getCard(hand, i);
        //short c1 = c;
        //debug << hex << "card: " << c1 << endl;
        if (winning(palette, getCol(c)) == player_index) {
            short colorcard = c;
            moves_arr[count++] = (colorcard << 8);
            //debug << hex << colorcard << " " << moves_arr[count-1] << endl;
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
                //short p1 = p;
                //short c1 = c;
                //debug << "card: " << hex << p1 << " " << hex << c1 << endl;
                newpalette[player_index] = pushBack(palette[player_index], p);
                if (winning(newpalette, getCol(c)) == player_index) {
                    short f = c;
                    short s = p;
                    moves_arr[count++] = (f << 8 | p);
                    //debug << hex << f << " " << p << " " << moves_arr[count-1] << endl;
                    thirdkind++;
                }
            }

    moves_arr[59] = count;
    moves_arr[58] = thirdkind;
    moves_arr[57] = secondkind;
    moves_arr[56] = firstkind;
/*
    for (int i = 0; i < 60; i++) {
        debug << hex << moves_arr[i] << " ";
    }
    debug << endl;
*/
}

int losePoint(Cards * palette, int player_index, int current_rule) {
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
        
    return (2 * player_index - 1) * res;
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
    return new_rule;
}

int alpha_beta(int alpha, int beta, Cards * palette, Cards * hands, 
                int player_index, int current_rule) {
    //generate the set of all possible moves
    Move moves_arr[60];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hands[player_index], player_index, current_rule);
    //set up the best
    int best;
    if (player_index == 0)
        best = alpha;
    else
        best = beta;
    
    int size_of_moves = moves_arr[59];
    if (size_of_moves == 0) {       
        return losePoint(palette, player_index, current_rule);
    }

    for (int i = 0; i < size_of_moves; i++) {
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
    memset(used, 0, sizeof(used));
    for (int i = 0; i < sizeOfCards(palette[0]); i++) {
        int a = getNum(getCard(palette[0], i));
        int b = getCol(getCard(palette[0], i));
        used[7 * (a - 1) + b - 1] = true;
    }
    for (int i = 0; i < sizeOfCards(palette[1]); i++) {
        int a = getNum(getCard(palette[1], i));
        int b = getCol(getCard(palette[1], i));
        used[7 * (a - 1) + b - 1] = true;
    }
    for (int i = 0; i < sizeOfCards(hand); i++) {
        int a = getNum(getCard(hand, i));
        int b = getCol(getCard(hand, i));
        used[7 * (a - 1) + b - 1] = true;
    }

    for (int i = 0; i < oppo_hand_size; i++) {
        //srand(clock());
        int ran;
        while (true) {
            ran = rand() % 49;
            if (!used[ran])
                break;
        }
        int c = ((int)(ran / 7) + 1 ) * 10 + ran % 7 + 1;
        res = pushBack(res, intToCard(c));
    }
    
    return res;
}

Move bestMove(Cards * palette, Cards hand, int player_index,
                 int current_rule, int oppo_hand_size, int max_random_time) {
    Move moves_arr[60];
    int moves_val[60];
    memset(moves_arr, 0, sizeof(moves_arr));
    memset(moves_val, 0, sizeof(moves_val));
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    int size_of_moves = moves_arr[59];

    if (size_of_moves == 0) {
        Move m = 0;
        return m;
    }

    for (int i = 0; i < max_random_time; i++) {
        Cards oppo_hand = randomCards(palette, hand, oppo_hand_size);
        Cards hands[2];
        hands[player_index] = hand;
        hands[1 - player_index] = oppo_hand;
        Cards new_palette[2];
        Cards new_hands[2];
        for (int j = 0; j < size_of_moves; j++) {
            int new_rule = moveTo(palette, hands, new_palette, new_hands,
                                    player_index, current_rule, moves_arr[j]);
            moves_val[j] += alpha_beta(-INF, INF, new_palette, new_hands,
                                        1 - player_index, new_rule);
        }
    }

    int maxi, mini, maxidx, minidx;
    maxi = -INF;
    mini = INF;
    for (int i = 0; i < size_of_moves; i++) {
        if (moves_val[i] > maxi) {
            maxi = moves_val[i];
            maxidx = i;
        }
        if (moves_val[i] < mini) {
            mini = moves_val[i];
            minidx = i;
        }
    }
    //ofstream debug;
    //debug.open("bestMove.txt", ios::app);
    //for (int i = 0; i < size_of_moves; i++) {
    //    debug << hex << moves_arr[i] << " ";
    //}
    //debug << endl;

    if (player_index == 0) {
        //debug << hex << moves_arr[maxidx] << endl;
        //debug.close();
        return moves_arr[maxidx];
    }
    else {
        //debug << hex << moves_arr[minidx] << endl;
        //debug.close();
        return moves_arr[minidx];
    }
}


int weightrand(int a, int b, int c, int wa, int wb, int wc) {
    srand(clock());
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

int randomPlay(Cards * palette, Cards * hands, int player_index, int current_rule) {
    Move moves_arr[60];
    memset(moves_arr, 0, sizeof(moves_arr));
    possibleMoves(moves_arr, palette, hands[player_index], player_index, current_rule);
    int size_of_moves = moves_arr[59];
    if (size_of_moves == 0)
        return losePoint(palette, player_index, current_rule);
    
    int first = moves_arr[56];
    int second = moves_arr[57];
    int third = moves_arr[58];
    //int r = weightrand(first, second, third, 5, 4, 1);
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
                            player_index, current_rule, mv);
    return randomPlay(new_palette, new_hands, 1 - player_index, new_rule);
}

MoveScore mcts(Cards * palette, Cards hand, int oppo_hand_size,
                 int player_index, int current_rule, int max_random_time) {
    Move moves_arr[60];
    int moves_count[60];
    double moves_val[60];
    memset(moves_arr, 0, sizeof(moves_arr));
    memset(moves_count, 0, sizeof(moves_arr));
    memset(moves_val, 0, sizeof(moves_val));
    possibleMoves(moves_arr, palette, hand, player_index, current_rule);
    int first = moves_arr[56];
    int second = moves_arr[57];
    int third = moves_arr[58];
    int tempvalue;

    ofstream debug;
    debug.open("mcts.txt", ios::app);
    debug << "begin the mcts" << endl;
    debug << "print the palette and the hand card" << endl;
    debug << hex << palette[0] << endl;
    debug << hex << palette[1] << endl;
    debug << hex << hand << endl;
    debug << dec << "current rule: " << current_rule << endl;
    for (int i = 0; i < 60; i++) {
        debug << hex << moves_arr[i] << " ";
    }
    debug << endl;



    if (moves_arr[59] == 0) {
        MoveScore ms;
        ms.mv = 0;
        ms.score = losePoint(palette, player_index, current_rule);
        tempvalue = ms.score;
        debug << "no move, give 0000" << endl;
        return ms;
    }

    for (int j = 1; j < max_random_time; j++) {
        Cards oppo_hand = randomCards(palette, hand, oppo_hand_size);
        Cards hands[2];
        hands[player_index] = hand;
        hands[1 - player_index] = oppo_hand;

        Cards new_palette[2], new_hands[2];
        for (int k = 0; k < 1; k++) {
            //int r = weightrand(first, second, third, 500, 50, 1);
            int r;
            if (first > 0)
                r = rand() % first;
            else if (second > 0)
                r = rand() % second;
            else
                r = rand() % third;

            Move m = moves_arr[r];
            int new_rule = moveTo(palette, hands, new_palette, new_hands,
                                    player_index, current_rule, m);
            int res = randomPlay(new_palette, new_hands, 1 - player_index, new_rule);
            moves_count[r] += 1;
            moves_val[r] += res;
        }
    }

    int maxidx, minidx;
    double maxval = -10000.0, minval = 10000.0;
    for (int i = 0; i < moves_arr[59]; i++) {
        if (moves_count[i] >= 0) {
            double t = moves_val[i] / moves_count[i];
            debug << "print the expected score: " << t << endl;
            if (t > maxval) {
                maxidx = i;
                maxval = t;
            }
            if (t < minval) {
                debug << "player 1 debug, change the minidx" << endl;
                minidx = i;
                minval = t;
                debug << dec << minidx << endl;
            }
        }
    }

    //debug << "minidix: " << minidx << " " << "maxidx: " << maxidx << endl;

    MoveScore ret;
    if (player_index == 0) {
        ret.mv = moves_arr[maxidx];
        if (maxidx == -1)
            ret.mv = 0;
        ret.score = maxval;
    }
    else {
        ret.mv = moves_arr[minidx];
        if (minidx == -1)
            ret.mv = 0;
        ret.score = minval;
        debug << "player 1 debug, minidx: " << dec << minidx << endl;
        debug << "move: " << hex << ret.mv << endl;
    }

    debug << "output move: " << hex << ret.mv << endl;

    return ret;    
}
