#include "auf2.cpp"
int main() try {
    Spieler spieler1;
    Roulette roulett;
    char choice{'y'};
    AddEvenRange(1,36,red);
    AddOddRange(1,36,black);
    while(choice != 'n') {
        roulett.play();
        log("Do you want to continue? (y/n)");
        cin >> choice;
    }
    log("end");
}
catch(std::runtime_error& re) {
    std::cerr << re.what(); //what: return the explanatory string, std::cerr : standard output stream for error
    return -1;  //Programmende mit return-Wert !=0
}
