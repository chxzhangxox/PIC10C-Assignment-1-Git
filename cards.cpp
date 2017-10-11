#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/*
 You might or might not need these two extra libraries
 #include <iomanip>
 #include <algorithm>
 */


/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string suitnameEng;
    switch (suit){
        case OROS:
            suitnameEng = "coins";
            break;
        case COPAS:
            suitnameEng = "cups";
            break;
        case ESPADAS:
            suitnameEng = "swords";
            break;
        case BASTOS:
            suitnameEng = "clubs";
            break;
        default: break;
    }
    return suitnameEng;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string ranknameEng;
    switch(rank){
        case AS:
            ranknameEng = "One";
            break;
        case DOS:
            ranknameEng = "Two";
            break;
        case TRES:
            ranknameEng = "Three";
            break;
        case CUATRO:
            ranknameEng = "Four";
            break;
        case CINCO:
            ranknameEng = "Five";
            break;
        case SEIS:
            ranknameEng = "Six";
            break;
        case SIETE:
            ranknameEng = "Seven";
            break;
        case SOTA:
            ranknameEng = "Ten";
            break;
        case CABALLO:
            ranknameEng = "Eleven";
            break;
        case REY:
            ranknameEng = "Twelve";
            break;
        default: break;
    }
return ranknameEng;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */

//Constructor
Hand::Hand(){
    //initialize two variables
    cards;
    sum = 0;
}

//Accessor
//compute the sum of hand cards
double Hand::sumCard() const{
    double sum = 0;
    const double larger7 = 0.5;
    for (size_t i = 0; i < cards.size(); i++){
        if (cards[i].get_rank() > 7)
            sum += larger7;
        else
            sum += cards[i].get_rank();
    }
    return sum;
}

//Accessor
//return the humber of cards of hand cards
int Hand::size() const{
    return cards.size();
}

//print hand cards to console
void Hand::print_to_console(){
    const int WIDTH = 20;
    for (size_t i = 0; i < cards.size(); i++){
        string SpanishName = cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit();
        string EnglishName = cards[i].get_english_rank() + " of " + cards[i].get_spanish_suit();
        cout << "        " << setw(WIDTH) << left << SpanishName << setw(WIDTH) << left << EnglishName << endl;
    }
    return;
}

//print some hand card to console (in our program, we always print out the last element: new card)
void Hand::print_to_console(int n){
    if (n > cards.size())
        cout << "wrong number";
    const int WIDTH = 20;
    string SpanishName = cards[n].get_spanish_rank() + " de " + cards[n].get_spanish_suit();
    string EnglishName = cards[n].get_english_rank() + " of " + cards[n].get_spanish_suit();
    cout << "        " << setw(WIDTH) << left << SpanishName << setw(WIDTH) << left << EnglishName << endl;
    return;
}

//print hand hard to log file
void Hand::print_to_file(ofstream& fout){
    const int WIDTH = 20;
    for (size_t i = 0; i < cards.size(); i++){
        string SpanishName = cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit();
        string EnglishName = cards[i].get_english_rank() + " of " + cards[i].get_spanish_suit();
        fout << "        " << setw(WIDTH) << left << SpanishName << setw(WIDTH) << left << EnglishName << endl;
    }
    return;
}

//Mutator
//draw a random card from the deck and add it to hand cards
void Hand::draw_card(){
    Card newCard;
    cards.push_back(newCard);
    return;
}

//reset the handcards to 0
void Hand::resetHand(){
    cards.resize(0);
    return;
}

/* *************************************************
 Player class
 ************************************************* */

//Constructor: initialize the money
Player::Player(int m){
    money = m;
}
//Accessor
//get the total money left
int Player::get_money() const{
    return money;
}

//Mutator
//set the new amount of money after each round
int Player::set_money(int n) {
    money += n;
    return money;
}

