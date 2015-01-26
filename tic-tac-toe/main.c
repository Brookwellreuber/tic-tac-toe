//
//  main.c
//  tic-tac-toe
//
//  Created by David Brookwell-Reuber on 12-06-29.
//  Copyright (c) 2012 Grant MacEwan University. All rights reserved.
//
#define FALSE 0
#define TRUE !FALSE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char board[9];
char current;
char other;
char player1 = 'X';
char player2 = 'O';
/*Global variables*/

/* Swapping function that switches between players */
void swap (){
	char temp = current;
	current = other;
	other = temp; 
}
/* Initializes the variables and the board for the game */
void init(){
	current = player2;
	other = player1;
	board[0] = '1';
	board[1] = '2';
	board[2] = '3';
	board[3] = '4';
	board[4] = '5';
	board[5] = '6';
	board[6] = '7';
	board[7] = '8';
	board[8] = '9';
}
/* Prints out the board and any changes made by players when making moves */
void display()
{

		printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
		printf("|---|---|---|\n");
		printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
		printf("|---|---|---|\n");
		printf("| %c | %c | %c |\n", board[6], board[7], board[8]);

}
/* Checks if the current square is open */
int isOpen(char open){
	return open >= '1' &&
		   open <= '9';
}
/* Allows the player to make a move and uses isOpen to check if the move is valid */
void move(){
	char choice[30];
	do {
		printf("Current player (%c) please select a move on the board from 1-9 \n", current);
		scanf("%s", choice);
	}while (!isOpen(choice[0]) ||
		!isOpen(board[choice[0] - '1']));
	
		board[choice[0] - '1'] = current;
}
/* Checks if the player has scored 3 in a row */
int rowWin(int p1, int p2, int p3){
	return board[p1] == current &&
	board[p2] == current &&
	board[p3] == current;
	
}
/* Checks all valid win combinations and is used to determine the winner */
int win(){
	return rowWin(0, 3, 6) ||
	rowWin(1, 4, 7) || rowWin(2, 5, 8) ||
	rowWin(0, 1, 2) || rowWin(3, 4, 5) ||
	rowWin(6, 7, 8) || rowWin(0, 4, 8) ||
	rowWin(2, 4, 6);
}
/* Checks if the game has ended in a draw */
int draw(){
	for (int i = 0; i < 9 ; i++) {
		if (isOpen(board[i])) {
			return FALSE;
		}
	}
			return TRUE;
	
}
/* Main game function that calls swap, display, move, draw and win to 
 run and determine the victor or if they both draw */
char playGame (){
	
	init ();
	do {
		swap();
		display();
		move();
	}while (!draw() && !win());
	if (draw()) {
		printf("The game was a Draw between %c and %c\n", player1, player2);
		return ' ';
	}else {
		printf("player %c won\n", current);
		return current;
	}
	
}
/* Asks the player if they would like to play again */
int playAgain(){
	char line[30];
	do{
		printf("Would you like to play again, Please enter yes or no: ");
		scanf("%s", line);
		line[0] = toupper(line[0]);
	}while (line[0] != 'Y' && line[0] != 'N');
return line[0] == 'Y';
}

int main(int argc, const char * argv[]){
	int draws = 0;
	int win1 = 0;
	int win2 = 0;
	
	do{
		switch (playGame()) {
			case ' ': 
				draws++;
				break;
				
			case 'X':
				win1 ++;
				break;
			case 'O':
				win2++;
				break;
		}
		printf("player one: %d \n player two: %d\n Draws: %d\n", win1, win2, draws);
	}while (playAgain());


	return 0;
}