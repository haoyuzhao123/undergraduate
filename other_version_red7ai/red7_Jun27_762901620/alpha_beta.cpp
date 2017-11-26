#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <fstream>

#include "rules.h"
#include "alpha_beta.h"

using namespace std;

//const int INF = 10000000;

//define a struct to store each move
//the first is the card that change the rules
//the second is the card that put in the palette
//the score is the final score

/*
struct move {
    int first;
    int second;
    int score;
};
*/

void print_list_on_screen(list<int> a) {
  for (list<int>::iterator it=a.begin();it!=a.end();it++)
    cout << *it << " ";
  cout << endl;
}

move alpha_beta(int alpha, int beta, list<int> palette[], list<int> hand0, list<int> hand1,
            bool active[], int num_players, int current_rule, int player_index, int max_depth) {
    move best;
    best.first = 0;
    best.second = 0;
    move reply;

    if (max_depth == 0) {
        best.score = 5 * (hand0.size() - hand1.size());
        return best;
    }

    //cout << "hand0" << endl;
    //print_list_on_screen(hand0);
    //cout << "hand1" << endl;
    //print_list_on_screen(hand1);
    //cout << "palette[0]" << endl;
    //print_list_on_screen(palette[0]);
    //cout << "palette[1]" << endl;
    //print_list_on_screen(palette[1]);
    //cout << endl;
    //cout << endl;

    list<int> hand;
    if (player_index == 0) {
        hand = hand0;
        best.score = alpha;
    }
    else {
        hand = hand1;
        best.score = beta;
    }

    list<int> original = hand;
    list<int>::iterator it, it2;

    int count = 0;

    for (it = original.begin(); it != original.end(); it++) {
        palette[player_index].push_back(*it);

        if (winning(0, palette, active, num_players,
             current_rule) == player_index) {
            count ++;

            int card = *it;
            hand.remove(*it);
            if (player_index == 0) {
                reply = alpha_beta(alpha, beta, palette, hand, hand1, 
                            active, num_players, current_rule, 1 - player_index, max_depth - 1);
                if (reply.score > alpha) {
                    best.first = 0;
                    best.second = card;
                    best.score = reply.score;
                    alpha = best.score;
                    //cout << "debugging! modifying alpha: " << alpha << endl;
                }
            }
            else if (player_index == 1) {
                reply = alpha_beta(alpha, beta, palette, hand0, hand, 
                            active, num_players, current_rule, 1 - player_index, max_depth - 1);
                if (reply.score < beta) {
                    best.first = 0;
                    best.second = card;
                    best.score = reply.score;
                    beta = best.score;
                    //cout << "debugging! modifying beta: " << beta << endl;
                }
            }
            hand = original;
            //cout << "debugging! pass the recover of the hand!" << endl;

            if (alpha >= beta) {
                palette[player_index].pop_back();
                return best;
            }

        }
        palette[player_index].pop_back();
        //cout << "debugging! pass the recover of the palette!" << endl;
    }

    //cout<<"debugging! pass the first set of possible moves!" << "  this is player: " << player_index << endl;

    for (it = original.begin(); it != original.end(); it++) {
        if (winning(*it%10, palette, active, num_players,
             current_rule) == player_index) {
            count ++;

            int card = *it;
            hand.remove(*it);
            if (player_index == 0) {
                reply = alpha_beta(alpha, beta, palette, hand, hand1, 
                            active, num_players, *it%10, 1 - player_index, max_depth - 1);
                if (reply.score > alpha) {
                    best.first = card;
                    best.second = 0;
                    best.score = reply.score;
                    alpha = best.score;
                }
            }
            else if (player_index == 1) {
                reply = alpha_beta(alpha, beta, palette, hand0, hand, 
                            active, num_players, *it%10, 1 - player_index, max_depth - 1);
                if (reply.score < beta) {
                    best.first = card;
                    best.second = 0;
                    best.score = reply.score;
                    beta = best.score;
                }
            }
            hand = original;

            if (alpha >= beta) {
                return best;
            }

        }
    }

    //cout << "debugging! pass the second set of possible moves!" << "  this is player: " << player_index << endl;

    for (it = original.begin(); it != original.end(); it++) {
        for (it2 = original.begin(); it2 != original.end(); it2++) {
            if (it!=it2) {
	            palette[player_index].push_back(*it);

	            if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                count ++;

                    int card1 = *it2;
                    int card2 = *it;
                    hand.remove(*it);
                    hand.remove(*it2);

                    if (player_index == 0) {
                        reply = alpha_beta(alpha, beta, palette, hand, hand1, 
                            active, num_players, *it2%10, 1 - player_index, max_depth - 1);
                        if (reply.score > alpha) {
                            best.first = card1;
                            best.second = card2;
                            best.score = reply.score;
                            alpha = best.score;
                        }
                    }
                    else if (player_index == 1) {
                        reply = alpha_beta(alpha, beta, palette, hand0, hand, 
                            active, num_players, *it2%10, 1 - player_index, max_depth - 1);
                        if (reply.score < beta) {
                            best.first = card1;
                            best.second = card2;
                            best.score = reply.score;
                            beta = best.score;
                        }
                    }
                    hand = original;

                    if (alpha >= beta) {
                        return best;
                    }


	            }

	            palette[player_index].pop_back();
	
            }
        }
    }

    //cout << "debugging! pass the third set of the possible moves!" << "  this is player: " << player_index << endl;

    if (count > 0) {
        return best;
    }
    else {
        list<int> win_palette = palette[1 - player_index];
        list<int> top;
        switch (current_rule) {
            case 7: top=red(win_palette); break;
            case 6: top=orange(win_palette); break;
            case 5: top=yellow(win_palette); break;
            case 4: top=green(win_palette); break;
            case 3: top=blue(win_palette); break;
            case 2: top=indigo(win_palette); break;
            case 1: top=violet(win_palette); break;
        }
        int value = 0;
        for (list<int>::iterator itr = top.begin(); itr != top.end(); itr++) {
            value += (int)(*itr / 10);
        }
        best.score = (2 * player_index - 1) * value;
        //cout << "player: " << 1-player_index << " wins"<<endl;
        //cout << "the score is: " << best.score << endl;
        return best;
    }

}

