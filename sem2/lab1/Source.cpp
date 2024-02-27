#include "Header.h"

void Treap::swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
    delete temp;
}

void Treap::split(Node* p, int x, Node*& f, Node*& s) {
    if (p == nullptr) {
        f = nullptr;
        s = nullptr;
        return ;
    }
    Node* f1 = nullptr, * s1 = nullptr;
    if (p->key <= x) {
        split(p->right, x, f1, s1);
        p->right = f1;
        f = p;
        p = s1;
    }
    else {
        split(p->left, x, f1, s1);
        p->left = s1;
        f = f1;
        s = p;
    }
}

Node* Treap::merge(Node* l, Node* r) {
    if (!l) return r;
    if (!r) return l;
    if (l->priority > r->priority) {
        l->right = merge(l->right, r);
        return l;
    }
    else {
        r->left = merge(l, r->left);
        return r;
    }
}

void Treap::insert(int x) {
    std::pair <Node*, Node*> q;
    Node* f1 = nullptr, * s1 = nullptr;
    split(root, x, f1, s1);
    Node* t = new Node(x);
    root = merge(f1, merge(t, s1));
}
void Treap::insert(int x,int y) {
    std::pair <Node*, Node*> q;
    Node* f1 = nullptr, * s1 = nullptr;
    split(root, x, f1, s1);
    q.first = f1;
    q.second = s1;
    Node* t = new Node(x,y);
    root = merge(q.first, merge(t, q.second));
}

void Treap::erase(Node*& t, int key) {
    if (t == nullptr) return;
    if (t->key == key)  t = merge(t->left, t->right);
    else
    {
        if (key < t->key) {
            erase(t->left, key);
        }
        else {
            erase(t->right, key);
        }
    }
    root = t; 
}

void Treap::buildTree(std::vector<int> keys) {
    for (int i = 0; i < size(keys); i++)
    {
        int key = keys[i];
        insert(key);
    }
}
void Treap::buildTree(std::vector<int> keys, std::vector<int> prioritys) {
    for (int i = 0; i < size(keys);i++)
    {
        int key = keys[i];
        int priority = prioritys[i];
        insert(key,priority);
    }
}

Node* Treap::search(Node* node, int key)
{
    if (node == nullptr) return node;
    if (node->key == key) return node;
    else if (key < node->key)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
}

Node* Treap::unite(Node* root1, Node* root2)
{
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    Node* u;
    if (root1->key < root2->key)
    {
        u = root1;
        u->right = unite(root1->right, root2);
    }
    else
    {
        u = root2;
        u->left = unite(root1, root2->left);
    }
    return u;
}


void Treap::outTree(Node* node,int level) {
    if (node == nullptr) return;

    outTree(node->right, level + 1);
    for (int i = 0; i < level; i++)
        std::cout << "          ";
    std::cout << '(' <<node->key<<','<< node->priority << ')' << '\n';
    outTree(node->left, level + 1);
}

bool Treap::InTree(Node* node1, int k) {
    if (node1 == nullptr) return false;
    if (node1->key == k) return true;
    if (k < node1->key) return InTree(node1->left, k);
    else return InTree(node1->right, k);
}

Node* Treap::intersect(Node* root1, Node* root2) 
    {
    if (root1 == nullptr || root2 == nullptr) return nullptr;
    Node* inter = nullptr;

    if (InTree(root2, root1->key))
    {
        inter = new Node(root1->key, root1->priority);
        inter->left = intersect(root1->left, root2);
        inter->right = intersect(root1->right, root2);
    }
    else
    {
        inter = intersect(root1->left, root2);
        inter = intersect(root1->right, root2);
    }
    return inter;
}
