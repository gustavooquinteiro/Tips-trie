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
    TrieNode *pCrawl = root;

    for (level = 0; level < length; level++){
        int index = CHAR_TO_INDEX(key[level]);
        if (!hasChild(pCrawl, index))
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = TRUE;
}

int search(TrieNode *root, const char *key){
    register int level;
    int length = strlen(key);
    TrieNode *pCrawl = root;

    for (level = 0; level < length; level++){
        int index = CHAR_TO_INDEX(key[level]);

        if (!hasChild(pCrawl, index))
            return FALSE;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl && isEndOfWord(pCrawl));
}

char *append(char *orig, char c){
    size_t sz = strlen(orig);
    char *str = malloc(sz + 2);
    strcpy(str, orig);
    str[sz] = c;
    str[sz + 1] = '\0';
    return str;
}

void suggestPartialMatch(TrieNode *root, char* key){
    if(isEndOfWord(root)){        
        write(key);
        return;
    }

    if (isLastNode(root)){
        return;
    }
    
    for (register int i =0; i< ALPHABET_SIZE; i++){
        if (hasChild(root, i)){
            char * search = append(key, i+'a');
            suggestPartialMatch(root->children[i], search);
            free(search);
            search = NULL;
        }
    }
}

int suggest(TrieNode * root, char* query){
    TrieNode* pCrawl = root;
    register int level;
    int n = strlen(query);
    for (level = 0; level < n; level++){
        int index = CHAR_TO_INDEX(query[level]);

        if (!hasChild(pCrawl,index))
            return NO_MATCH;

        pCrawl = pCrawl->children[index];
    }

    if(isFullWord(pCrawl)){
        return MATCH;
    }else{
        
        suggestPartialMatch(pCrawl, query);
        
        return PARTIAL_MATCH;
    }

}

TrieNode * clear(TrieNode * root, char * word, unsigned int depth){
    if (!root)
        return NULL;
    if(depth == strlen(word)){
        if(isEndOfWord(root))
            root->isEndOfWord = FALSE;
        if(isLastNode(root))
            removeNode(root);
        return root;
    }
    
    int index = CHAR_TO_INDEX(word[depth]);
    root->children[index] = clear(root->children[index], word, depth + 1);
    if (isLastNode(root) && !isEndOfWord(root))
        removeNode(root);
    return root;   
}

void removeTrie(TrieNode* root){
    removeNode(root);
    free(root);
}

void removeNode(TrieNode * node){
    register int level;
    TrieNode *pCrawl = node;
    for (level =0; level< ALPHABET_SIZE; level++){

        if (!hasChild(pCrawl, level))
            continue;

        removeNode(pCrawl->children[level]);

        free(pCrawl->children[level]);
        pCrawl->children[level] = NULL;

    }

}

int isFullWord(TrieNode* node){
    return (isEndOfWord(node) && isLastNode(node))? TRUE: FALSE;
}

int isEndOfWord(TrieNode * node){
    return (node->isEndOfWord)? TRUE: FALSE;
}

int isLastNode(TrieNode * root){
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (hasChild(root, i))
            return FALSE;
    }
    return TRUE;
}

int hasChild(TrieNode * node, int child){
    return (node->children[child])? TRUE: FALSE;
}
