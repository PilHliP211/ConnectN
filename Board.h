#pragma once
#include <memory>
#include <vector>
#include <string>

using namespace std;
class Board
{
public:
	//Constructors
	Board();
	Board(int n);
	~Board();

	//Types
	enum class piece { X, O, empty };

	//Functions
	int DropPiece(int col);
	void Show();
	bool IsGameOver();
	void Clear();

	//Accessors
	vector<vector<piece>>* GetPieces() { return pieces; }

	//Testers
	bool static TestBoard();
private:
	//Members
	int N;
	bool gameOver;
	vector<vector<piece>>* pieces;

	//Helpers
	vector<vector<piece>>* initBoard();
	vector<piece>* initColumn();
	char getPiece(piece p);
	string getRowDiv(int n);

	//Testing utilities

};

