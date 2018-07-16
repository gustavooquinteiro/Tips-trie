#include "../lib/main.h"
int main(){
	TrieNode * root = getNode();
	char option;
	while (scanf("%c", &option) && option != 'e'){
		switch(option){
			case 'i':
				insertTrie(root);
				break;
			case 'b':
				searchTrie(root);
				break;
			case 's':
				break;
		}
	}
	exit(EXIT_SUCCESS);
}

void insertTrie(TrieNode * trie){
	char * word =NULL;
	scanf(" %[^/n]s", word);
	insert(trie, word);
}

void searchTrie(TrieNode * trie){
	char * word = NULL;
	scanf("%[^/n]s", word);
	printf("%s %s",search(trie,word)? "Found": "Not Found", word); 
}
