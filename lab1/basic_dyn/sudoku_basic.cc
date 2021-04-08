#include <assert.h>
#include <stdio.h>

#include <algorithm>

#include "sudoku.h"

//int board[N];//���̣�һά����ֵ��ʾ���������
//int spaces[N];//����Ŀո�ֵ��ʾ�������е��±�
//int nspaces;// ����������Ŀո�����
//int (*chess)[COL] = (int (*)[COL])board;//��ʾ���̵Ķ�ά���� 

static int find_spaces(int board[N],int spaces[N])//��ǿո� ��spaces[x]==1����chess[x/9][x%9]Ϊ�ո� 
{
  int nspaces = 0;
  for (int cell = 0; cell < N; ++cell) {
    if (board[cell] == 0)
      spaces[nspaces++] = cell;
  }
  return nspaces;
}

int input(const char in[N],int board[N],int spaces[N])//����������ַ��� תΪһά���� �е����� 
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

bool solve_sudoku_basic(int which_space,int nspaces,int board[N],int spaces[N])//���which_space���ո� 
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
