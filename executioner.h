#ifndef EXECUTIONER
#define EXECUTIONER

char _PUZZLE[100];

void setPuzzle(char * c);
void Setup();
void endGame();
void Display_Man(int c);
int Player_Input();
void Display_Word();
int Check_Word();
void Display();
int checkWin(int option);


#endif
