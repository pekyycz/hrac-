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

    cout << "\n" << jmeno << ", classa uspesne vybrana!\n";
    return 0;
}
