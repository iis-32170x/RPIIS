#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void SimRaznNM(Mnozh MultMn[]) {        //Симметрическая разность
    Mnozh C = MultMn[0];
    if (MultMn[0].KolSkob == 0) {

        int n = 1;
        while (n < MultMn[0].KolMnoz) {
            Mnozh D, E, L;

            int d = 0, e = 0, l = 0;


            for (int i = 0; i < C.MoshMn; i++) {    //Разность A и B
                bool isduplicate = false;
                for (int j = 0; j < MultMn[n].MoshMn; j++) {
                    if (C.El[i].el == MultMn[n].El[j].el ||
                        ((C.El[i].razm == MultMn[n].El[j].razm) &&
                            (C.El[i].NeorMN == true && MultMn[n].El[j].NeorMN == true))) {
                        int kr = C.El[i].kratn - MultMn[n].El[j].kratn;
                        if (kr == 0) {}
                        else if (kr > 0) {
                            D.El[d].el = C.El[i].el;
                            D.El[d].kratn = kr;
                            d++;
                            D.MoshMn++;
                        }
                        else {              //Учитываем кратность элементов при сим разности и берем модуль разности кратностей
                            kr *= -1;
                            D.El[d] = C.El[i];
                            D.El[d].kratn = kr;
                            d++;
                            D.MoshMn++;
                        }
                        isduplicate = true;  break;
                    }
                }
                if (!isduplicate) {
                    D.El[d] = C.El[i];
                    D.El[d].kratn = C.El[i].kratn;
                    d++;
                    D.MoshMn++;
                }
            }

            for (int i = 0; i < MultMn[n].MoshMn; i++) {    //Разность B и A
                bool isduplicate = false;
                for (int j = 0; j < C.MoshMn; j++) {
                    if (C.El[j].el == MultMn[n].El[i].el || ((C.El[j].razm == MultMn[n].El[i].razm) && (C.El[j].NeorMN == true && MultMn[n].El[i].NeorMN == true))) {

                        isduplicate = true;  break;
                    }
                }
                if (!isduplicate) {
                    E.El[e] = MultMn[n].El[i];
                    E.El[e].kratn = MultMn[n].El[i].kratn;
                    e++;
                    E.MoshMn++;
                }
            }

            for (int i = 0; i < E.MoshMn; i++) {    //Объединение 
                bool isDuplicate = false;
                for (int j = 0; j < L.MoshMn; j++) {
                    if (E.El[i].el == L.El[j].el) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    L.El[l] = E.El[i];
                    L.El[l].kratn = E.El[i].kratn;
                    l++;
                    L.MoshMn++;
                }
            }

            for (int i = 0; i < D.MoshMn; i++) {
                bool isDuplicate = false;
                for (int j = 0; j < L.MoshMn; j++) {
                    if (D.El[i].el == L.El[j].el) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    L.El[l] = D.El[i];
                    L.El[l].kratn = D.El[i].kratn;
                    l++;
                    L.MoshMn++;
                }
            }
            L.MoshMn--;
            C = L;
            n++;
        }

        cout << endl << "Результат симметрической разности нескольких мультимножеств:" << endl;
        for (int j = 0; j < C.MoshMn; j++) {
            if (C.El[j].kratn == 1)
                cout << C.El[j].el << '\t';
            else
                cout << C.El[j].kratn << ' ' << C.El[j].el << "     ";
        }
    }
    else
        cout << "Некорректный ввод";
    cout << endl;
}

void ViewMnozh(Mnozh MultMn[]) {                //Вывод множеств, содержащихся в файле
    for (int i = 0; i < MultMn[0].KolMnoz; i++) {
        cout << "Множество " << i + 1 << ':' << '\t';
        for (int j = 0; j < MultMn[i].MoshMn; j++) {
            if (MultMn[i].El[j].kratn == 1)
                cout << MultMn[i].El[j].el << '\t';
            else
                cout << MultMn[i].El[j].kratn << ' ' << MultMn[i].El[j].el << "     ";
        }
        cout << endl;
    }
    cout << endl;
}

