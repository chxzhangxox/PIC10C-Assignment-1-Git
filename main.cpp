//
//  Chenxi Zhang
//  Student ID: 604450251
//  Professor: Salazar Ricardo
//  Program: design a Spanish card game
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include <cmath>

using namespace std;

const int WIDTH = 20; //formatting use

int main(){
    //initialize hand card
    Hand myHand;
    Hand dealerHand;
    
    //initialize money they have
    int moneyP = 100;
    int moneyD = 900;
    
    //initialize bet and count (document # of rounds)
    int bet = 0;
    int count = 0;
    
    //set up initial money P and D have
    string response;
    Player player(moneyP);
    Player dealer(moneyD);
    
    ofstream fout;
    fout.open("gamelog.txt");
    
    
    
    while (player.get_money() > 0 && dealer.get_money() > 0){
        
        myHand.resetHand();
        dealerHand.resetHand();
        count++;
        
        string gameNumber = "Game number: " + to_string(count);
        string moneyLeft = "Money left: $" + to_string(player.get_money());
        
        cout << "You have $" << player.get_money() << ". Enter bet: ";
        cin >> bet;
        
        if (bet > player.get_money()){
            cout << "You entered the bet more than the money you have" << endl;
            return 0;
        }
        else{
            do{
                //player draws a card
                myHand.draw_card();
                if (myHand.size()>1){
                    cout << "New card:" << endl;
                    myHand.print_to_console(myHand.size() - 1);
                    cout << "\nYour cards: " << endl;
                }
                else
                    cout << "Your cards: " << endl;
                myHand.print_to_console();
                cout << "Your total is " << myHand.sumCard() << ". Do you want another card (y/n)?";
                cin >> response;
            }while (response == 'y' && myHand.sumCard() < 7.5);
        }
        
        //dealer draws a card
        do{
            dealerHand.draw_card();
            if (dealerHand.size() > 1){
                cout << "\nNew card:" << endl;    //print out the new card
                dealerHand.print_to_console(dealerHand.size() - 1);
            }
            cout << "\nDealer's cards: " << endl;
            dealerHand.print_to_console();
            cout << "The dealer's total is " << dealerHand.sumCard() << "." << endl;
        } while (dealerHand.sumCard() < 5.5);  //do it while the sum of card is less than 5.5
        
        /*determine the result of the game and set the money*/
        if (myHand.sumCard() <= 7.5 && dealerHand.sumCard() > 7.5){
            cout << "\nYou win " << bet << "." << endl;
            player.set_money(bet);
            dealer.set_money(-bet);
        }
        else if (myHand.sumCard() > 7.5 && dealerHand.sumCard() <= 7.5){
            cout << "\nToo bad. You lose " << bet << "." << endl;
            player.set_money(-bet);
            dealer.set_money(bet);
        }
        else if ((myHand.sumCard() > 7.5) < (dealerHand.sumCard() > 7.5)){
            cout << "\nToo bad. You lose " << bet << "." << endl;
            player.set_money(-bet);
            dealer.set_money(bet);
        }
        else if (pow(myHand.sumCard() - 7.5,2) > (pow(dealerHand.sumCard() - 7.5,2))){
            cout << "\nToo bad. You lose " << bet << "." << endl;
            player.set_money(-bet);
            dealer.set_money(bet);
        }
        else if ((pow(myHand.sumCard() - 7.5,2)) < (pow(dealerHand.sumCard() - 7.5,2))){
            cout << "\nYou win " << bet << "." << endl;
            player.set_money(bet);
            dealer.set_money(-bet);
        }
        else{
            cout <<"\nNobody Wins!" << endl;
            player.set_money(0);
            dealer.set_money(0);
        }
        
        
    }
    return 0;
}
