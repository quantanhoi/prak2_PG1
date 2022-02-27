#ifndef AUF2_H
#define AUF2_H
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define log(x) cout << x << endl;
int spalte1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
int spalte2[12] = {13,14,15,16,17,18,19,20,21,22,23,24};
int spalte3[12] = {25,26,27,28,29,30,31,32,33,34,35,36};
std::vector<int> black;                                                 // odd and even (aufgabe 2.3)
std::vector<int> red;
void AddEvenRange(int begin, int end, std::vector<int>& destination) {
    if(begin%2 == 1) begin++;
    for(; begin <= end; begin+=2) destination.push_back(begin);
}
void AddOddRange(int begin, int end, std::vector<int>& destination) {
    if(begin %2 == 0) begin++;
    for(; begin <= end; begin+=2) destination.push_back(begin);
}

class Spieler{
public:
    Spieler() {einsatz = 10000;}   //default constructor
    int getEinsatz();
    bool checkEinsatz();
    void addEinsatz(int geld, double multiplier);
protected:
    int einsatz;                                 //geld
    bool check{true};
};
int Spieler::getEinsatz()  {
    return einsatz;
}
bool Spieler::checkEinsatz() {
    if(einsatz < 0) check = false;
    return check;
}
class Roulette:Spieler {      //inheritance
private:
    int random;        //random number that will be generated
    int betamount;     //amount to bet
    char spielmodi;   //Spiel Modi
    int wettezahl; //die Zahl, auf die er wettet;
    char farbe;    // Farbe
    int spalte;    //Spalte
public:
    int getEinsatz();
    int getRandom();    //function to create random number, which is gonna be our lucky number
    int getBetAmount();   //the amount of money you wanna bet
    int getSpalte();      //if you want to choose a specific column to bet
    char getFarbe();      //chose a specific color to bet
    int getWetteZahl();
    void Spiel();          //choose mode to play
    void checkresult();
    int play();            //combine play and check result
    void addEinsatz();     //if win add money
    Roulette() {random = -1; betamount = 0; wettezahl = -1; farbe = 'n'; spalte = -1; spielmodi = 'n';} //default constructor 'n' for none
};
#endif // AUF2_H
