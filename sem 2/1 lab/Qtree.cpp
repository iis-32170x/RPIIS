#include <iostream>
#include <vector>
#include <cmath>
#include "Qtree.h"
using namespace std;

bool list(vector<vector<int>> & matrix, int size, int x, int y) {
    int firstValue = matrix[x][y];
    for (int i = x; i < x+ size; i++) {
        for (int j = y; j < y + size; j++) {
            if (matrix[i][j] != firstValue) {
                return false;
            }
        }
    }
    return true;
}

int getMaxDepth(QuadTree* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->next) {
        return 1;
    }
    int depthLeft_down = getMaxDepth(node->Left_down);
    int depthRight_down = getMaxDepth(node->Right_down);
    int depthLeft_up = getMaxDepth(node->Left_up);
    int depthRight_up = getMaxDepth(node->Right_up);
    int maxDepth = 1 + max({ depthLeft_up, depthRight_up, depthLeft_down, depthRight_down });
    return maxDepth;
}

QuadTree* To_tree(vector<vector<int>>& matrix, int size, int x, int y) {
    if (size == 0)
        size = matrix.size();
    if (list(matrix, size, x, y))
        return new QuadTree{ true, matrix[x][y], nullptr, nullptr, nullptr, nullptr };
    else {
        int Size_2 = size / 2;
        QuadTree* node = new QuadTree();
        node->next = false;
        node->info = -1;
        node->Left_up = To_tree(matrix, Size_2, x, y);
        node->Right_up = To_tree(matrix, Size_2, x, y + Size_2);
        node->Left_down = To_tree(matrix, Size_2, x + Size_2, y);
        node->Right_down = To_tree(matrix, Size_2, x + Size_2, y + Size_2);
        return node;
    }
}

void releaseTree(QuadTree* Node, int depth) {
    if (Node == nullptr)
        return;
    if (Node->next) {
        for (int i = 0; i < depth; i++) {
            cout << "-";
        }
        cout << Node->info << endl;
    }
    releaseTree(Node->Left_up, depth + 1);
    releaseTree(Node->Right_up, depth + 1);
    releaseTree(Node->Left_down, depth + 1);
    releaseTree(Node->Right_down, depth + 1);
}

