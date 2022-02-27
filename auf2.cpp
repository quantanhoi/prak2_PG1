#include "auf2.h"
int Roulette::getEinsatz() {
    return einsatz;
}
void Roulette::addEinsatz() {
    if(spalte != -1) {
        einsatz = einsatz + betamount *2;
    }
    if(wettezahl != -1 ) {
        einsatz = einsatz + betamount *36;
    }
    if(farbe != 'n' ) {
        einsatz = einsatz + betamount *3;
    }
}
int Roulette::getRandom() {
    srand (time(NULL));
    random = rand() % 37 + 0;                                      //random number generator
    return random;
}
int Roulette::getBetAmount() {
    cout << "Please Enter the amount you want to bet: ";
    cin >> betamount;
    if(betamount < 0 || betamount > getEinsatz()) {
        throw std::runtime_error{"You don't have enough money or have entered an insufficient amount"};
    }
    einsatz = einsatz - betamount;
    return betamount;
}
void Roulette::Spiel() {
    cout << "Please choose a mode: \nf. Farbe(Rot oder Schwarz)\ns. Spalte (1, 2, 3)\nz. Einzelne Zahl( 0 - 36)\n choice: ";
    cin >> spielmodi;
    switch (spielmodi) {
        case 's':
            getSpalte();
            break;
        case 'f':
            getFarbe();
            break;
        case'z':
            getWetteZahl();
            break;
        default:
            break;
    }
}
char Roulette::getFarbe() {
    cout << "Choose your color (r for red, s for schwarz): ";
    cin >> farbe;
    if(farbe != 'r' && farbe != 's') {
        log("Fail to choose a color");
        farbe = 'n';                        //back to default
        return 0;
    }
    getBetAmount();
    return farbe;
}
int Roulette::getWetteZahl() {
    cout << "Choose your bet number: ";
    cin >> wettezahl;
    if(wettezahl < 0 || wettezahl > 36) {
        log("Fail to choose a number");
        wettezahl = -1;                 //back to default
        return 0;
    }
    getBetAmount();
    return wettezahl;
}
int Roulette::getSpalte() {
    cout << "Choose your column: ";
    cin >> spalte;
    if(spalte > 3 || spalte < 1 ) {
        log("Fail to choose a column");
        spalte = -1;                       //back to default
        return 0;
    }
    getBetAmount();
    return spalte;
}
void Roulette::checkresult() {
    if((wettezahl != -1 || spalte!= -1) || farbe != 'n' ) {
        cout <<"The random number is: " << getRandom() << endl;
        int column{};  //variable zum pruefen
        int* columnfind{};
        if(spalte != -1) {
                columnfind = std::find(spalte1, spalte1+12, wettezahl);    //spalte = 1st 12, 2nd 12, 3rd 12
                if (columnfind != spalte1+12) {
                    column = 1;
                    log("Die Spalte ist 1");
                }
                else {
                    columnfind = find(spalte2, spalte2+12, wettezahl);
                    if(columnfind != spalte2+12) {
                        column = 2;
                        log("Die Spalte ist 2");

                    }
                    else {
                        column = 3;
                        log("Die Spalte ist 3");
                    }

                }
            /*if(spalte == 3) {
                if(random%3 == 0) {
                    log("You won!!");
                    addEinsatz();
                }
                else {
                    log("You lose :(");
                }
            }
            else {
                if(random%3 == spalte) {
                    log("You won!!");
                    addEinsatz();
                }
                else {
                    log("You lose :(");
                }
            }*/
            /*if(random%3==1) {    //spalte1 = 1, 4, 7, 10,...
                column = 1;
            }
            if(random%3==2) {
                column = 2;
            }
            if(random%3==3) {
                column = 3;
            }
            if(spalte == column) {
                log("You won!!");
                addEinsatz();
            }
            else {
                log("You lose :(");
            }*/
            if (column == spalte) {               //1st 12 part 2
                log("You won");
                addEinsatz();
            }
            else {
                log("You lose :(");
            }
        }
        if(farbe != 'n') {
            if(farbe == 's') {
                auto find = std::find(black.begin(), black.end(), wettezahl);
                if(find == black.end()) {
                    log("You won!!");
                    addEinsatz();
                }
                else {
                    log("You lose :(")
                }
            }
        }
        if(wettezahl != -1) {
            if(wettezahl == random) {
                log("You won!!");
                addEinsatz();
            }
            else {
                log("You lose :(")
            }
        }
    }
    cout << "You now have: " << einsatz << endl;
}
int Roulette::play(){
    Spiel();
    if((spielmodi != 's' && spielmodi != 'z') && spielmodi != 'f') {
        return 0;
    }
    checkresult();
    return 0;
}
