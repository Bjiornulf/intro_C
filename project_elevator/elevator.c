#include <stdlib.h>
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
	Elevator *elevator = (Elevator *) malloc(sizeof(Elevator));
	elevator->capacity = capacity;
	elevator->currentFloor = currentFloor;
	elevator->targetFloor = 0;
	elevator->persons = persons;

	return elevator;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
	Building *building = (Building *) malloc(sizeof(Building));
	building->nbFloor = nbFloor;
	building->elevator = elevator;
	building->waitingLists = waitingLists;

	return building;
}

PersonList *exit_elevator(Elevator *e)
{
	PersonList *personList = NULL;
	PersonList *current = e->persons;
	PersonList *staying = NULL;
	PersonList *temp = NULL;
	while (current != NULL) {
		if (current->person->dest == e->currentFloor) {
			// the person must exit.
			// moving her from the list of the elevator to return list
			temp = current->next;
			current->next = personList;
			personList = current;
			current = temp;
		} else {
			temp = current->next;
			current->next = staying;
			staying = current;
			current = temp;
		}
	}
	e->persons = reverse_list(staying);	// to avoid flicker
	return personList;
}

PersonList *enter_elevator(Elevator *e, PersonList *waitingList)
{
	PersonList *personList = NULL;
	PersonList *temp;
	int available_space = e->capacity - length_list(e->persons);
	while (waitingList != NULL && available_space > 0) {
		available_space--;
		temp = waitingList->next;
		waitingList->next = e->persons;
		e->persons = waitingList;
		waitingList = temp;
	}
	return waitingList;
}

void step_elevator(Building *b)
{
	if (b->elevator->currentFloor == b->elevator->targetFloor) {
		free_list(exit_elevator(b->elevator));
		(b->waitingLists)[b->elevator->currentFloor] = enter_elevator(b->elevator, (b->waitingLists)[b->elevator->currentFloor]);
	} else if (b->elevator->currentFloor < b->elevator->targetFloor) {
		b->elevator->currentFloor++;
	} else {
		b->elevator->currentFloor--;
	}
}
