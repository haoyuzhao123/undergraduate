#ifndef SEARCH_H_
#define SEARCH_H_

#include "card.h"

typedef short Move;

struct MoveScore
{
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
int losePoint(Cards * palette, int player_index, int current_rule);

int moveTo(Cards * palette, Cards * hands, Cards * new_palette, Cards * new_hands,
            int player_index, int current_rule, Move mv);

//just return the score of the game, do not consider the move
int alpha_beta(int alpha, int beta, Cards * palette, Cards * hands,
                 int player_index, int current_rule);

Cards randomCards(Cards * palette, Cards hand, int oppo_hand_size);

Move bestMove(Cards * palette, Cards hand, int player_index,
                 int current_rule, int oppo_hand_size, int max_random_time);

#endif