void insert_move_to_list(list<move> & move_list, move e) {
    list<move>::iterator itr;
    for (itr = move_list.begin();;itr++) {
        if (itr == move_list.end()) {
            move_list.push_back(e);
            break;
        }
        move f = *itr;
        if (f.first == e.first && f.second == e.second) {
            (*itr).score += e.score;
            break;
        }

    }
}

move best_move(list<int> palette[], list<int> hand, int hand_size[],
            bool active[], int num_players, int current_rule, int player_index, int MAX_ITER, int max_depth) {
    srand(clock());
    bool used[49];
    memset(used, 0, sizeof(used));

    list<int>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }
    for (it = palette[0].begin(); it != palette[0].end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }
    for (it = palette[1].begin(); it != palette[1].end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }

    list<move> move_list;

    for (int j = 0; j < MAX_ITER; j++) {
        list<int> oppo_hand;
        bool used2[49];
        memcpy(used2, used, sizeof(used));

        for (int i = 0; i < hand_size[1-player_index]; i++) {
            while (true) {
                int temp = rand() % 49;
                if (!used2[temp]) {
                    used2[temp] = true;
                    int a = (int)(temp / 7);
                    int b = temp % 7;
                    int value = 10 * (a + 1) + (b + 1);
                    oppo_hand.push_back(value);
                    break;
                }
            }
        }

        list<int> hands[2];

        if (player_index == 0) {
            hands[0] = hand;
            hands[1] = oppo_hand;
        }
        else {
            hands[0] = oppo_hand;
            hands[1] = hand;
        }

        list<int> original;
        list<int>::iterator it,it2;
        for (it=hand.begin();it!=hand.end();it++)
        {
            original=palette[player_index];
            palette[player_index].push_back(*it);

            if (winning(0, palette, active, num_players, current_rule)==player_index) {
	            move e;
                e.first = 0;
                e.second = *it;
                list<int> new_hands[2];
                new_hands[0] = hands[0];
                new_hands[1] = hands[1];
                new_hands[player_index].remove(*it);
                move reply = alpha_beta(-INF, INF, palette, new_hands[0], new_hands[1], 
                                        active, 2, current_rule, 1 - player_index, max_depth - 1);
                e.score = reply.score;

                insert_move_to_list(move_list, e);
                
            }

            palette[player_index]=original;
      
        }
  
        for (it=hand.begin();it!=hand.end();it++)
            if (winning(*it%10, palette, active, num_players, current_rule)==player_index) {
                move e;
                e.first = *it;
                e.second = 0;
                list<int> new_hands[2];
                new_hands[0] = hands[0];
                new_hands[1] = hands[1];
                new_hands[player_index].remove(*it);
                move reply = alpha_beta(-INF, INF, palette, new_hands[0], new_hands[1], 
                                        active, 2, (*it)%10, 1 - player_index, max_depth - 1);
                e.score = reply.score;

                insert_move_to_list(move_list, e);
            }

        for (it=hand.begin();it!=hand.end();it++)
            for (it2=hand.begin();it2!=hand.end();it2++)
                if (it!=it2) {
	                original=palette[player_index];
	                palette[player_index].push_back(*it);

	                if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                    move e;
                        e.first = *it2;
                        e.second = *it;
                        list<int> new_hands[2];
                        new_hands[0] = hands[0];
                        new_hands[1] = hands[1];
                        new_hands[player_index].remove(*it);
                        new_hands[player_index].remove(*it2);
                        move reply = alpha_beta(-INF, INF, palette, new_hands[0], new_hands[1], 
                                                active, 2, (*it2)%10, 1 - player_index, max_depth - 1);
                        e.score = reply.score;

                        insert_move_to_list(move_list, e);
	                }

	                palette[player_index]=original;
	
                }

        


    }

    move minm, maxm;
    minm.first = 0;
    minm.second = 0;
    maxm.first = 0;
    maxm.second = 0;
    minm.score = INF;
    maxm.score = -INF;

    list<move>::iterator itr;
    for (itr = move_list.begin(); itr != move_list.end(); itr++) {
        if((*itr).score < minm.score) {
            minm = (*itr);
        }
        if((*itr).score > maxm.score) {
            maxm = (*itr);
        }
    }

    if (player_index == 0) {
        return maxm;
    }
    else {
        return minm;
    }

}

