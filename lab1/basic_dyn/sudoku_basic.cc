#include <assert.h>
#include <stdio.h>

#include <algorithm>

#include "sudoku.h"

//int board[N];//棋盘（一维），值表示所填的数字
//int spaces[N];//待填的空格，值表示在棋盘中的下标
//int nspaces;// 棋盘上最初的空格总数
//int (*chess)[COL] = (int (*)[COL])board;//表示棋盘的二维数组 

static int find_spaces(int board[N],int spaces[N])//标记空格 若spaces[x]==1，则chess[x/9][x%9]为空格 
{
  int nspaces = 0;
  for (int cell = 0; cell < N; ++cell) {
    if (board[cell] == 0)
      spaces[nspaces++] = cell;
  }
  return nspaces;
}

int input(const char in[N],int board[N],int spaces[N])//根据输入的字符串 转为一维棋盘 中的数字 
{
  for (int cell = 0; cell < N; ++cell) {
    board[cell] = in[cell] - '0';
    assert(0 <= board[cell] && board[cell] <= NUM);
  }
  return find_spaces(board,spaces);
}

bool available(int guess, int cell, int board[N])
{
  for (int i = 0; i < NEIGHBOR; ++i) {
    int neighbor = neighbors[cell][i];
    if (board[neighbor] == guess) {
      return false;
    }
  }
  return true;
}

bool solve_sudoku_basic(int which_space,int nspaces,int board[N],int spaces[N])//填第which_space个空格 
{
  if (which_space >= nspaces) {
    return true;
  }

  // find_min_arity(which_space);
  int cell = spaces[which_space];

  for (int guess = 1; guess <= NUM; ++guess) {
    if (available(guess, cell,board)) {
      // hold
      assert(board[cell] == 0);
      board[cell] = guess;

      // try
      if (solve_sudoku_basic(which_space+1,nspaces,board,spaces)) {
		return true;
      }

      // unhold
      assert(board[cell] == guess);
      board[cell] = 0;
    }
  }
  return false;
}
