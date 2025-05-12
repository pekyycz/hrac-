#include <iostream>
using namespace std;

void vypisClassu(int cislo) {
    switch (cislo) {
        case 1:
            cout << "Class: Paladin\n";
            cout << "Zivoty: 5/5\n";
            cout << "Mana: 5/5\n";
            cout << "Utok: 3\n";
            cout << "Schopnosti:\n";
            cout << "- Utok: Uder za 3 poskozeni\n";
            cout << "- Uder svetlem: 1 poskozeni vsem (2 many)\n";
            cout << "- Oziveni: +1 zivot (1 mana)\n";
            break;
        case 2:
            cout << "Class: Lovec\n";
            cout << "Zivoty: 4/4\n";
            cout << "Mana: 3/3\n";
            cout << "Utok: 4\n";
            cout << "Schopnosti:\n";
            cout << "- Strela: 4 poskozeni\n";
            cout << "- Vypad: dvojity utok (1 mana)\n";
            break;
        case 3:
            cout << "Class: Mag\n";
            cout << "Zivoty: 3/3\n";
            cout << "Mana: 7/7\n";
            cout << "Utok: 2\n";
            cout << "Schopnosti:\n";
            cout << "- Koule: 5 poskozeni (2 many)\n";
            cout << "- Ohen: vsem poskozeni (3 many)\n";
            cout << "- Stit: snizeni poskozeni (1 mana)\n";
            break;
        default:
            cout << "Neplatna volba.\n";
    }
}

void vesnice(int zivoty, int maxzivoty, int mana, int maxmana, int utok, int goldy = 20) {
    cout << "\n--- Vitej ve vesnici! ---\n";
    cout << "Ze zacatku mas 20 goldu.\n";

    int volba;
    while (true) {
        cout << "\n---------- V E S N I C E ----------" << endl;
        cout << "Zivoty: " << zivoty << "/" << maxzivoty << endl;
        cout << "Mana: " << mana << "/" << maxmana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Goldy: " << goldy << endl;

        cout << "\nVyber z moznosti:\n";
        cout << "1 - Doplnit +1 zivot (3 goldy)\n";
        cout << "2 - Doplnit +1 manu (2 goldy)\n";
        cout << "3 - Zvysit max zivoty o 1 (5 goldu)\n";
        cout << "4 - Zvysit utok o 1 (7 goldu)\n";
        cout << "5 - Odejit\n";
        cout << "Tvoje volba: ";
        cin >> volba;

        switch (volba) {
            case 1:
                if (zivoty >= maxzivoty) {
                    cout << "Mas plne zivoty.\n";
                } else if (goldy < 3) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    zivoty++;
                    goldy -= 3;
                    cout << "Doplnil sis +1 zivot.\n";
                }
                break;
            case 2:
                if (mana >= maxmana) {
                    cout << "Mas plnou manu.\n";
                } else if (goldy < 2) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    mana++;
                    goldy -= 2;
                    cout << "Doplnil sis +1 many.\n";
                }
                break;
            case 3:
                if (goldy < 5) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    maxzivoty++;
                    goldy -= 5;
                    cout << "Zvysil sis max zivoty o 1.\n";
                }
                break;
            case 4:
                if (goldy < 7) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    utok++;
                    goldy -= 7;
                    cout << "Zvysil sis utok o 1.\n";
                }
                break;
            case 5:
                cout << "Opustil jsi vesnici.\n";
                return;
            default:
                cout << "Neplatna volba.\n";
        }
    }
}

void menu() {
    cout << "\nVyber si classu:\n";
    cout << "1 - Paladin\n";
    cout << "2 - Lovec\n";
    cout << "3 - Mag\n";
    cout << "Zadej cislo classy: ";
}

int main() {
    int vyber = 0;
    char potvrzeni = 'n';
    string jmeno;

    cout << "Ahoj, vitam te v me hre! Jak se jmenujes?: ";
    cin >> jmeno;

    int zivoty = 0, maxzivoty = 0, mana = 0, maxmana = 0, utok = 0;

    while (potvrzeni != 'y') {
        menu();
        cin >> vyber;

        if (vyber >= 1 && vyber <= 3) {
            vypisClassu(vyber);
            cout << "\nChces tuto classu? (y/n): ";
            cin >> potvrzeni;
        } else {
            cout << "Neplatny vyber, zkus znovu.\n";
        }
    }

    switch (vyber) {
        case 1: zivoty = maxzivoty = 5; mana = maxmana = 5; utok = 3; break;
        case 2: zivoty = maxzivoty = 4; mana = maxmana = 3; utok = 4; break;
        case 3: zivoty = maxzivoty = 3; mana = maxmana = 7; utok = 2; break;
    }

    cout << "\n" << jmeno << ", classa uspesne vybrana!\n";
    vesnice(zivoty, maxzivoty, mana, maxmana, utok);

    return 0;
}
