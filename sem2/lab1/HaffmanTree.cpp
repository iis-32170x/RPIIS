#include "HaffmanTree.h"
Node* getNode(char field, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->field = field;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}
Node* BuildTree(string text, unordered_map<char, string>& BTable) {
	unordered_map<char, int> freq;
	for (char field : text) {
		freq[field]++;
	}
	priority_queue<Node*, vector<Node*>, compare> prique;
	for (auto x : freq) {
		cout << x.first << "-" << x.second << endl;
		prique.push(getNode(x.first, x.second, nullptr, nullptr));
	}
	while (prique.size() > 1)
	{

		Node* left = prique.top(); prique.pop();
		Node* right = prique.top();	prique.pop();
		int total_freq = left->freq + right->freq;
		prique.push(getNode('\0', total_freq, left, right));
	}
	Node* root = prique.top();
	string code;
	queue<pair<Node*, string>> q;
	q.push({ root, "" });

	while (!q.empty()) {
		Node* node = q.front().first;
		code = q.front().second;
		q.pop();

		if (node->field != '\0') {
			BTable[node->field] = code;
		}

		if (node->left != nullptr) {
			q.push({ node->left, code + '0' });
		}

		if (node->right != nullptr) {
			q.push({ node->right, code + '1' });
		}
	}

	cout << "BTable:" << endl;
	for (auto const& pair : BTable) {
		cout << pair.first << " - " << pair.second << endl;
	}
	return root;
}
string EncodeText(string text, unordered_map<char, string>& BTable) {
	string encodedText = "";
	for (char c : text) {
		encodedText += BTable[c];
	}
	return encodedText;
}
string DecodeText(string encodedText, Node* root) {
	string decodedText = "";
	Node* current = root;

	for (char bit : encodedText) {
		if (bit == '0') {
			current = current->left;
		}
		else {
			current = current->right;
		}

		if (current->field != '\0') {
			decodedText += current->field;
			current = root;
		}
	}

	return decodedText;
}