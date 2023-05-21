#include "liste.h"
#include "cozi.h"
#include "stive.h"
#include "ARBORI.h"
int main(int argc, char **argv) {

    FILE *fisierC,*fisierD,*fisierR;
    int cerinte[5];
    fisierC=fopen(argv[1],"rt");
    fscanf(fisierC,"%d%d%d%d%d",&cerinte[0],&cerinte[1],&cerinte[2],&cerinte[3],&cerinte[4]);
    fclose(fisierC);
    fisierD=fopen(argv[2], "rt");
    fisierR=fopen(argv[3],"wt");
    //CERINTA 1
    char c;
    struct Echipa oneTeam;
    struct Echipa *startLista=NULL;
    int numberOfTeams;
    int i, j;
    int k;
    fscanf(fisierD,"%d",&numberOfTeams);
    for(i=0;i<numberOfTeams;i++){
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
        for(j=0;j<oneTeam.numberOfPlayers;j++){
            //citire primul nume
            k=0;
            c=getc(fisierD);
            oneTeam.gamers[j].firstName=malloc(sizeof(char));
            oneTeam.gamers[j].firstName[0]=c;
            k++;
            while(c!=' ')
            {
                c=getc(fisierD);
                k++;
                oneTeam.gamers[j].firstName=realloc(oneTeam.gamers[j].firstName,k*sizeof(char));
                oneTeam.gamers[j].firstName[k-1]=c;
            }
            k++;
            oneTeam.gamers[j].firstName=realloc(oneTeam.gamers[j].firstName,k*sizeof(char));
            oneTeam.gamers[j].firstName[k-1]='\0';
            //citire al doilea nume
            k=0;
            c=getc(fisierD);
            oneTeam.gamers[j].secondName=malloc(sizeof(char));
            oneTeam.gamers[j].secondName[0]=c;
            k++;
            while(c!=' ')
            {
                c=getc(fisierD);
                k++;
                oneTeam.gamers[j].secondName=realloc(oneTeam.gamers[j].secondName,k*sizeof(char));
                oneTeam.gamers[j].secondName[k-1]=c;
            }
            k++;
            oneTeam.gamers[j].secondName=realloc(oneTeam.gamers[j].secondName,k*sizeof(char));
            oneTeam.gamers[j].secondName[k-1]='\0';
            //citire puncte jucator
            fscanf(fisierD,"%d",&oneTeam.gamers[j].points);
            c=getc(fisierD);//endofline
        }
        addAtBeginning(&startLista,oneTeam.numberOfPlayers,oneTeam.teamName,oneTeam.gamers);
        oneTeam.gamers=NULL;
        oneTeam.teamName=NULL;
    }
    if(cerinte[0]==1 && cerinte[1]==0 && cerinte[2]==0 && cerinte[3]==0 && cerinte[4]==0){
        display(startLista,fisierR);
    }
    else
    {   
        //Cerimta 2
        //aflarea numarului N
        int n=1;
        while(n<=numberOfTeams){
            n=n*2;
        }
        if(n>numberOfTeams){
            n=n/2;
        }
        //printf("%d\n",n);
        //score calculator
        float score;
        float min1;
        int posMin,p;
        struct Echipa *copieStartLista;
        int NoT=numberOfTeams;
        for(j=0;j<NoT-n;j++)
        {
            copieStartLista=startLista;
            min1=5000;p=0;
            while(copieStartLista!=NULL){
                score=0;
                for(i=0;i<(copieStartLista->numberOfPlayers);i++){
                    score+=copieStartLista->gamers[i].points;
                }
                score=score/(copieStartLista->numberOfPlayers);
                if(min1>score){
                    min1=score;
                    posMin=p;
                }
                copieStartLista=copieStartLista->next;p++;
            }
            Delete(&startLista,posMin);
        }
        if(cerinte[0]==1 && cerinte[1]==1 && cerinte[2]==0 && cerinte[3]==0 && cerinte[4]==0){
            display(startLista,fisierR);
        }else{
            //CERINTA 3
            //declarare stive
            Sode* stivaCastigatori,*stivaInvinsi;
            Node* startLista2 = NULL;
            stivaCastigatori=NULL;
            stivaInvinsi=NULL;
            int y=7;
            float scoruriTop8[8];
            //Afisare lista
            display(startLista,fisierR);
            fprintf(fisierR,"\n");
            //Creare coada initiala
            Queue *Coada=createQueue();
            struct Echipa *copieLista=startLista;
            char *s1,*s2;
            while (copieLista!=NULL)
            {
                s1=copieLista->teamName;
                s1[strlen(s1)-1]='\0';
                copieLista=copieLista->next;
                s2=copieLista->teamName;
                s2[strlen(s2)-1]='\0';
                enQueue(Coada,s1,s2);
                copieLista=copieLista->next;
            }
            //
            int ok=1;
            int index=0;
            while(ok==1)
            {
                index++;
                fprintf(fisierR,"--- ROUND NO:%d\n",index);
                while(!isEmpty1(Coada))
                {   
                    //Afisare meci 
                    Code *unMeci;
                    unMeci=deQueue(Coada);
                    fprintf(fisierR,"%s",unMeci->t1);
                    s1=unMeci->t1;
                    for(i=0; i<33-strlen(s1); i++)
                    {
                        fprintf(fisierR," ");
                    }
                    fprintf(fisierR,"-");
                    s2=unMeci->t2;
                    for(i=0; i<33-strlen(s2); i++)
                    {
                        fprintf(fisierR," ");
                    }
                    fprintf(fisierR,"%s\n",unMeci->t2);
                    //Castigator si invinsi
                    copieLista=startLista;
                    float scr1, scr2,score1;
                    while (copieLista!=NULL)
                    {
                        //Cautare in lista a echipelor scoase din coada si calcul scor
                        if(strcmp(copieLista->teamName,s1)==0)
                        {
                            score1=0;
                            for(j=0; j<(copieLista->numberOfPlayers); j++)
                            {
                                score1+=copieLista->gamers[j].points;
                            }
                            score1=score1/(copieLista->numberOfPlayers);
                            scr1=score1;
                        }
                        if(strcmp(copieLista->teamName,s2)==0)
                        {
                            score1=0;
                            for(j=0; j<(copieLista->numberOfPlayers); j++)
                            {
                                score1+=copieLista->gamers[j].points;
                            }
                            score1=score1/(copieLista->numberOfPlayers);
                            scr2=score1;
                        }
                        copieLista=copieLista->next;
                    }
                    //creare stive
                    if(scr1>scr2)
                    {
                        //Adaugare punct castigatori
                        copieLista=startLista;
                        while(copieLista!=NULL)
                        {
                            if(strcmp(copieLista->teamName,s1)==0)
                            {
                                for(j=0; j<(copieLista->numberOfPlayers); j++)
                                    copieLista->gamers[j].points++;
                            }
                            copieLista=copieLista->next;
                        }
                        push(&stivaCastigatori,s1);
                        push(&stivaInvinsi,s2);
                    }
                    else
                    {
                        //Adaugare punct castigatori
                        copieLista=startLista;
                        while(copieLista!=NULL)
                        {
                            if(strcmp(copieLista->teamName,s2)==0)
                            {
                                for(j=0; j<(copieLista->numberOfPlayers); j++)
                                    copieLista->gamers[j].points++;
                            }
                            copieLista=copieLista->next;
                        }
                        push(&stivaCastigatori,s2);
                        push(&stivaInvinsi,s1);
                    }
                }
                fprintf(fisierR,"\n");
                fprintf(fisierR,"WINNERS OF ROUND NO:%d\n",index);
                //Stiva Castigatoare operatii diverse
                char *Winner1,*Winner2, *Loser;
                int k1;
                k1=numberOfElements(stivaCastigatori);
                if(numberOfElements(stivaCastigatori)==1)
                {
                    ok=0;
                    Winner1=pop(&stivaCastigatori);
                    //Afisare Nume echipa + scor
                    fprintf(fisierR,"%s",Winner1);
                    for(i=0; i<34-strlen(Winner1); i++)
                    {
                        fprintf(fisierR," ");
                    }
                    copieLista=startLista;
                    score=0;
                    while(copieLista!=NULL)
                    {
                        if(strcmp(copieLista->teamName,Winner1)==0)
                        {
                            for(j=0; j<(copieLista->numberOfPlayers); j++)
                                score+=copieLista->gamers[j].points;
                            score=score/(copieLista->numberOfPlayers);
                        }
                        copieLista=copieLista->next;
                    }
                        fprintf(fisierR,"-  %.2f\n",score);
                }else{
                    for(k=0;k<k1/2;k++)
                    {
                        Winner1=pop(&stivaCastigatori);
                        fprintf(fisierR,"%s",Winner1);
                        for(i=0; i<34-strlen(Winner1); i++)
                        {
                            fprintf(fisierR," ");
                        }
                        copieLista=startLista;
                        score=0;
                        while(copieLista!=NULL)
                        {
                            if(strcmp(copieLista->teamName,Winner1)==0)
                            {
                                for(j=0; j<(copieLista->numberOfPlayers); j++)
                                    score+=copieLista->gamers[j].points;
                                score=score/(copieLista->numberOfPlayers);
                            }
                            copieLista=copieLista->next;
                        }
                        fprintf(fisierR,"-  %.2f\n",score);
                        Winner2=pop(&stivaCastigatori);
                        fprintf(fisierR,"%s",Winner2);
                        for(i=0; i<34-strlen(Winner2); i++)
                        {
                            fprintf(fisierR," ");
                        }
                        copieLista=startLista;
                        score=0;
                        while(copieLista!=NULL)
                        {
                            if(strcmp(copieLista->teamName,Winner2)==0)
                            {
                                for(j=0; j<(copieLista->numberOfPlayers); j++)
                                    score+=copieLista->gamers[j].points;
                                score=score/(copieLista->numberOfPlayers);
                            }
                            copieLista=copieLista->next;
                        }
                        fprintf(fisierR,"-  %.2f\n",score);
                        enQueue(Coada,Winner1,Winner2);
                        //Salvez scorurile ultimelor 8 echipe la momentul cand raman doar 8 echipe
                        if(k1/2==4)
                        {
                            copieLista=startLista;
                            while(copieLista!=NULL)
                            {
                                if(strcmp(copieLista->teamName,Winner1)==0)
                                {
                                    addAtBeginning(&startLista2,copieLista->numberOfPlayers,copieLista->teamName,copieLista->gamers);
                                    score=0;
                                    for(j=0; j<(copieLista->numberOfPlayers); j++)
                                        score+=copieLista->gamers[j].points;
                                    score=score/(copieLista->numberOfPlayers);
                                    scoruriTop8[y]=score;
                                    y--;
                                }
                                if(strcmp(copieLista->teamName,Winner2)==0)
                                {
                                    addAtBeginning(&startLista2,copieLista->numberOfPlayers,copieLista->teamName,copieLista->gamers);
                                    score=0;
                                    for(j=0; j<(copieLista->numberOfPlayers); j++)
                                        score+=copieLista->gamers[j].points;
                                    score=score/(copieLista->numberOfPlayers);
                                    scoruriTop8[y]=score;
                                    y--;
                                }
                                copieLista=copieLista->next;
                            }
                        }
                    }
                    fprintf(fisierR,"\n");
                }
                //PIERZATORII 
                for(k=0;k<k1;k++)
                {
                    Loser=pop(&stivaInvinsi);
                    DeleteName(&startLista,Loser);
                }

            }
            //CERINTA 4
            char **EchipeNumeDescrescator = NULL;
            if(cerinte[3]==1)
            {
                //Adaugare in BST
                Aode *root=NULL;
                copieLista=startLista2;
                fprintf(fisierR,"\nTOP 8 TEAMS:\n");
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
                EchipeNumeDescrescator=malloc(8*sizeof(char*));
                int index1=0;
                BstToVect(root,EchipeNumeDescrescator,&index1);
            }
            if(cerinte[4]==1){
                //Cerinta 5
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
        }
    }
    fclose(fisierD);
    fclose(fisierR);
    return 0;
}