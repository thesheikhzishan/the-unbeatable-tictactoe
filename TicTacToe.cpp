#include<iostream>
#include<vector>
#include<windows.h>
using namespace std;
void animated_line()
{
	for (int i = 0; i < 80; i++)
	{
		cout << "-";
		Sleep(2);
	}
}
class TicTacToe
{
	
	char matrix[3][3];
	
	char first_chance;

	int computer_move;

	bool check_validity_move(int row, int column);

	pair<int, int> threat();

	pair<int, int> computer_winning();

	void move_player();

	pair<int, int> empty_plus_position();

	void move_computer();

	bool empty();

	pair<int, int> empty_position();

	pair<int, int> unoccupied_corner();

public:
	
	TicTacToe();
	
	void set_first_chance(char c)
	{
		first_chance = c;
	}

	void turn(char &chance);

	void print_board();

	bool win_status();

	bool is_full();
};

bool TicTacToe::check_validity_move(int row, int column)
{
	if (row >= 1 && row <= 3 && column >= 1 && column <= 3 && matrix[row - 1][column - 1] == ' ')
		return true;
	return false;
}
pair<int, int> TicTacToe::empty_position()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
				return make_pair(i + 1, j + 1);
	return make_pair(0, 0);
}
pair<int, int> TicTacToe::unoccupied_corner()
{
	if (matrix[0][0] == ' ')
		return make_pair(1, 1);
	else if (matrix[0][2] == ' ')
		return make_pair(1, 3);
	else if (matrix[2][0] == ' ')
		return make_pair(3, 1);
	else if (matrix[2][2] == ' ')
		return make_pair(3, 3);
	return make_pair(0, 0);
}
pair<int, int> TicTacToe::computer_winning()
{
	pair<int, int> pos;
	int count_spaces = 0, count_O = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == ' ')
			{
				count_spaces++;
				pos.first = i + 1;
				pos.second = j + 1;
			}
			else if (matrix[i][j] == 'O')
				count_O++;
		}
		if (count_spaces == 1 && count_O == 2)
			return pos;
		else
			count_spaces = count_O = 0;

	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[j][i] == ' ')
			{
				count_spaces++;
				pos.first = j + 1;
				pos.second = i + 1;
			}
			else if (matrix[j][i] == 'O')
				count_O++;
		}
		if (count_spaces == 1 && count_O == 2)
			return pos;
		count_spaces = count_O = 0;

	}

	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][i] == ' ')
		{
			count_spaces++;
			pos.first = i + 1;
			pos.second = i + 1;
		}
		if (matrix[i][i] == 'O')
			count_O++;
	}
	if (count_spaces == 1 && count_O == 2)
		return pos;
	else
		count_spaces = count_O = 0;

	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][2 - i] == ' ')
		{
			count_spaces++;
			pos.first = i + 1;
			pos.second = 3 - i;
		}
		if (matrix[i][2 - i] == 'O')
			count_O++;
	}
	if (count_spaces == 1 && count_O == 2)
		return pos;
	pos.first = 0;
	pos.second = 0;
	return pos;
}

bool TicTacToe::is_full()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
				return false;
	return true;
}

bool TicTacToe::empty()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (matrix[i][j] != ' ')
				return false;
	return true;
}

pair<int, int> TicTacToe::empty_plus_position()
{
	if (matrix[0][1] == ' ')
		return make_pair(1, 2);
	else if (matrix[1][0] == ' ')
		return make_pair(2, 1);
	else if (matrix[1][2] == ' ')
		return make_pair(2, 3);
	else if (matrix[2][1] == ' ')
		return make_pair(3, 2);
	return make_pair(0, 0);
}

void TicTacToe::move_player()
{
	int row, column;
	print_board();
	cout << "\n\n\tEnter the row and column : ";
	cin >> row >> column;
	while (1)
	{
		if (!check_validity_move(row, column))
		{
			cout << "\n\n\tInvalid Choice ! Please Enter Position Again";
			cin >> row >> column;
		}
		else
			break;
	}
	matrix[row - 1][column - 1] = 'X';

}

