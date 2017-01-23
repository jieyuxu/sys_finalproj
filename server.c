#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "executioner.h"
#include <sys/socket.h>
#include "networking.h"
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <pthread.h>

#define BUFSIZE 100

void process( char * s );
void sub_server( int sd );

// int main() {

//   // int x = 1;
//   // int f;
//   // int sd, connection;

//   // char buffer[MESSAGE_BUFFER_SIZE];

//   int sd = server_setup();
//   printf("Waiting to connect... \n");

//   // while (1) {
//   //   connection = server_connect( sd );
//   //   //printf("start game? (y/n)? ");
//   //   //fgets(buffer, sizeof(buffer), stdin);
//   //   // if (strchr(buffer, 'y')){
//   //   int pid = fork();
//   //   if ( pid == 0 ) {
//   //     close(sd);
//   //     sub_server( connection );
//   //     // printf("Reached this exit\n");
//   //     exit(0);
//   //   }        
//   //   else {
//   //     close( connection );
//   //   }
//   //   // }
//   // }
//   int newsockfd, portno, pid;
//   struct sockaddr_in serv_addr, cli_addr;
//   unsigned int clilen = sizeof(cli_addr);
//   char buffer[256];
  
//   listen(sd, 5);
//   while (1) {
//         newsockfd = accept(sd, (struct sockaddr *) &cli_addr, &clilen);
      
//         if (newsockfd < 0) {
//            printf("error on accept");
//            exit(1);
//         }
        
//         /* Create child process */
//         pid = fork();
      
//         if (pid < 0) {
//            printf("error on fork");
//            exit(1);
//         }
        
//         if (pid == 0) {
//            /* This is the client process */
//            close(sd);
//            sub_server(newsockfd);
//            exit(0);
//         }
//         else {
//            close(newsockfd);
//         }
      
//   } /* end of while */
//   return 0;
// }

void *connection_handler(void *);

int main(int argc, char **argv) {
  int parentfd; /* parent socket */
  int childfd; /* child socket */
  int portno = 9001; /* port to listen on */
  int clientlen; /* byte size of client's address */
  struct sockaddr_in serveraddr; /* server's addr */
  struct sockaddr_in clientaddr; /* client addr */
  char buf[BUFSIZE]; /* message buffer */
  int optval; /* flag value for setsockopt */
  int n; /* message byte size */
  int connectcnt; /* number of connection requests */
  int notdone;
  fd_set readfds;

  /* 
   * check command line arguments 
   */

  /* 
   * socket: create the parent socket 
   */
  parentfd = socket(AF_INET, SOCK_STREAM, 0);
  if (parentfd < 0) 
    printf("printf opening socket");

  /* setsockopt: Handy debugging trick that lets 
   * us rerun the server immediately after we kill it; 
   * otherwise we have to wait about 20 secs. 
   * Eliminates "printf on binding: Address already in use" printf. 
   */
  optval = 1;
  setsockopt(parentfd, SOL_SOCKET, SO_REUSEADDR, 
       (const void *)&optval , sizeof(int));

  /*
   * build the server's Internet address
   */
  bzero((char *) &serveraddr, sizeof(serveraddr));

  /* this is an Internet address */
  serveraddr.sin_family = AF_INET;

  /* let the system figure out our IP address */
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

  /* this is the port we will listen on */
  serveraddr.sin_port = htons((unsigned short)portno);

  /* 
   * bind: associate the parent socket with a port 
   */
  if (bind(parentfd, (struct sockaddr *) &serveraddr, 
     sizeof(serveraddr)) < 0) 
    printf("printf on binding");

  /* 
   * listen: make this socket ready to accept connection requests 
   */
  if (listen(parentfd, 5) < 0) /* allow 5 requests to queue up */ 
    printf("printf on listen");


  /* initialize some things for the main loop */
  clientlen = sizeof(clientaddr);
  notdone = 1;
  connectcnt = 0;
  printf("server> ");
  fflush(stdout);

  /* 
   * main loop: wait for connection request or stdin command.
   *
   * If connection request, then echo input line 
   * and close connection. 
   * If command, then process command.
   */
  while (1) {

    /* 
     * select: Has the user typed something to stdin or 
     * has a connection request arrived?
     */
    FD_ZERO(&readfds);          /* initialize the fd set */
    FD_SET(parentfd, &readfds); /* add socket fd */
    FD_SET(0, &readfds);        /* add stdin fd (0) */
    if (select(parentfd+1, &readfds, 0, 0, 0) < 0) {
      printf("printf in select");
    }

  //   /* if the user has entered a command, process it */
  //   if (FD_ISSET(0, &readfds)) {
  //     fgets(buf, BUFSIZE, stdin);
  //     switch (buf[0]) {
  //     case 'c': /* print the connection cnt */
  // printf("Received %d connection requests so far.\n", connectcnt);
  // printf("server> ");
  // fflush(stdout);
  // break;
  //     case 'q': /* terminate the server */
  // notdone = 0;
  // break;
  //     default: /* bad input */
  // printf("printf: unknown command\n");
  // printf("server> ");
  // fflush(stdout);
  //     }
  //   }    
    /* if a connection request has arrived, process it */
    if (FD_ISSET(parentfd, &readfds)) {
      /* 
       * accept: wait for a connection request 
       */
      childfd = accept(parentfd, (struct sockaddr *) &clientaddr, &clientlen);
      if (childfd < 0) 
        printf("printf on accept");
      connectcnt++;
      
      
      
      close(childfd);
    }
  }

  /* clean up */
  printf("Terminating server.\n");
  close(parentfd);
  exit(0);
}
   
      
void sub_server( int sd ) {
  Setup();
  Display();
  write(sd, _PUZZLE, sizeof(_PUZZLE));
  
  char buffer[MESSAGE_BUFFER_SIZE];
  
  while ( checkWin()){
    
    read( sd, buffer, sizeof(buffer));
    printf("[SERVER %d] received: %s\n", getpid(), buffer );
    Player_Input( buffer );
    Display();
    write( sd, buffer, sizeof(buffer));    
  }   
}
  

// void process( char * s ) {
  
//   while ( *s ) {
//     *s = (*s - 'a' + 13) % 26 + 'a';
//     s++;
//   }
  
  
// }
