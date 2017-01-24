<<<<<<< HEAD:Version 1.0/executioner.c
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
char character_input[5];
int character = 1;

void setPuzzle(char * c){
  strcpy(_PUZZLE, c);
}

void Setup(){
  int i;
   printf(" \n \
 ██░ ██  ▄▄▄      ███▄    █   ▄████     ▄▄▄        ██████ ▄████▄   ██▓ ██▓ ███▄ ▄███▓ ▄▄▄      ███▄    █\n \ 
▓██░ ██▒▒████▄    ██ ▀█   █  ██▒ ▀█▒   ▒████▄    ▒██    ▒▒██▀ ▀█  ▓  ▒▓  ▒▓██▒▀█▀ ██▒▒████▄    ██ ▀█   █ \n \
▒██▀▀██░▒██  ▀█▄ ▓██  ▀█ ██▒▒██░▄▄▄░   ▒██  ▀█▄  ░ ▓██▄  ▒▓█    ▄ ▒██▒▒██▒▓██    ▓██░▒██  ▀█▄ ▓██  ▀█ ██▒\n \
░▓█ ░██ ░██▄▄▄▄██▓██▒  ▐▌██▒░▓█  ██▓   ░██▄▄▄▄██   ▒   ██▒▓▓▄ ▄██▒░██░░██░▒██    ▒██ ░██▄▄▄▄██▓██▒  ▐▌██▒\n \
░▓█▒░██▓ ▓█   ▓██▒██░   ▓██░░▒▓███▀▒    ▓█   ▓██▒▒██████▒▒ ▓███▀ ░░██░░██░▒██▒   ░██▒ ▓█   ▓██▒██░   ▓██░\n \
 ▒ ░░▒░▒ ▒▒   ▓▒█░ ▒░   ▒ ▒  ░▒   ▒     ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░ ░▒ ▒  ░░▓  ░▓  ░ ▒░   ░  ░ ▒▒   ▓▒█░ ▒░   ▒ ▒ \n \
 ▒ ░▒░ ░  ▒   ▒▒ ░ ░░   ░ ▒░  ░   ░      ▒   ▒▒ ░░ ░▒  ░ ░ ░  ▒    ▒ ░ ▒ ░░  ░      ░  ▒   ▒▒ ░ ░░   ░ ▒░\n \
 ░  ░░ ░  ░   ▒     ░   ░ ░ ░ ░   ░      ░   ▒   ░  ░  ░ ░         ▒ ░ ▒ ░░      ░     ░   ▒     ░   ░ ░ \n \
 ░  ░  ░      ░  ░        ░       ░          ░  ░      ░ ░ ░       ░   ░         ░         ░  ░        ░ \n \
                                                         ░                                               \n");
  //printf("Would you like to kill a man? Or a dog? \n \t \t (Press m)   (Press d)");
  //fgets(character_input, 5, stdin);
  //if (strchr(character_input, 'd'))
          //character = 0;
  printf("Please Input Word: ");
  fgets(_PUZZLE, _MAX_SIZE, stdin);
  char* SPC = strchr(_PUZZLE, '\n');
  *(SPC) = 0;

  //  for(i = 0; _PUZZLE[i]; i++){
  //_PUZZLE[i] = tolower(_PUZZLE[i]);
  //}
}

void endGame(){
  printf("\nASCII MAN'S HEAD WAS CHOPPED OFF. SHAME ON YOU. GET OUT OF HERE!\n");
  printf("ASCII Man whispers: I will haunt you from the deadddddd\n");
  printf("The word was: %s \nExiting...\n", _PUZZLE);
  exit(0);
}


void Display_Man(int c){
  if (c == 1){
    printf("\n\t O\n       \\ | /\n\t |\n\t/\n ");
    printf("My foot! WHO the HELL just cut off my foot?!? Imma kill 'em!\n");
  }
  else if(c == 2){
    printf("\n\t O\n       \\ | /\n\t |\n");
    printf("Well look at that! Now I can't walk. Requesting a wheelchair on aisle terminal.\n");
  }
  else if(c == 3){
    printf("\n\t O\n       \\ | /\n");
    printf("BRUH. Ya cut my spine in half! I'm the new Clark Kent after his accident.\n");
  }
  else if(c == 4){
    printf("\n\t O\n       \\ |\n");
    printf("Welp. It's just you and me now rightie. No other appendages in our way. We can finally be together. Forever. \n");
  }
  else if(c == 5){
    printf("\n\t O\n         |\n");
    printf("No hands now... Does this mean I never have to work again? WOOHOO! *cough* I mean- HELP!\n");
  }
  else if(c == 6){
    printf("\n\t O\n");
    printf("I'm only a DAMN HEAD NOW! How am I even still alive...? WHO CARES. DON'T LET ME DIE BASTARD!\n");
  }
  else if(c == 7){
    endGame();
  }
  else
    printf("\n\t O\n       \\ | /\n\t |\n\t/ \\\n ");
}

void Display_Dog(int c){
  if (c == 1){
    printf("^..^     / \n/_/\\_____/ \n   /\\  / \n  /  \\/ \n");
    printf("My foot! WHO the WOOF just ate me foot?!? I'll steal their squishy toy! \n");
  }
  else if(c == 2){
    printf("^..^     / \n/_/\\_____/ \n   /\\  \n  /  \\\n");
    printf("Well look at that! Now I have no hind legs. I'm perpetually sitting. More treats for me!\n");
  }
  else if(c == 3){
    printf("^..^     / \n/_/\\_____/ \n   /   \n  /  \n");
    printf("With only one paw left I can still shake master's hand! I am still perfect Ascii Doggo! \n");
  }
  else if(c == 4){
    printf("^..^     / \n/_/\\_____/ \n");
    printf("Welp. It's just you and me now tail. Though I can no longer chase you, I will get you somehow! \n");
  }
  else if(c == 5){
    printf("^..^ \n/_/\\_____ \n");
    printf("TAILIE! NOOOOOO! That was the last tail! You better be prepared to get sent to the Pound bucko! \n");
  }
  else if(c == 6){
    printf("^..^ \n/_/ \n");
    printf("I'm only a DAMN HEAD NOW! How can I still woof...? WHO CARES. PLZ DON'T LET ME DIE MASTER! *maximum cuteness lvl puppy eyes activated*\n");
  }
  else if(c == 7){
      //endGame();
  }
  else
    printf("^..^     / \n/_/\\_____/ \n   /\\  /\\ \n  /  \\/  \\ \n");
}



int Player_Input( char * j){
  //if (isupper(j))
  //tolower(j);
  char BUFFER[100];
  strcpy(BUFFER, j);                                                                                                                                                                                                                                                                                                                                                    

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
  printf("\n\n++==THIS IS THE HANG ASCII MAN==++\n\n");
  Display_Man(GRIM_REAPER);
  printf("\nLetters Left:\n");
  Display_Word();
  printf("\n");
}

int checkWin(char * ans, char * bank){
  if(Check_Word(ans, bank)){
    Display();
    printf("\nYOU WIN!!! ASCII Man lives for another day. That is... until the next game~ ;)\nExiting...\n");
    return 0;
  }
  if(GRIM_REAPER == 7){
    printf("\nYOU LOSE!!! ASCII Man dies. Will he live the next game??? ;)\nExiting...\n");
    return 0;
  }
  return 1;
}

int checkWinServer(char * ans, char * bank){
  if(Check_Word(ans, bank)){
    Display();
     printf("\nYOU LOSE!!! ASCII Man lives for another day. That is... until the next game~ ;)\nExiting...\n");
     exit(0);
  }
  if(GRIM_REAPER == 7){
    printf("\nYOU WIN!!! ASCII Man dies. Will he live the next game??? ;)\nExiting...\n");
    exit(0);
  }
  return 1;
}

          
=======
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
char character_input[5];
int character = 1;

void setPuzzle(char * c){
  strcpy(_PUZZLE, c);
}

void title(){
     printf(" \n \
 ██░ ██  ▄▄▄      ███▄    █   ▄████     ▄▄▄        ██████ ▄████▄   ██▓ ██▓ ███▄ ▄███▓ ▄▄▄      ███▄    █\n \ 
▓██░ ██▒▒████▄    ██ ▀█   █  ██▒ ▀█▒   ▒████▄    ▒██    ▒▒██▀ ▀█  ▓  ▒▓  ▒▓██▒▀█▀ ██▒▒████▄    ██ ▀█   █ \n \
▒██▀▀██░▒██  ▀█▄ ▓██  ▀█ ██▒▒██░▄▄▄░   ▒██  ▀█▄  ░ ▓██▄  ▒▓█    ▄ ▒██▒▒██▒▓██    ▓██░▒██  ▀█▄ ▓██  ▀█ ██▒\n \
░▓█ ░██ ░██▄▄▄▄██▓██▒  ▐▌██▒░▓█  ██▓   ░██▄▄▄▄██   ▒   ██▒▓▓▄ ▄██▒░██░░██░▒██    ▒██ ░██▄▄▄▄██▓██▒  ▐▌██▒\n \
░▓█▒░██▓ ▓█   ▓██▒██░   ▓██░░▒▓███▀▒    ▓█   ▓██▒▒██████▒▒ ▓███▀ ░░██░░██░▒██▒   ░██▒ ▓█   ▓██▒██░   ▓██░\n \
 ▒ ░░▒░▒ ▒▒   ▓▒█░ ▒░   ▒ ▒  ░▒   ▒     ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░ ░▒ ▒  ░░▓  ░▓  ░ ▒░   ░  ░ ▒▒   ▓▒█░ ▒░   ▒ ▒ \n \
 ▒ ░▒░ ░  ▒   ▒▒ ░ ░░   ░ ▒░  ░   ░      ▒   ▒▒ ░░ ░▒  ░ ░ ░  ▒    ▒ ░ ▒ ░░  ░      ░  ▒   ▒▒ ░ ░░   ░ ▒░\n \
 ░  ░░ ░  ░   ▒     ░   ░ ░ ░ ░   ░      ░   ▒   ░  ░  ░ ░         ▒ ░ ▒ ░░      ░     ░   ▒     ░   ░ ░ \n \
 ░  ░  ░      ░  ░        ░       ░          ░  ░      ░ ░ ░       ░   ░         ░         ░  ░        ░ \n \
                                                         ░                                               \n");
}
            
void Setup(){
  int i;
  //printf("Would you like to kill a man? Or a dog? \n \t \t (Press m)   (Press d)");
  //fgets(character_input, 5, stdin);
  //if (strchr(character_input, 'd'))
          //character = 0;
  printf("Please Input Word: ");
  fgets(_PUZZLE, _MAX_SIZE, stdin);
  char* SPC = strchr(_PUZZLE, '\n');
  *(SPC) = 0;

  for(i = 0; _PUZZLE[i]; i++){
    _PUZZLE[i] = tolower(_PUZZLE[i]);
  }
}

void endGame(){
  printf("\nASCII MAN'S HEAD WAS CHOPPED OFF. SHAME ON YOU. GET OUT OF HERE!\n");
  printf("ASCII Man whispers: I will haunt you from the deadddddd\n");
  printf("The word was: %s \nExiting...\n", _PUZZLE);
  // exit(0);
}


void Display_Man(int c){
  if (c == 1){
    printf("\n\t O\n       \\ | /\n\t |\n\t/\n ");
    printf("My foot! WHO the HELL just cut off my foot?!? Imma kill 'em!\n");
  }
  else if(c == 2){
    printf("\n\t O\n       \\ | /\n\t |\n");
    printf("Well look at that! Now I can't walk. Requesting a wheelchair on aisle terminal.\n");
  }
  else if(c == 3){
    printf("\n\t O\n       \\ | /\n");
    printf("BRUH. Ya cut my spine in half! I'm the new Clark Kent after his accident.\n");
  }
  else if(c == 4){
    printf("\n\t O\n       \\ |\n");
    printf("Welp. It's just you and me now rightie. No other appendages in our way. We can finally be together. Forever. \n");
  }
  else if(c == 5){
    printf("\n\t O\n         |\n");
    printf("No hands now... Does this mean I never have to work again? WOOHOO! *cough* I mean- HELP!\n");
  }
  else if(c == 6){
    printf("\n\t O\n");
    printf("I'm only a DAMN HEAD NOW! How am I even still alive...? WHO CARES. DON'T LET ME DIE BASTARD!\n");
  }
  else if(c == 7){
    endGame();
  }
  else
    printf("\n\t O\n       \\ | /\n\t |\n\t/ \\\n ");
}

void Display_Dog(int c){
  if (c == 1){
    printf("^..^     / \n/_/\\_____/ \n   /\\  / \n  /  \\/ \n");
    printf("My foot! WHO the WOOF just ate me foot?!? I'll steal their squishy toy! \n");
  }
  else if(c == 2){
    printf("^..^     / \n/_/\\_____/ \n   /\\  \n  /  \\\n");
    printf("Well look at that! Now I have no hind legs. I'm perpetually sitting. More treats for me!\n");
  }
  else if(c == 3){
    printf("^..^     / \n/_/\\_____/ \n   /   \n  /  \n");
    printf("With only one paw left I can still shake master's hand! I am still perfect Ascii Doggo! \n");
  }
  else if(c == 4){
    printf("^..^     / \n/_/\\_____/ \n");
    printf("Welp. It's just you and me now tail. Though I can no longer chase you, I will get you somehow! \n");
  }
  else if(c == 5){
    printf("^..^ \n/_/\\_____ \n");
    printf("TAILIE! NOOOOOO! That was the last tail! You better be prepared to get sent to the Pound bucko! \n");
  }
  else if(c == 6){
    printf("^..^ \n/_/ \n");
    printf("I'm only a DAMN HEAD NOW! How can I still woof...? WHO CARES. PLZ DON'T LET ME DIE MASTER! *maximum cuteness lvl puppy eyes activated*\n");
  }
  else if(c == 7){
      //endGame();
  }
  else
    printf("^..^     / \n/_/\\_____/ \n   /\\  /\\ \n  /  \\/  \\ \n");
}



int Player_Input( char * j){
  if (isupper(j))
    tolower(j);
  char BUFFER[100];
  strcpy(BUFFER, j);                                                                                                                                                                                                                                                                                                                                                    

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
  printf("\n\n++==THIS IS THE HANG ASCII MAN==++\n\n");
  Display_Man(GRIM_REAPER);
  printf("\nLetters Left:\n");
  Display_Word();
  printf("\n");
}

int checkWin(char * ans, char * bank){
  if(Check_Word(ans, bank)){
    Display();
    printf("\nYOU WIN!!! ASCII Man lives for another day. That is... until the next game~ ;)\nExiting...\n");
    return 0;
  }
  if(GRIM_REAPER == 7){
    printf("\nYOU LOSE!!! ASCII Man dies. Will he live the next game??? ;)\nExiting...\n");
    return 0;
  }
  return 1;
}

int checkWinServer(char * ans, char * bank){
  if(Check_Word(ans, bank)){
    Display();
     printf("\nYOU LOSE!!! ASCII Man lives for another day. That is... until the next game~ ;)\nExiting...\n");
     exit(0);
  }
  if(GRIM_REAPER == 7){
    printf("\nYOU WIN!!! ASCII Man dies. Will he live the next game??? ;)\nExiting...\n");
    exit(0);
  }
  return 1;
}

          
>>>>>>> b8ca9544b1cf2f810ab8ef5722766a718f0447f9:executioner.c
