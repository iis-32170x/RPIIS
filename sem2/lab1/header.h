// Создаем класс БДР
class BST 
{
private:

	
	// Создаем структуру узлов
	struct Node 
	{
		int key;
		Node* left;
		Node* right;
	};

	Node* root;


	// Приватные функции (методы)
	// Если я не использовал "inline", то у меня возникала ошибка LNK2005 
	inline Node* CreateLeaf(int key);
	inline void AddLeafPrivate(int key, Node* Ptr);
	inline void PrintInOrderPrivate(Node* Ptr);
	inline Node* ReturnNode(int key);
	inline Node* ReturnNodePrivate(int key, Node* Ptr);
	inline int FindSmallestPrivate(Node* Ptr);
	inline void Remove(Node* parent, Node* match, bool left);
	inline void RemoveNodePrivate(int key, Node* Ptr);
	inline void RemoveRoot();
	inline void RemoveSubTree(Node* Ptr);

public:

	inline BST();
	inline ~BST();


	// Функция (методы), которые пользователь непостредственно использует при запуске программы 
	inline void AddLeaf(int key);
	inline void PrintInOrder();
	inline void PrintChildren(int key);
	inline int FindSmallest();
	inline void RemoveNode(int key);
};
