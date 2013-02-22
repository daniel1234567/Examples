/* James M. Rogers */
/* Copyright 2003  */

#include "server.h"

void
NewConn (int fd)
{

}

void
NewData (int fd, char *data, int size)
{

}

void
ConnClose (int fd)
{

}

int
main ()
{
  Server *New;

  New = NewServer ();

  SetPort (New, 8000, 25);
  SetCallbacks (New, NewConn, NewData, ConnClose);
  ServerOpen (New);
  while (1)
    {
      ServerLoop (New);
    }
  ServerClose (New);
  return 0;
}
