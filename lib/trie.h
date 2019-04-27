#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filemanager.h"

#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26
#define TRUE 1
#define FALSE 0
#define NO_MATCH 5
#define PARTIAL_MATCH 10
#define MATCH 15
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i) ((char)(i + '0'))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

typedef struct TrieNode TrieNode;

TrieNode *getNode();

void insert(TrieNode *root, const char *key);
void removeTrie(TrieNode* root);
void removeNode(TrieNode * node);
void suggestPartialMatch(TrieNode * root, char * key);
int suggest(TrieNode* root, char * key);
int search(TrieNode *root, const char *key);

int isFullWord(TrieNode* node);
int hasChild(TrieNode * node, int child);
int isEndOfWord(TrieNode * node);
int isLastNode(TrieNode * root);

char *append(char *orig, char c);
#endif
