class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int key);
    Node* search(Node* node, int key);
    Node* deleteNode(Node* node, int key);
    Node* findMin(Node* node);
    void destroyTree(Node* node);
    void inorderTraversal(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key);
    bool search(int key);
    void deleteKey(int key);
    void destroyTree();
    void inorderTraversal();
};
