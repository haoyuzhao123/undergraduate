#ifndef CARD_H_
#define CARD_H_

//this file contains the definition of a card, the definition
//of a palette, and the definition of a hand

//use a char to represent a card
//the first 4 bit is the number of the card
//the next 4 bit is the color
typedef char Card;

//use a long long to represent a hand or a palette
//cards can store 8 card, and the last bit is never used
//the when the 64th bit is 1, it means that the there are
//not 8 cards, and the 8th byte can denote the size
//if the 64th bit is 0, then there are 8 card in the hand
typedef long long Cards;

const Cards noCards = 0xF000000000000000;

//the comparision of 2 cards
//return 0 if the first is larger than the second
int largeCard(Card first, Card second);

int getNum(Card card);
int getCol(Card card);

//conver a integer to a Card
Card intToCard(int i);

//conver a Card to an integer
int cardToInt(Card i);

//get the ith card in a set of cards, start from 0
Card getCard(Cards hand, int i);

//return the size of cards
int sizeOfCards(Cards hand);

//return the maximum card in a hand
Card maxCard(Cards hand);

//return the larger of 2 hands, 0 means the first
//and 1 the second, if return -1, something wrong happens
int largeCards(Cards first, Cards second);

//set up a hand of null cards
Cards nullCards();

//delete card at ith place, start from 0
Cards deleteCard(Cards hand, int i);

//insert card at ith place, start from 0
Cards insertCard(Cards hand, int i, Card card);

//faster deletion and insertion at the last of the card
Cards pushBack(Cards hand, Card card);
Cards popBack(Cards hand);

//remove certain card from hand
Cards removeCard(Cards hand, Card card);

//the best cards of each rule
Cards red(Cards hand);
Cards orange(Cards hand);
Cards yellow(Cards hand);
Cards green(Cards hand);
Cards blue(Cards hand);
Cards indigo(Cards hand);
Cards violet(Cards hand);

int winning(Cards palette[], int rule);

//the implemention of the card operations
int largeCard(Card first, Card second) {
    int card1 = first;
    int card2 = second;
    if (first > second)
        return 0;
    else
        return 1;
}

inline int getNum(Card card) {
    int res = card >> 4;
    return res;
}

inline int getCol(Card card) {
    int res = card & (0x0F);
    return res;
}

Card intToCard(int i) {
    char num = (char)(i / 10);
    char col = (char)(i % 10);
    Card res = num << 4 | col;
    return res;
}

int cardToInt(Card i) {
    int num = i >> 4;
    int col = i & (0x0F);
    return 10 * num + col;
}

inline Card getCard(Cards hand, int i) {
    return *((Card*)&hand + i);
}

int sizeOfCards(Cards hand) {
    if (hand > 0)
        return 8;
    else {
        int temp = (hand >> 56) & (0x0F);
        return temp;
    }
}

Card maxCard(Cards hand) {
    Card res = 0x00;
    Card temp;
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        if (largeCard(res, (temp = getCard(hand, i))))
            res = temp;
    }
    return res;
}

int largeCards(Cards first, Cards second) {
    int sizefirst = sizeOfCards(first);
    int sizesecond = sizeOfCards(second);
    if (sizefirst < sizesecond)
        return 1;
    else if (sizefirst > sizesecond)
        return 0;
    else if (sizefirst == 0 && sizesecond == 0)
        return -1;
    else {
        Card maxfirst = maxCard(first);
        Card maxSecond = maxCard(second);
        if (largeCard(maxfirst, maxSecond))
            return 1;
        else
            return 0;
    }
}

inline Cards nullCards() {
    Cards res = 0xF000000000000000;
    return res;
}

Cards deleteCard(Cards hand, int i) {
    int size = sizeOfCards(hand);
    if (size <= 1) {
        Cards res = 0xF000000000000000;
        return res;
    }
    else {
        long long temp = 0xF000000000000000;
        long long newsize = size - 1;
        long long mask = 0xFFFFFFFFFFFFFFFF;

        long long masknew;
        if (i != 0) {
            masknew = mask & 0x0FFFFFFFFFFFFFFF;
            masknew = (masknew >> (8 * (8-i)));
            long long temp2 = 0x000000000000000F;
            masknew = masknew | (temp2 << (8*i-4));
        }
        else if (i == 0)
            masknew = 0;
        
        if (i == 7)
            mask = 0;
        else
            mask = (mask << (8 * (i + 1)));

        Cards res = (hand & masknew)
                    | (((hand & mask) >> 8) & 0x00FFFFFFFFFFFFFF)
                    | temp
                    | (newsize << 56);

        if (size != 8)
            res = res & 0xFF00FFFFFFFFFFFF;
        return res;
    }
}

