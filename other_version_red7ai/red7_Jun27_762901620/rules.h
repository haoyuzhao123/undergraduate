#ifndef RULES_H_
#define RULES_H_

#include <list>

using namespace std;

const int MAX_PLAYERS = 2;
const int MAX_ROUNDS = 12;

//the compare function of 2 list
//first size, then particular card
bool compare(list<int> a, list<int> b);

//the functions that returns the best
//list of cards in a hand
list<int> red(list<int> a);
list<int> orange(list<int> a);
list<int> yellow(list<int> a);
list<int> green(list<int> a);
list<int> blue(list<int> a);
list<int> indigo(list<int> a);
list<int> violet(list<int> a);

//the winning function
//rewrite the parameters for the
//convinience of searching and other operation
int winning(int rule, list<int> palette[], bool active[],
            int num_players, int current_rule);


#endif