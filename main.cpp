#include <iostream>

#include "session.h"

int main() {
    std::cout << "let's play some blackjack" << std::endl;
    std::cout << "would you like to play? Y/N..." << std::endl;
    //x takes in the string if the player wants to play or not.
    //playcout and not play count is used in the beginning for the continuous prompts. For example, if the user types in something other than yes or no, then
    // I would still have to make sure he gets another chance right?

    std::string name;
    session new_session;
    if(!new_session.beginning_prompt()){
        return 0;
    }
    name = new_session.initialization();
    player dealer;
    player guest(name);
    new_session.mixanddistribute(&dealer, &guest);
    bool keepplaying = true;
    while(keepplaying){
        //status check
        new_session.pointcalc(&dealer, &guest);
        new_session.printstatus(&dealer, &guest);
        //TODO i neeed to work on the distribution and scoring system...
        if(new_session.askformorecard(&guest)){
            new_session.draw_session_during_game(&guest);
            if(guest.current >21){
                keepplaying = false;
            }
        }
        if(dealer.wantcard){
            new_session.draw_session_during_game(&dealer);
            if(dealer.current >21){
                keepplaying = false;
            }
        }
        if(!guest.wantcard && !dealer.wantcard){
            keepplaying = false;
        }
    }
    std::cout <<"dealer status::";
    dealer.currentsituation();
    std::cout <<"guest status::";
    guest.currentsituation();
    new_session.end_message(&dealer, &guest);
    return 0;
}