void SortMnozh(Mnozh MultMn[]) {                    //Убираем повторяющиеся элементы и увеличиваем кратность
    for (int i = 0; i <= MultMn[0].KolMnoz; i++) {
        for (int j = 0; j < MultMn[i].MoshMn; j++) {
            for (int k = j + 1; k < MultMn[i].MoshMn; k++) {
                if ((MultMn[i].El[j].el == MultMn[i].El[k].el && ((MultMn[i].El[j].kratn != MultMn[i].El[k].kratn) || (MultMn[i].El[j].kratn == 1 && MultMn[i].El[k].kratn == 1))) || ((MultMn[i].El[j].razm == MultMn[i].El[k].razm) && (MultMn[i].El[j].NeorMN == true && MultMn[i].El[k].NeorMN == true))) {
                    MultMn[i].El[j].kratn = MultMn[i].El[j].kratn + MultMn[i].El[k].kratn;
                    for (int t = k; t < MultMn[i].MoshMn - 1; t++) {
                        MultMn[i].El[t] = MultMn[i].El[t + 1];
                    }
                    MultMn[i].MoshMn--;
                    k--;
                }

            }
        }
    }
}

void ReadFile(Mnozh MultMn[], string path) {
    ifstream file;
    file.open(path);
    int KolSkob = 0;
    int KolSkobKort = 0;

    if (file.is_open()) {
        char ch;
        int m = 0;
        MultMn[0].KolMnoz = m + 1;
        int KolElemMnozh = 0;
        bool permn = false;
        while (file.get(ch)) {
            if (ch == '{') {
                if (KolSkob > 0) {
                    MultMn[m].El[KolElemMnozh].el.push_back(ch);
                    MultMn[m].El[KolElemMnozh].NeorMN = true;
                    MultMn[m].El[KolElemMnozh].razm += ch;
                    KolSkob++;
                }
                else {
                    if (permn == false) {
                        KolSkob++;
                        permn = true;
                    }
                    else {
                        m++;
                        MultMn[0].KolMnoz = m + 1;
                        KolElemMnozh = 0;
                        KolSkob++;
                    }
                }
            }
            else if (ch == ',') {
                if (KolSkob == 1) {
                    KolElemMnozh++;
                }
                else {
                    MultMn[m].El[KolElemMnozh].el.push_back(ch);
                    if (MultMn[m].El[KolElemMnozh].NeorMN)
                        MultMn[m].El[KolElemMnozh].razm += ch;
                }
            }
            else if (isdigit(ch)) {
                if (KolSkob == 1) {
                    if (MultMn[m].El[KolElemMnozh].kratn == 1 && !MultMn[m].El[KolElemMnozh].ProverkaNa1) {
                        MultMn[m].El[KolElemMnozh].kratn = (ch - 48);
                        MultMn[m].El[KolElemMnozh].ProverkaNa1 = true;
                    }
                    else {
                        MultMn[m].El[KolElemMnozh].kratn = MultMn[m].El[KolElemMnozh].kratn * 10 + (ch - 48);
                    }
                }
                else {
                    MultMn[m].El[KolElemMnozh].el.push_back(ch);
                    if (MultMn[m].El[KolElemMnozh].NeorMN)
                        MultMn[m].El[KolElemMnozh].razm += ch;
                }
            }
            else if (ch == '<') {
                KolSkob++;
                KolSkobKort++;
                MultMn[m].El[KolElemMnozh].el.push_back(ch);
                if (MultMn[m].El[KolElemMnozh].NeorMN)
                    MultMn[m].El[KolElemMnozh].razm += ch;
            }
            else if (ch == '>') {
                KolSkob--;
                KolSkobKort--;
                MultMn[m].El[KolElemMnozh].el.push_back(ch);
                if (MultMn[m].El[KolElemMnozh].NeorMN)
                    MultMn[m].El[KolElemMnozh].razm += ch;
            }
            else if (ch == '}') {
                if (KolSkob > 1) {
                    MultMn[m].El[KolElemMnozh].el.push_back(ch);
                    if (MultMn[m].El[KolElemMnozh].NeorMN)
                        MultMn[m].El[KolElemMnozh].razm += ch;
                    KolSkob--;
                }
                else {
                    MultMn[m].MoshMn = KolElemMnozh + 1;
                    KolSkob--;
                }
            }
            else if (ch == ' ' || ch == '\n') {}
            else {
                MultMn[m].El[KolElemMnozh].el.push_back(ch);
                if (MultMn[m].El[KolElemMnozh].NeorMN)
                    MultMn[m].El[KolElemMnozh].razm += ch;
            }
        }
    }
    else {
        cout << "Error";
    }
    MultMn[0].KolSkob = KolSkob;
    MultMn[0].KolSkobKort = KolSkobKort;
    file.close();
    ViewMnozh(MultMn);
    SortMnozh(MultMn);

    SimRaznNM(MultMn);

}