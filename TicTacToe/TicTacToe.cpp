#include <iostream>
using namespace std;
class TicTacToe {
	
public:
	char grid[7][7];
	void createGrid() {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				if (i % 2 == 0)
					grid[i][j] = '-';
				else
				{
					if (j % 2 != 0)
						grid[i][j] = ' ';
					else
						grid[i][j] = '|';
				}
			}
		}
		printGrid();
	}
	void printGrid() {
		for (int row = 0; row < 7; row++) {
			for (int col = 0; col < 7; col++) {
				cout << grid[row][col];
			}
			cout << endl;
		}
	}
	void makeMove(int place,char player) {
		
		switch (place)
		{
		case 7:if (grid[1][1] == ' ') grid[1][1] = player; else cout << "Can't move there!" << endl; break;
		case 8:if (grid[1][3] == ' ') grid[1][3] = player; else cout << "Can't move there!" << endl; break;
		case 9:if (grid[1][5] == ' ') grid[1][5] = player; else cout << "Can't move there!" << endl; break;
		case 4:if (grid[3][1] == ' ') grid[3][1] = player; else cout << "Can't move there!" << endl; break;
		case 5:if (grid[3][3] == ' ') grid[3][3] = player; else cout << "Can't move there!" << endl; break;
		case 6:if (grid[3][5] == ' ') grid[3][5] = player; else cout << "Can't move there!" << endl; break;
		case 1:if (grid[5][1] == ' ') grid[5][1] = player; else cout << "Can't move there!" << endl; break;
		case 2:if (grid[5][3] == ' ') grid[5][3] = player; else cout << "Can't move there!" << endl; break;
		case 3:if (grid[5][5] == ' ') grid[5][5] = player; else cout << "Can't move there!" << endl; break;
		}
	}
	bool isWin() {
		bool row1 = (grid[1][1] == grid[1][3] && grid[1][3] == grid[1][5]) && grid[1][1] != ' ' ? true : false;
		bool row2 = (grid[3][1] == grid[3][3] && grid[3][3] == grid[3][5]) && grid[3][1] != ' ' ? true : false;
		bool row3 = (grid[5][1] == grid[5][3] && grid[5][3] == grid[5][5]) && grid[5][1] != ' ' ? true : false;
		bool rowWin = row1 || row2 || row3;
		bool col1 = (grid[1][1] == grid[3][1] && grid[3][1] == grid[5][1]) && grid[1][1] != ' ' ? true : false;
		bool col2 = (grid[1][3] == grid[3][3] && grid[3][3] == grid[5][3]) && grid[1][3] != ' ' ? true : false;
		bool col3 = (grid[1][5] == grid[3][5] && grid[5][5] == grid[5][5]) && grid[1][5] != ' ' ? true : false;
		bool colWin = col1 || col2 || col3;
		bool diag1 = (grid[1][1] == grid[3][3] && grid[3][3] == grid[5][5]) && grid[1][1] != ' ' ? true : false;
		bool diag2 = (grid[1][5] == grid[3][3] && grid[3][3] == grid[5][1]) && grid[1][5] != ' ' ? true : false;
		bool diagWin = diag1 || diag2;
		bool win = rowWin || colWin || diagWin;
		return win;
	}
};




int main()
{
	TicTacToe game = TicTacToe();
	char x = 'X';
	char o = 'O';
	int move, change=0;
	cout << "Welcome to Tic-Tac-Toe!\nX moves first,\nO move next.\nYou can make moves\nby pressing the numbers\nlike this:\n-------\n|7|8|9|\n-------\n|4|5|6|\n-------\n|1|2|3|\n-------\nGood luck!"<<endl;
	game.createGrid();

	while (!game.isWin())
	{
		if (change == 0) {
			cout << "X move" << endl;
			cin >> move;
			game.makeMove(move, x);
			system("cls");
			game.printGrid();
			change = 1;
		}
		else
		{
			cout << "O move" << endl;
			cin >> move;
			game.makeMove(move, o);
			system("cls");
			game.printGrid();
			change = 0;
		}
		
	}
	


	return 0;
}