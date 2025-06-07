#include <iostream>
using namespace std;

void prvniVesnice (int&goldy){
    cout << "ze zacatku mas 40 goldu" <<endl;
    goldy = 40;
}

void vypisClassu(int cislo, int zivoty, int maxzivoty) {
    switch (cislo) {
        case 1:
            cout <<endl;
            cout << "Class: Fighter\n";
            cout << "Zivoty: " << zivoty << "/" << maxzivoty <<endl;
            cout << "Mana: 5/5\n";
            cout << "Utok: 3\n";
            cout <<endl;
            cout << "Schopnosti:\n";
            cout << "- Utok: Uder za 3 poskozeni\n";
            cout << "- Uder svetlem: 1 poskozeni vsem (2 many)\n";
            cout << "- Oziveni: +1 zivot (1 mana)\n";
            break;
        case 2:
            cout <<endl;
            cout << "Class: Marksman\n";
            cout << "Zivoty: " << zivoty << "/" << maxzivoty <<endl;
            cout << "Mana: 3/3\n";
            cout << "Utok: 4\n";
            cout <<endl;
            cout << "Schopnosti:\n";
            cout << "- Strela: 4 poskozeni\n";
            cout << "- Vypad: dvojity utok (1 mana)\n";
            break;
        case 3:
            cout << "Class: Mag\n";
            cout << "Zivoty: " << zivoty << "/" << maxzivoty <<endl;
            cout << "Mana: 10/10\n";
            cout << "Utok: 2\n";
            cout <<endl;
            cout << "Schopnosti:\n";
            cout << "- Koule: 5 poskozeni (2 many)\n";
            cout << "- Ohen: vsem poskozeni (3 many)\n";
            cout << "- Stit: snizeni poskozeni (1 mana)\n";
            break;
        default:
            cout << "Neplatna volba.\n";
    }
}

void vesnice(int& zivoty, int& maxzivoty, int& mana, int& maxmana, int& utok, int& goldy) {
    int volba;
    while (true) {
        cout << "\n---------- V E S N I C E ----------" << endl;
        cout << "PO OPUSTENI TETO VESNICE SE UTKAS S MINI-BOSSEM! NAKUP SI POTREBNE VECI A PRIPRAV SE NA SOUBOJ"<<endl;
        cout <<endl;
        cout << "========= S T A T Y  M I N I B O S S E ==========" << endl;
        cout << "Zivoty: 20" << endl;
        cout << "Utok: 3" << endl;
        cout << "========= T V E  S T A T Y =========="<<endl;
        cout << "Zivoty: " << zivoty << "/" << maxzivoty << endl;
        cout << "Mana: " << mana << "/" << maxmana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Goldy: " << goldy << endl;

        cout << "\nVyber z moznosti:\n";
        cout << "1 - Doplnit +1 zivot (5 goldu)\n";
        cout << "2 - Doplnit +1 manu (4 goldy)\n";
        cout << "3 - Zvysit max zivoty o 1 (10 goldu)\n";
        cout << "4 - Zvysit utok o 1 (14 goldu)\n";
        cout << "5 - Odejit\n";
        cout << "Tvoje volba: ";
        cout <<endl;
        cin >> volba;
        switch (volba) {
            case 1:
                if (zivoty >= maxzivoty) {
                    cout << "Mas plne zivoty.\n";
                } else if (goldy < 5) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    zivoty++;
                    goldy -= 5;
                    cout << "Doplnil sis +1 zivot.\n";
                }
                break;
            case 2:
                if (mana >= maxmana) {
                    cout << "Mas plnou manu.\n";
                } else if (goldy < 4) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    mana++;
                    goldy -= 4;
                    cout << "Doplnil sis +1 many.\n";
                }
                break;
            case 3:
                if (goldy < 10) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    maxzivoty++;
                    goldy -= 10;
                    cout << "Zvysil sis max zivoty o 1.\n";
                }
                break;
            case 4:
                if (goldy < 14) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    utok++;
                    goldy -= 14;
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

