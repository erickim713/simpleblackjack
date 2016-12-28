//
// Created by HyungWoo on 23/12/2016.
//
#include "card.h"
#include <vector>
#ifndef CARDGAMES_DECK_H
#define CARDGAMES_DECK_H

class Deck{

public:
    int counter = 0;
    //deck creator
    std::vector<Card> actualdeck;
    std::vector<int> record;
    Card arrayofCards[52];
    int arrayofindexes[52];
    Deck();
    void printthedeck();
    void shufflethedeck();
    std::vector<Card> returnthedeck();
    void emptydeck();
    //TODO:: I need to make the random function for shuffling the deck randomly.

};
#endif //CARDGAMES_DECK_H
