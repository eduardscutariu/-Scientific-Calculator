#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;
#include "ExtendedCalculator.h"

int main(int argc, char* argv[]) {
    ExtendedCalculator calc;

    if (argc > 1) {
        string intrare = argv[1];
        try {
            double rezultat = calc.evalueaza(intrare);
            string rezultatStr = to_string(rezultat);
            size_t zecimal = rezultatStr.find('.');
            if (zecimal != string::npos) {
                size_t nonZero = rezultatStr.find_last_not_of('0');
                if (nonZero != string::npos) {
                    if (rezultatStr[nonZero] == '.') {
                        rezultatStr = rezultatStr.substr(0, nonZero);
                    }
                    else {
                        rezultatStr = rezultatStr.substr(0, nonZero + 1);
                    }
                }
            }
            cout << "Rezultat: " << rezultatStr << endl;
        }
        catch (const char* msg) {
            cout << "Eroare: " << msg << endl;
        }
    }
    else {
        while (true) {
            cout << "Meniu:\n";
            cout << "1. Introdu o ecuatie\n";
            cout << "2. Salveaza rezultatul curent\n";
            cout << "3. Citeste ecuatii din fisier\n";
            cout << "4. Iesire\n";
            cout << "Alege o optiune: ";
            int optiune;
            cin >> optiune;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (optiune) {
            case 1: {
                string intrare;
                cout << "Introdu o expresie: ";
                getline(cin, intrare);
                try {
                    double rezultat = calc.evalueaza(intrare);
                    string rezultatStr = to_string(rezultat);
                    size_t zecimal = rezultatStr.find('.');
                    if (zecimal != string::npos) {
                        size_t nonZero = rezultatStr.find_last_not_of('0');
                        if (nonZero != string::npos) {
                            if (rezultatStr[nonZero] == '.') {
                                rezultatStr = rezultatStr.substr(0, nonZero);
                            }
                            else {
                                rezultatStr = rezultatStr.substr(0, nonZero + 1);
                            }
                        }
                    }
                    cout << "Rezultat: " << rezultatStr << endl;
                }
                catch (const char* msg) {
                    cout << "Eroare: " << msg << endl;
                }
                break;
            }
            case 2: {
                string numeVariabila;
                cout << "Introdu numele variabilei in care doresti sa salvezi rezultatul: ";
                cin >> numeVariabila;
                double valoare = calc.obtineUltimulRezultat();
                calc.seteazaVariabila(numeVariabila, valoare);
                cout << "Rezultatul a fost salvat în variabila " << numeVariabila << endl;
                break;
            }
            case 3: {
                string numeFisierIntrare;
                cout << "Introdu numele fisierului din care doresti sa citesti ecuatiile: ";
                cin >> numeFisierIntrare;
                ifstream fisierIntrare(numeFisierIntrare);
                if (!fisierIntrare.is_open()) {
                    cout << "Nu s-a putut deschide fisierul de intrare." << endl;
                    break;
                }
                cout << "Doresti sa afisezi rezultatele la consola sau intr-un fisier text? (c/f): ";
                char optiune;
                cin >> optiune;
                ofstream fisierIesire;
                if (optiune == 'f') {
                    string numeFisierIesire;
                    cout << "Introdu numele fisierului in care doresti sa salvezi rezultatele: ";
                    cin >> numeFisierIesire;
                    fisierIesire.open(numeFisierIesire);
                    if (!fisierIesire.is_open()) {
                        cout << "Nu s-a putut deschide fisierul de iesire." << endl;
                        break;
                    }
                }
                string linie;
                while (getline(fisierIntrare, linie)) {
                    try {
                        double rezultat = calc.evalueaza(linie);
                        if (optiune == 'c') {
                            cout << "Rezultat: " << setprecision(numeric_limits<double>::max_digits10) << rezultat << endl;
                        }
                        else if (optiune == 'f') {
                            fisierIesire << "Rezultat: " << setprecision(numeric_limits<double>::max_digits10) << rezultat << endl;
                        }
                    }
                    catch (const char* msg) {
                        cout << "Eroare: " << msg << endl;
                    }
                }
                fisierIntrare.close();
                if (fisierIesire.is_open()) {
                    fisierIesire.close();
                }
                break;
            }
            case 4:
            {
                return 0;
                break;
            }

            }
        }


        // Testăm metoda seteazaUltimaExpresie
        try {
            calc.seteazaUltimaExpresie("2 + 2");
        }
        catch (const char* msg) {
            cout << "Eroare: " << msg << endl;
        }

        // Testăm metoda obtineUltimaExpresie
        cout << "Ultima expresie: " << calc.obtineUltimaExpresie() << endl;

        // Testăm metoda evalueaza
        try {
            double rezultat = calc.evalueaza(calc.obtineUltimaExpresie());
            cout << "Rezultatul evaluarii: " << rezultat << endl;
        }
        catch (const char* msg) {
            cout << "Eroare: " << msg << endl;
        }

        // Testăm metoda statică obtineUltimulRezultat
        cout << "Ultimul rezultat: " << Calculator::obtineUltimulRezultat() << endl;

        // Testăm operatorul de negație !
        Calculator negatie = !calc;
        cout << "Negatia ultimului rezultat: " << negatie << endl;

        // Testăm operatorii ==
        Calculator calc2;
        calc2.seteazaUltimaExpresie("3 + 3");
        cout << "Cele doua calculatoare : " << (calc == calc2 ? "" : "nu sunt ") << "egale." << endl;
        cout << "Primul calculator : " << (calc < calc2 ? "" : "nu este ") << "mai mic decat al doilea calculator." << endl;

        // Testăm operatorii >> și <<
        cout << "Introdu o expresie pentru test: " << endl;
        cin >> calc;
        cout << calc;
        return 0;
    }
    return 0;
}
