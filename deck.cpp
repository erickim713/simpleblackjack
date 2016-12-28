//
// Created by HyungWoo on 23/12/2016.
//

#include <iostream>
#include "deck.h"
#include "card.h"
#include <algorithm>
#include <random>


Deck::Deck() {
    for (int i = 0; i<4; i++){
        for(int j = 1; j<14; j++){
            Card card(j, i);
            arrayofCards[13*i + (j-1)] = card;
            arrayofindexes[13*i + (j-1)] = 13*i + (j-1);
//            actualdeck.push_back(card);
        }
    }
}

std::vector<Card> Deck::returnthedeck() {return actualdeck;}

void Deck::shufflethedeck(){
    std::cout << "shuffling the deck..." << std::endl;
    //i haven't found a smart way to shuffle the deck... how do you shuffle a list of objects... i am still clueless
    //instead i will just put all the cards into an array
    // and the just shuffle the indexes. and then push into the vector based on the index.
    //TODO if i have time i should fix this process since it takes forever, for this one
    // i don't know why it won't accept the random number generator function in the random_shuffle function's third argument
    std::random_shuffle(std::begin(arrayofindexes), std::end(arrayofindexes));

    while(counter <52){
        srand(time(NULL));
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,51); // distribution in range [1, 6]
        int y = dist6(rng);
        bool found = (std::find(record.begin(), record.end(), y) != record.end());
        if(found){
            continue;
        }
        else{
            actualdeck.push_back(arrayofCards[arrayofindexes[y]]);
            record.push_back(y);
            counter++;
        }
    }
    counter = 0;
}

void Deck::emptydeck() {
    //cleans out the deck
    while(!actualdeck.empty()){
        actualdeck.pop_back();
        record.pop_back();
    }
}

void Deck::printthedeck() {
    if(actualdeck.empty()){
        std::cout<<"It's empty!!!\n";
    }
    else{
        std::vector<Card>::const_iterator iterator;
        for(iterator = actualdeck.begin(); iterator != actualdeck.end(); ++iterator){
            std::cout << iterator->value<<std::endl;
            std::cout << iterator->typeofthecards<<std::endl;
        }
    }
}