move random_move(list<int> palette[], int player_index, list<int> hands[], int current_rule) {
    list<int>::iterator it, itr, it2;
    list<int> original;
    list<move> move_list;
    
    ofstream debug;
    debug.open("randommove.txt", ios::app);

    move reply;
    bool active[] = {true, true};
    int num_players = 2;
    reply.first = 0;
    reply.second = 0; 
    reply.score = 0;
    list<int> hand = hands[player_index];
    for (it=hand.begin();it!=hand.end();it++)
    {
        original=palette[player_index];
        palette[player_index].push_back(*it);

        if (winning(0, palette, active, num_players, current_rule)==player_index) {
            reply.first = 0;
            reply.second = *it;
            move_list.push_back(reply);
        }

        palette[player_index]=original;
      
    }
  
    for (it=hand.begin();it!=hand.end();it++)
        if (winning(*it%10, palette, active, num_players, current_rule)==player_index) {
            reply.first = *it;
            reply.second = 0;
            move_list.push_back(reply);
        }

    for (it=hand.begin();it!=hand.end();it++)
        for (it2=hand.begin();it2!=hand.end();it2++)
            if (it!=it2) {
	            original=palette[player_index];
	            palette[player_index].push_back(*it);

	            if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                reply.first = *it2;
                    reply.second = *it;
                    move_list.push_back(reply);
	            }

	            palette[player_index]=original;
	
            }
      
    if (move_list.size() == 0) {
        reply.first = 0;
        reply.second = 0;
        debug << reply.first << " " << reply.second << endl;
        return reply;
    }
    else {
        srand(clock());
        int move_size = move_list.size();
        int t = rand() % t;
        list<move>::iterator itr = move_list.begin();;
        for (int i = 0; i <= t; i++) {
            itr++;
        }
        debug << (*itr).first << " " << (*itr).second << endl;
        return *itr;
    }
}

