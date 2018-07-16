#include "../lib/trie.h"

typedef struct TrieNode{
	struct TrieNode *children[ALPHABET_SIZE];
	int isEndOfWord; 
}TrieNode;

TrieNode *getNode(){
    struct TrieNode *pNode = NULL;
 
    pNode = (TrieNode *)malloc(sizeof(TrieNode));
 
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

int search(struct TrieNode *root, const char *key){
   register int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
 
        if (!pCrawl->children[index])
            return FALSE;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl && pCrawl->isEndOfWord);
}
