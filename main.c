#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y) //gotoxy
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void obst_0(int a){ // a = x_obst_0 ......: y = 6 to y = 14
	int i ;
	for ( i = 3; i <= 6; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy(a + 2, i);
		printf("|");	
	}
	gotoxy(a, 6);
	printf("___");
	
	gotoxy(a, 14);
	printf("___");
	for ( i = 15; i <= 21 ; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy( a +2 , i);
		printf("|");
	}
	return ;		
}

void obst_1(int a){ // a = x_obst_1 ......: y = 10 to y = 18
	int i ;
	for ( i = 3; i <= 10; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy(a + 2, i);
		printf("|");	
	}
	gotoxy(a, 10);
	printf("___");
	
	gotoxy(a, 18);
	printf("___");
	for ( i = 19; i <= 21 ; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy( a +2 , i);
		printf("|");
	}
	return ;		
}

void obst_2(int a){ // a = x_obst_2 ......: y = 8 to y = 16
	int i ;
	for ( i = 3; i <= 8; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy(a + 2, i);
		printf("|");	
	}
	gotoxy(a, 8);
	printf("___");
	
	gotoxy(a, 16);
	printf("___");
	for ( i = 17; i <= 21 ; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy( a +2 , i);
		printf("|");
	}
	return ;		
}

void obst_3(int a){ // a = x_obst_2 ......: y = 2 to y = 8
	int i ;
	
	gotoxy(a, 8);
	printf("___");
	for ( i = 9; i <= 21 ; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy( a +2 , i);
		printf("|");
	}
	return ;		
}

void obst_4(int a){ // a = x_obst_2 ......: y = 15 to y = 22
	int i ;
	for ( i = 3; i <= 15; i++){
		gotoxy(a, i);
		printf("|");
		gotoxy(a + 2, i);
		printf("|");	
	}
	gotoxy(a, 15);
	printf("___");

	return ;		
}


