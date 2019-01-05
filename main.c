#include <stdio.h>
#include <string.h>

#include <mm_malloc.h>
#define CHAR_SIZE 26

struct Trie{
    int isLeaf;
    struct Trie *children[CHAR_SIZE];
    char *pass;
};
struct Trie *getNewNode(){
    int i;
    struct Trie *node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf=0;
    for (i=0; i<CHAR_SIZE; i++)
        node->children[i] = NULL;
    return node;
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
    if(curr->pass!=NULL)
        return curr->isLeaf=1;


};


void insert(struct Trie **head, char *str, char *pass)
{
    struct Trie *curr = *head;
    char *name = str;

    // start from root node

    while (*str)
    {
        // create a new node if path doesn't exists
        if (curr->children[*str - 'a'] == NULL)
            curr->children[*str - 'a'] = getNewNode();

        // go to next node
        curr = curr->children[*str - 'a'];

        // move to next character
        str++;
    }

    // mark current node as leaf
    curr->isLeaf = 1;
    curr->pass = pass;
    printf("\"%s\" was added \n", name);
}
int find(struct Trie* head, char* str)
{
    // return 0 if Trie is empty
    if (head == NULL)
        return 0;

    struct Trie* curr = head;
    while (*str)
    {
        // go to next node
        curr = curr->children[*str - 'a'];

        // if string is invalid (reached end of path in Trie)
        if (curr == NULL)
            return 0;

        // move to next character
        str++;
    }

    // if current node is a leaf and we have reached the
    // end of the string, return 1
    return curr->isLeaf;
}

// returns 1 if given node has any children
int haveChildren(struct Trie* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->children[i])
            return 1;	// child found

    return 0;
}

int main() {
    struct Trie *root = getNewNode();
    FILE *fp;
    fp=fopen("input.txt", "r");
    char lines[255];
    char *opr;

    while(fgets(lines, 255, fp)) {
        opr = strtok(lines, " ");
       if(opr[1] == 'a'){

           char *name;
           char *pass;

           opr = strtok(NULL, " ");
           name = opr;
           opr = strtok(NULL, " ");
           pass=opr;






            if(search(root, name) == 1)
                printf("\"%s\" username reserved\n", name);
            else

                insert(&root, name, "password123");

       }
       else if(opr[1]=='q'){
           // got q
           opr = strtok(NULL, " "); //got name
           opr = strtok(NULL, " "); //got pass
       }
       else if(opr[1]=='s'){
            //got s
           opr = strtok(NULL, " "); //got name

       }
       else if(opr[1]=='d'){
           //got d
           opr = strtok(NULL, " "); //got name

       }
       else if(opr[1]=='l'){
           // got l


       }

    }

   // printf("%s parola---", root->children[14]->children[25]->children[13]->children[20]->children[17]->pass);




     //insert(&root, "ada", "ab");

printf("%s \n", root->children[14]->children[25]->children[13]->children[20]->children[17]->pass);


}