#pragma once
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool isEmpty(TrieNode*);
void suggestionsRec(struct TrieNode* root, string currPrefix);
int autocomplete(TrieNode* root, const string query);


