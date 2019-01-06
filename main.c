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



void insert(struct Trie **head, char *str, char *pass,FILE *out)
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
    fprintf(out, "\"%s\" was added \n", name);
}


// returns 1 if given node has any children
int haveChildren(struct Trie* curr)
{
    int i;
    for ( i= 0; i < CHAR_SIZE; i++)
        if (curr->children[i])
            return 1;	// child found

    return 0;
}
void query(struct Trie *root, char *str, char *pass,FILE *out){
    char *name = str;
    int i;
    int len= (int )strlen(str);
    char *arr= malloc(sizeof(len));
    for ( i = 0; i < len; i++) {
        arr[i]=str[i];

    }
    struct Trie *curr = root;
    if(curr->children[str[0]- 'a'] == NULL){
        fprintf(out,"\"");
        for (i = 0; i < len; i++) {
            fprintf(out,"%c",arr[i]);
        }
        fprintf(out,"\" no record\n");
    }
    else {
        int temp = 0;
        int temp2 = 0;
        while (curr->children[str[temp] - 'a'] != NULL) {
            curr = curr->children[str[temp] - 'a'];


            temp++;
            temp2++;
        }
        if (temp2 == len) {
            if (haveChildren(curr) == 1) {
                fprintf(out,"\"");
                for (i = 0; i < len ; i++) {
                    fprintf(out,"%c", arr[i]);
                }
                fprintf(out,"\" not enough username\n");
            }

        }if(temp2<len){
            fprintf(out,"\"");
            for (i = 0; i < len ; i++) {
                fprintf(out,"%c", arr[i]);
            }
            fprintf(out,"\" incorrect username\n");
        }


    }
}
void find(struct Trie *root, char *str,FILE *out){
    char *name = str;
    int i;
    int len= (int )strlen(str);
    char *arr= malloc(sizeof(len));
    for ( i = 0; i < len-1; i++) {
        arr[i]=str[i];

    }
    struct Trie *curr = root;
    if(curr->children[str[0]- 'a'] == NULL){
        fprintf(out,"\"");
        for (i = 0; i < len-1; i++) {
            fprintf(out,"%c",arr[i]);
        }
        fprintf(out,"\" no record\n");
    }
    else {
        int temp = 0;
        int temp2 = 0;
        while(curr->children[str[temp] - 'a'] != NULL)
        {
            curr = curr->children[str[temp] - 'a'];


            temp++;
            temp2++;}
        if(temp2==len-1){
            if(haveChildren(curr)==1){
                fprintf(out,"\"");
                for (i = 0; i < len-1; i++) {
                    fprintf(out,"%c",arr[i]);
                }
                fprintf(out,"\" not enough username\n");
            } if(haveChildren(curr)==0){
                fprintf(out,"\"");
                for (i = 0; i < len-1; i++) {
                    fprintf(out,"%c",arr[i]);
                }
                fprintf(out,"\" password %s\n",curr->pass);
            }

        }if(temp2<len-1){
            fprintf(out,"\"");
            for (i = 0; i < len-1; i++) {
                fprintf(out,"%c",arr[i]);
            }
            fprintf(out,"\" incorrect username\n");

        }







    }

}

void deletion(struct Trie *root, char *str,FILE *out){
    char *name = str;
    int i;
    int len= (int )strlen(str);
    char *arr= malloc(sizeof(len));
    for ( i = 0; i < len-1; i++) {
        arr[i]=str[i];

    }
    struct Trie *curr = root;
    if(curr->children[str[0]- 'a'] == NULL){
        fprintf(out,"\"");
        for (i = 0; i < len-1; i++) {
            fprintf(out,"%c",arr[i]);
        }
        fprintf(out,"\" no record\n");
    }
    else {
        int temp = 0;
        int temp2 = 0;
        while(curr->children[str[temp] - 'a'] != NULL)
        {
            curr = curr->children[str[temp] - 'a'];


            temp++;
            temp2++;}
        if(temp2==len-1){
            if(haveChildren(curr)==1){
                fprintf(out,"\"");
                for (i = 0; i < len-1; i++) {
                    fprintf(out,"%c",arr[i]);
                }
                fprintf(out,"\" not enough username\n");
            }

        }if(temp2<len-1){
            fprintf(out,"\"");
            for (i = 0; i < len-1; i++) {
                fprintf(out,"%c",arr[i]);
            }
            fprintf(out,"\" incorrect username\n");

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




int main(int argc, char *argv[]) {
    struct Trie *root = getNewNode();
    FILE *fp;
    fp=fopen(argv[1], "r");
    char lines[255];
    char *opr;
    char *out = argv[2]; // output file argument.

    FILE *op; // output file pointer.
    op = fopen(out,"w");




    while(fgets(lines, 255, fp)) {
        opr = strtok(lines, " ");
        if(opr[1] == 'a'){

            char *name;
            char *pass;
            opr = strtok(NULL, " ");
            name = opr;
            opr = strtok(NULL, " ");
            pass=opr;
            char str2[10];
            strcpy(str2,pass);

            if(search(root, name) == 1)
                fprintf(op,"\"%s\" username reserved\n", name);
            else

                insert(&root, name, str2,op);



        }
        else if(opr[1]=='q'){
            // got q
            char *name;
            char *pass;
            opr = strtok(NULL, " "); //got name
            name = opr;
            opr = strtok(NULL, " "); //got pass
            pass = opr;
            query(root, name, pass,op);
        }
        else if(opr[1]=='s'){
            //got s
            char *name;
            opr = strtok(NULL, " "); //got name
            name = opr;
            find(root, name,op);

        }
        else if(opr[1]=='d'){
            //got d
            opr = strtok(NULL, " "); //got name
            deletion(root, opr,op);
        }
        else if(opr[1]=='l'){
            // got l


        }


    }

    // printf("%s parola---", root->children[14]->children[25]->children[13]->children[20]->children[17]->pass);






//printf("%s \n", root->children[14]->children[25]->children[13]->children[20]->children[17]->pass);


}