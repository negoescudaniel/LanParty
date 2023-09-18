#include "liste.h"
#include "cozi.h"
#include "stive.h"
#include "ARBORI.h"
void citireJucator(FILE *fisierD, struct Echipa *oneTeam, int j);
float scoreCalculator(struct Echipa *Lista);
void formareCoada(struct Echipa *copieLista,Queue **Coada);
void afisareMeci(FILE *fisierR,Queue **Coada, char **s1, char **s2);
void WinnerLoser(struct Echipa *startLista,char **s1, char **s2, Sode **stivaCastigatori, Sode **stivaInvinsi);
void showWinners(FILE *fisierR, struct Echipa *startLista, Sode **stivaCastigatori, char **Winner1, char **Winner2);
void winners(FILE *fisierR, struct Echipa *startLista, struct Echipa **startLista2, int *ok, int *k1, Sode **stivaCastigatori, Sode **stivaInvinsi,float **scoruriTop8,Queue **Coada);
void cerinta1(FILE *fisierD, struct Echipa **startLista, int *numberOfTeams);
void cerinta2(int numberOfTeams, struct Echipa **startLista);
void cerinta4(FILE *fisierR,char ***EchipeNumeDescrescator,float *scoruriTop8,struct Echipa *copieLista);
void cerinta3(FILE *fisierR, struct Echipa **startLista, struct Echipa **startLista2,float *scoruriTop8);
void cerinta5(FILE *fisierR,char **EchipeNumeDescrescator);

int main(int argc, char **argv) {
   FILE *fisierC,*fisierD,*fisierR;
    int cerinte[5];
    float score;
    fisierC=fopen(argv[1],"rt");
    fscanf(fisierC,"%d%d%d%d%d",&cerinte[0],&cerinte[1],&cerinte[2],&cerinte[3],&cerinte[4]);
    fclose(fisierC);
    fisierD=fopen(argv[2], "rt");
    fisierR=fopen(argv[3],"wt");
    //CERINTA 1
    int i,j,k;
    struct Echipa *startLista=NULL;
    int numberOfTeams;
    cerinta1(fisierD, &startLista, &numberOfTeams);
    if(cerinte[0]==1 && cerinte[1]==0 && cerinte[2]==0 && cerinte[3]==0 && cerinte[4]==0){
        display(startLista,fisierR);
    }
    else
    {   
        //Cerimta 2
        cerinta2(numberOfTeams,&startLista);
        if(cerinte[0]==1 && cerinte[1]==1 && cerinte[2]==0 && cerinte[3]==0 && cerinte[4]==0){
            display(startLista,fisierR);
        }else{
            //CERINTA 3
            float scoruriTop8[8];
            struct Echipa* startLista2 = NULL;
            cerinta3(fisierR, &startLista, &startLista2, scoruriTop8);
            char **EchipeNumeDescrescator = NULL;
            //CERINTA 4
            if(cerinte[3]==1){
                struct Echipa *copieLista=startLista2;
                cerinta4(fisierR,&EchipeNumeDescrescator,scoruriTop8,copieLista);
            }
            //CERINTA 5
            if(cerinte[4]==1)
                cerinta5(fisierR,EchipeNumeDescrescator);
        }
    }
    fclose(fisierD);
    fclose(fisierR);
    return 0;
}

void citireJucator(FILE *fisierD, struct Echipa *oneTeam, int j){
    int k=0;
    char c;
    c=getc(fisierD);
    (*oneTeam).gamers[j].firstName=malloc(sizeof(char));
    (*oneTeam).gamers[j].firstName[0]=c;
    k++;
    while(c!=' ')
    {
        c=getc(fisierD);
        k++;
        (*oneTeam).gamers[j].firstName=realloc((*oneTeam).gamers[j].firstName,k*sizeof(char));
        (*oneTeam).gamers[j].firstName[k-1]=c;
    }
    k++;
    (*oneTeam).gamers[j].firstName=realloc((*oneTeam).gamers[j].firstName,k*sizeof(char));
    (*oneTeam).gamers[j].firstName[k-1]='\0';
    //citire al doilea nume
    k=0;
    c=getc(fisierD);
    (*oneTeam).gamers[j].secondName=malloc(sizeof(char));
    (*oneTeam).gamers[j].secondName[0]=c;
    k++;
    while(c!=' ')
    {
        c=getc(fisierD);
        k++;
        (*oneTeam).gamers[j].secondName=realloc((*oneTeam).gamers[j].secondName,k*sizeof(char));
        (*oneTeam).gamers[j].secondName[k-1]=c;
    }
    k++;
    (*oneTeam).gamers[j].secondName=realloc((*oneTeam).gamers[j].secondName,k*sizeof(char));
    (*oneTeam).gamers[j].secondName[k-1]='\0';
    //citire puncte jucator
    fscanf(fisierD,"%d",&(*oneTeam).gamers[j].points);
    c=getc(fisierD);//endofline
}

