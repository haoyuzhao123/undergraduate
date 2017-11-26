#include <iostream>
#include <iomanip>

#include "card.h"

using namespace std;

int main()
{
    Card card1 = 0x77;
    Card card2 = 0x76;

    cout << largeCard(card1, card2) << endl;

    card1 = 0x46;
    card2 = 0x54;
    cout << largeCard(card1, card2) << endl;
    cout << "largeCard test end, should output " << 0 << " " << 1 << endl;

    cout << intToCard(66) << endl;
    cout << intToCard(65) << endl;
    cout << "intToCard test end, should output " << (char)(0x66) << " " << (char)(0x65) << endl;

    cout << cardToInt(card1) << endl;
    cout << cardToInt(card2) << endl;
    cout << "cardToInt test end, should output " << 46 << " " << 54 << endl;

    Cards hand1 = 0xF600123453576423;
    Cards hand2 = 0x7567423562241234;

    cout << getCard(hand1, 1) << endl;
    cout << getCard(hand2, 6) << endl;
    cout << "getCard test end, should output " << (char)(0x64) << " " << (char)(0x67) << endl;

    cout << sizeOfCards(hand1) << endl;
    cout << sizeOfCards(hand2) << endl;
    cout << "sizeOfCards test end, should output " << 6 << " " << 8 << endl;

    cout << hex << (int)maxCard(hand1) << endl;
    cout << hex << (int)maxCard(hand2) << endl;
    cout << "maxCard test end, should output " << hex << 0x64 << " " << 0x75 << endl;

    //cout << hex << nullCards() << endl;
    //cout << "nullCards test end, should output " << hex << 0xF000000000000000 << endl;


    cout << hex << deleteCard(hand1, 2) << endl;
    cout << hex << deleteCard(hand1, 0) << endl;
    cout << hex << deleteCard(hand2, 7) << endl;
    cout << "deleteCard test end, should output " << hex
        << 0xF500001234536423 << " "
        << 0xF500001234535764 << " "
        << 0xF767423562241234 << " "
        << endl;

    //cout << hex << insertCard(nullCards(), 0, 0x12) << endl;
    cout << hex << insertCard(hand1, 3, 0x77) << endl;
    cout << hex << insertCard(hand1, 6, 0x77) << endl;
    cout << hex << insertCard(hand1, 0, 0x77) << endl;
    cout << hex << insertCard(deleteCard(hand2, 5), 5, 0x42) << endl;
    cout << "insertCard test end, should output " << hex
      //<< 0xF100000000000012 << " "
        << 0xF712345377576423 << " "
        << 0xF777123453576423 << " "
        << 0xF712345357642377 << " "
        << hand2 << endl;

    //cout << hex << pushBack(nullCards(), 0x12) << endl;
    cout << hex << pushBack(0xF500001234566543, 0x21) << endl;
    cout << hex << pushBack(0xF712233445566776, 0x65) << endl;

    cout << "pushBack end, should output: " << hex
      //<< 0xF000000000000012 << " "
        << 0xF600211234566543 << " "
        << 0x6512233445566776 << endl;

    cout << hex << popBack(0xF100000000000032) << endl;
    cout << hex << popBack(0xF600211234566543) << endl;
    cout << hex << popBack(0x6512233445566776) << endl;

    //cout << "popBack end, should output: " << hex
    //    << nullCards() << " "
    //    << 0xF500001234566543 << " "
    //    << 0xF712233445566776 << endl;
    
    cout << hex << red(0xF723344556655443) << endl;
    cout << hex << orange(0xF600666765424372) << endl;
    cout << hex << yellow(0x2131415174644536) << endl;
    cout << hex << green(0xF400000064536342) << endl;
    cout << hex << blue(0xF500007756456734) << endl;
    cout << hex << indigo(0xF600122356764534) << endl;
    cout << hex << violet(0xF600423153377614) << endl;

    short s[20];
    cout << dec << sizeof(s) << endl;

    return 0; 

}
