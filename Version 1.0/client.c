
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "networking.h"

int main( int argc, char *argv[] ) {

  char *host;
  if (argc != 2 ) {
    printf("host not specified, conneting to 127.0.0.1\n");
    host = "127.0.0.1";
  }
  else
    host = argv[1];

  int sd;

  sd = client_connect( host );

  //read( sd, buffer, sizeof(buffer) );                                                                                                                                                                     

  char buffer[MESSAGE_BUFFER_SIZE];

  //write(sd, 'hello', 6);
  
  //Reading for Setup
  printf("Reading for input 1\n");
  read( sd, buffer, sizeof(buffer) );
  setPuzzle(buffer);
  //printf("The word is: %s", buffer);
  
  
  
  
  

  while (1) {
    Display();
    printf("Enter Letter: ");
    fgets( buffer, sizeof(buffer), stdin );
    char *p = strchr(buffer, '\n');
    *p = 0;
   

    
    
    if(Player_Input(buffer)){

      write( sd, buffer, sizeof(buffer) );
      read( sd, buffer, sizeof(buffer) );
      //printf( "received: %s\n", buffer );                                                                                                                                                                 
    }

  }

  return 0;
}






/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <unistd.h> */

/* #include "executioner.h" */
/* #include "networking.h" */

/* char ans[100]; */
/* int grim_reaper = 0; */

/* int main( int argc, char *argv[] ) { */

/*   char *host; */
/*   if (argc != 2 ) { */
/*     printf("host not specified, connecting to 127.0.0.1\n"); */
/*     host = "127.0.0.1"; */
/*   } */
/*   else */
/*     host = argv[1]; */
  
/*   int sd, isR; */

/*   sd = client_connect( host ); */

/*   char sbuffer[MESSAGE_BUFFER_SIZE]; */
/*   char rbuffer[MESSAGE_BUFFER_SIZE]; */
/*   char BANK[25]; */
  

/*   //Reading for Setup */
/*   read( sd, sbuffer, sizeof(sbuffer) ); */
/*   // setPuzzle(buffer); */
/*   setPuzzle(sbuffer); */

/*   while (1) { */
/*     Display(); */

/*     printf("Enter Letter: "); */

/*     if (fgets( sbuffer, sizeof(sbuffer), stdin) != NULL){ */
/*       char *p = strchr(sbuffer, '\n'); */
/*       *p = 0; */
/*       send(sd, sbuffer, 200, 0); */
/*       Player_Input(sbuffer); */
/*     } */

/*    // printf("where you at 1\n"); */
/*     //Player_Input(buffer, cat); */

/*     // if(Player_Input(buffer, cat)){ */
/*     //   //printf("where you at 2\n"); */
/*     //   write( sd, buffer, sizeof(buffer) ); */
/*     //  // printf("where you at 3\n"); */
/*     //   read( sd, buffer, sizeof(buffer) ); */
/*     //   //printf( "received: %s\n", buffer ); */
/*     //   //printf("where you at 4\n"); */
/*     // } */
    
/*   }   */
/*   return 0; */
/* } */
