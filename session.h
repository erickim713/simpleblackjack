//
// Created by HyungWoo on 24/12/2016.
//

#include "deck.h"
#include "player.h"

#ifndef CARDGAMES_SESSION_H
#define CARDGAMES_SESSION_H



class session{
public:
    Deck t2;
    session();
    bool beginning_prompt();
    std::string initialization();
    void mixanddistribute(player *a1, player *a2);
    void pointcalc(player *a1, player *a2);
    void printstatus(player *a1, player *a2);
    void offerquestion();
    bool askformorecard(player *a1);
    void draw_session_during_game(player *a1);
    void end_message(player *a1, player *a2);
};

#endif //CARDGAMES_SESSION_H
