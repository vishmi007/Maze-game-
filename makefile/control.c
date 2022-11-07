/* *****************************************************************************************************
 * Author: Vishmi Kalansooriya                               
 * Date:  09th September 2021                                    
 * Purpose: To implement a program to control the game.                   
 *********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "control.h"
#include <string.h>
#include "terminal.h"
/*********************************************************
 * Name   : controlPawn                           
 * Import : level (int)                                
 * Export : None
 * Purpose:  to let the piece move according to the user input.                
 *********************************************************************************************************/


void controlPawn(int level)
{

    int cols = 0;
    int rows = 0;
    int pawnRowIndex = 0 ;
    int pawnColIndex = 0;
    int winRow = 0;
    int winCol = 0;
    char move; /* to store the user input and act accordingly */

     /* calling the createmap method to get the created 2D array , piece's intial position , win piece position,
     the number of rows and column of the array */

     
    char*** map = createMap(&pawnRowIndex,&pawnColIndex,&rows,&cols,&winRow,&winCol);

  /* setting the pawn piece at the initial position ( The place where it should be when the game starts) */
    map[pawnRowIndex][pawnColIndex] = "^";
   /* setting the pawn piece at the initial position ( The place where it should be when the game starts) */   
     map[winRow][winCol] = "X";

     /* clearing the screen before displaying the map ( 2D array ) */
    system("clear"); 
     /* calling the display map method to display the 2D array while passing the level ( 0, 1, 2 ,3) entered 
      as arguments by the user */
     displayMap(map,&rows,&cols,level);
     
      


     int r,c;
     for( r = 0; r < rows; r++)
     {
     
         for( c = 0; c < cols; c++)
         {
              /* to move the pawn until it meets the win piece ( X) */
             while(strcmp(map[winRow][winCol],"X") == 0)
             {
                  /* calling the disable buffer method to not let the user press enter */

                 disableBuffer();
                /* taking the user input */
                 scanf("%c",&move);
                 
                /* To perform actions according to the user input */ 
                 switch(move)
                 {
                     case 'w' :
                        system("clear"); /* clear the screen before displaying the map again with the changes done
                        according to the user input */
                        if(strcmp(map[pawnRowIndex-1][pawnColIndex]," ") == 0) /* check whether the pawn can be moved front */
                        {
                            /* set the pawn to the initial row position - 1 position */
                             map[pawnRowIndex-1][pawnColIndex] = "^";
                             map[pawnRowIndex][pawnColIndex] = " "; /* make the initial position that the pawn was into empty space*/
                             pawnRowIndex = pawnRowIndex -1;   /* now set the moved position as the initial positin */
                             displayMap(map,&rows,&cols,level); /* display the map with the changes */
                           


                        }else if(strcmp(map[pawnRowIndex-1][pawnColIndex],"X") == 0) /* if the position that the pawn isto be moved is
                        where the win charachter (X) is */ 
                        { 
                             map[pawnRowIndex-1][pawnColIndex] = "^"; /* move the pawn */
                             printf(" You win ! \n "); /* Display the fancy message */
                            
                        }else
                        {
                             /* if the move that is requested to be done by the user has an obstacle or a boarder just print the 
                             map as it is */
                             displayMap(map,&rows,&cols,level);

                        }
                        break;
                        
                        case 's' :
                        system("clear");
                       if(strcmp(map[pawnRowIndex+1][pawnColIndex]," ") == 0)
                       {
                             map[pawnRowIndex+1][pawnColIndex] = "v";
                             map[pawnRowIndex][pawnColIndex] = " ";
                             pawnRowIndex = pawnRowIndex +1;
                             displayMap(map,&rows,&cols,level);
                        }else if(strcmp(map[pawnRowIndex +1][pawnColIndex],"X") == 0)
                        { 
                             map[pawnRowIndex +1][pawnColIndex] = "^";
                             printf(" You win ! \n ");    
                        
                       }else
                       {
                           displayMap(map,&rows,&cols,level);
                       }
                       break;
                      
                        
                    case 'a' :
                         system("clear");
                         if(strcmp(map[pawnRowIndex][pawnColIndex-1]," ") == 0)
                         {
                              map[pawnRowIndex][pawnColIndex-1] = "<";
                              map[pawnRowIndex][pawnColIndex] = " ";
                              displayMap(map,&rows,&cols,level);
                              pawnColIndex = pawnColIndex-1;
                              break;
                         }else if(strcmp(map[pawnRowIndex][pawnColIndex-1],"X") == 0)
                        { 
                             map[pawnRowIndex][pawnColIndex -1] = "^";
                             printf(" You win ! \n");

                         }else
                         {
                              displayMap(map,&rows,&cols,level);
                         }
                         break;
                        
                         

                    case 'd':
                         system("clear");
                         if(strcmp(map[pawnRowIndex][pawnColIndex+1]," ") == 0)
                         {
                               map[pawnRowIndex][pawnColIndex+1] = ">";
                               map[pawnRowIndex][pawnColIndex] = " ";
                               pawnColIndex = pawnColIndex+1;
                               displayMap(map,&rows,&cols,level);
                         }else if(strcmp(map[pawnRowIndex][pawnColIndex +1],"X") == 0)
                        { 
                             map[pawnRowIndex-1][pawnColIndex +1] = "^";
                             printf(" You win ! \n ");

                         }else
                         {
                              displayMap(map,&rows,&cols,level);
                         }
                         break;
                        
                    }
             }
    } 

    }
    /* freeing the manually allocated spaces */
     for(r = 0; r < rows; r ++)
    {
       free(map[r]);
    }
   
    free(map);
    map = NULL;



    enableBuffer();

    
}
/*********************************************************
 * Name   : displayMap                            
 * Import : displayMap( char 2D array), rows ( integer pointer), cols (integer pointer), plevel ( integer)                              
 * Export : None
 * Purpose:  to display the map ( 2D array).               
 *********************************************************************************************************/

void displayMap(char*** displayMap,int* rows, int* cols,int plevel)
{
    int r = 0;
    int c = 0;
    int i = 0;
    int j = 0 ;
   

    
    for(r = 0; r < *rows; r++)
    {
        for(c = 0; c < *cols; c++)
        { 
            if(plevel != 0) /* check if the level entered by the user is 0 to display the whole map */
            {
                 if((strcmp(displayMap[r][c],"^") == 0) || (strcmp(displayMap[r][c],"<")== 0) || 
                 (strcmp(displayMap[r][c],"v")== 0) || (strcmp(displayMap[r][c],">") == 0))
                {
                     
                        for(i = r - plevel; i <= (r + plevel); i++) /* to display according to the neccesay level */
                        {
                             for(j = c - plevel; j <= (c + plevel); j++)
                                {
                                   /* print only the characters inside the bound ( To not let this go out of bound) */
                                   if(( (i >= 0) && (i <= (*rows - 1)) && (j >= 0) && ( j <= (*cols -1))) )
                                    {
                                        printf("%s",displayMap[i][j]);

                                    }
                                }
                           printf("\n");
                        }
                   

                }

            }else 
            printf("%s",displayMap[r][c]); /* print the whole map if it is 0 */
        }
        printf("\n");
    }
    
}