float scoreCalculator(struct Echipa *Lista){
    float score;
    int i;
    score=0;
    for(i=0;i<(Lista->numberOfPlayers);i++){
        score+=Lista->gamers[i].points;
    }
    score=score/(Lista->numberOfPlayers);
    return score;
}

void formareCoada(struct Echipa *copieLista,Queue **Coada){
    while (copieLista!=NULL)
    {
        char *s1,*s2;
        s1=copieLista->teamName;
        s1[strlen(s1)-1]='\0';
        copieLista=copieLista->next;
        s2=copieLista->teamName;
        s2[strlen(s2)-1]='\0';
        enQueue(*Coada,s1,s2);
        copieLista=copieLista->next;
    }
}

void afisareMeci(FILE *fisierR,Queue **Coada, char **s1, char **s2){
    Code *unMeci;
    int i;
    unMeci=deQueue((*Coada));
    fprintf(fisierR,"%s",unMeci->t1);
    *s1=unMeci->t1;
    for(i=0; i<33-strlen(*s1); i++)
    {
        fprintf(fisierR," ");
    }
    fprintf(fisierR,"-");
    *s2=unMeci->t2;
    for(i=0; i<33-strlen(*s2); i++)
    {        
        fprintf(fisierR," ");
    }
    fprintf(fisierR,"%s\n",unMeci->t2);
}

void WinnerLoser(struct Echipa *startLista,char **s1, char **s2, Sode **stivaCastigatori, Sode **stivaInvinsi){
    struct Echipa *copieLista=startLista;
    int j;
    float scr1, scr2;
    while (copieLista!=NULL)
    {
        //Cautare in lista a echipelor scoase din coada si calcul scor
        if(strcmp(copieLista->teamName,*s1)==0)
            scr1=scoreCalculator(copieLista);
        if(strcmp(copieLista->teamName,*s2)==0)
            scr2=scoreCalculator(copieLista);
        copieLista=copieLista->next;
    }
    //creare stive
    if(scr1>scr2)
    {
        //Adaugare punct castigatori
        copieLista=startLista;
        while(copieLista!=NULL)
        {
            if(strcmp(copieLista->teamName,*s1)==0)
            {
                for(j=0; j<(copieLista->numberOfPlayers); j++)
                    copieLista->gamers[j].points++;
            }
                copieLista=copieLista->next;
        }
        push(&(*stivaCastigatori),*s1);
        push(&(*stivaInvinsi),*s2);
    }
    else
    {
        //Adaugare punct castigatori
        copieLista=startLista;
        while(copieLista!=NULL)
        {
            if(strcmp(copieLista->teamName,*s2)==0)
            {
                for(j=0; j<(copieLista->numberOfPlayers); j++)
                    copieLista->gamers[j].points++;
            }
            copieLista=copieLista->next;
        }
        push(&(*stivaCastigatori),*s2);
        push(&(*stivaInvinsi),*s1);
    }
}

