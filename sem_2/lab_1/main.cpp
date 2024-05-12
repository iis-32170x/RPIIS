#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char symbol;
    int count;
    Node* left;
    Node* right;
};

Node* create(char c, int n) {
    Node* newNode = new Node();
    newNode->symbol = c;
    newNode->count = n;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void Chastota(const string& str, vector<int>& freq) {
    for (char c : str) {
        freq[c]++;
    }
}

void print(Node* root, string prefix) {
    if (root == nullptr) {
        return;
    }

    if (root->symbol != '\0') {
        cout << root->symbol << ": " << prefix << endl;
        return;
    }

    print(root->left, prefix + "0");
    print(root->right, prefix + "1");
}

int main() {
    string str;
    cout << "Введите строку для кодировки: ";
    getline(cin, str);

    vector<int> freq(256, 0);

    Chastota(str, freq);

    vector<Node*> nodes;

    // Создаем узлы
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes.push_back(create((char)i, freq[i]));
        }
    }

    while (nodes.size() > 1) {
        int min1 = str.length(), min2 = str.length();
        int i1 = -1, i2 = -1;

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->count < min1) {
                min1 = nodes[i]->count;
                i1 = i;
            } else if (nodes[i]->count < min2) {
                min2 = nodes[i]->count;
                i2 = i;
            }
        }

        // родительский узел с объединенной частотой
        Node* parent = new Node();
        parent->symbol = '\0';
        parent->count = min1 + min2;
        parent->left = nodes[i1];
        parent->right = nodes[i2];

        nodes.erase(nodes.begin() + i1);
        nodes.erase(nodes.begin() + i2 - 1);
        nodes.push_back(parent);
    }

    Node* root = nodes[0];

    print(root, "");

    return 0;
}