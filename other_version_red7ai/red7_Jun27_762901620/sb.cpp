#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>

#include "rules.h"
#include "alpha_beta.h"

using namespace std;

ofstream outstr;


int main(int argc, char *argv[]) {
    srand(clock());
    outstr.open("file.txt",ios::app);
    //change the global variables into local
    int num_players;
    int player_index;
    int current_rule;

    list<int> palette[MAX_PLAYERS];
    bool active[MAX_PLAYERS];
    list<int> hand;
    int hand_size[MAX_PLAYERS];

    //begin the original codes
    cin >> num_players;
    cin >> player_index;
    cin >> current_rule;

    int i,j,n,m;
    cin >> n;
    for (i=0;i<n;i++) {
        cin >> m;
        hand.push_back(m);
    }

    for (i=0;i<num_players;i++)
    {
        cin >> hand_size[i];
        cin >> n;
        if (n==0) active[i]=false;
        else {
	        active[i]=true;
	        for (j=0;j<n;j++)
	        {
	            cin >> m;
	            palette[i].push_back(m);
	        }
        }
    }

    list<int> original;
    list<int>::iterator it,it2;

    /*
    int count_method = 0;
    if (hand_size[player_index] == 7) {
    for (it=hand.begin();it!=hand.end();it++)
    {
        original=palette[player_index];
        palette[player_index].push_back(*it);

        if (winning(0, palette, active, num_players, current_rule)==player_index) {
            count_method ++;
        }

        palette[player_index]=original;
      
    }
  
    for (it=hand.begin();it!=hand.end();it++)
        if (winning(*it%10, palette, active, num_players, current_rule)==player_index) {
            count_method++;
        }

    for (it=hand.begin();it!=hand.end();it++)
        for (it2=hand.begin();it2!=hand.end();it2++)
            if (it!=it2) {
	            original=palette[player_index];
	            palette[player_index].push_back(*it);

	            if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                count_method++;
	            }

	            palette[player_index]=original;
	
            }
    
    if (count_method <= 6) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    int max_card = 0;
    for (it = hand.begin(); it != hand.end(); it++) {
        if (*it > max_card) {
            max_card = *it;
        }
    }
    if (max_card <= 5) {
        cout << 0 << " " << endl;
    }
    }
    */
/*
    if (hand_size[0] + hand_size[1] == 7) {
        move reply = best_move(palette, hand, hand_size, active,
                                num_players, current_rule, player_index, 100, 4);
        cout << reply.first << " " << reply.second << endl;
        return 0;
    }
    if (hand_size[0] + hand_size[1] == 6) {
        move reply = best_move(palette, hand, hand_size, active,
                                num_players, current_rule, player_index, 200, 6);
        cout << reply.first << " " << reply.second << endl;
        return 0;
    }
*/
    if (hand_size[0] + hand_size[1] <= 5) {
        move reply = best_move(palette, hand, hand_size, active,
                                num_players, current_rule, player_index, 500, 6);
        cout << reply.first << " " << reply.second << endl;
        return 0;
    }


    if (hand_size[player_index] >= 5) {
        cout << "asdfasdf" << endl;
        outstr << "begin mcts" << endl;
        move reply = mcts(palette, player_index, hand, hand_size, current_rule, 1);
        cout << reply.first << " " << reply.second << endl;
        outstr << reply.first << " " << reply.second << endl;
        outstr.close();
    }


/*
    if (hand_size[player_index] >= 4) {
        move reply = best_move(palette, hand, hand_size, active,
                                num_players, current_rule, player_index, 300, 3);
        cout << reply.first << " " << reply.second << endl;
        return 0;
    }
*/


    for (it=hand.begin();it!=hand.end();it++)
    {
        original=palette[player_index];
        palette[player_index].push_back(*it);

        if (winning(0, palette, active, num_players, current_rule)==player_index) {
	    cout << 0 << " " << *it << endl;
	    return 0;
        }

        palette[player_index]=original;
      
    }
  
    for (it=hand.begin();it!=hand.end();it++)
        if (winning(*it%10, palette, active, num_players, current_rule)==player_index) {
            cout << *it << " " << 0 << endl;
            return 0;
        }

    for (it=hand.begin();it!=hand.end();it++)
        for (it2=hand.begin();it2!=hand.end();it2++)
            if (it!=it2) {
	            original=palette[player_index];
	            palette[player_index].push_back(*it);

	            if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                cout << *it2 << " " << *it << endl;
	                return 0;
	            }

	            palette[player_index]=original;
	
            }
      
    cout << 0 << " " << 0 << endl;
    return 0;
 
}