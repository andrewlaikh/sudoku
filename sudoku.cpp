#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << '\n';
  assert(in);

  char buffer[512];

  int row = 0;
  //basically is a function to read file in.
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    //increase row after 9 chars have been read in
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << '\n';
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << '\n';
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << '\n';
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++)
    cout << (char) ('1'+r) << "   ";
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */
bool is_complete(const char board[9][9]){
  for (int column = 0; column < 9; column++)
  {
    for (int row = 0; row < 9; row++)
    {
      if (static_cast<int>(board[column][row]) <48 || static_cast<int>(board[column][row]) >57)
      {
        return false;
      }
    }
  }
  return true;
}

/*Question 2 function*/
bool make_move(const char position[], const char digit, const char board[9][9])
{
  int columnPosition = (static_cast<int>((position[0]))-65);
  int rowPosition = (static_cast<int>(position[1])-49);
  if ((rowPosition < 0 || rowPosition > 8) || (columnPosition < 0 ||   columnPosition > 8))
  {
    return false;
  }
  int entry = (static_cast<int>(digit)-48);
  //checks column to see if there is a repeat number
  for (int columnCheck = 0; columnCheck < 9; columnCheck++)
  {
      if (columnCheck == columnPosition)
      {
        continue;
      }
      if ((static_cast<int>(board[columnCheck][rowPosition])-48)==entry)
      {
        return false;
      }
  }
  //checks row to see if there is a repeat number
  for (int rowCheck = 0; rowCheck < 9 && (rowCheck !=rowPosition); rowCheck++)
  {
      if (rowCheck == columnPosition)
      {
        continue;
      }
      if ((static_cast<int>(board[columnPosition][rowCheck])-48)==entry)
      {
        return false;
      }
  }
  //check square for overlap
  for (int cBorderMin = ((columnPosition/3)*3); cBorderMin < (cBorderMin +2); cBorderMin++)
  {
    for (int rBorderMin = ((rowPosition/3)*3); rBorderMin < (rBorderMin +2); rBorderMin++)
    {
      if ((rBorderMin == rowPosition) && (cBorderMin==columnPosition))
      {
        continue;
      }
      if (entry == board[cBorderMin][rBorderMin])
      {
        return false;
      }
    }
  }

  return true;
}

/*Question 3 function*/

//http://www.cplusplus.com/doc/tutorial/files/ crediting source for writing output

bool save_board(const char* filename, char board[9][9])
{
  ofstream out_stream;
  out_stream.open(filename);
  for (int column =0; column < 9; column++)
  {
    for (int row = 0; row < 9; row++)
    {
      char temp;
      temp = board[column][row];
      out_stream.put(temp);
    }
    out_stream.put('\n');
  }
  out_stream.close();
  //check if this is the right place to put close
  if (out_stream.fail())
  {
    return false;
  }
  return true;
}

/*Question 4 function*/
//fidelis: go iterative then recursive.

bool solve_board(char board[9][9])
{
  while(!is_complete(board))
  {
    for (int column = 0; column < 9; column++)
    {
      for (int row = 0; row < 9; row++)
      {
        int unCompletedBlank = static_cast<int>(board[column][row]);
        if (unCompletedBlank < 48)
        {
              char currentPosition[3];
              currentPosition[0] = static_cast<char>(column+65);
              currentPosition[1] = static_cast<char>(row+49);
              currentPosition[2] = '\0';
              for (int guess = 1; guess <= 10; guess++)
              {
                if (make_move1(currentPosition, static_cast<char>(guess+48),board)==true)
                {
                  board[column][row] = static_cast<char>(guess+48);
                  //test iteratively and validate line by line. recursive solution is not v far.
                  return solve_board(board);
                }
                if (guess==10 && column==0 && row ==0)
                {

                  return false;
                }
              }
           }
        }
      }
    }
  return true;
}


bool make_move1(const char position[], const char digit,const char board[9][9])
{
  int columnPosition = (static_cast<int>((position[0]))-65);
  int rowPosition = (static_cast<int>(position[1])-49);
  int entry = (static_cast<int>(digit)-48);
  //checks column to see if there is a repeat number
  for (int columnCheck = 0; columnCheck < 9; columnCheck++)
  {
      if (columnCheck == columnPosition)
      {
        continue;
      }
      if ((static_cast<int>(board[columnCheck][rowPosition])-48)==entry)
      {
        return false;
      }
  }
  //checks row to see if there is a repeat number
  for (int rowCheck = 0; rowCheck < 9; rowCheck++)
  {
      if (rowCheck == rowPosition)
      {
        continue;
      }
      if ((static_cast<int>(board[columnPosition][rowCheck])-48)==entry)
      {
        return false;
      }
  }
  //check square to see for overlap
  for (int cBorderMin = ((columnPosition/3)*3); cBorderMin < (cBorderMin +2); cBorderMin++)
  {
    for (int rBorderMin = ((rowPosition/3)*3); rBorderMin < (rBorderMin +2); rBorderMin++)
    {
      if ((rBorderMin == rowPosition) && (cBorderMin==columnPosition))
      {
        continue;
      }
      if (entry == board[cBorderMin][rBorderMin])
      {
        return false;
      }
    }
  }

  return true;
}

/* solve board problem
bool solve_board(char board[9][9])
{
  while(!is_complete(board))
  {
    for (int column = 0; column < 9; column++)
    {
      for (int row = 0; row < 9; row++)
      {
        int unCompletedBlank = static_cast<int>(board[column][row]);
        if (unCompletedBlank < 48)
        {
              char currentPosition[3];
              currentPosition[0] = static_cast<char>(column+65);
              currentPosition[1] = static_cast<char>(row+49);
              currentPosition[2] = '\0';
              for (int guess = 1; guess <= 10; guess++)
              {
                if (make_move1(currentPosition, static_cast<char>(guess+48),board)==true)
                {
                  board[column][row] = static_cast<char>(guess+48);
                  return solve_board(board);
                }
                if (guess==10)
                {
                  return false;
                }
              }
           }
        }
      }
    }
  return true;
}
*/