main(){
	
	int y_bird, i, jump, jump_times, x_obst[9], x_obst_check[9] , random, score;
	setlocale(LC_ALL, "portuguese");
	srand( time ( NULL ));

	
	for ( i = 0; i < 10 ; i++)
		x_obst_check[i] = 0;
		
	gotoxy(33,13);
	printf("Flappy bird");
	gotoxy(32, 15);
	printf("Enter to play");
	fflush(stdin);
	getchar();
	system("cls");
	gotoxy(33,13);
	printf("Tutorial :");
	gotoxy(28, 15);
	printf("Space or up_arrow to jump");
	sleep( 1.50000);
	system("cls");
	y_bird = 12;
	jump = 0;
	x_obst[0] = 0;
	random = 0;
	score = 0;
	for ( ; ; ){
		
		gotoxy( 3, 2);
		printf("______________________________________________________________________");// written at 3x, 2y : inside at 3y
		gotoxy( 3, 22);
		printf("______________________________________________________________________");// written at 3x, 22y : inside at 21y
		for (i = 3 ; i < 22 ; i++ ){
			gotoxy( 3, i);
			printf("|");
			gotoxy( 72, i);
			printf("|");
		}
		
		//***printing the bird
		gotoxy(10, y_bird);
		printf("0");
		
		//**************The print obstacles begin**************
		
		//***Obst[0]
		if ( x_obst_check[0] == 1){
			if ( x_obst[0] < 5)
				x_obst_check[0] = 0;
			else{
			obst_0(x_obst[0]);
			x_obst[0]--;
			}
		}
		
		//***Obst[1]
		if ( x_obst_check[1] == 1){
			if ( x_obst[1] < 5)
				x_obst_check[1] = 0;
			else{
			obst_1(x_obst[1]);
			x_obst[1]--;
			}
		}
		//***Obst[2]
		if ( x_obst_check[2] == 1){
			if ( x_obst[2] < 5)
				x_obst_check[2] = 0;
			else{
			obst_2(x_obst[2]);
			x_obst[2]--;
			}
		}
		//***Obst[3}
		if ( x_obst_check[3] == 1){
			if ( x_obst[3] < 5)
				x_obst_check[3] = 0;
			else{
			obst_3(x_obst[3]);
			x_obst[3]--;
			}
		}
		//***Obst[4]
		if ( x_obst_check[4] == 1){
			if ( x_obst[4] < 5)
				x_obst_check[4] = 0;
			else{
			obst_4(x_obst[4]);
			x_obst[4]--;
			}
		}
		//***OBST[5] = 0
		if (x_obst_check[5] == 1){
			if ( x_obst[5] < 5)
				x_obst_check[5] = 0;
			else{
			obst_0(x_obst[5]);
			x_obst[5]--;
			}
		}
		//***Obst[6] = 1
		if (x_obst_check[6] == 1){
			if ( x_obst[6] < 5)
				x_obst_check[6] = 0;
			else{	
			obst_1(x_obst[6]);
			x_obst[6]--;
			}
		}	 
		//***Obst[7] = 2
		if ( x_obst_check[7] == 1){
			if ( x_obst[7] < 5)
				x_obst_check[7] = 0;
			else{
				obst_2(x_obst[7]);
				x_obst[7]--;			
			}	
			
		}
		//***Obst[8] = 3
		if ( x_obst_check[8] == 1){
			if ( x_obst[8] < 5)
				x_obst_check[8] = 0;
			else{
				obst_3(x_obst[8]);
				x_obst[8]--;
			}	
			
		}
		
		//***Obst[9] = 4
		if ( x_obst_check[9] == 1){
			if ( x_obst[9] < 5)
				x_obst_check[9] = 0;
			else{
				obst_4(x_obst[9]);
				x_obst[9]--;
			}	
			
		}
		//**************The print obstacles end**************
		
		//***New Obstacle***New Obstacle
		if ( x_obst[random] < 53 ){
			random = rand() % 10;
			if ( x_obst_check[random] != 1 )
			x_obst[random] = 69;
			x_obst_check[random] = 1;
			
		}
		//***Smashed Bird against those Mario Pipes+++***+++***+++***+++***
		if ( x_obst[0] >= 8 && x_obst[0] <= 10 || x_obst[5] >= 8 && x_obst[5] <= 10 ){
			if (y_bird <= 6 || y_bird >= 14)
				break;
			score++;	
		}
		
		if ( x_obst[1] >= 8 && x_obst[1] <= 10 || x_obst[6] >= 8 && x_obst[6] <= 10 ){
			if (y_bird <= 10 || y_bird >= 18 )
				break;
			score++;	
		}
		
		if ( x_obst[2] >= 8 && x_obst[2] <= 10 || x_obst[7] >= 8 && x_obst[7] <= 10 ){
			if (y_bird <= 8 || y_bird >= 16 )
				break;
			score++;	
		}
		
		if ( x_obst[3] >= 8 && x_obst[3] <= 10 || x_obst[8] >= 8 && x_obst[8] <= 10){
			if (y_bird <= 2 || y_bird >= 8 )
				break;
			score++;	
		}
		
		if ( x_obst[4] >= 8 && x_obst[4] <= 10 || x_obst[9] >= 8 && x_obst[9] <= 10 ){
			if (y_bird <= 15 || y_bird >= 22 )
				break;
			score++;	
		}
		
		//***Get space ( Get jump )***
		if ( GetAsyncKeyState(VK_SPACE) &0x25 || GetAsyncKeyState(VK_UP) &0x25 ){
			jump = 1;
			jump_times = 0;
		}
		
		//***bird jumping
		if ( jump == 1){
			if ( jump_times != 4 ){
				jump_times++;
				y_bird--;;
			}
			else{
				jump = 0;
				jump_times = 0;
			}
					
		}
		
		if ( y_bird < 3 || y_bird > 21)
			break;
		
		//***bird falling
		if ( jump_times != 4 && jump == 0 )
			y_bird++;
			
		gotoxy(1,1);
		printf("Score : %d", score / 3);	
		usleep( 50000);
		system("cls");
	}
	system("cls");
	gotoxy(35,15);
	printf("Score : %d", score / 3);	
	sleep(1);
	fflush(stdin);
	getch();
}
