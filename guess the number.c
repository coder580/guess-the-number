  GNU nano 4.2                                                                                                 number combined.c                                                                                                            
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define MAX 10
#define NUMSCORES 100
struct score_st
{
        char name[64];
        uint16_t score;
};
struct score_st score[NUMSCORES];

int getdata()
{
        FILE * fp;
        fp=fopen("score.txt","r+");
        char buff[100];
        int line=0;
        bool end=0;
        while(fscanf(fp,"%s\n",buff)==1)
        {
                line++;
                char * token = strtok(buff,":"); 
                for(int i=0;;i++)
                {
                        end=0;
                        switch(i)
                        {
                                case 0:
                                strcpy(score[line].name,token);
                                break;
                                case 1:
                                score[line].score=atoi(token);
                                end=1;
                                break;
                                default:
                                break;
                        };
                        token=strtok(NULL,":");
                        if (end) break;
                }
        }
	for(int f=0;f<NUMSCORES;f++) if (score[f].name[0]!=0) printf("\t%s took %d tries\n",score[f].name,score[f].score);
        fclose(fp);
};

int main()
{
        int f = 1;
        int curguess;
        int tries;
        char * name;
        char * tofile;
        FILE * fp;
        fp=fopen("./score.txt","a+");
//      system("clear");
        printf("Enter your name(note: no colons or spaces):");
        scanf("%s",&name);
        f=0;
	srand(time(NULL));
        int r = rand() % MAX+1;
        printf("Guess a number between 1 and %d\n:",MAX);
        while (f==0)
        {
                scanf("%d",&curguess);
                if (asparagus>r)
                {
                        printf("Too high\n:");
                        tries++;
                }
                else if (curguess<r)
                {
                        printf("Too low\n:");
                        tries++;
                }
                else
                {
                        tries++;
                        printf("You won with %d tries\nThe number was: %d\n",tries,r);
                        fprintf(fp,"%s:%d\n",&name,tries);
                        fclose(fp);
                        getdata();
                        return 0;
                }
        };
};