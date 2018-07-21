#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26
#define TRUE 1
#define FALSE 0
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

typedef struct TrieNode TrieNode;

int search(TrieNode *root, const char *key);
void insert(TrieNode *root, const char *key);
int suggest(TrieNode* root, const char * key);
void removeTrie(TrieNode* root);
void removeNode(TrieNode * node);
TrieNode *getNode();

#endif
