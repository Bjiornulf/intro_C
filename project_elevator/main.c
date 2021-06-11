#include <time.h>
#include <stdlib.h>
#include <curses.h>

#include "elevator.h"
#include "person.h"

#define HEIGHT 30
#define WIDTH 40
#define PERSON_WIDTH 3

/*
	Controls :
		- q to quit
		- [1 ... 9] to go to the said floor
	
	Gameplay :
		persons enter and exit the elevator according to the floor. You
		control the elevator. You have to make sure they all
		get to their desired floor
*/

void DisplayInfo(WINDOW *win) {
	int title_length = 18;
	int title_start  = (WIDTH - 2) / 2 - title_length / 2;
	box(win, 0, 0);
	mvwprintw(win, 1, title_start, "Elevator simulator");
	mvwprintw(win, 3, 1, "Controls :");
	mvwprintw(win, 4, 5, "- q to quit");
	mvwprintw(win, 5, 5, "- [1 ... 9] to change floor");
	mvwprintw(win, 6, 5, "- h to get to this screen");
	mvwprintw(win, 15, 1, "Press any key to continue");
	char c = wgetch(win);
	while ((c = wgetch(win)) == ERR) {
		;
	}
}

void DisplayPersonList(WINDOW *win, PersonList *list, int level, int offset)
{
	while(list != NULL) {
		// display 25 for a person going from floor 2 to floor 5
		mvwaddch(win, level, offset, '0' + list->person->src);
		mvwaddch(win, level, offset+1, '0' + list->person->dest);
		list = list->next;
		offset+= PERSON_WIDTH;
	}
}

void DisplayElevator(WINDOW *win, int nbFloor, Elevator *e, int offset) {
	//Display elevator
	// [23 24 31 30 42]
	int level = 3*(nbFloor - e->currentFloor); // 3 lines per level
	mvwaddch(win, level, offset+1, '[');
	DisplayPersonList(win, e->persons, level, offset+2);
	mvwaddch(win, level, offset+2+ (PERSON_WIDTH*e->capacity), ']');
}

void DisplayBuilding(WINDOW *win, Building *b) {
	int offset = 1;

	// display wall
	// |                |
	// |[23 24 31 30 42]| 31 32
	// |                |
	int right_wall = offset + 3 + (PERSON_WIDTH*b->elevator->capacity);
	for(int i=0; i < b->nbFloor; ++i) {
		int level = 3*i+1;
		mvwaddch(win,level, offset,'|');
		mvwaddch(win,level+1,offset,'|');
		mvwaddch(win,level, right_wall,'|');
		mvwaddch(win,level+1,right_wall,'|');
	}
	for(int i=offset+1; i < right_wall; i++) {
		mvwaddch(win,3*(b->nbFloor)+1,i,'_');
	}
	DisplayElevator(win, b->nbFloor, b->elevator, offset);
	for(int i=0; i < b->nbFloor; i++) {
		int level = 3*(b->nbFloor - i);
		DisplayPersonList(win,b->waitingLists[i], level, right_wall + 2);
	}
}

int main() {
	srand(time(NULL)); // should only be called once
	// generate list of waiting persons
	int nbFloor = 5;
	PersonList **waitingLists = malloc(nbFloor*sizeof(PersonList*));
	for(int currentFloor=0; currentFloor < nbFloor; currentFloor++) {
		waitingLists[currentFloor] = NULL;
		int nbPerson = 5; // 5 persons in the waiting list
		for(int j=0 ; j<nbPerson ; j++) {
			int dest = rand() % (nbFloor);
			Person *p = create_person(currentFloor, dest);
			waitingLists[currentFloor] = insert(p,waitingLists[currentFloor]);
		}
	}

	// Initialize building and elevator
	int capacity = 3;
	int currentFloor = 0;
	Elevator *elevator = create_elevator(capacity, currentFloor , NULL);
	Building *building = create_building(nbFloor, elevator, waitingLists);
	// Initialize ncurse display
	initscr(); // initialize ncurses
	noecho(); // do not display in window the pressed keys
	halfdelay(2);
	WINDOW *win = newwin(HEIGHT, WIDTH, 0, 0);
	
	// Introductory screen
	DisplayInfo(win);

	// Animation loop
	bool run=true;

	while(run) {
		// Generate people in function of input (or quit if 'q')
		int input = wgetch(win);
		if(input == 'q') {
			run = false;
		} else if (input == 'h') {
			wclear(win);
			DisplayInfo(win);
		} else {
			int level = input - '0';
			if(0 <= level && level < nbFloor) {
				building->elevator->targetFloor = level;
			}
		}
		// Update state machine of elevator !!!!
		step_elevator(building);
		wclear(win); // clear display area
		box(win, 0,0); // display border of window
		DisplayBuilding(win, building);
		wrefresh(win); // actual display function
	}
	endwin(); // correct ending of ncurses
	return 0;
}
