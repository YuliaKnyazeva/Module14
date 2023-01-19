#include "Trie.h"
#include <iostream>
#include <string>

TrieNode* getNewNode(void)
{

    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

void suggestionsRec(struct TrieNode* root, string currPrefix)
{
    if (root->isEndOfWord)
        cout << currPrefix << endl;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char buf = 'a' + i;
            suggestionsRec(root->children[i],
                currPrefix + buf);
        }
}


int autocomplete(TrieNode* root, const string query)
{
    struct TrieNode* newNode = root;
    for (int i = 0;i<query.length();i++) {
        int index = query[i] - 'a';

        if (!newNode->children[index])
            return 0;

        newNode = newNode->children[index];
    }
    if (isEmpty(newNode)) {
        cout << query << endl;
        return -1;
    }
    suggestionsRec(newNode, query);
    return 1;
}