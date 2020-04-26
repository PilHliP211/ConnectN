#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
	this->N = 7;
	this->gameOver = false;
	this->pieces = initBoard();
}

Board::Board(int n)
{
	this->N = n;
	this->gameOver = false;
	this->pieces = initBoard();
}

Board::~Board()
{
}

/**
Drops a piece into the board at a specified column.
Parameters:
	int col - the index of the column at which to drop a piece. Must be between 0-N
Returns:
	success code (non-zero indicates failure)
*/
int Board::DropPiece(int col)
{
	return 0;
}

/**
Displays the current board with the pieces it contains.
*/
void Board::Show()
{
	vector<vector<piece>> *pieces = GetPieces();
	for (int i = 0; i < N - 1; i++) {
		cout << getRowDiv(N) << endl;
		for (int j = 0; j < N; j++)
			cout << '|' << getPiece(pieces->at(j).at(i));
		cout << '|' << endl;
	}
	cout << getRowDiv(N) << endl;
}

/**
Indicates if this board is in a game completed state.
Returns:
	True if the game is over, false otherwise.
*/
bool Board::IsGameOver()
{
	return false;
}

/**
Clears this board by setting all its pieces to empty.
*/
void Board::Clear()
{
}

vector<vector<Board::piece>>* Board::initBoard()
{
	vector<vector<piece>> *board = new vector<vector<piece>>(N);
	for (int i = 0; i < N; i++)
		board->at(i) = *initColumn();
	return board;
}

vector<Board::piece>* Board::initColumn()
{
	vector<piece>* column = new vector<piece>(N-1);
	for (int i = 0; i < N - 1; i++)
		column->at(i) = piece::empty;
	return column;
}

char Board::getPiece(piece p)
{
	switch (p) {
	case piece::X:
		return 'x';
	case piece::O:
		return 'o';
	case piece::empty:
	default:
		return ' ';
	}
}

string Board::getRowDiv(int n)
{
	string div = "-";
	for (int i = 0; i < N; i++)
		div += "--";
	return div;
}

///Tests

bool Board::TestBoard()
{
	cout << "Beginning Board tests..." << endl;
	bool success = false;
	Board* b1 = new Board();
	Board* b2 = new Board(7);
	cout << "Board 1 init:" << endl;
	b1->Show();
	cout << "Board 2 init:" << endl;
	b2->Show();
	
	return true;
}

