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
        return 1;

    curr->isLeaf =1;

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


// returns 1 if given node has any children
int haveChildren(struct Trie* curr)
{
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->children[i])
            return 1;	// child found

    return 0;
}
void query(struct Trie *root, char *str, char *pass){
    char *name = str;
    int len= strlen(str);
    struct Trie *curr = root;
    if(curr->children[str[0]- 'a'] == NULL)
        printf("\"%s\" - no record \n", str);
    else {






    }

}

void find(struct Trie *root, char *str){
    int i;
    char *name = str;
    int len = strlen(str);
    struct Trie *curr = root;
    if(curr->children[str[0]- 'a'] == NULL)
        printf("\"%s\" - no record \n", str);
    else {
        for (int i = 0; i < len ; i++) {
            curr=curr->children[str[i]- 'a'];
            if(curr){
                printf("a ");
            }
        }





        }


    }




//    while(*str){
//        curr = curr -> children[*str - 'a'];
//        if(curr==NULL)
//            printf("\"%s\" no record\n", str);
//
//        str++;
//    }






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
           char *name;
           char *pass;
           opr = strtok(NULL, " "); //got name
           name = opr;
           opr = strtok(NULL, " "); //got pass
           pass = opr;
           query(root, name, pass);
       }
       else if(opr[1]=='s'){
            //got s
           char *name;
           opr = strtok(NULL, " "); //got name
           name = opr;
          find(root, name);

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






//printf("%s \n", root->children[14]->children[25]->children[13]->children[20]->children[17]->pass);


}