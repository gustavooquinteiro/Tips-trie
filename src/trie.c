#include "../lib/trie.h"

struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];
	int isEndOfWord; 
};

TrieNode *getNode(){
    TrieNode *pNode = (TrieNode *)malloc(sizeof(TrieNode));
 
    if (pNode){
        register int i;
        pNode->isEndOfWord = FALSE;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}


void insert(TrieNode *root, const char *key){
    register int level;
    int length = strlen(key);
    int index;
 
    TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    pCrawl->isEndOfWord = TRUE;
}

int search(TrieNode *root, const char *key){
    register int level;
    int length = strlen(key);
    int index;
    TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return FALSE;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl && pCrawl->isEndOfWord);
}

void removeTrie(TrieNode* root){
    removeNode(root);    
    free(root);
    root = NULL;    
}


void removeNode(TrieNode * node){
    register int level;
    TrieNode *pCrawl = node;
    for (level =0; level< ALPHABET_SIZE; level++){
        
        if (!pCrawl->children[level])
            continue;
    
        removeNode(pCrawl->children[level]);
        
        free(pCrawl->children[level]);
        pCrawl->children[level] = NULL;
    
    }        
    
}
