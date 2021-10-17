
#include<stdio.h>
//#include<graphics.h>
//#include<dos.h>
#include<stdlib.h>

char T[11]={'T','1','2','3','4','5','6','7','8','9'},player='X';
int n,cont=0,chek[10], g=0;

void draw();
void replace(int ,char);
char cas_Win();
bool check_avialibility(int);
void repeat();

main(){
	repeat();
	printf("\033[1;32m");
	printf ("\n the winners is : %c ",cas_Win());
	printf("\033[0m");
	exit(0);
	
}
void repeat(){
	draw();
	do{
			printf ("\n torn %c  \n choose a number 1-9 : ",player);
			scanf("%d",&n);
			while(!check_avialibility(n)){
				printf("\033[1;31m");
				printf ("\n errour  de saisir \n ");
				printf("\033[0m");
				printf("try again : ");
				scanf("%d",&n);
				
			}
			chek[g]=n;		
			g++; 
			
			if(cont %2==0){
				system("cls");
				replace(n,player);
				cont++;
				player='O';
				draw();
			}
			else{
				system("cls");
				replace(n,player);
				cont++;
				player='X';
				draw();
				
			}
		if(g==9){
			printf("\033[1;34m");
			printf ("\n ta3adol ");
			printf("\033[0m");
			exit(0);	
		}
	}while(cas_Win()=='F' );
}
void draw(){
	printf("\n \t\t\t\t\t| \t %c \t |\t %c \t|\t %c \t|\n \t\t\t\t\t_________________________________________________\n\n",T[1],T[2],T[3]);
	printf("\t\t\t\t\t| \t %c \t |\t %c \t|\t %c \t|\n \t\t\t\t\t_________________________________________________\n\n",T[4],T[5],T[6]);
	printf("\t\t\t\t\t| \t %c \t |\t %c \t|\t %c \t|\n     			  \n",T[7],T[8],T[9]);
}
void replace(int n,char player){	
		 T[n]=player;
}
char cas_Win(){	
	if(T[1]==T[2] && T[1]==T[3]){
		return T[1];
	}
	else if(T[1]==T[4] && T[1]==T[7]){
		return T[1];
	}
	else if(T[1]==T[5] && T[1]==T[9]){
		return T[1];
	}
	else if(T[2]==T[5] && T[2]==T[8]){
		return T[2];
	}
	else if(T[3]==T[6] && T[3]==T[9]){
		return T[9];
	}
	else if(T[9]==T[8] && T[9]==T[7]){
		return T[9];
	}
	else if(T[3]==T[5] && T[3]==T[7]){
		return T[3];
	}
	else return 'F';
}
bool check_avialibility(int n){
	if(n<1 || n>9){
		return false;
	}
	for(int i=0;i<g;i++){
		if(chek[i]==n){
			return false;
		}
	}
	return true;
}
