/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>

#include "battleship.h"

CellContent my_CellContent[10][10];
CellContent op_CellContent[10][10];
CellContent my_guess_CellContent[10][10];


void load_game()
{
  FILE* fd_my = fopen("battleship.my", "r");
  FILE* fd_op = fopen("battleship.op", "r");

  for (int i = 0; i < 10; i++) {
    for (int k = 0; k < 10; k++) {
      fread(my_CellContent,sizeof(CellContent), 100,fd_my);
      fread(op_CellContent,sizeof(CellContent), 100,fd_op);
      my_guess_CellContent[i][k] = Unknown;
    }
  }
}

CellContent get_shot(int row, int col)
{
  if (row >= 10 || col >= 10 || row < 0 || col < 0) {
    return OutOfRange;
  }
  return my_CellContent[row][col];
}

bool shoot(int row, int col)
{
  if (row >= 10 || col >= 10 || row < 0 || col < 0) {
    return false;
  }

  my_guess_CellContent[row][col]=op_CellContent[row][col];
  my_guess_CellContent[row-1][col-1]=Water;
  my_guess_CellContent[row][col-1]=Water;
  my_guess_CellContent[row-1][col]=Water;
  my_guess_CellContent[row+1][col+1]=Water;
  my_guess_CellContent[row+1][col]=Water;
  my_guess_CellContent[row][col+1]=Water;
  my_guess_CellContent[row-1][col+1]=Water;
  my_guess_CellContent[row+1][col-1]=Water;

  return true;
}

CellContent get_my_guess(int row, int col)
{
  if (row >= 10 || col >= 10 || row < 0 || col < 0) {
    return OutOfRange;
  }
  return my_guess_CellContent[row][col];
}