void fight(string classa, int& zivoty, int& mana, int utok, int& goldy) {
    int bossHP = 20;
    int bossUtok = 3;

    cout << "\n--- Souboj s malym bossem zacina! ---\n";
    while (bossHP > 0 && zivoty > 0) {
        cout << "\nTvoje HP: " << zivoty << " | Mana: " << mana << endl;
        cout << "Boss HP: " << bossHP << endl;

        if (classa == "Fighter") {
            cout << "Vyber akci:\n";
            cout << "1 - Uder (za " << utok << " poskozeni)\n";
            cout << "2 - Uder svetlem (1 vsem, stoji 2 many)\n";
            cout << "3 - Oziveni (+1 zivot, stoji 1 manu)\n";
        } else if (classa == "Marksman") {
            cout << "Vyber akci:\n";
            cout << "1 - Strela (za 4 poskozeni)\n";
            cout << "2 - Vypad (dvojity utok, stoji 1 manu)\n";
        } else if (classa == "Mag") {
            cout << "Vyber akci:\n";
            cout << "1 - Koule (5 poskozeni, stoji 2 many)\n";
            cout << "2 - Ohen (vsem poskozeni, stoji 3 many)\n";
            cout << "3 - Stit (snižuje poskozeni, stoji 1 manu)\n";
        }

        int volba;
        cin >> volba;

        switch (volba) {
            case 1:
                if (classa == "Fighter") {
                    bossHP -= utok;
                    cout << "Uderil jsi bosse za " << utok << " poskozeni.\n";
                } else if (classa == "Marksman") {
                    bossHP -= 4;
                    cout << "Strelil jsi bosse za 4 poskozeni.\n";
                } else if (classa == "Mag") {
                    if (mana >= 2) {
                        bossHP -= 5;
                        mana -= 2;
                        cout << "Pouzil jsi kouli, boss ztratil 5 HP.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                }
                break;
            case 2:
                if (classa == "Fighter") {
                    if (mana >= 2) {
                        bossHP -= 1;
                        mana -= 2;
                        cout << "Pouzil jsi uder svetlem, boss ztratil 1 HP.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                } else if (classa == "Marksman") {
                    if (mana >= 1) {
                        bossHP -= 8;
                        mana -= 1;
                        cout << "Pouzil jsi vypad, boss ztratil 8 HP.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                } else if (classa == "Mag") {
                    if (mana >= 3) {
                        bossHP -= 6;
                        mana -= 3;
                        cout << "Pouzil jsi ohen, boss ztratil 6 HP.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                }
                break;
            case 3:
                if (classa == "Fighter") {
                    if (mana >= 1) {
                        zivoty += 1;
                        mana -= 1;
                        cout << "Vylecil jsi se o 1 zivot.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                } else if (classa == "Mag") {
                    if (mana >= 1) {
                        bossUtok = max(1, bossUtok - 1);
                        mana -= 1;
                        cout << "Pouzil jsi stit, snizil jsi poskozeni bosse.\n";
                    } else {
                        cout << "Nemas dost many!\n";
                    }
                }
                break;
            default:
                cout << "Neplatna volba.\n";
                continue;
        }

        if (bossHP > 0) {
            zivoty -= bossUtok;
            cout << "Boss na tebe utoci za " << bossUtok << " poskozeni!\n";
        }
    }

    if (zivoty > 0) {
        cout << "\nVyhral jsi nad bossem!\n";
    } else {
        cout << "\nByl jsi porazen bossem...\n";
    }
    goldy += 20;
    cout << "\nZiskal jsi 20 zlatych za vyhru nad minibossem!" << endl;
}

void menu() {
    cout << "\nVyber si classu:\n";
    cout << "1 - Fighter\n";
    cout << "2 - Marksman\n";
    cout << "3 - Mag\n";
    cout << "Zadej cislo classy: ";
}

void prochazkaLesem() {
    cout << "Vydavas se na cestu lesem..." <<endl;
    cout << endl;
    cout << "Je ticho. Jen sem tam zaslechnes sovu nebo prasknuti vetve..."<<endl;
    cout << endl;
    cout << "Z NICOTY NA TEBE VYSKOCI OBROVSKY BOSS!"<<endl;
    cout << endl;
}

void mensiBossFight(string classa, int& zivoty, int& mana, int utok, int& goldy) {
    int bossHP = 28;
    int bossUtok = 4;

    cout << "\n--- SOUBOJ S BOSSEM ZACINA! ---\n";
    while (bossHP > 0 && zivoty > 0) {
        cout << "Tvoje HP: " << zivoty << " | Mana: " << mana << endl;
        cout << "Boss HP: " << bossHP << endl;

        if (classa == "Fighter") {
            cout << "1 - Uder (" << utok << " dmg)\n";
            cout << "2 - Uder svetlem (1 dmg vsem, 2 many)\n";
            cout << "3 - Oziveni (+1 HP, 1 mana)\n";
        } else if (classa == "Marksman") {
            cout << "1 - Strela (4 dmg)\n";
            cout << "2 - Vypad (8 dmg, 1 mana)\n";
            cout << "3 - Leceni (+1 HP, 1 mana)\n";
        } else if (classa == "Mag") {
            cout << "1 - Koule (5 dmg, 2 many)\n";
            cout << "2 - Ohen (6 dmg, 3 many)\n";
            cout << "3 - Stit (snižuje dmg bossa, 1 mana)\n";
            cout << "4 - Leceni (+1 HP, 1 mana)\n";
        }

        int volba;
        cin >> volba;

        switch (volba) {
            case 1:
                if (classa == "Fighter") {
                    bossHP -= utok;
                    cout << "Uderil jsi bosse za " << utok << " poskozeni.\n";
                } else if (classa == "Marksman") {
                    bossHP -= 4;
                    cout << "Strelil jsi bosse za 4 poskozeni.\n";
                } else if (classa == "Mag") {
                    if (mana >= 2) {
                        bossHP -= 5;
                        mana -= 2;
                        cout << "Koule zasahla, 5 dmg.\n";
                    } else cout << "Nemas dost many!\n";
                }
                break;

            case 2:
                if (classa == "Fighter") {
                    if (mana >= 2) {
                        bossHP -= 1;
                        mana -= 2;
                        cout << "Uder svetlem zasahl za 1 dmg.\n";
                    } else cout << "Nemas dost many!\n";
                } else if (classa == "Marksman") {
                    if (mana >= 1) {
                        bossHP -= 8;
                        mana -= 1;
                        cout << "Pouzil jsi vypad za 8 dmg.\n";
                    } else cout << "Nemas dost many!\n";
                } else if (classa == "Mag") {
                    if (mana >= 3) {
                        bossHP -= 6;
                        mana -= 3;
                        cout << "Ohen zasahl za 6 dmg.\n";
                    } else cout << "Nemas dost many!\n";
                }
                break;

            case 3:
                if (classa == "Fighter" || classa == "Marksman") {
                    if (mana >= 1) {
                        zivoty += 1;
                        mana -= 1;
                        cout << "Vylecil jsi se o 1 HP.\n";
                    } else cout << "Nemas dost many!\n";
                } else if (classa == "Mag") {
                    if (mana >= 1) {
                        bossUtok = max(1, bossUtok - 1);
                        mana -= 1;
                        cout << "Stit aktivni, boss bude delat mensi dmg.\n";
                    } else cout << "Nemas dost many!\n";
                }
                break;

            case 4:
                if (classa == "Mag") {
                    if (mana >= 1) {
                        zivoty += 1;
                        mana -= 1;
                        cout << "Vylecil jsi se o 1 HP.\n";
                    } else cout << "Nemas dost many!\n";
                } else {
                    cout << "Neplatna volba.\n";
                }
                break;

            default:
                cout << "Neplatna volba.\n";
                continue;
        }

        if (bossHP > 0) {
            zivoty -= bossUtok;
            cout << "Boss na tebe utoci za " << bossUtok << " poskozeni!\n";
        }
    }

    if (zivoty > 0) {
        cout << "\nPorazil jsi velkeho bosse! Vyborne!\n";
        goldy += 30;
        cout << "Ziskal jsi 30 zlatych!\n";
    } else {
        cout << "\nByl jsi porazen. Zkus to znovu lepe pripravene.\n";
    }
}



void druhaVesnice(int& zivoty, int& maxzivoty, int& mana, int& maxmana, int& utok, int& goldy) {
    int volba;
    while (true) {
        cout << "\n---------- D R U H A  V E S N I C E ----------" << endl;
        cout << "--- Staty ---" << endl;
        cout << "Zivoty: " << zivoty << "/" << maxzivoty << endl;
        cout << "Mana: " << mana << "/" << maxmana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Goldy: " << goldy << endl;

        cout << "\nVyber z moznosti:\n";
        cout << "1 - Doplnit +1 zivot (5 goldy)\n";
        cout << "2 - Doplnit +1 manu (4 goldy)\n";
        cout << "3 - Zvysit max zivoty o 1 (10 goldu)\n";
        cout << "4 - Zvysit utok o 1 (14 goldu)\n";
        cout << "5 - Odejit\n";
        cout << "Tvoje volba: ";
        cin >> volba;

        switch (volba) {
            case 1:
                if (zivoty >= maxzivoty) {
                    cout << "Mas plne zivoty.\n";
                } else if (goldy < 5) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    zivoty++;
                    goldy -= 5;
                    cout << "Doplnil sis +1 zivot.\n";
                }
                break;
            case 2:
                if (mana >= maxmana) {
                    cout << "Mas plnou manu.\n";
                } else if (goldy < 4) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    mana++;
                    goldy -= 4;
                    cout << "Doplnil sis +1 many.\n";
                }
                break;
            case 3:
                if (goldy < 10) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    maxzivoty++;
                    goldy -= 10;
                    cout << "Zvysil sis max zivoty o 1.\n";
                }
                break;
            case 4:
                if (goldy < 14) {
                    cout << "Nemas dostatek goldu.\n";
                } else {
                    utok++;
                    goldy -= 14;
                    cout << "Zvysil sis utok o 1.\n";
                }
                break;
            case 5:
                cout << "Opustil jsi vesnici.\n";
                cout << endl;
                return;
            default:
                cout << "Neplatna volba.\n";
        }
    }
}


int main() {
    int vyber = 0;
    int goldy = 40;
    char potvrzeni = 'n';
    string jmeno;

    cout << "Ahoj, vitam te v me hre! Jak se jmenujes(bez mezer prosim)?: ";
    cin >> jmeno;

    int zivoty = 0, maxzivoty = 0, mana = 0, maxmana = 0, utok = 0;
    string classa;

    while (potvrzeni != 'y') {
        menu();
        cin >> vyber;

        if (vyber >= 1 && vyber <= 3) {
            if (vyber == 1) {
                zivoty = maxzivoty = 30;
                mana = maxmana = 5;
                utok = 3;
                classa = "Fighter";
            } else if (vyber == 2) {
                zivoty = maxzivoty = 25;
                mana = maxmana = 3;
                utok = 4;
                classa = "Marksman";
            } else if (vyber == 3) {
                zivoty = maxzivoty = 25;
                mana = maxmana = 10;
                utok = 2;
                classa = "Mag";
            }

            vypisClassu(vyber, zivoty, maxzivoty);
            cout <<

"Potvrdit tuto volbu? (y/n): ";
cin >> potvrzeni;
} else {
cout << "Neplatna volba. Zkus to znovu.\n";
}
}
prvniVesnice(goldy);
vesnice(zivoty, maxzivoty, mana, maxmana, utok, goldy);
fight(classa, zivoty, mana, utok, goldy);
druhaVesnice(zivoty, maxzivoty, mana, maxmana, utok, goldy);
prochazkaLesem ();
mensiBossFight (classa, zivoty, mana, utok, goldy);


return 0;
}
