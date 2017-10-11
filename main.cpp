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
        
    }
    return 0;
}
