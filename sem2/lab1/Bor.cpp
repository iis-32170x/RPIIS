#include <string>
#include "bor.h"

bor::bor() {
	is_End_of_word = 0;
	key = 0;
	for (int i = 0; i < MaxChar; ++i)
		children[i] = nullptr;
}
void bor::insert(const char* word, int key)
{
	bor* current_Node = this;
	for (int i = 0; word[i] != '\0'; ++i)
	{
		char symbol = word[i];
		if (current_Node->children[symbol] == nullptr)
			current_Node->children[symbol] = new bor();
		current_Node = current_Node->children[symbol];
	}
	current_Node->is_End_of_word = 1;
	current_Node->key = key;

}
bool bor::del(const char* word)
{
	bor* current_node = this;
	for (int i = 0; word[i] != '\0'; ++i)
	{
		if (current_node->children[word[i]] = nullptr)
			return false;
		current_node = current_node->children[word[i]];
	}

	current_node->is_End_of_word = 0;
	return true;
}
int bor::find(const char* word)
{
	bor* current_node = this;
	for (int i = 0; word[i] != '\0'; ++i)
	{
		char symbol = word[i];
		if (current_node->children[symbol] == nullptr)
			return -1;
		current_node = current_node->children[symbol];
	}
	if (current_node->is_End_of_word == 0)
		return -1;

	return current_node->key;
}