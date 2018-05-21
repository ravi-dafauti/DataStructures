/*
A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

Input is given as a 1D array of size 9.

Input: board[] =  {'X', 'X', 'O',
'O', 'O', 'X',
'X', 'O', 'X'};
Output: Valid

Input: board[] =  {'O', 'X', 'X',
'O', 'X', 'X',
'O', 'O', 'X'};
Output: Invalid
(Both X and O cannot win)

Input: board[] =  {'O', 'X', ' ',
' ', ' ', ' ',
' ', ' ', ' '};
Output: Valid
(Valid board with only two moves played)
*/

#include<iostream>
using namespace std;
int check[8][3] = {
	{0,1,2},
	{3,4,5},
	{6,7,8},
	{0,3,6},
	{1,4,7},
	{2,5,8},
	{0,4,8},
	{2,4,6}
};
bool win(char board[], char c)
{
	for (int i = 0; i < 8; i++)
	{
		if (board[check[i][0]] == c&&board[check[i][1]] == c&&board[check[i][2]] == c)
			return true;
	}
	return false;
}
bool isValid(char board[])
{
	int count_O, count_X;
	count_O = count_X = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == 'O')
			count_O++;
		if (board[i] == 'X')
			count_X++;
	}
	if (count_O == count_X || count_X  == count_O + 1)
	{
		if (win(board, 'O'))
		{
			if (win(board, 'X'))
				return false;
			if (count_O != count_X)
				return false;
		}
		if (win(board, 'X'))
		{
			if (count_O + 1!= count_X)
				return false;
		}
		return true;
	}
	return false;
}

int main()
{
	char board[] = { 'X', 'X', 'O',
		'O', 'O', 'X',
		'X', 'O', 'X' };
	(isValid(board)) ? cout << "Given board is valid" :
		cout << "Given board is not valid";
    return 0;
}

