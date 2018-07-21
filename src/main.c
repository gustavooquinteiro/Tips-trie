#include "../lib/main.h"
int main(){
	TrieNode * root = getNode();
	char option;
	while (scanf("%c", &option) && option != END){
		switch(option){
			case INSERT:
				insertTrie(root);
				break;
			case SEARCH:
				searchTrie(root);
				break;
			case SUGGEST:
				break;
		}
	}
    removeTrie(root);
	exit(EXIT_SUCCESS);
}

void insertTrie(TrieNode * trie){
	char * word = malloc(26 * sizeof(char));
	scanf(" %[^\n]s", word);
	insert(trie, word);
    removeWord(word);
}

void searchTrie(TrieNode * trie){
	char * word = malloc(26 * sizeof(char));
	scanf(" %[^\n]s", word);
	printf("%s %s\n",search(trie,word)? "Found": "Not Found", word); 
    removeWord(word);
}

void removeWord(char * word){
    free(word);
    word = NULL;
}    
