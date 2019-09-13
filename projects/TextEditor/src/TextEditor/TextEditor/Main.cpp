
#define PDC_DLL_BUILD 1
#include <fstream>
#include "curses.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	//ifstream input;
	//if (input.is_open() == true) {

	
	//}
	
	
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	

	// Main terminal
	WINDOW* win = stdscr; 
	
	// Terminal dimensions
	int term_rows = getmaxy(win);
	int term_cols = getmaxx(win);
	
	// Main window dimensions
	
	int mHeight = term_rows - 6;
	int mWidth = term_cols - 3;
	int mStart_y = 3;
	int mStart_x = 0;
	
	// Top window dimensions
	int tHeight = 3;
	int tWidth = term_cols;
	int tStart_y = 0;
	int tStart_x = 0;

	// Bottom window dimensions
	int bHeight = 3;
	int bWidth = term_cols;
	int bStart_y = term_rows-3;
	int bStart_x = 0;

	// Right side window dimensions

	int rsHeight = term_rows -4;
	int rsWidth = 3;
	int rsStart_y = 2;
	int rsStart_x = term_cols-3;

	// Window creations
	WINDOW* mWin = newwin(mHeight, mWidth, mStart_y, mStart_x);
	WINDOW* topWin = newwin(tHeight, tWidth, tStart_y, tStart_x); // Top window
	WINDOW* botWin = newwin(bHeight, bWidth, bStart_y, bStart_x); // Bottom window
	WINDOW* rsWin = newwin(rsHeight, rsWidth, rsStart_y, rsStart_x); // Right side window
	

	refresh();

	// Creates box for each window
	box(topWin, 0, 0); 
	box(botWin, 0, 0);
	box(rsWin, 0, 0);
	

	// Printing border text
	//mvwprintw(win, 10, 10,"yesh");
	mvwprintw(topWin, 1, term_cols / 2 - 14, "File	Edit	Save");
	mvwprintw(botWin, 1, term_cols / 2 - 5, "Word Count:");
	
	

	// Refreshing windows
	wrefresh(topWin);
	wrefresh(botWin);
	wrefresh(rsWin);

	
	int key_x_pos = 1; // Position of writing
	int key_y_pos = 1; // Position of writing
	
	int ch;
	ch = getch();

	// Writes user input to screen
	while (ch != KEY_F(8)) {
		
		// Checks if enter has been pressed and starts new line
		if (ch == 10) {
			key_y_pos += 1;
			key_x_pos = 1;
		
		}

		// Checks if line has reached edge of terminal and starts a new line
		if (key_x_pos == term_cols - 3) {
			key_y_pos += 1;
			key_x_pos = 1;
		}

		// Prints typed char and updates for next position
		mvwprintw(mWin, key_y_pos, key_x_pos, "%c", ch);
		key_x_pos += 1;
		wrefresh(mWin);
		
		ch = getch();
	}
	
	
	
	//resize_term(term_rows, term_cols);

	//refresh();
	//wattron(win, A_REVERSE);
	//mvwprintw(win, 0, 0, "Hewwo")
	//mvwprintw(win, 0, 0, "	File	Edit	Save												"); // Prints text in the box at desired location
	//mvwprintw(win, 29, 0, "						     Word Count:			  	   		        ");
	//wattroff(win, A_REVERSE);
	//wrefresh(win); // Refreshes changes to screen from memory in the window

	
	//wrefresh(win);

	//int c = getch();

	endwin();


	return 0;

}

















	//WINDOW* main_window = nullptr;
	//int num_rows = 0;
	//int num_cols = 0;

	//// Initiialize screen, begin curses mode
	//main_window = initscr();

	//// Take up most of screen
	//getmaxyx(main_window, num_rows, num_cols);
	//resize_term(num_rows - 1, num_cols - 1);
	//getmaxyx(main_window, num_rows, num_cols);

	//// Turn off key echo
	//noecho;
	//nodelay(main_window, TRUE);
	//keypad(main_window, TRUE);
	//curs_set(0);

	//// FUN STUFF HAPPENS HERE
	//for (int i = 0; i < num_cols; i++) {
	//	// Top border
	//	mvaddch(0, i, 219);

	//	// Bottom border
	//	mvaddch(num_rows - 1, i, 219);
	//}
	//
	//for (int i = 0; i < num_rows; i++) {

	//	// Left column
	//	mvaddch(i, 0, 219);

	//	// RIght coloumn
	//	mvaddch(i, num_cols - 1, 219);
	//}

	//// Tells curses to draw
	//refresh();

	//// Revert back to normal console mode
	//nodelay(main_window, TRUE);
	//keypad(main_window, TRUE);
	//mvaddstr(0, 0, "Press any key to continue...");
	//char result = getch();
	//endwin();






