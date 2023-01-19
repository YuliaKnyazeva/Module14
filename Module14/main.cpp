#include "Trie.h"
#include <iostream>

int main()
{
    string word;
    int menu = 1;

    struct TrieNode* root = getNewNode();
    insert(root, "auto");
    insert(root, "apple");
    insert(root, "bear");
    insert(root, "beast");
    insert(root, "a");
    insert(root, "life");
    insert(root, "lifetime");
    insert(root, "lifestyle");
    insert(root, "hell");
    insert(root, "help");
    insert(root, "hello");
    while (menu) {
        cout << "Enter the word\n";
        cin >> word;

        int comp = autocomplete(root, word);

        if (comp == -1)
            cout << "No other strings found with this prefix\n";

        else if (comp == 0)
            cout << "Strings not found\n";
        cout << "Enter 1 for new word or 0 for exit\n";
        cin >> menu;
    }
    return 0;
}