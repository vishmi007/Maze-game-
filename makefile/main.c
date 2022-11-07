
/* *****************************************************************************************************
 * Author: Vishmi Kalansooriya                               
 * Date:  09th September 2021                                    
 *  The main                  
 *********************************************************************************************************/
#include <stdio.h>
#include "map.h"
#include "array.h"
#include "control.h"

/*********************************************************
 * Name   : main                           
 * Import : accept arguments                                 
 * Export : None.
 * Purpose:  to call in the methods created.               
 *********************************************************************************************************/

int main(int argc, char* argv[])
{
  

  /* to check if the user HAS given a level to play the game */

  if( argc != 2)
  {
    printf(" Sorry ! please give in the necessary level to be played. \n "); /* a message to the user if he/ she not entered the level */
  }else 
  {
    #ifdef DARK  
   
    int level = 0;
    level = atoi(argv[1]); /* cast the level that is given by the user to an integer since it is a String */

    if( level < 0) /* check if the user has entered a valid level */
    {
      printf(" Sorry ! please enter a valid level . \n "); /* a message to the user if not */
    }else 
    {
        controlPawn(level); /* calling the controlPawn method if all cases are satisfied */
    }
   
    
  #endif  
  }
  return 0;
}

/* with the use of -Wall -std=c89 there are no warnings showing , but sir , with the use of -Wall -ansi -pedantic there are
warnings saying  c90 forbids mixed declartion. Hope it isnt an issue because we are using c89 . I did not add -Wall -std=c89 as
the CFLAGS in makefile because we were encouraged to use -Wall -ansi -pedantic . Thanks */

/* Use DARK=1 when compiling */