//
// Created by HyungWoo on 24/12/2016.
//


#include <iostream>
#include "session.h"


session::session() {

}

std::string session::initialization() {
    std::string name;
    std::cout <<"you decided to play! what's your name?" << std::endl;
    std::cin >> name;
    std::cout <<"Hi " << name << ". I am glad to have you as a company!" <<std::endl;
    return name;
}

void session::mixanddistribute(player *a1, player *a2) {
    t2.shufflethedeck();
    t2.actualdeck.pop_back();
    a1->draw(*(t2.actualdeck.end()));
    t2.actualdeck.pop_back();
    a2->draw(*(t2.actualdeck.end()));
    t2.actualdeck.pop_back();
    a1->draw(*(t2.actualdeck.end()));
    t2.actualdeck.pop_back();
    a2->draw(*(t2.actualdeck.end()));
    t2.actualdeck.pop_back();
}

void session::pointcalc(player *a1, player *a2) {
    a1->dealercheck();
    a2->dealercheck();
}

void session::printstatus(player *a1, player *a2) {
    std::cout << "||dealer's hand||" << std::endl;
    a1->myhand();
    std::cout << "||guest's hand||" << a2->current <<std::endl;
    a2->myhand();
}

bool session::askformorecard(player *a1){
    std::string wantmorecard;
    std::cout<< "do you want to more card? yes/y/no/n" <<std::endl;
    std::cin >> wantmorecard;
    if(wantmorecard.compare("N") == 0 || wantmorecard.compare("n") ==0 || wantmorecard.compare("no") ==0 || wantmorecard.compare("No") ==0  || wantmorecard.compare("NO")==0){
        a1->wantcard = false;
        a1->dealercheck();
        std::cout <<"okay so you don't want anymore cards. Got it!" <<std::endl;
        return false;
    }
    else{
        return true;
    }
}

void session::draw_session_during_game(player *a1) {
    a1->draw(*(t2.actualdeck.end()));
    t2.actualdeck.pop_back();
    a1->dealercheck();
}

bool session::beginning_prompt() {
    int playcount = 0;
    //checking if the player wants to play or not. in a continuous loop. why? because he might be trolling by putting random stuff into the console.
    while(playcount == 0){
        std::string x;
        std::cin >> x;
        if(x.compare("Y") == 0 || x.compare("y") ==0 || x.compare("yes") ==0 || x.compare("Yes") ==0  || x.compare("YES")==0){
            playcount++;
        }
        else if(x.compare("N") ==0 || x.compare("n")==0 || x.compare("no") ==0|| x.compare("No")==0 || x.compare("NO")==0){
            std::cout << "Maybe next time then.. See ya later! " << std::endl;
            return false;
        }
        else{
            std::cout << "I didn't understand what you typed in. Do you want to play? choose Yes or No (Y or N)" <<std::endl;
        }
    }
    return true;
}

void session::end_message(player *a1, player *a2) {
    if(a1->current <22 && a2->current <22){
        if(a1->current > a2->current){
            std::cout <<"dealer wins!!" <<std::endl;
        }
        else if(a1->current == a2->current){
            std::cout <<"tied" <<std::endl;
        }
        else {
            std::cout <<"guest wins!!" <<std::endl;
        }
    }
    if(a1->current >21 && a2->current > 21){
        if(a1->current > a2->current){
            std::cout <<"guest wins!!" <<std::endl;
        }
        else if(a1->current == a2->current){
            std::cout <<"tied" <<std::endl;
        }
        else {
            std::cout <<"dealer wins!!" <<std::endl;
        }
    }
    if(a1->current > 21 && a2->current < 22){
        std::cout << "guest wins!!" <<std::endl;
    }
    if(a2->current > 21 && a1->current < 22){
        std::cout << "dealer wins!!" <<std::endl;
    }
}