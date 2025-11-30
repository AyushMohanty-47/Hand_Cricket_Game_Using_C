#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Simon_plays();
int Start_Innings(int Batsmen,int Target);

int Simon_plays()
{
	int a,b;
	while(1)
	{
		if(scanf("%d",&a)!=1)
		{
			while((b=getchar())!='\n'&& b!='\n'){}
			printf("INVALID INPUT. YOU HAVE TO ENTER BETWEEN 0 TO 6: ");
			continue;
		}
		if(a<0||a>6)
		{
			printf("ONLY 0 TO 6 ALLOWED. GO FOR IT: ");
			continue;
		}
		while((b=getchar())!='\n'&& b!='\n'){}
		return a;
	}
}
int Start_Innings(int Batsmen,int Target)
	{
		int Score=0;
		int Ball=1;
		int Free_Hit=0;
		while(1)
		{
			int Player_1,Comp_1;
			{
				if (Batsmen==1)
				{
					printf("\nBALL %d-YOUR BATTING. ALL THE BEST. ENTER YOUR RUN(0 TO 6): ",Ball);
					Player_1=Simon_plays();
					Comp_1=rand()%7;
					printf("SYSTEM BOWLS, WATCH THE BALL & HIT: %d\n", Comp_1);
					if (Comp_1==0 && Player_1==0)
					{
    					printf("RUN OUT!!\n");
    					printf("TOTAL SCORE: %d\n", Score);
    					break;
					}	
					if(Comp_1==0)
					{
						printf("NO BALL, FREE HIT, 1 RUN TO YOUR TOTAL!\n");
						Score+=1;
						Free_Hit=1;
						continue;
					}
					if(Player_1==Comp_1)
					{
						if(Free_Hit)
						{
							printf("STILL NOT OUT 'CAUSE THAT WAS A FREE HIT BALL!\n");
							Free_Hit=0;
						} 
						else
						{
							printf("LOUD APPEAL & THAT'S OUT.\nSCORE: %d\n",Score);
							break;
						}
					}
				else 
				{
					Score+=Player_1;
					printf("THE SCORE IS %d, TOTAL IS %d\n",Player_1,Score);
			    }
			}
		else 
		{
			printf("SYSTEM BATS. YOU BALL.\nBall%d. BOWL: ",Ball);
			Player_1=Simon_plays();
			Comp_1=rand()%7;
			printf("SYSTEM BATS ON: %d\n",Comp_1);
			if(Player_1==0)
			{
				printf("YOU BOWLED A NO BALL, FREE 1 RUN FOR SYSTEM & A FREE HIT!\n");
				Score+=1;
				Free_Hit=1;
				continue;
			}
			if(Player_1==Comp_1)
			{
				if(Free_Hit)
				{
					printf("SYSTEM IS SAFE AS THAT WAS A FREE HIT!\n");
					Free_Hit=0;
				}
				else
				{
				printf("SYSTEM DEPARTS. NICELY BOWLED. FINAL SCORE: %d\n",Score);
				break;
				}
			}
			else
			{
				Score+=Comp_1;
				printf("SYSTEM SCORED %d. Total score: %d\n",Comp_1,Score);
				Free_Hit=0;
			}
		}
		if (Target>0 && Score>=Target)
		{
			if (Batsmen)
			printf("CONGRATS, YOU HAVE SUCCESSFULLY CHASED THE TARGET, QUITE A HUNT!\n");
			else
			printf("\nSYSTEM HAS CHASED THE TARGET, BETTER LUCK NEXT TIME!\n");
			break;
		}
		Ball++;
	}
}
	return Score;
	}

int main()
{
	srand((unsigned int)time(NULL));
	printf("\n----IT'S IN THE GAME, WELCOME----\n");
	sleep(2);
	printf("---TOSS TIME---\n");
	sleep(2);
	int Player_Toss,Toss,Choose;
    printf("CHOOSE:0 FOR HEADS OR 1 FOR TAILS.\nENTER YOUR CHOICE: ");
    Player_Toss=Simon_plays();
    while(Player_Toss!=0 && Player_Toss!=1) 
	{
        printf("JUST ENTER 0(HEADS) OR 1(TAILS): ");
        Player_Toss=Simon_plays();
    }
    Toss=rand()%2; 
    printf("COIN'S UP: %s\n",(Toss==0)?"HEADS":"TAILS");
    if (Player_Toss==Toss) 
	{
        printf("YOU WON THE TOSS!\n");
        sleep(2);
        printf("CHOOSE:1 FOR BATTING OR 2 FOR BOWLING: ");
        Choose=Simon_plays();
        while (Choose!=1 && Choose!=2) 
		{
            printf("ENTER 1(BATTING) OR 2(BOWLING): ");
            Choose=Simon_plays();
        }
    } 
	else 
	{
        printf("SYSTEM WINS THE TOSS\n");
        sleep(2);
        Choose=(rand()%2)+1;
        if (Choose==1)
            printf("SYSTEM DECIDES TO BOWL FIRST.\n");
        else
            printf("SYSTEM DECIDES TO BAT FIRST.\n");
    }
    int Player1_Score,Comp1_Score;
    if (Choose==1)
    {
    	printf("\nYOU BAT FIRST.\n");
		Player1_Score=Start_Innings(1,0);
		int Target=Player1_Score+1;
		printf("\n---TIME FOR SYSTEM TO BAT. SYSTEM NEEDS %d TO WIN---\n",Target);
		Comp1_Score=Start_Innings(0,Target);	
	}
	else
	{
		printf("\nYOU BOWL FIRST.\n");
		Comp1_Score=Start_Innings(0,0);
		int Target=Comp1_Score+1;
		printf("\n--YOU NEED %d RUNS TO WIN. THINK YOU CAN BEAT THE SYSTEM?--\n", Target);
		Player1_Score=Start_Innings(1,Target);
	}
    printf("FINAL SCORE:\nPLAYER1: %d\nSYSTEM: %d\n",Player1_Score,Comp1_Score);
    if (Player1_Score>Comp1_Score)
    	printf("YOU WIN,NICE WORK OUT THERE!\n");
	else if (Player1_Score<Comp1_Score)
		printf("SYSTEM WINS. BETTER LUCK NEXT TIME. MAYBE YOU ARE INDEED WEAK!\n");
	else
	printf("IT IS A TIE,GOOD GAME.\n");
	return 0;	
}
