/* James M. Rogers */
/* Copyright 2003  */

#define BUFFER	 512		/* the largest message */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

typedef void _cb_1 (int);
typedef void _cb_3 (int, char *, int);

typedef struct Server
{
  int state;
  _cb_1 *callback_new;
  _cb_3 *callback_data;
  _cb_1 *callback_close;

  fd_set rfds, afds;
  int PrimarySocket;
  int Port;
  int QDepth;

  int buf_size;
  char buffer[BUFFER];
} Server;

Server *NewServer ();
int SetPort (Server *, int, int);
void SetCallbacks (Server *, _cb_1 *, _cb_3 *, _cb_1 *);
int ServerOpen (Server *);
int ServerClose (Server *);
int ServerLoop (Server *);
