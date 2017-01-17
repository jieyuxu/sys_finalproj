#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int _MAX_SIZE = 100;
char _PUZZLE[100];
char _LETTER_BANK[25];
int _LETTER_COUNTER = 0;
int GRIM_REAPER = 0;

void Setup(){
  fgets(_PUZZLE, _MAX_SIZE, stdin);
  char* SPC = strchr(_PUZZLE, '\n');
  *(SPC) = 0;
  //printf("Printing the input: <%s>\n", _PUZZLE);
}

void endGame(){
  printf("\nASCII MAN'S HEAD WAS CHOPPED OFF. SHAME ON YOU. GET OUT OF HERE!\nExiting...\n");
  exit(0);
}

void checkWin(){
  if(Check_Word()){
    printf("\nYOU WIN!!\nExiting...\n");
    exit(0);
  }
}

void Display_Man(int c){
  if (c == 1){
    printf("\t O\n       \\ | /\n\t |\n\t/\n ");
  }
  else if(c == 2){
    printf("\t O\n       \\ | /\n\t |\n");
  }
  else if(c == 3){
    printf("\t O\n       \\ | /\n");
  }
  else if(c==4){
    printf("\t O\n       \\ |\n");
  }
  else if(c == 5){
    printf("\t O\n       \\\n");
  }
  else if(c == 6){
    printf("\t O\n");
  }
  else if (c == 7){
    endGame();
  }
  else
    printf("\t O\n       \\ | /\n\t |\n\t/ \\\n ");
}

void Player_Input(){
  char BUFFER[100];
  printf("Please input: ");
  fgets(BUFFER, 100, stdin);
  BUFFER[1] = 0;
  char * puzzle = _PUZZLE;
  

  if(strstr(_LETTER_BANK, BUFFER) == NULL){
    strcat(_LETTER_BANK, BUFFER);
    _LETTER_COUNTER++;
    if (! strchr(puzzle, BUFFER[0])){
      GRIM_REAPER++;
    }
  }

  else{
    while (strchr(_LETTER_BANK, BUFFER[0])){
      printf("Letter already guessed. \nChoose another: ");
      fgets(BUFFER, 100, stdin);
      BUFFER[1] = 0;
    }

    strcat(_LETTER_BANK, BUFFER);
    _LETTER_COUNTER++;


    if (! strchr(puzzle, BUFFER[0])){
      GRIM_REAPER++;
    }
  }
  
  printf("The letter bank is currently: <%s>\n", _LETTER_BANK);
  
}




void Display_Word(){
  char * letter = _PUZZLE;
  
  while(*letter != '\0'){
  

    if(strchr(_LETTER_BANK, *letter) == NULL){
      printf(" _ ");
    }
    else{
      printf("%c", *letter);
    }

   
    letter++;
  }

   printf("\n");

    
}

int Check_Word(){
  char * letter = _PUZZLE;
  
  while(*letter != '\0'){
  

    if(strchr(_LETTER_BANK, *letter) == NULL){
      return 0;
    }

   
    letter++;
  }

   return 1;
}


void Display(){
  Display_Man(GRIM_REAPER);
  Display_Word();
}


main(){

  Setup();
  // Display_Man(1);
  // Display_Man(2);
  // Display_Man(3);
  // Display_Man(4);
  // Display_Man(5);
  // Display_Man(6);
  // Display_Man(7);
  while(1){
    Display();
    Player_Input();
    checkWin();
  }
}
