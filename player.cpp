//
// Created by HyungWoo on 24/12/2016.
//

#include "card.h"
#include "deck.h"
#include "player.h"
#include <vector>
#include <iostream>

player::player(const std::string x){
    //creator
    if(x.compare("dealer") == 0){
        //this is the dealer set up
        name = "dealer";
    }
    else{
        name = x;
    }
}


void player::currentsituation() {
    for(std::vector<Card>::const_iterator i = hand.begin(); i != hand.end(); i++)   {
        std::cout << dictionary[(i->value) - 1] << "||";
    }
    std::cout << "total card value is: " << current << std::endl;
}

void player::myhand() {
    if(hand.empty()){
        std::cout << "my hand is empty !!" << std::endl;
    }
    else{
        if(name.compare("dealer")==0){
            for(std::vector<Card>::const_iterator i = hand.begin(); i != hand.end(); i++)   {
                if(i == hand.begin()){
                    std::cout << "x" << "||";
                }
                else{
                    std::cout << dictionary[(i->value)-1] << "||";
                }
            }
        }
        else{ //for the guest.
            for(std::vector<Card>::const_iterator i = hand.begin(); i != hand.end(); i++)   {
                std::cout << dictionary[(i->value) - 1] << "||";
            }
        }

        std::cout << std::endl;
    }
}

void player::draw(Card card) {
    if(wantcard){
        hand.push_back(card);

    }
}

bool player::dealercheck() {
    //main logic
    int counter = 0;
    int currentvalue = 0;
    for(std::vector<Card>::const_iterator i = hand.begin(); i!= hand.end(); i++){
        if(i->value >10){
            currentvalue = currentvalue + 10;
        }
        else{
            if(dictionary[(i->value) - 1].compare("Ace") == 0){
                currentvalue = currentvalue + 11;
                counter++;
            }
            else {
                currentvalue = currentvalue + i->value;
            }
        }
    }
    if(currentvalue > 21 && counter >0){
        for(int x = 0; x <counter; x++){
            if(currentvalue>21){
                //use soft value of the ace.
                currentvalue = currentvalue - 10;
            }
        }
    }
    current = currentvalue;
    if(name.compare("dealer")== 0){
        if(currentvalue > 15){
            wantcard = false;
        }
    }
}



