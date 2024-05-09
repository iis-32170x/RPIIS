#pragma once

const int MaxChar = 256;
class bor
{
public:
	int is_End_of_word;
	int key;
	bor* children[MaxChar];

	bor();
	void insert(const char* word, int key);
	int find(const char* word);
	bool del(const char* word);

};