void zapolneniye(QuadTree* node, vector<vector<int>>& matrix, int x, int y, int size) {
    if (node == nullptr) {
        return;
    }
    if (node->next) {
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                matrix[i][j] = node->info;
            }
        }
    }
    else {
        int Size_2 = size / 2;
        zapolneniye(node->Left_up, matrix, x, y, Size_2);
        zapolneniye(node->Right_up, matrix, x, y + Size_2, Size_2);
        zapolneniye(node->Left_down, matrix, x + Size_2, y, Size_2);
        zapolneniye(node->Right_down, matrix, x + Size_2, y + Size_2, Size_2);
    }
}
vector<vector<int>> to_matrix(int depth) {
    int res = 0, reso = 0, index = 0, i = 0, j = 0, temp;
    bool fl1 = 1, fl2 = 1, fl3 = 1, fl4 = 1;
    vector<vector<int>> matrix(pow(2, depth), vector<int>(pow(2, depth)));
    if (depth == 0) {
        return vector<vector<int>>();
    }
    if (depth == 2) {
        while (res < pow(4, depth)) {
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == '-') {
                    reso++;
                    index = i;
                }
                if (s1[i] == ' ') {
                    index = i;
                    break;
                }
            }
            temp = pow(4, (depth - reso));
            if (res < pow(4, depth) / 4) {
                if (fl1) {
                    i = 0;
                    j = 0;
                    fl1 = 0;
                }
                while (temp > 0) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = 0;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;


                }
                res += pow(4, (depth - reso));
            }



            else if (res < pow(4, depth) / 2) {
                if (fl2) {
                    i = 0;
                    j = pow(2, depth) / 2;
                    fl2 = 0;
                }
                while (temp > 0) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 2;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;


                }
                res += pow(4, (depth - reso));




            }
            else if (res < pow(4, depth) / 4 * 3) {
                if (fl3) {
                    i = pow(2, depth) / 2;
                    j = 0;
                    fl3 = 0;
                }
                while (temp > 0) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = 0;

                    }
                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;


                }


                res += pow(4, (depth - reso));

            }
            else {
                if (fl4) {
                    i = pow(2, depth) / 2;
                    j = pow(2, depth) / 2;
                    fl4 = 0;
                }
                while (temp > 0) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 2;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;


                }


                res += pow(4, (depth - reso));
            }
            reso = 0;
        }
    }
    if (depth == 3) {
        while (res < pow(4, depth) / 4) {
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == '-') {
                    reso++;
                    index = i;
                }
                if (s1[i] == ' ') {
                    index = i;
                    break;
                }
            }
            temp = pow(4, (depth - reso));
            if (res < pow(4, depth) / 4 / 4) {
                if (fl1) {
                    i = 0;
                    j = 0;
                    fl1 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 4 / 4) {
                    if (j > pow(2, depth) / 4 - 1) {
                        i++;
                        j = 0;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }
            }



            if (res < pow(4, depth) / 2 / 4 && temp != 0) {
                if (fl2) {
                    i = 0;
                    j = pow(2, depth) / 4;
                    fl2 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 2 / 4) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = pow(2, depth) / 4;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;

                    res++;
                }





            }
            if (res < pow(4, depth) / 4 * 3 / 4 && temp != 0) {
                if (fl3) {
                    i = pow(2, depth) / 4;
                    j = 0;
                    fl3 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 4 * 3 / 4) {
                    if (j > pow(2, depth) / 4 - 1) {
                        i++;
                        j = 0;

                    }
                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;

                    res++;
                }




            }
            if (temp != 0 && res < pow(4, depth) / 4) {
                if (fl4) {
                    i = pow(2, depth) / 4;
                    j = pow(2, depth) / 4;
                    fl4 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 4) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = pow(2, depth) / 4;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }



            }
            reso = 0;
        }
        fl1 = fl2 = fl3 = fl4 = 1;
        while (res < pow(4, depth) / 2) {
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == '-') {
                    reso++;
                    index = i;
                }
                if (s1[i] == ' ') {
                    index = i;
                    break;
                }
            }
            temp = pow(4, (depth - reso));
            if (res < pow(4, depth) / 16 * 5) {
                if (fl1) {
                    i = 0;
                    j = pow(2, depth) / 2;
                    fl1 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 5) {
                    if (j > pow(2, depth) / 2 / 2 * 3 - 1) {
                        i++;
                        j = pow(2, depth) / 2;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;


                }
            }



            if (res < pow(4, depth) / 16 * 6 && temp != 0) {
                if (fl2) {
                    i = 0;
                    j = pow(2, depth) / 2 / 2 * 3;
                    fl2 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 6) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 2 / 2 * 3;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }





            }
            if (res < pow(4, depth) / 16 * 7 && temp != 0) {
                if (fl3) {
                    j = pow(2, depth) / 2;
                    i = pow(2, depth) / 4;
                    fl3 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 7) {
                    if (j > pow(2, depth) / 2 / 2 * 3 - 1) {
                        i++;
                        j = pow(2, depth) / 2;

                    }
                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;


                }




            }
            if (temp != 0) {
                if (fl4) {
                    i = pow(2, depth) / 2 / 2;
                    j = pow(2, depth) / 2 / 2 * 3;
                    fl4 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 2) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 2 / 2 * 3;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }



            }
            reso = 0;
        }
        fl1 = fl2 = fl3 = fl4 = 1;
        while (res < pow(4, depth) / 4 * 3) {
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == '-') {
                    reso++;
                    index = i;
                }
                if (s1[i] == ' ') {
                    index = i;
                    break;
                }
            }
            temp = pow(4, (depth - reso));
            if (res < pow(4, depth) / 16 * 9) {
                if (fl1) {
                    i = pow(2, depth) / 2;
                    j = 0;
                    fl1 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 9) {
                    if (j > pow(2, depth) / 4 - 1) {
                        i++;
                        j = 0;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }

            }



            if (res < pow(4, depth) / 16 * 10 && temp != 0) {
                if (fl2) {
                    i = pow(2, depth) / 2;
                    j = pow(2, depth) / 4;
                    fl2 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 10) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = pow(2, depth) / 4;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }





            }
            if (res < pow(4, depth) / 16 * 11 && temp != 0) {
                if (fl3) {
                    i = pow(2, depth) / 4 * 3;
                    j = 0;
                    fl3 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 11) {
                    if (j > pow(2, depth) / 4 - 1) {
                        i++;
                        j = 0;

                    }
                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }




            }
            if (temp != 0) {
                if (fl4) {
                    i = pow(2, depth) / 4 * 3;
                    j = pow(2, depth) / 4;
                    fl4 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 12) {
                    if (j > pow(2, depth) / 2 - 1) {
                        i++;
                        j = pow(2, depth) / 4;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }



            }
            reso = 0;
        }
        fl1 = fl2 = fl3 = fl4 = 1;
        while (res < pow(4, depth)) {
            string s1;
            cin >> s1;
            for (int i = 0; i < s1.length(); ++i) {
                if (s1[i] == '-') {
                    reso++;
                    index = i;
                }
                if (s1[i] == ' ') {
                    index = i;
                    break;
                }
            }
            temp = pow(4, (depth - reso));
            if (res < pow(4, depth) / 16 * 13) {
                if (fl1) {
                    i = pow(2, depth) / 2;
                    j = pow(2, depth) / 2;
                    fl1 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 13) {
                    if (j > pow(2, depth) / 4 * 3 - 1) {
                        i++;
                        j = pow(2, depth) / 2;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }

            }



            if (res < pow(4, depth) / 16 * 14 && temp != 0) {
                if (fl2) {
                    j = pow(2, depth) / 4 * 3;
                    i = pow(2, depth) / 2;
                    fl2 = 0;
                }
                while (temp > 0 && (res < pow(4, depth) / 16 * 14)) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 4 * 3;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;


                }

            }
            if (res < pow(4, depth) / 16 * 15 && temp != 0) {
                if (fl3) {
                    i = pow(2, depth) / 4 * 3;
                    j = pow(2, depth) / 2;
                    fl3 = 0;
                }
                while (temp > 0 && res < pow(4, depth) / 16 * 15) {
                    if (j > pow(2, depth) / 4 * 3 - 1) {
                        i++;
                        j = pow(2, depth) / 2;

                    }
                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }




            }
            if (temp != 0) {
                if (fl4) {
                    i = pow(2, depth) / 4 * 3;
                    j = pow(2, depth) / 4 * 3;
                    fl4 = 0;
                }
                while (temp > 0 && res < pow(4, depth)) {
                    if (j > pow(2, depth) - 1) {
                        i++;
                        j = pow(2, depth) / 4 * 3;
                    }

                    matrix[i][j] = s1[index + 1] - '0';
                    j++;
                    temp--;
                    res++;

                }



            }
            reso = 0;
        }
    }
    return matrix;
}
