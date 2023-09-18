#include"ARBORI.h"
Aode* newAode(float scor,char *s)
{
    Aode* aode=(Aode*)malloc(sizeof(Aode));
    aode->scr=scor;
    //aode->tName=malloc(sizeof(*s));
    //strcpy(aode->tName,s);
    aode->tName=s;
    aode->left=NULL;
    aode->right=NULL;
    return aode;
}

Aode* insert(Aode* node, float scor1, char *nume)
{
    if(node==NULL)
    {
        return newAode(scor1,nume);
    }
    if(scor1 < node->scr)
    {
        node->left=insert(node->left,scor1,nume);
    }else if(scor1 > node->scr)
    {
        node->right=insert(node->right,scor1,nume);
    }
    else if(scor1 == node -> scr)
    {
        if(strcmp(nume,node->tName)<0)
        {
            node->left=insert(node->left,scor1,nume);
        }
        else
        {
            node->right=insert(node->right,scor1,nume);
        }
    }
    return node;
}
void inordine(Aode *rut,FILE *afisare){
    if(rut!=NULL)
    {  
        inordine(rut->right,afisare);
        fprintf(afisare,"%s",rut->tName);
        for(int k=0;k<34-strlen(rut->tName);k++)
        { 
            fprintf(afisare," ");
        }
        fprintf(afisare,"-  %.2f\n",rut->scr);
        inordine(rut->left,afisare);
    }
}
void inordine111(Aode *rut)
{
    if(rut)
    {
        inordine111(rut->right);
        printf("%s",rut->tName);
        for(int k=0; k<34-strlen(rut->tName); k++)
            printf(" ");
        printf("-  %.2f\n",rut->scr);
        inordine111(rut->left);
    }
}

BstToVect(Aode* rut,char **vect, int *p)
{
    if(rut!=NULL)
    {
        BstToVect(rut->right,vect,p);
        vect[(*p)]=rut->tName;
        (*p)++;
        BstToVect(rut->left,vect,p);
    }
}
//AVL

int nodeHeight(Mode *root)
{
    if(root == NULL)
        return -1;
    else return root->height;
}

Mode* RightRotation(Mode *z)
{
    Mode *y = z->left;
    Mode *T3 = y->right;
//roteste
    y->right=z;
    z->left=T3;
//update inaltimi
    z->height=max(nodeHeight(z->left),nodeHeight(z->right))+1;
    y->height=max(nodeHeight(y->left),nodeHeight(y->right))+1;
    return y;
}


Mode* insert2(Mode *node,int key,char *s){
    if(node==NULL){
        node=(Mode*)malloc(sizeof(Mode));
        node->cheie=key;
        node->nume=s;
        node->height=0;
        node->left=NULL;
        node->right=NULL;
        return node;
    }else if(key < node->cheie)
            node->left=insert2(node->left,key,s);
    else if(key > node->cheie)
            node->right=insert2(node->right,key,s);

    node->height=1+max(nodeHeight(node->left),nodeHeight(node->right));
    int k=(nodeHeight(node->left)-nodeHeight(node->right));
    if(k>1&& key <node->left->cheie)
        return RightRotation(node);
    return node;
}
int max(int a, int b)
{
    return((a>b)?a:b);
}