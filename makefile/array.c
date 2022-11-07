/*********************************************************
 * Author: Vishmi Kalansooriya                               
 * Date:  09th September  2021                                    
 * Purpose: To create the map by creating a 2Darray using the metadata provided.                   
 *********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "array.h"

/*********************************************************
 * Name   : createMap                             
 * Import : rowIndex (int pointer), colIndex(int pointer), mapRows (int pointer), mapCols (int pointer),
 *  winRow (int pointer), winCol (int pointer).                                 
 * Export : thisArray ( char 2D array).
 * Purpose:  to create the  game map using the metadata and storing them in a char 2D array .                
 *********************************************************************************************************/

char*** createMap(int* rowIndex,int* colIndex,int* mapRows,int* mapCols,int* winRow, int* winCol)
{
    /* Initializing the number of rows , coloumns , amount of obstacles, and the 2D array */
    int r =0;
    int c = 0;
    int rows = 0;
    int cols = 0;
    int ref = 0;
    int* pointerOne;
    pointerOne = &ref;        
    int** pointerTwo;
    pointerTwo = &pointerOne;
    int amount = 0;


    /* calling in the getMetaData function to get the number of rows coloumns and the positions of the pieces) */

    getMetadata(&pointerTwo,&amount,&rows,&cols);

    /* manually allocating space for the 2D array */

    char*** thisArray = (char***)malloc(sizeof(char**)*rows); /* the rows */

    for(r = 0; r < rows; r++)
    {
        thisArray[r] = (char**)malloc(sizeof(char*)*cols); /* The columns */
 
    }

/* Filling the 2D array with empty spaces */
     for(r = 0; r < rows; r ++)
    {
        for( c = 0; c < cols; c ++)
        {
            thisArray[r][c] = " ";
        }
       
    }
/* inserting # in the coners of the 2D array */
    thisArray[0][0] = "#";
    thisArray[rows-1][0] = "#";
    thisArray[0][cols-1] = "#";
    thisArray[rows-1][cols -1] = "#";

/* setting up the boundry boarders with " = " vertically ang "|" horizontally" */
    for( c = 1; c < cols-1; c++)
    {
        thisArray[0][c] = "=";
    }
     for( r = 1; r < rows -1; r++)
    {
        thisArray[r][0] = "|";
    }
       for( c = 1; c < cols -1; c++)
    {
        thisArray[rows-1][c] = "=";
    }
       for( r = 1; r < rows -1; r++)
    {
        thisArray[r][cols-1] = "|";
    }

    /* initializing the viriables that are to be stored with the index values of the playing piece, 
    the win charachter and the boundaries */
    int indexRow = 0;
    int indexCol = 0;
    int pawnRow = 0;
    int pawnCol  = 0;
    int indexWinRow = 0;
    int indexWinCol = 0;

    /* since it is said to always assume that the player is in the first row */

    pawnRow= pointerTwo[0][0];  /* declaring the coloumn and row of the playing piece */
    pawnCol = pointerTwo[0][1];
  /*  thisArray[indexRow][indexCol] = "^"; */

   /* since it is said to always assume that the win charachter is in the second row */
    
    indexWinRow = pointerTwo[1][0];  /* declaring the coloumn and row of the win Charachter */
    indexWinCol = pointerTwo[1][1];
   /* thisArray[indexRow][indexCol] = "X"; */

   /* placing the obstacles in the map */
    
    for(r = 2; r < amount ; r++)
    {
        if((pointerTwo[r][2] = 2))
       {
           indexRow = pointerTwo[r][0];
           indexCol = pointerTwo[r][1];
           thisArray[indexRow][indexCol] = "0";
           

       }
    } 

    /* to pass on the values */

    *mapRows = rows;
    *mapCols = cols;
    *rowIndex = pawnRow;
    *colIndex = pawnCol;
    *winRow = indexWinRow;
    *winCol = indexWinCol;
    

    return thisArray;  /* return the made array */ 

/* freeing the manually allocated spaces */
    for(r = 0; r < rows; r ++)
    {
        
         free(pointerTwo[r]);
        
    }
   
    free(pointerTwo);
    pointerTwo = NULL;


    

}