pair<int, int> TicTacToe::threat()
{
	pair<int, int> pos;
	int count_spaces = 0, count_X = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == ' ')
			{
				count_spaces++;
				pos.first = i + 1;
				pos.second = j + 1;
			}
			else if (matrix[i][j] == 'X')
				count_X++;
		}
		if (count_spaces == 1 && count_X == 2)
			return pos;
		count_spaces = count_X = 0;
		
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[j][i] == ' ')
			{
				count_spaces++;
				pos.first = j + 1;
				pos.second = i + 1;
			}
			else if (matrix[j][i] == 'X')
				count_X++;
		}
		if (count_spaces == 1 && count_X == 2)
			return pos;
		count_spaces = count_X = 0;
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][i] == ' ')
		{
			count_spaces++;
			pos.first = i + 1;
			pos.second = i + 1;
		}
		if (matrix[i][i] == 'X')
			count_X++;
	}
	if (count_spaces == 1 && count_X == 2)
		return pos;
	count_spaces = count_X = 0;

	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][2 - i] == ' ')
		{
			count_spaces++;
			pos.first = i + 1;
			pos.second = 3 - i;
		}
		if (matrix[i][2 - i] == 'X')
			count_X++;
	}

	if (count_spaces == 1 && count_X == 2)
		return pos;
	pos.first = 0;
	pos.second = 0;
	return pos;
}

bool TicTacToe::win_status()
{
	int count_X = 0, count_O = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'X')
				count_X++;
			else if (matrix[i][j] == 'O')
				count_O++;
		}
		if (count_X == 3 || count_O == 3)
			return true;
		count_X = count_O = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[j][i] == 'X')
				count_X++;
			else if (matrix[j][i] == 'O')
				count_O++;
		}
		if (count_X == 3 || count_O == 3)
			return true;
		count_X = count_O = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][i] == 'X')
			count_X++;
		else if (matrix[i][i] == 'O')
			count_O++;
	}
	if (count_X == 3 || count_O == 3)
		return true;
	count_X = count_O = 0;
	for (int i = 0; i < 3; i++)
	{
		if (matrix[i][2 - i] == 'X')
			count_X++;
		else if (matrix[i][2 - i] == 'O')
			count_O++;
	}
	if (count_X == 3 || count_O == 3)
		return true;
	return false;
}

void TicTacToe::print_board()
{
	cout << "\n\n\t\t     |     |     \n";
	cout << "\t\t  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << "  \n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t-----------------\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << "  \n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t-----------------\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << "  \n";
	cout << "\t\t     |     |     \n\n\n";
}

void TicTacToe::turn(char &chance)
{
	if (chance == 'X')
	{
		move_player();
		chance = 'O';
	}
	else
	{
		move_computer();
		chance = 'X';
	}
}
TicTacToe::TicTacToe()
{
	first_chance = 'O';
	computer_move = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = ' ';
}

