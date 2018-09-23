#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef MAIN_H
#define MAIN_H
#define INSERT 'i'
#define SEARCH 'b'
#define SUGGEST 's'
#define END 'q'
#define HELP 'h'


int main();
void insertTrie(TrieNode * trie);
void searchTrie(TrieNode * trie);
void removeWord(char * word);
void suggestTrie(TrieNode * trie);

#endif
