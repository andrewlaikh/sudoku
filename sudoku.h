void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool outOfRange(int columnPosition, int rowPosition);
bool make_move(const char position[], char digit, const char board[9][9]);
bool squareOverlap(int entry, int columnPosition, int rowPosition, const char board[9][9]);
bool columnOverlap(int entry, int columnPosition, int rowPosition, const char board[9][9]);
bool rowOverlap(int entry, int columnPosition, int rowPosition, const char board[9][9]); 
//bool save_board(const char* filename, char board[9][9]);
//bool solve_board(char board[9][9]);
//bool make_move1(const char board[9][9], const char position[], const char digit, const int previousValue, const int previousValueColumn, const int previousValueRow);