void showWinners(FILE *fisierR, struct Echipa *startLista, Sode **stivaCastigatori, char **Winner1, char **Winner2){
    float score;
    struct Echipa *copieLista;
    int i;
    *Winner1=pop(&stivaCastigatori);
    fprintf(fisierR,"%s",*Winner1);
    for(i=0; i<34-strlen(*Winner1); i++)
        fprintf(fisierR," ");
    copieLista=startLista;
    while(copieLista!=NULL)
    {
        if(strcmp(copieLista->teamName,*Winner1)==0)
            score=scoreCalculator(copieLista);
        copieLista=copieLista->next;
    }
    fprintf(fisierR,"-  %.2f\n",score);
    *Winner2=pop(&stivaCastigatori);
    fprintf(fisierR,"%s",*Winner2);
    for(i=0; i<34-strlen(*Winner2); i++)
        fprintf(fisierR," ");
    copieLista=startLista;
    while(copieLista!=NULL)
    {
        if(strcmp(copieLista->teamName,Winner2)==0)
            score=scoreCalculator(copieLista);
        copieLista=copieLista->next;
    }
    fprintf(fisierR,"-  %.2f\n",score);
}

void winners(FILE *fisierR, struct Echipa *startLista, struct Echipa **startLista2, int *ok, int *k1, Sode **stivaCastigatori, Sode **stivaInvinsi,float **scoruriTop8,Queue **Coada){
    char *Winner1,*Winner2;
    struct Echipa *copieLista=startLista;
    int i, k, y=7;
    float score;
    *k1=numberOfElements(*stivaCastigatori);
    if(numberOfElements(*stivaCastigatori)==1)
    {
        *ok=0;
        Winner1=pop(&(*stivaCastigatori));
        //Afisare Nume echipa + scor
        fprintf(fisierR,"%s",Winner1);
        for(i=0; i<34-strlen(Winner1); i++)
            fprintf(fisierR," ");
        copieLista=startLista;
        while(copieLista!=NULL)
        {
            if(strcmp(copieLista->teamName,Winner1)==0)
                score=scoreCalculator(copieLista);
            copieLista=copieLista->next;
        }
        fprintf(fisierR,"-  %.2f\n",score);
    }else{
        for(k=0;k<(*k1)/2;k++)
        {
            showWinners(fisierR,startLista,stivaCastigatori,&Winner1,&Winner2);
            enQueue(Coada,Winner1,Winner2);
            //Salvez scorurile ultimelor 8 echipe la momentul cand raman doar 8 echipe
            if(k1==8)
            {
                copieLista=startLista;
                while(copieLista!=NULL)
                {
                    if(strcmp(copieLista->teamName,Winner1)==0)
                    {
                        addAtBeginning(&(*startLista2),copieLista->numberOfPlayers,copieLista->teamName,copieLista->gamers);
                        (*scoruriTop8)[y]=scoreCalculator(copieLista);
                        y--;
                    }
                    if(strcmp(copieLista->teamName,Winner2)==0)
                    {
                        addAtBeginning(&(*startLista2),copieLista->numberOfPlayers,copieLista->teamName,copieLista->gamers);
                        (*scoruriTop8)[y]=scoreCalculator(copieLista);
                        y--;
                    }
                    copieLista=copieLista->next;
                }
            }
        }
        fprintf(fisierR,"\n");
    }
}

void cerinta1(FILE *fisierD, struct Echipa **startLista, int *numberOfTeams){
    char c;
    struct Echipa oneTeam;
    int i, j, k;
    fscanf(fisierD,"%d",numberOfTeams);
    for(i=0;i<(*numberOfTeams);i++){
        fscanf(fisierD,"%d",&oneTeam.numberOfPlayers);
        //citire nume echipa
        c=getc(fisierD);
        c=getc(fisierD);
        k=0;
        oneTeam.teamName=malloc(sizeof(char));
        oneTeam.teamName[0]=c;
        k++;
        c=getc(fisierD);
        while(c!='\n')
        {
            k++;
            oneTeam.teamName=realloc(oneTeam.teamName,k*sizeof(char));
            oneTeam.teamName[k-1]=c;
            c=getc(fisierD);
        }
        k++;
        oneTeam.teamName=realloc(oneTeam.teamName,k*sizeof(char));
        oneTeam.teamName[k-1]='\0';
        //
        oneTeam.teamName[k-1]='\0';
        //citire jucatori
        oneTeam.gamers=malloc(oneTeam.numberOfPlayers*sizeof(struct Player));
        for(j=0;j<oneTeam.numberOfPlayers;j++)
            citireJucator(fisierD, &oneTeam, j);
        addAtBeginning(startLista,oneTeam.numberOfPlayers,oneTeam.teamName,oneTeam.gamers);
        oneTeam.gamers=NULL;
        oneTeam.teamName=NULL;
    }
}

