struct Node {
    int key;
    unsigned char height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};