void TicTacToe::move_computer()
{
	computer_move++;
	if (first_chance == 'O')
	{
		if (empty())
		{
			matrix[2][2] = 'O';
			return;
		}
		else
		{
			pair<int, int> lose = threat();
			pair<int, int> win = computer_winning();
			if (computer_move == 2)
			{
				if (matrix[1][1] == ' ')
				{
					if (matrix[2][1] == 'X' || matrix[0][1] == 'X')
						matrix[0][2] = 'O';
					else if (matrix[1][2] == 'X' || matrix[1][0] == 'X')
						matrix[2][0] = 'O';
					else if (matrix[0][0] == 'X' || matrix[2][0] == 'X')
						matrix[0][2] = 'O';
					else if (matrix[0][2] == 'X')
						matrix[2][0] = 'O';
				}
				else if (matrix[1][1] == 'X')
					matrix[0][0] = 'O';
			}
			else
			{
				if (win != make_pair(0, 0))
				{
					matrix[win.first - 1][win.second - 1] = 'O';
					return;
				}
				else if (lose != make_pair(0, 0))
				{
					matrix[lose.first - 1][lose.second - 1] = 'O';
					return;
				}
				else
				{
					pair<int, int> empty_cornor = unoccupied_corner();
					if (empty_cornor != make_pair(0, 0))
						matrix[empty_cornor.first - 1][empty_cornor.second - 1] = 'O';
					else
					{
						pair<int, int> pos = empty_position();
						matrix[pos.first - 1][pos.second - 1];
					}
						
				}

			}
		}
	}
	else
	{
		pair<int, int> win = computer_winning(), lose = threat();
		if (computer_move == 1)
		{
			if (matrix[1][1] == ' ')
				matrix[1][1] = 'O';
			else if (matrix[1][1] == 'X')
			{
				pair<int, int> cornor = unoccupied_corner();
				matrix[cornor.first - 1][cornor.second - 1] = 'O';
			}

		}
		else if (computer_move == 2)
		{
			if (matrix[1][1] == 'X')
			{
				if (win != make_pair(0, 0))
					matrix[win.first - 1][win.second - 1] = 'O';
				else if (lose != make_pair(0, 0))
					matrix[lose.first - 1][lose.second - 1] = 'O';
				else
				{
					pair<int, int> cornor = unoccupied_corner();
					matrix[cornor.first - 1][cornor.second - 1] = 'O';
				}
			}
			else if(matrix[1][1] == 'O')
			{
				if (win != make_pair(0, 0))
					matrix[win.first - 1][win.second - 1] = 'O';
				else if (lose != make_pair(0, 0))
					matrix[lose.first - 1][lose.second - 1] = 'O';
				else
				{
					pair<int, int> pos = empty_plus_position();
					matrix[pos.first - 1][pos.second - 1] = 'O';
				} 
			}
		}
		else
		{
			cout << win.first << win.second << endl;
			if (win != make_pair(0, 0))
				matrix[win.first - 1][win.second - 1] = 'O';
			else if (lose != make_pair(0, 0))
				matrix[lose.first - 1][lose.second - 1] = 'O';
			else
			{
				pair<int, int> pos = empty_position();
				matrix[pos.first - 1][pos.second - 1] = 'O';
			}
		}
	}
}

int main()
{
	char c, chance = 'O';
	int choice;
	do {
		system("cls");
		TicTacToe game;
		cout << "\n\n";
		cout << "\n\n\t\t\tTHE ";
		/*Sleep(150);
		cout << "ARCHIT ";
		Sleep(150);
		cout << "JAIN ";
		Sleep(150);
		cout << "PRESENTS\n\n";
		Sleep(1000);
		animated_line();
		cout << "\t\t---- THE ";*/
		Sleep(150);
		cout << "UNBEATABLE ";
		Sleep(150);
		cout << "TIC ";
		Sleep(150);
		cout << "TAC ";
		Sleep(150);
		cout << "TOE ";
		Sleep(150);
		cout << "GAME----\n";
		Sleep(150);
		animated_line();
		cout << "\n\n\tDo you want first turn (Y / N) ?: ";
		cin >> c;
		if (c == 'Y' || c == 'y')
		{
			game.set_first_chance('X');
			chance = 'X';
		}
		else
			game.set_first_chance('O');

		system("cls");

		
		while (!game.is_full() && !game.win_status())
		{
			system("cls"); // for unbuntu or make replace cls with clear
			game.turn(chance);
		}
		system("cls");
		game.print_board();
		if (!game.win_status())
			cout << "\n\n\tDRAW\n";
		else
			cout << "\n\n\tCOMPUTER WINS !!!\n";

		cout << "\n\n\t WANNA TRY AGAIN (1 / 0) : ";
		cin >> choice;
	
	} while (choice != 'N' && choice == 'n');
	
}