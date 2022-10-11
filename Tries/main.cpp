#include <iostream>
#include <string>
#include <algorithm>

#define alphabet 26
using namespace std;

struct TrieNode{
    struct TrieNode *children[alphabet] = {NULL};
    char value = '@';
    bool isWord = false;
};

struct TrieNode *getTrieNode(){
    return new TrieNode;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *current = root;
 
    for (int i = 0; i < key.length(); i++){
        int alphabet_index = key[i] - 'a';

        if (!current->children[alphabet_index]){
            current->children[alphabet_index] = getTrieNode();
            current->children[alphabet_index]->value = key[i];
        }

        current = current->children[alphabet_index];
    }

    current->isWord = true;
}

bool isInTrie(struct TrieNode *root, string key){
    struct TrieNode *current = root;
 
    for (int i = 0; i < key.length(); i++){
        int alphabet_index = key[i] - 'a';

        if (!current->children[alphabet_index])
            return false;
        
        current = current->children[alphabet_index];
    }
    return current->isWord;
}

void trieDFS(struct TrieNode *root){
    if(!root)
        return;
    
    cout << root->value << endl;
    for(int i = 0; i < alphabet; i++)
        trieDFS(root->children[i]);
    
}


int main(){
    int trieWords = 0;
    cin >> trieWords;
    
    struct TrieNode *root = getTrieNode();
    string key = "";

    for (int i = 0; i < trieWords; i++){
        cin >> key;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        insert(root, key);
    }

    cout<<"Trie DFS: \n";
    trieDFS(root);

    int lookUpWords = 0;
    cin >> lookUpWords;
    string searches[lookUpWords];

    for (int i = 0; i < lookUpWords; i++){
        cin >> key;
         transform(key.begin(), key.end(), key.begin(), ::tolower);
        searches[i] = key;
    }

    cout<<"Resultado de busqueda:"<<endl;
    for (int i = 0; i < lookUpWords; i++){
        if( isInTrie(root, searches[i]) )
            cout<<searches[i]<<" True"<<endl;
        else
             cout<<searches[i]<<" False"<<endl;
    }

    return 0;
}