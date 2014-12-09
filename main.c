#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int field[200] = {};
int n = 2, m = 2;
int Score=0;

void PrintGame();
void ChangeField(int [], int);
int SelectFigure(int []);
void menu();
void GameOver();
int main() {
	system("mode 25,29");
	int choice;
	int* figure;
	menu();
	while (1)
	{
		srand(time(NULL));
		choice=1+rand()%7;
		switch (choice)
		{
			case 1:
				figure=(int*)malloc(4);
				n=2;m=2;
				figure[0]=1; figure[1]=1;
				figure[2]=1; figure[3]=1;
				break;
			case 2:
				figure=(int*)malloc(6);
				n=3;m=2;
				figure[0]=1; figure[1]=1;
				figure[2]=1; figure[3]=0;
				figure[4]=1; figure[5]=0;
				break;
			case 3:
				figure=(int*)malloc(6);
				n=3;m=2;
				figure[0]=1; figure[1]=1;
				figure[2]=0; figure[3]=1;
				figure[4]=0; figure[5]=1;
				break;
			case 4:
				figure=(int*)malloc(6);
				n=3;m=2;
				figure[0]=0; figure[1]=1;
				figure[2]=1; figure[3]=1;
				figure[4]=1; figure[5]=0;
				break;
			case 5:
				figure=(int*)malloc(6);
				n=3;m=2;
				figure[0]=1; figure[1]=0;
				figure[2]=1; figure[3]=1;
				figure[4]=0; figure[5]=1;
				break;
			case 6:
				figure=(int*)malloc(6);
				n=3;m=2;
				figure[0]=0; figure[1]=1;
				figure[2]=1; figure[3]=1;
				figure[4]=0; figure[5]=1;
				break;
			case 7:
				 figure=(int*)malloc(4);
				 n=4; m=1;
				 figure[0]=1;
				 figure[1]=1;
				 figure[2]=1;
				 figure[3]=1;
				 break;
			default:
				break;
		}
		ChangeField(figure, SelectFigure(figure));
		free(figure);
		
	}
	//PrintGame();
	getch();
	return 0;
}

