//
// Created by HyungWoo on 23/12/2016.
//

#ifndef CARDGAMES_CARD_H
#define CARDGAMES_CARD_H


#include <string>

//i need to create a card. what does a card have??
// card has: value, color, type of the card (one of the four: Hearts, Spade, Clover, Diamond)
class Card
{
    private:

        //0 means it's not been set, it should be from 1 through

        //0 is spade, 1 is clover, 2 is diamond, 3 is heart, 4 means not specified
    public:
        int value;
        std::string typeofthecards;
        //creator for the card object.
        Card(const int v = 0, const int t = 4);
        //color can be inferred from the typeofthecard: clover and spades are black // hearts and diamonds are red.
        void printthecard();


};

#endif //CARDGAMES_CARD_H
