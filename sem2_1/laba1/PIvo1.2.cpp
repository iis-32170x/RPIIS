#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Diramida {
private:
    struct Node {
        int key, priority;
        string name;
        Node* l = nullptr;
        Node* r = nullptr;

        Node(string name, int key = 0) : key(key), priority(rand()) {}
    } *root = nullptr;
public:
    void Split(Node* n, int key, Node*& a, Node*& b) {
    if (!n) {
        a = b = nullptr;
        return;
    }

    if (n->key < key) {
        Split(n->r, key, n->r, b);
        a = n;
    }
    else {
        Split(n->l, key, a, n->l);
        b = n;
    }
}

    Node* Merge(Node* a, Node* b) {
        if (!a || !b)
            return a ? a : b;

        if (a->priority > b->priority) {
            a->r = Merge(a->r, b);
            return a;
        }
        else {
            b->l = Merge(a, b->l);
            return b;
        }
    }
        void Insert(string name, int key) {
            Node* Ferst, *Second;
            Split(root, key, Ferst, Second);
            root = Merge(Ferst, new Node(name, key));
            root = Merge(root, Second);
        }

        Node* Erase(int key) {
            Node* Ferst, * Second, * Third;
            Split(root, key, Ferst, Third);
            Split(Third, key + 1, Second, Third);
            root = nullptr;
            root = Merge(Ferst, Third);
            return root;
        }

        void Find(int key) {
            Node* Ferst, * Second, * Third;
            Split(root, key + 1, Ferst, Second);
            Split(Ferst, key, Ferst, Third);
            if (!Third)
                cout << "Такого узла/листа нет" << endl;
            else cout << "Такого узел/лист есть и вот его приоритет " << Third->priority << endl;
            root = Merge(Ferst, Third);
            root = Merge(root, Third);
        }

        Node* Root() {
            return root;
        }
        void printTree(Node* root, int n) {
            if (!root)
                return;
            n++;
            if(root->l)
            printTree(root->l, n);
            for (int i = 0; i < n; i++) {
                cout << "   ";
            }
            cout << root->key << " " << root->name << " " << root->priority << " " << n << endl;
            if(root->r)
            printTree(root->r, n);
        }
};

int main() {
    system("chcp 1251");
    vector<string> name{ "Gogen", "Moore", "OLEG", "Edwards", "Su", "Maria", "Veronika" };
    vector<int> nums{ 26,31,24,25,27,23,56 };
    Diramida d;
    for (int i = 0; i < name.size(); i++)
        d.Insert(name[i], nums[i]);
     auto root = d.Root();
     d.printTree(root, 0);
     cout << endl;
     root = d.Erase(23);
     d.printTree(root, 0);
     d.Find(56);
     d.Find(57);
    return 0;
}