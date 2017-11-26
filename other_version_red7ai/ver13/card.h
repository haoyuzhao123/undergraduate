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

inline int getNum(Card card) {
    int res = card >> 4;
    return res;
}
inline int getCol(Card card) {
    int res = card & (0x0F);
    return res;
}

//conver a integer to a Card
Card intToCard(int i);

//conver a Card to an integer
int cardToInt(Card i);

//get the ith card in a set of cards, start from 0
inline Card getCard(Cards hand, int i) {
    return *((Card*)&hand + i);
}

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



#endif