int random_score(list<int> palette[], int player_index, list<int> hands[], int current_rule) {
    ofstream debug;
    debug.open("randomscore.txt", ios::app);
    debug << "begin random_score" << endl;
    move reply = random_move(palette, player_index, hands, current_rule);
    if (reply.first == 0 && reply.second == 0) {
        debug << "enter first" << endl;
        list<int> win_palette = palette[1 - player_index];
        list<int> top;
        switch (current_rule) {
            case 7: top=red(win_palette); break;
            case 6: top=orange(win_palette); break;
            case 5: top=yellow(win_palette); break;
            case 4: top=green(win_palette); break;
            case 3: top=blue(win_palette); break;
            case 2: top=indigo(win_palette); break;
            case 1: top=violet(win_palette); break;
        }
        int value = 0;
        for (list<int>::iterator itr = top.begin(); itr != top.end(); itr++) {
            value += (int)(*itr / 10);
        }
        reply.score = (2 * player_index - 1) * value;
        debug << "leave first" << endl;
        //cout << "player: " << 1-player_index << " wins"<<endl;
        //cout << "the score is: " << best.score << endl;
        return reply.score;
    }
    else if (reply.first == 0 && reply.second != 0) {
        debug << "enter second" << endl;
        palette[player_index].push_back(reply.second);
        hands[player_index].remove(reply.second);
        debug << "leave second" << endl;
        return random_score(palette, 1 - player_index, hands, current_rule);
    }
    else if (reply.first != 0 && reply.second == 0) {
        debug << "enter third" << endl;
        hands[player_index].remove(reply.first);
        debug << "leave third" << endl;
        return random_score(palette, 1 - player_index, hands, reply.first % 10);
    }
    else {
        debug << "enter fouth" << endl;
        palette[player_index].push_back(reply.second);
        hands[player_index].remove(reply.second);
        hands[player_index].remove(reply.first);
        debug << "leave fourth" << endl;
        return random_score(palette, 1 - player_index, hands, reply.first % 10);
    }
}