Cards insertCard(Cards hand, int i, Card card1) {
    Cards newcard = card1;
    long long temp = 0xF000000000000000;
    unsigned long long mask = 0xFFFFFFFFFFFFFFFF;

    long long masknew;
    if (i != 0) {
        masknew = (mask >> (8 * (8-i)));
    }
    else if (i == 0)
        masknew = 0;
        
    if (i == 7)
        mask = 0;
    else
        mask = (mask << (8 * i));

    Cards res = (hand & masknew)
                | ((hand & mask) << 8)
                | (newcard << (8 * i));
    long long sizehand = sizeOfCards(hand);
    if (sizehand < 7) {
        sizehand++;
        res = res
            | 0xF000000000000000
            | (sizehand << 56);
    }
    return res;
}

Cards removeCard(Cards hand, Card card) {
    int handsize = sizeOfCards(hand);
    for (int j = 0; j < handsize; j++)
        if (getCard(hand, j) == card)
            return deleteCard(hand, j);
    
    return hand;
}

Cards pushBack(Cards hand, Card card) {
    int i = sizeOfCards(hand);
    if (i == 7) {
        long long t = 0xFF;
        long long temp = ~(t << 56);
        Cards newcard = card;
        Cards newhand = hand;
        newhand = (newhand & temp) | (newcard << 56);
        return newhand;
    }
    else {
        long long j = i + 1;
        long long t = 0xF;
        long long temp = ~(t << 56);
        Cards newcard = card;
        Cards newhand = hand;
        newhand = (newhand & temp) | (newcard << (8 * i)) | (j << 56);
        return newhand;
    }
}

Cards popBack(Cards hand) {
    int i = sizeOfCards(hand);
    if (i == 1)
        return noCards;
    else {
        long long j = i - 1;
        long long t = 0xF;
        long long temp = ~(t << 60);
        long long temp2 = temp >> (8 * (8 - i) + 4);
        Cards newhand = hand;
        newhand = newhand & temp2;
        newhand = newhand | (j << 56) | (~temp);
        return newhand;
    }
}

//the rules of red7
Cards red(Cards hand) {
    Card c = maxCard(hand);
    Cards res = noCards;
    return pushBack(res, c);
}

Cards orange(Cards hand) {
    Cards n[8], best;
    for (int i = 1; i < 8; i++)
        n[i] = noCards;
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card card = getCard(hand, i);
        int t = getNum(card);
        n[t] = pushBack(n[t], card);
    }
    best = n[1];
    for (int i = 2; i < 8; i++)
        if (largeCards(best, n[i])) best = n[i];
    
    return best;
}

Cards yellow(Cards hand) {
    Cards n[8], best;
    for (int i = 1; i < 8; i++) n[i] = noCards;
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card c = getCard(hand, i);
        int col = getCol(c);
        n[col] = pushBack(n[col], c);
    }
    best = n[1];
    for (int i = 2; i < 8; i++)
        if (largeCards(best, n[i])) best = n[i];
    
    return best;
}

Cards green(Cards hand) {
    Cards res = noCards;
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card c = getCard(hand, i);
        int num = getNum(c);
        if (num % 2 == 0) res = pushBack(res, c);
    }
    return res;
}

Cards blue(Cards hand) {
    int m_color[8] = {0,0,0,0,0,0,0,0};
    Card best[8] = {0,0,0,0,0,0,0,0};
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card c = getCard(hand, i);
        int col = getCol(c);
        if (largeCard(best[col], c)) best[col] = c;
    }
    Cards res = noCards;
    for (int i = 1; i < 8; i++)
        if (best[i] != 0) res = pushBack(res, best[i]);
    return res;
}

Cards indigo(Cards hand) {
    Card m_number[8] = {0,0,0,0,0,0,0,0};
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card c = getCard(hand, i);
        int num = getNum(c);
        if (largeCard(m_number[num], c)) m_number[num] = c;
    }
    Cards res = noCards;
    Cards cur = noCards;
    for (int i = 1; i < 8; i++)
        if (m_number[i] == 0) cur = noCards;
        else {
            cur = pushBack(cur, m_number[i]);
            if (largeCards(res, cur)) res = cur;
        }
    
    return res;
}

Cards violet(Cards hand) {
    Cards res = noCards;
    int sizeofhand = sizeOfCards(hand);
    for (int i = 0; i < sizeofhand; i++) {
        Card c = getCard(hand, i);
        if ((c >> 4) < 4) res = pushBack(res, c);
    }
    return res;
}

int winning(Cards palette[], int rule) {
    int res;
    switch (rule) {
        case 7: res = largeCards(red(palette[0]), red(palette[1])); break;
        case 6: res = largeCards(orange(palette[0]), orange(palette[1])); break;
        case 5: res = largeCards(yellow(palette[0]), yellow(palette[1])); break;
        case 4: res = largeCards(green(palette[0]), green(palette[1])); break;
        case 3: res = largeCards(blue(palette[0]), blue(palette[1])); break;
        case 2: res = largeCards(indigo(palette[0]), indigo(palette[1])); break;
        case 1: res = largeCards(violet(palette[0]), violet(palette[1])); break;
    }
    return res;
}


#endif
