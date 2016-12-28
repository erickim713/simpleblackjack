//
// Created by HyungWoo on 23/12/2016.
//

#include "card.h"
#include <iostream>

Card ::Card(const int v, const int t){
    value = v;
    if(t == 4){
        typeofthecards = "not assigned";
    }
    else if(t == 3){
        typeofthecards = "clover";
    }
    else if(t == 2){
        typeofthecards = "heart";
    }
    else if(t == 1){
        typeofthecards = "diamond";
    }
    else if(t == 0){
        typeofthecards = "spade";
    }
    else{
    }

}
//this is probably more for poker style.
void Card::printthecard() {
    std::cout << "this is the value of the card: " << value << "  and this is the type of the card:  " << typeofthecards << std::endl;
}