move mcts(list<int> palette[], int player_index, list<int> hand, int hand_size[], int current_rule, int MAX_ITER) {
    srand(clock());

    ofstream debug;
    debug.open("mcts.txt", ios::app);
    
    bool used[49];
    memset(used, 0, sizeof(used));
    bool active[] = {true, true};
    int num_players = 2;

    int MAX_ITER2 = 10;

    list<int>::iterator it;
    for (it = hand.begin(); it != hand.end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }
    for (it = palette[0].begin(); it != palette[0].end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }
    for (it = palette[1].begin(); it != palette[1].end(); it++) {
        int temp = *it;
        int a = (int)(*it / 10);
        int b = *it % 10;
        used[7 * (a-1) + (b-1)] = true;
    }

    list<move> move_list;

    debug << "begin enter random sample" << endl;

    for (int j = 0; j < MAX_ITER; j++) {
        list<int> oppo_hand;
        bool used2[49];
        memcpy(used2, used, sizeof(used));

        for (int i = 0; i < hand_size[1-player_index]; i++) {
            while (true) {
                int temp = rand() % 49;
                if (!used2[temp]) {
                    used2[temp] = true;
                    int a = (int)(temp / 7);
                    int b = temp % 7;
                    int value = 10 * (a + 1) + (b + 1);
                    oppo_hand.push_back(value);
                    break;
                }
            }
        }

        list<int> hands[2];

        if (player_index == 0) {
            hands[0] = hand;
            hands[1] = oppo_hand;
        }
        else {
            hands[0] = oppo_hand;
            hands[1] = hand;
        }

        debug << "begin simulation for a hand" << endl;
        debug.close();

        for (int k = 0; k <= MAX_ITER2; k++) {
        list<int> original;
        list<int>::iterator it,it2;
        for (it=hand.begin();it!=hand.end();it++)
        {
            original=palette[player_index];
            palette[player_index].push_back(*it);

            if (winning(0, palette, active, num_players, current_rule)==player_index) {
	            move e;
                e.first = 0;
                e.second = *it;
                list<int> new_hands[2];
                new_hands[0] = hands[0];
                new_hands[1] = hands[1];
                new_hands[player_index].remove(*it);
                list<int> new_palette[2];
                new_palette[0] = palette[0];
                new_palette[1] = palette[1];

                int m_score = random_score(new_palette, 1-player_index, new_hands, current_rule);

                e.score = m_score;

                insert_move_to_list(move_list, e);
                
                
            }

            palette[player_index]=original;
      
        }
  
        for (it=hand.begin();it!=hand.end();it++)
            if (winning(*it%10, palette, active, num_players, current_rule)==player_index) {
                move e;
                e.first = *it;
                e.second = 0;
                list<int> new_hands[2];
                new_hands[0] = hands[0];
                new_hands[1] = hands[1];
                new_hands[player_index].remove(*it);
                list<int> new_palette[2];
                new_palette[0] = palette[0];
                new_palette[1] = palette[1];
                int m_score = random_score(new_palette, 1-player_index, new_hands, e.first % 10);
                e.score = m_score;

                insert_move_to_list(move_list, e);
            }

        for (it=hand.begin();it!=hand.end();it++)
            for (it2=hand.begin();it2!=hand.end();it2++)
                if (it!=it2) {
	                original=palette[player_index];
	                palette[player_index].push_back(*it);

	                if (winning(*it2%10, palette, active, num_players, current_rule)==player_index) {
	                    move e;
                        e.first = *it2;
                        e.second = *it;
                        list<int> new_hands[2];
                        new_hands[0] = hands[0];
                        new_hands[1] = hands[1];
                        new_hands[player_index].remove(*it);
                        new_hands[player_index].remove(*it2);
                        list<int> new_palette[2];
                        new_palette[0] = palette[0];
                        new_palette[1] = palette[1];
                        int m_score = random_score(new_palette, 1-player_index, new_hands, e.first % 10);
                        e.score = m_score;

                        insert_move_to_list(move_list, e);
	                }

	                palette[player_index]=original;
	
                }


        }


    }

    move minm, maxm;
    minm.first = 0;
    minm.second = 0;
    maxm.first = 0;
    maxm.second = 0;
    minm.score = INF;
    maxm.score = -INF;

    list<move>::iterator itr;
    for (itr = move_list.begin(); itr != move_list.end(); itr++) {
        if((*itr).score < minm.score) {
            minm = (*itr);
        }
        if((*itr).score > maxm.score) {
            maxm = (*itr);
        }
    }

    if (player_index == 0) {
        return maxm;
    }
    else {
        return minm;
    }
}

/*

int main() {
    list<int> hand0;
    list<int> hand1;

    int hand_size[2];
    hand_size[0] = 3;
    hand_size[1] = 1;

    //hand1.push_back(17);
    //hand1.push_back(27);
    //hand1.push_back(37);
    //hand1.push_back(47);
    hand0.push_back(46);
    hand0.push_back(45);
    hand0.push_back(44);

    list<int> palette[2];
    list<int> temp;
    temp.push_back(77);
    temp.push_back(11);
    temp.push_back(21);
    //temp.push_back(42);
    //temp.push_back(33);

    palette[1] = temp;

    list<int> temp1;
    temp1.push_back(67);
    temp1.push_back(66);
    temp1.push_back(65);
    temp1.push_back(64);
    palette[0] = temp1;

    bool active[] = {true, true};
    int num_players = 2;
    int current_rule = 7;
    int player_index = 0;

    int al = -INF;
    int be = INF;

    //move t = alpha_beta(al, be, palette, hand0, hand1, active, 2, 4, 1);
    //cout<<t.score<<endl;
    move reply = best_move(palette, hand0, hand_size, active, 2, current_rule, 0);
    cout << reply.first << " " << reply.second << endl;

    return 0;
}

*/