#ifndef ALPHA_BETA_H_
#define ALPHA_BETA_H_

#include <list>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 10000000;

//define a struct to store each move
//the first is the card that change the rules
//the second is the card that put in the palette
//the score is the final score
struct move {
    int first;
    int second;
    int score;
};

move best_move(list<int> palette[], list<int> hand, int hand_size[],
            bool active[], int num_players, int current_rule, int player_index, int MAX_ITER, int max_depth);

move mcts(list<int> palette[], int player_index, list<int> hand, int hand_size[], int current_rule, int MAX_ITER);



#endif