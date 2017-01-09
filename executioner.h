#ifndef EXECUTIONER
#define EXECUTIONER

void display();
void makeman(int c);
void displayword();

int checkanswer(char * guess);
int checkletter(char * letter); //checks if is in word bank

int addtobank(char letter);
char * tolowercase(char * word);

int updatecounter(char * word, char letter); //if the guess is incorrect, the 



#endif
