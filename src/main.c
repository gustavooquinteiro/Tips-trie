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
        suggestTrie(root);
				break;
      case HELP:
        printf("----------------Tips-Trie Help------------------------\n");
        printf("%c word                - insert word in trie     \n", INSERT);
        printf("%c word                - search in trie for the word  \n", SEARCH);
        printf("%c prefix              - search in trie for word(s) with the prefix   \n", SUGGEST);
        printf("%c                     - display this help menu        \n", HELP);
        printf("%c                     - exit the program              \n\n", END);
        printf("----------------------------------------------------\n");
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

void suggestTrie(TrieNode * trie){
	char * word = malloc(26 * sizeof(char));
	scanf(" %[^\n]s", word);
	switch (suggest(trie, word)) {
		case NO_MATCH:
			printf("Not found any word with prefix \"%s\"\n", word);
			break;
		case PARTIAL_MATCH:
			printf("Found some words with \"%s\" as prefix\n", word);
			read();
			break;
		case MATCH:
			printf("%s is a whole word.\nTry less letters for more results, if you want\n", word);
			break;
	}
	removeWord(word);
}


void removeWord(char * word){
    free(word);
    word = NULL;
}
