#include <stdio.h>
#include <string.h>

#include <mm_malloc.h>
#define CHAR_SIZE 26

struct Trie{
    int isLeaf;
    struct Trie *children[CHAR_SIZE];
    char pass;
    struct Trie *next;
};
struct Trie *getNewNode(){
    int i;
    struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf=0;
    for (i=0; i<CHAR_SIZE; i++)
        node->children[i] = NULL;
    return node;
};

void insert(struct Trie **root, char *str, char pass){

    struct Trie *curr =*root;
    size_t length = strlen(str);
    int count = 0;

    while(*str){

        if(curr->children[*str - 'a']==NULL){
            curr->children[*str -'a'] =getNewNode();
        }
        count++;
        curr->next = curr->children[*str - 'a'];//next node
        curr = curr->next;
        str++;//next child
    }

    if(count == length)
    {
        curr->pass = pass;
        curr->isLeaf=1;
    }



};


int search(struct Trie *root, char *str){
    if(root==NULL)
        return 0; // trie is empty
    struct Trie *curr = root;
    while(*str){
        curr = curr -> children[*str - 'a'];
        if(curr==NULL)
            return 0;
        str++;
    }
    return curr->isLeaf=1;
};


int haveChildren(struct Trie *curr){
    int i;
    for (i = 0; i < CHAR_SIZE; i++) {
        if(curr->children[i])
            return 1; //found child.
    }
    return 0;
};

int main() {
    struct Trie *root = getNewNode();
    insert(&root, "adam", "a");
    insert(&root, "adams", "b");
    printf("%d \n", search(root, "adam"));



}