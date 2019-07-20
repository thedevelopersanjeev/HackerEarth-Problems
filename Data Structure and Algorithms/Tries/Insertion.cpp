#include<bits/stdc++.h>
using namespace std;

// considering only english words will be inserted in the trie
// maximum number of children that each trienode can have
// is number of alphabets in english which is 26
const int ALPHABETS = 26;

// Structure for a single node in Trie
typedef struct TrieNode{
    // Children Nodes for this Trie
    // It can have maximum ALPHABETS(26) children
    TrieNode* children[ALPHABETS];
    // represents if this node is the ending of a word
    bool isEndingWord;
} TrieNode;

// return a new TrieNode initialised with nulls
TrieNode* getNode(){
    // allocate memory
    TrieNode* temp = new TrieNode;
    // mark that this is not the ending of a word
    temp->isEndingWord = false;
    // mark all children as NULL
    for(int i = 0; i < ALPHABETS; i++)
        temp->children[i] = NULL;
    // return node
    return temp;
}

// inserts a new key into the TrieNode having root as root
void insertNode(TrieNode* root, string key){
    // create a new temp node and initialise it with root node
    // it will be used to crawl over the TrieNode
    TrieNode* temp = root;
    for(int i = 0; i < key.length(); i++){
        // inded at which current character of key will be inserted
        int index = key[i] - 'a';
        if(temp->children[index] == NULL){
            // initialise a new node there as there was no node present previously
            temp->children[index] = getNode();
        }
        // move to next character
        temp = temp->children[index];
    }
    // this is a ending of the word that we just inserted
    temp->isEndingWord = true;
}

// checks if given key is present in given trie node or not
bool searchKey(TrieNode* root, string key){
    // create a temp node to crawl over the trienode and initialise it with 
    // root node
    TrieNode* temp = root;
    for(int i = 0; i < key.length(); i++){
        // get index of current character in current node's children array
        int index = key[i] - 'a';
        // given word query has greater word length
        // trienode finishes here
        if(temp->children[index] == NULL)
            return false;
        // move to next node
        temp = temp->children[index];
    }
    // if last node is not null and is ending character
    // given query exists in TrieNode
    return (temp != NULL && temp->isEndingWord);
}

int main(){
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int n = 8;
    TrieNode* root = getNode();
    for(int i = 0; i < n; i++)
        insertNode(root, keys[i]);
    if(searchKey(root, "the"))
        cout <<"the found\n";
    else
        cout <<"the not found\n";
    if(searchKey(root, "these"))
        cout <<"these found\n";
    else
        cout <<"these not found\n";
    return 0;
}