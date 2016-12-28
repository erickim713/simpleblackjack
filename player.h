//
// Created by HyungWoo on 24/12/2016.
//

#include <string>
#include <vector>
#include "card.h"

#ifndef CARDGAMES_PLAYER_H
#define CARDGAMES_PLAYER_H

#endif //CARDGAMES_PLAYER_H

class player{
public:
    std::string dictionary[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    std::string name;
    std::vector<Card> hand;
    bool wantcard = true;
    int current;
    int points; //how many points till the end of the game.
    player(const std::string x = "dealer");
    void myhand();
    void currentsituation();
    void draw(Card card);

    bool dealercheck();
};