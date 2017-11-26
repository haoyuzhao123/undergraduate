#include "rules.h"
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//rewrite the implementations of the rules
//only small changes


//first is greater, then return true
//otherwise return false
bool compare(list<int> a, list<int> b) {
    if (a.size() == 0) {
        return false;
    }
    else if (a.size() > b.size()) {
        return true;
    }
    else if (a.size() < b.size()) {
        return false;
    }
    else {
        return (*max_element(a.begin(), a.end()) >
                *max_element(b.begin(), b.end()));
    }
}

list<int> red(list<int> a) {
    list<int> r;
    r.push_back(*max_element(a.begin(),a.end()));
    return r;
}

list<int> orange(list<int> a) {
    list<int> n[8],best;
    for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
        n[(int)(*it/10)].push_back(*it);
    }

    best=n[1];
    for (int i=2;i<8;i++) {
        if (compare(n[i],best)) best=n[i];
    }

    return best;   

}

list<int> yellow(list<int> a) {
    list<int> n[8],best;
    for (list<int>::iterator it=a.begin();it!=a.end();it++)
        n[*it%10].push_back(*it);

    best=n[1];
    for (int i=2;i<8;i++)
        if (compare(n[i],best)) best=n[i];

    return best;   

}

list<int> green(list<int> a) {
    list<int> r;
    for (list<int>::iterator it=a.begin();it!=a.end();it++)
        if (((int)(*it/10))%2==0) r.push_back(*it);
    return r;
}

list<int> blue(list<int> a) {
    int m_color[8]={0,0,0,0,0,0,0,0};
    for (list<int>::iterator it=a.begin();it!=a.end();it++)
        if (*it>m_color[*it%10]) m_color[*it%10]=*it;
    list<int> r;
    for (int i=1;i<8;i++)
        if (m_color[i]>0) r.push_back(m_color[i]);
    return r;

}

list<int> indigo(list<int> a) {
    int m_number[8]={0,0,0,0,0,0,0,0};
    for (list<int>::iterator it=a.begin();it!=a.end();it++)
        if (*it>m_number[(int)(*it/10)]) m_number[(int)(*it/10)]=*it;

    list<int> best, current;
    for (int i=1;i<8;i++)
        if (m_number[i]==0) current.clear();
        else {
            current.push_back(m_number[i]);
            if (compare(current,best)) best=current;
        }

    return best;
}

list<int> violet(list<int> a) {
    list<int> r;
    for (list<int>::iterator it=a.begin();it!=a.end();it++)
        if (((int)(*it/10))<4) r.push_back(*it);

    return r;
}


int winning(int rule, list<int> palette[], bool active[],
            int num_players, int current_rule) {

    if (rule==0) rule=current_rule;
    int i,win;
    win=-1;
    list<int> best, top;
    for (i=0;i<num_players;i++)
        if (active[i]) {
            top.clear();
            switch (rule) {
                case 7: top=red(palette[i]); break;
                case 6: top=orange(palette[i]); break;
                case 5: top=yellow(palette[i]); break;
                case 4: top=green(palette[i]); break;
                case 3: top=blue(palette[i]); break;
                case 2: top=indigo(palette[i]); break;
                case 1: top=violet(palette[i]); break;
            }
      
            if (compare(top,best)) {
	            best=top;
	            win=i;
            }
        }
    //  highest=best;
    return win;
}