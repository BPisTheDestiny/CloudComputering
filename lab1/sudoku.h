#ifndef SUDOKU_H
#define SUDOKU_H

const bool DEBUG_MODE = false;//是否输出中间结果（调试信息） 
enum { ROW=9, COL=9, N = 81, NEIGHBOR = 20 };//行数 列数 方格数 一个方格周围20个相邻的方格（列、行、宫）
const int NUM = 9;//填数字1~9


extern int neighbors[N][NEIGHBOR];//neighbors[i][j]表示第i个方格的第j个邻居的下标
//extern int board[N];//棋盘（一维），值表示所填的数字
//extern int spaces[N];//待填的空格，值表示在棋盘中的下标
//extern int nspaces; // 棋盘上最初的空格总数
//extern int (*chess)[COL];//表示棋盘的二维数组 

/*********************************/
const int num_of_puzzle = 1e7+5;
extern char puzzle[num_of_puzzle][128];
extern char solution[num_of_puzzle][N+1];

extern int board[num_of_puzzle][N];
/********************************/


void init_neighbors();
int input(const char in[N],int board[N],int spaces[N]);
void init_cache();

bool available(int guess, int cell,int board[N]);

bool solve_sudoku_basic(int which_space,int nspaces, int board[N],int spaces[N]);
bool solve_sudoku_min_arity(int which_space);
bool solve_sudoku_min_arity_cache(int which_space);
bool solve_sudoku_dancing_links(int unused,int board[N]);
bool solved(int board[N]);
#endif
