#include <iostream> 
using namespace std;
void equalK(char* str1, char* str2, int left1, int right1, int left2, int right2, bool& a) {
    while (left1 < right1 && str1[left1] != '<') {
        left1++;
    }
    while (right1 > left1 && str1[right1] != '>') {
        right1--;
    }
    while (left2 < right2 && str2[left2] != '<') {
        left2++;
    }
    while (right2 > left2 && str2[right2] != '>') {
        right2--;
    }
    if ((left1 == right1 && left2 != right2) || (left1 != right1 && left2 == right2)) {
        a = false;
        return;
    }
    if (left1 != right1 && left2 != right2) {
        int i = left1 + 1;
        int j = left2 + 1;

        while (i < right1 && j < right2) {
            if (str1[i] != str2[j]) {
                a = false;
                return;
            }
            equalK(str1, str2, i, right1, j, right2, a);
            while (i < right1 && str1[i] != '<') {
                i++;
            }
            while (right1 > i && str1[right1] != '>') {
                right1--;
            }
            while (j < right2 && str2[j] != '<') {
                j++;
            }
            while (right2 > j && str2[right2] != '>') {
                right2--;
            }

            i++;
            j++;
        }
    }
}
void equal(char* str1, char* str2, int& z) {
    bool a = true;
    int h = 0;
    int left1, right1, left2, right2;
    left1 = right1 = left2 = right2 = 0;
    if (str1[0] == '{' && str1[strlen(str1) - 1] == '}' && str2[0] == '{' && str2[strlen(str2) - 1] == '}') {
        if (strlen(str1) == strlen(str2)) {
            for (int i = 1; i < strlen(str1) - 1; i++) {
                for (int j = 1; j < strlen(str2) - 1; j++) {
                    if (str1[i] == str2[j]) {
                        h++;
                        break;
                    }
                }
            }
        }
        equalK(str1, str2, left1, right1, left2, right2, a);

    }
    else {
        if (strcmp(str1, str2) == 0) {
            z++;
        }
    }

    if (h == (strlen(str1) - 2) && a == true) {
        z++;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int m1, a, b, z;
    bool x;
    cout << "Введите колличество множеств";
    cin >> m1;
    char*** A = new char** [m1];
    int* C = new int[m1];
    int** D = new int* [2];
    string str;
    for (int i = 0; i < m1; i++) {

        cout << "Введите множество";
        b = 0;
        a = 0;
        int s, f;
        cin >> str;
        for (int j = 1; j < size(str) - 1; j++) {
            x = false;
            if (str[j] == '{') {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '}') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }

            if (str[j] == '<') {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '>') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            if (str[j] != ',' && str[j] != '}' && str[j] != '>') {
                for (int k = 0; k < size(str); k++) {
                    if (str[k] == ',' || str[k] == '}') {
                        j = k - 1;

                        break;
                    }

                }
            }
            if (str[j] == ',' && str[j + 1] != '<' && str[j + 1] != '{' && !x) {
                for (int k = j + 1; k < size(str); k++) {
                    if (str[k] == ',' || str[k] == '}') {
                        j = k - 1;

                        break;
                    }

                }

            }
            if (str[j] == ',' && str[j + 1] == '<' && !x) {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '>') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            if (str[j] == ',' && str[j + 1] == '{' && !x) {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '}') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            b++;
            if (x) {
                j--;
            }
        }
        C[i] = b;
        D[0] = new int[b];
        D[1] = new int[b];


        for (int j = 0; j < size(str) - 1; j++) {
            x = false;
            s = j + 1;
            if (str[j] == '{') {
                j++;
            }
            if (str[j] == '{') {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '}') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            if (str[j] == '<') {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '>') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            if (str[j] != ',' && str[j] != '}' && str[j] != '>') {
                for (int k = 0; k < size(str); k++) {
                    if (str[k] == ',' || str[k] == '}') {
                        j = k - 1;

                        break;
                    }

                }
            }
            if (str[j] == ',' && str[j + 1] != '<' && str[j + 1] != '{' && !x) {
                for (int k = j + 1; k < size(str); k++) {
                    if (str[k] == ',' || str[k] == '}') {
                        j = k - 1;
                        break;
                    }

                }

            }
            if (str[j] == ',' && str[j + 1] == '<' && !x) {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '>') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            if (str[j] == ',' && str[j + 1] == '{' && !x) {
                for (int k = j; k < size(str) - 1; k++) {
                    if (str[k] == '}') {
                        j = k + 1;
                        x = true;
                        break;
                    }
                }
            }
            f = j - s;
            if (f == 0) {
                f = 1;
            }
            D[0][a] = s;
            D[1][a] = f;
            a++;
            if (x) {
                j--;
            }
        }
        A[i] = new char* [b];
        for (int j = 0; j < b; j++) {
            string substring = str.substr(D[0][j], D[1][j]);
            char* charArray = new char[D[1][j]];
            substring.copy(charArray, D[1][j]);
            charArray[D[1][j]] = '\0';
            A[i][j] = charArray;
        }
        delete[] D[0];
        delete[] D[1];
    }
    int max = C[0];
    for (int i = 1; i < m1; i++) {
        if (C[i] > max) {
            max = C[i];
        }
    }
    char** B = new char* [max * max];
    a = 0;
    for (int i = 0; i < m1; i++) {

        for (int j = 0; j < C[i]; j++) {
            z = 0;
            for (int k = 0; k < m1; k++) {

                for (int w = 0; w < C[k]; w++) {
                    equal(A[i][j], A[k][w], z);
                }
            }
            if (z < 2) {
                B[a] = A[i][j];
                a++;
            }
        }

    }
    cout << "Симметрическая разность множеств: ";
    cout << "{";
    for (int i = 0; i < a; i++) {
        cout << B[i];
        if (i == a - 1) {

        }
        else {
            cout << ", ";
        }
    }
    cout << "}";
    return 0;
}