void cerinta2(int numberOfTeams, struct Echipa **startLista){
    //aflarea numarului N
    int i, j, n=1;
    while(n<=numberOfTeams){
        n=n*2;
    }
    if(n>numberOfTeams){
        n=n/2;
    }
    float score, min1;
    int posMin,p;
    struct Echipa *copieStartLista;
    int NoT=numberOfTeams;
    for(j=0;j<NoT-n;j++)
    {
        copieStartLista=(*startLista);
        min1=5000;p=0;
        while(copieStartLista!=NULL){
            score=scoreCalculator(copieStartLista);
            if(min1>score){
                min1=score;
                posMin=p;
            }
            copieStartLista=copieStartLista->next;p++;
        }
        Delete(&(*startLista),posMin);
    }
}

void cerinta3(FILE *fisierR, struct Echipa **startLista, struct Echipa **startLista2, float *scoruriTop8){
    int i,j,k;
    float score;
    Sode* stivaCastigatori,*stivaInvinsi;
    stivaCastigatori=NULL;
    stivaInvinsi=NULL;
    int y=7;
    //Afisare lista
    display(*startLista,fisierR);
    fprintf(fisierR,"\n");
    //Creare coada initiala
    Queue *Coada=createQueue();
    struct Echipa *copieLista=*startLista;
    char *s1,*s2,*Loser;
    formareCoada(copieLista,&Coada);
    int ok=1, index=0, k1, k;
    while(ok==1)
    {
        index++;
        fprintf(fisierR,"--- ROUND NO:%d\n",index);
        while(!isEmpty1(Coada))
        {   
            afisareMeci(fisierR, &Coada,&s1,&s2); 
            //Castigator si invinsi
            WinnerLoser(*startLista, &s1, &s2, &stivaCastigatori, &stivaInvinsi);
        }
        fprintf(fisierR,"\n");
        fprintf(fisierR,"WINNERS OF ROUND NO:%d\n",index);
        //Stiva Castigatoare operatii diverse
        winners(fisierR,*startLista,startLista2,&ok,&k1,&stivaCastigatori,&stivaInvinsi,&scoruriTop8,&Coada);
        //PIERZATORII 
        for(k=0;k<k1;k++)
        {
            Loser=pop(&stivaInvinsi);
            DeleteName(&(*startLista),Loser);
        }
    }
}

void cerinta4(FILE *fisierR,char ***EchipeNumeDescrescator,float *scoruriTop8,struct Echipa *copieLista){
    //Adaugare in BST
    Aode *root=NULL;
    fprintf(fisierR,"\nTOP 8 TEAMS:\n");
    int i;
    i=0;
    root=insert(root,scoruriTop8[i],copieLista->teamName);
    i++;
    copieLista=copieLista->next;
    while(copieLista!=NULL){
        root=insert(root,scoruriTop8[i],copieLista->teamName);
        i++;
        copieLista=copieLista->next;
    }
    //Afisare in Inordine pt afisare in ordine descrescatoare
    inordine(root,fisierR);
    //Pt Cerinta 5 Salvez numele celor 8 echipe in ordine descrescatoare
    *EchipeNumeDescrescator=malloc(8*sizeof(char*));
    int index1=0;
    BstToVect(root,*EchipeNumeDescrescator,&index1);
}

void cerinta5(FILE *fisierR,char **EchipeNumeDescrescator){
    int i;
    //Adaug echipele in AVL in ordine descrescatoare, precum au fost afisate la Cerinta 4
    fprintf(fisierR,"\nTHE LEVEL 2 TEAMS ARE:\n");
    Mode *AVLroot = NULL;
    for(i=0;i<8;i++){
        AVLroot=insert2(AVLroot,8-i,EchipeNumeDescrescator[i]);
    }
    //Afisarea echipelor de pe nivelul 2 al AVL
    fprintf(fisierR,"%s\n",AVLroot->right->right->nume);
    fprintf(fisierR,"%s\n",AVLroot->right->left->nume);
    fprintf(fisierR,"%s\n",AVLroot->left->right->nume);
    fprintf(fisierR,"%s\n",AVLroot->left->left->nume);
}