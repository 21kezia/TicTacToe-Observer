#include <string>
#include <list>
#include "subject.h"
#include <iostream>

using namespace std;

Subject::Subject()
{
	board = Board();
}

Subject::~Subject()
{
}

void Subject::add_observer(Observer& _observer)
{
	observers.push_back(&_observer);
}

void Subject::clear_observers()
{
	observers.clear();
}

void Subject::notify()
{
	for (iterator it = observers.begin(); it != observers.end(); it++)
	{
		(*it)->update();
	}
}

string * Subject::get_board()
{
	return board.get_board();
}

string Subject::get_winner()
{
	return board.win_detection();
}

void Subject::set_players(int players)
{
	board.set_players(players);
}

Board Subject::get_board_object()
{
	return board;
}

bool Subject::gameloop()
{
	print_header();

	handle_input();
	board.switch_turn();

	system("cls");

	return (!board.is_winner() && !board.is_tie());
}

void Subject::print_header()
{
	cout << string(2, '\n');
	cout << R"( tic tac toe )" << endl;

	cout << R"( made for hw )" << endl;
	cout << string(3, '\n');
}

void Subject::handle_input()
{
	bool incorrect = true;
	string place;

	cout << endl << "Player " << board.get_turn() << " Where would you like to put your mark? " << endl;

	while (incorrect) {
		cin >> place;

		place[0] = toupper(place[0]);
		string input = place;

		incorrect = !board.input_correct(place);

		if (incorrect)
			cout << input << " - is not a valid location" << endl;
	}
	board.changefield(place);
}
