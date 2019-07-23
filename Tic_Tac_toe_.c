#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void menu();
void ptp();
int notfull();
int check(char symbol);
int chk_col(char symbol);
int chk_row(char symbol);
int chk_lgtdiag(char symbol);
int chk_rgtdiag(char symbol);
void mark_it(int r,int c,char a);
void Generate_Table_and_Array();
void display();



char **table;
int rxc=4;
char p1char,p2char;
int x=-1,y=-1;
int c_x=-1,c_y=-1;
void main(){
menu();

}
void menu(){
int action;
printf("\t Welcome to tic tac toe!");


printf("\n\nEnter the tic tac toe's size of table:");
scanf("%d",&rxc);
ptp();
	}
	

	
void ptp(){

Generate_Table_and_Array();

printf("\nEnter player 1's and 2's symbol:\n");

scanf("\n%c %c",&p1char,&p2char);
display();
while(notfull()==1){


printf("\nEnter Player 1's Coordinates on table like 1,3 (Symbol:%c):",p1char);

scanf("%d,%d",&x,&y);

system("cls");

 mark_it(x,y,p1char);
display();
if(check(p1char)==1){
	printf("\nPlayer 1 Wins!");
		getch();
	exit(0);
}
if(notfull()==0){
	printf("\nGame Draws.");
	getch();
	exit(0);
}

printf("\nEnter Player 2's Coordinates on table like 1,3 (Symbol:%c):",p2char);
scanf("%d,%d",&x,&y);
system("cls");
mark_it(x,y,p2char);
display();
if(check(p2char)==1){
	printf("\nPlayer 2 Wins!");
		getch();
	exit(0);
}
if(notfull()==0){
	printf("\nGame Draws.");
		getch();
	exit(0);
}

}
}


int notfull(){
	int i=0,j=0;
	for(i=0;i<rxc;i++){
		for(j=0;j<rxc;j++){
			if(table[i][j]=='\0')
			return 1;
		}
		
	}
	return 0;
}

int check(char symbol){
	if(chk_col(symbol)==1 || chk_row(symbol)==1 || chk_lgtdiag(symbol)==1 || chk_rgtdiag(symbol)==1 )
	{
		return 1;
	}
	return 0;
}

	int chk_col(char symbol){
		int i=0,j=0;
		int count=0;
		for(i=0;i<rxc;i++){
	
	for(j=0;j<rxc;j++){
		if(table[j][i]==symbol)
		{
			count++;
		}
		
	}
	if(count==rxc){
		return 1;
	}
	count=0;

}
return 0;

}
	



	int chk_row(char symbol){
	int i=0,j=0;
		int count=0;
		for(i=0;i<rxc;i++){
	
	for(j=0;j<rxc;j++){
		if(table[i][j]==symbol)
		{
			count++;
		}
		
	}
	if(count==rxc){
		return 1;
	}
	count=0;

}
return 0;

	}
	

	int chk_lgtdiag(char symbol){
	int i=0;
	for(i=0;i<rxc;i++){
		if(table[i][i]!=symbol)
		return 0;
		}
		return 1;	
	}
	
		int chk_rgtdiag(char symbol){
			int i=0,j=rxc-1;
			for(i=0;i<rxc;i++){
		if(table[i][j-i]!=symbol)
		return 0;
		
	}	
		return 1;	
		}
		
		
		
void mark_it(int r,int c,char a){
	//
int flag=1;
while(flag==1){
	flag=0;
	
	r--;c--;
	//Not within range
	if(r<0 || r>rxc || c<0 || c>rxc){
		flag=1;
	}
	
	//if within range
	if(r>-1 && r<rxc && c>-1 && c<rxc)
	{   	//if within range and not in reserved place
		if(table[r][c]!=p1char && table[r][c]!=p2char)
		{
			table[r][c]=a;
			break;
		}
		else{
			flag=1;
		}
	}
	system("cls");
	display();
		flag=1;
	printf("\nInvalid move");
	printf("\nEnter again:");
	scanf("%d,%d",&r,&c);
}
x=-1;y=-1;
system("cls");
}
void Generate_Table_and_Array(){
	table=(char**) malloc(rxc*sizeof(char*));
	int i=0,j=0;
	for(i=0;i<rxc;i++)
	{
		table[i]=(char*) malloc(rxc*sizeof(char*));
		
	}
	//intialize all to \0
	for(i=0;i<rxc;i++){

	for(j=0;j<rxc;j++){
	table[i][j]='\0';
	}
}
}
void display(){
		printf("\n");
		int i=0,j=0;
		
for(i=0;i<rxc;i++){
	printf("\n");
	for(j=0;j<rxc;j++){
	printf("|%c|",*(*(table+i)+j));
	}
}
}

