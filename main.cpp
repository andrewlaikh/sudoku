#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============" << "\n\n";

  cout << "Calling load_board():" << '\n';
  load_board("easy.dat", board);

  cout << '\n' << "Displaying Sudoku board with display_board():" << '\n';
  display_board(board);
  cout << "Done!" << "\n\n";

  cout << "=================== Question 1 ===================" << "\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << "\n\n";

  cout << "=================== Question 2 ===================" << "\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

	// write more tests
  cout << "Putting '6' into H7 is ";
  if (!make_move("H7", '6', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '1' into Z8 is ";
  if (!make_move("Z8", '1', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '4' into I8 is ";
  if (!make_move("I8", '4', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '9' into H7 is ";
  if (!make_move("H7", '9', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '1' into A1 is ";
  if (!make_move("A1", '1', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

  cout << "Putting '5' into C4 is ";
  if (!make_move("C4", '5', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << '\n';
  display_board(board);

 cout << "=================== Question 3 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << '\n';
  else
    cout << "Save board failed." << '\n';
  cout << '\n';


  cout << "=================== Question 4 ===================" << "\n\n";

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "A solution cannot be found." << '\n';
  cout << '\n';


  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "A solution cannot be found." << '\n';
  cout << '\n';

  cout << "=================== Question 5 ===================" << "\n\n";
//1 doesn't work rn bc it starts from the first value so you need to modify that.
load_board("mystery3.dat", board);
if (solve_board(board)) {
  cout << "The 'mystery3' board has a solution:" << '\n';
  display_board(board);
} else
  cout << "A solution cannot be found." << '\n';
cout << '\n';

load_board("mystery2.dat", board);
if (solve_board(board)) {
  cout << "The 'mystery2' board has a solution:" << '\n';
  display_board(board);
} else
  cout << "A solution cannot be found." << '\n';
cout << '\n';

  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:" << '\n';
    display_board(board);
  } else
    cout << "A solution cannot be found." << '\n';
  cout << '\n';//1 doesn't work rn bc it starts from the first value so you need to modify that.



	// write more tests

  return 0;
}
