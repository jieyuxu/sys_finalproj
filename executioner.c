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

void setPuzzle(char * c){
  strcpy(_PUZZLE, c);
}

void Setup(){
  printf("Please Input Word: ");
  fgets(_PUZZLE, _MAX_SIZE, stdin);
  char* SPC = strchr(_PUZZLE, '\n');
  *(SPC) = 0;
  //printf("Printing the input: <%s>\n", _PUZZLE);
}

void endGame(){
  printf("\nASCII MAN'S HEAD WAS CHOPPED OFF. SHAME ON YOU. GET OUT OF HERE!\n");
  printf("ASCII Man whispers: I will haunt you from the deadddddd\n");
  printf("The word was: %s \nExiting...\n", _PUZZLE);
  exit(0);
}


void Display_Man(int c){
  if (c == 1){
    printf("\t O\n       \\ | /\n\t |\n\t/\n ");
    printf("My foot! WHO the HELL just cut off my foot?!? Imma kill 'em!\n");
  }
  else if(c == 2){
    printf("\t O\n       \\ | /\n\t |\n");
    printf("Well look at that! Now I can't walk. Requesting a wheelchair on aisle terminal.\n");
  }
  else if(c == 3){
    printf("\t O\n       \\ | /\n");
    printf("BRUH. Ya cut my spine in half! I'm the new Clark Kent after his accident.\n");
  }
  else if(c == 4){
    printf("\t O\n       \\ |\n");
    printf("Welp. It's just you and me now rightie. No other appendages in our way. We can finally be together. Forever. \n");
  }
  else if(c == 5){
    printf("\t O\n         |\n");
    printf("No hands now... Does this mean I never have to work again? WOOHOO! *cough* I mean- HELP!\n");
  }
  else if(c == 6){
    printf("\t O\n");
    printf("I'm only a DAMN HEAD NOW! How am I even still alive...? WHO CARES. DON'T LET ME DIE BASTARD!\n");
  }
  else if(c == 7){
    endGame();
  }
  else
    printf("\t O\n       \\ | /\n\t |\n\t/ \\\n ");
}

int Player_Input( char * j){
  char BUFFER[100];
  printf("<%s>\n", j);
  //printf("<%s>\n", BUFFER);
  strcpy(BUFFER, j);
  //strchr(BUFFER, "\n"); 
  printf("<%s>\n", BUFFER);
  //printf("Please input letter: ");
  //fgets(BUFFER, 100, stdin);

  if (isupper(BUFFER[0]))
    BUFFER[0] = tolower(BUFFER[0]);
  
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
      printf("Letter already guessed. \nChoose another! ");
      //fgets(BUFFER, 100, stdin);
      BUFFER[1] = 0;
      return 0;
    }

    strcat(_LETTER_BANK, BUFFER);
    _LETTER_COUNTER++;


    if (! strchr(puzzle, BUFFER[0])){
      GRIM_REAPER++;
    }
  }
  
  printf("The letter bank is currently: <%s>\n", _LETTER_BANK);
  return 1;
  
}




void Display_Word(){
  char * letter = _PUZZLE;
  
  while(*letter != '\0'){
    if(strchr(" ", *letter)){
      printf("   ");
    }

    else if(strchr(_LETTER_BANK, *letter) == NULL){
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
    if(strchr(" ", *letter)){
    }  

    else if(strchr(_LETTER_BANK, *letter) == NULL){
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

int checkWin(){
  if(Check_Word()){
    Display();
    printf("\nYOU WIN!!! ASCII Man lives for another day. That is... until the next game~ ;)\nExiting...\n");
    return 0;
  }
  return 1;
}

/*
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
*/
