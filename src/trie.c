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

int isLastNode(TrieNode * root){
    for (int i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i])
            return 0;
    }
    return 1;
}

char *append(char *orig, char c){
    size_t sz = strlen(orig);
    char *str = malloc(sz + 2);
    strcpy(str, orig);
    str[sz] = c;
    str[sz + 1] = '\0';
    return str;
}

void suggest(TrieNode *root, char* key){ 
    if(root->isEndOfWord){
        printf("\t%s\n", key);
    }
    if(isLastNode(root))
        return;
    
    for (int i =0; i< ALPHABET_SIZE; i++){
        if (root->children[i]){
            char * search = key;
            search = append(key, i+'a');
            suggest(root->children[i], search);
            free(search);
            search = NULL;
        }
            
    }
}

void printSuggestion(TrieNode * root, char* query){
    TrieNode* pCrawl = root;
    // Check if prefix is present and find the
    // the node (of last level) with last character
    // of given string.
    int level;
    int n = strlen(query);
    for (level = 0; level < n; level++){
        int index = CHAR_TO_INDEX(query[level]);
 
        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
            return;
 
        pCrawl = pCrawl->children[index];
    }
  
    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (pCrawl->isEndOfWord && isLastNode(pCrawl)){
        printf("%s", query);
    }
 
    // If there are are nodes below last
    // matching character.
    if (!isLastNode(pCrawl)){
        char*  prefix = query;
        printf("Você quis dizer: \n");
        suggest(pCrawl, prefix);
    }
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