void GameOver()
{
	system("cls");
	printf(
	"\n"
	" +---------------------+\n" 
	" |                     |\n"
	" |     T E T R I S     |\n"
	" |  xxx                |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx       xxx xxx  |\n"
	" |  xxx xxx   xxx xxx  |\n"
	" |  xxx xxx            |\n"
	" |                     |\n"
	" +---------------------+\n"
	" |                     |\n"
	" |                     |\n"
	" |                     |\n"
	" |  G A M E   O V E R  |\n"
	" |                     |\n"
	" |                     |\n"
	" |  YOUR SCORE: %5d  |\n"
	" |                     |\n"
	" |                     |\n"
	" |                     |\n"
	" +---------------------+\n"
	" |                     |\n"
	" |     Press enter     |\n"
	" |     to  exit        |\n"
	" |                     |\n"
	" +---------------------+\n",Score);
	//while (getch()!=13);
	Score=0;
	if (getch() == 13) {
		exit(1);
	}
}
void menu()
{
	printf(
	"\n"
	" +---------------------+\n" 
	" |    Tomsk  State     |\n"
	" |    University of    |\n"
	" |   Control Systems   |\n"
	" |and Radio Electronics|\n"
	" +---------------------+\n"
	" |                     |\n"
	" |     T E T R I S     |\n"
	" |  xxx                |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx       xxx xxx  |\n"
	" |  xxx xxx   xxx xxx  |\n"
	" |  xxx xxx            |\n"
	" |                     |\n"
	" +---------------------+\n"
	" |                     |\n"
	" | Student:            |\n"
	" |   Rudakov Aleksandr |\n"
	" |                     |\n"
	" | Group:              |\n"
	" |               433-2 |\n"
	" +---------------------+\n"
	" |                     |\n"
	" |    Practice 2014    |\n"
	" |                     |\n"
	" +---------------------+\n");
	getch();
	system("cls");
	printf(
	"\n"
	" +---------------------+\n" 
	" |                     |\n"
	" |     T E T R I S     |\n"
	" |  xxx                |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx   xxx xxx      |\n"
	" |  xxx       xxx xxx  |\n"
	" |  xxx xxx   xxx xxx  |\n"
	" |  xxx xxx            |\n"
	" |                     |\n"
	" +---------------------+\n"
	" |                     |\n"
	" | Instruction:        |\n"
	" |                     |\n"
	" | *put down   - space |\n"
	" |                     |\n"
	" | *rotate     - enter |\n"
	" |                     |\n"
	" | *move left  - A     |\n"
	" |                     |\n"
	" | *move right - D     |\n"
	" |                     |\n"
	" +---------------------+\n"
	" |                     |\n"
	" |Press enter to start |\n"
	" |                     |\n"
	" +---------------------+\n");
	while (getch()!=13);
}
int SelectFigure(int figure[])
{
	int space[40]={};
		int position=0;
	while(1)
	{
		system("cls");
		int i,j;
		printf("\n +-----Score:%5d-----+\n",Score);
		for(i=0;i<4;i++){
			for(j=0;j<10;j++){
				space[i*10+j]=0;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(figure[i*m+j]==1){
				space[i*10+position+j]=1;
				}
			}
		}
		for (i=0;i<4;i++) {
			printf(" |.");
			for (j=0;j<10;j++) {
				if(space[i*10+j]==0){
					printf(" .");
				}
				else{
					printf("x.");
				}
			}
			printf("|\n");
		}
		for(i=0;i<19;i++){
			if(field[(i+1)*10+position]==1){
				field[i*10+position]=2;
				break;
			}
		}
		if(i==19){
			field[i*10+position]=2;
		}
		PrintGame();
		printf("\n");
		field[i*10+position]=0;
		int move;
		move=getch();
		if(move=='a'&&position>0) position--;
		if(move=='d'&&position<(10-m)) position++;
		if(move==32) break;
		if(move==13){
			int arr[n*m];
			for(j=0;j<m;j++){
				for(i=0;i<n;i++){
					arr[j*n+n-1-i]=figure[i*m+j];
				}
			}
			for(i=0;i<n*m;i++){
			figure[i]=arr[i];
			}
			if(position==10-n||position==10-m){
				if (abs(m-n)==1) position-=n-m;
			}
			if (n==4)
			{
				if (position==9) position-=3;
				if (position==8) position-=2;
				if (position==7) position-=1;
			}
			int temp;
			temp=n;
			n=m;
			m=temp;
			
		}
	}
	return position;
}
void ChangeField(int figure[], int position) {
	int i,j, first, last, cell=0, row;
	int flag=1;
	for(cell=0-n; cell+n-1<20&&flag==1;cell++){
		for(j=0;j<m;j++){
			for(i=n-1;i>=0;i--){
				if(figure[i*m+j]==1){
					if (cell>=0) {
						if(field[(cell+i+1)*10+position+j]==1){
							flag=0;
						}
					} else if (cell+i+1<0) {
						if (field[position+j] == 1) {
							GameOver();
						}
					} else if (field[(cell+i+1)*10+position+j] == 1) {
						GameOver();
					}
					break;
				}
			}
			if (flag==0) break;
		}
	}
	if (cell<0) {
		printf("\nGameOver");
		exit(1);
		getch();
	}
	cell--;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(figure[i*m+j]==1){
			field[(cell+i)*10+position+j]=1;
			}
		}
	}
	for(i=0;i<20;i++){
		int boom=1;
		for(j=0;j<10;j++)
		{
			if (field[i*10+j]==0){
				boom=0;
				break;
			}
		}
		if(boom==1)
		{
			int k;
			for(k=i;k>0;k--){
				for(j=0;j<10;j++){
					field[k*10+j]=field[(k-1)*10+j];
				}
			}
			for(j=0;j<10;j++){
				field[j]=0;
			}
			Score++;
			
		}
	}
	//printf(" %d", cell);
}

void PrintGame() {
	int i,j;
	printf(" +");
	for(i=0;i<21;i++) printf("-");
	printf("+\n");
	for (i=0;i<20;i++) {
		printf(" |.");
		for (j=0;j<10;j++) {
			if(field[i*10+j]==2){
				printf("v.");
			}
			else
			{	
				if(field[i*10+j]==0){
					printf(" .");
				}
				else{
					printf("x.");
				}
			}
			//printf ("%2d", field[i*10+j]);
		}
		printf("|\n");
	}
	printf(" +");
	for(i=0;i<21;i++) printf("-");
	printf("+");
}
