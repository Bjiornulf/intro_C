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

PersonList *exitElevator(Elevator *e)
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
	e->persons = reverse(staying);	// to avoid flicker
	return personList;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList)
{
	PersonList *personList = NULL;
	PersonList *temp;
	int available_space = e->capacity - list_length(e->persons);
	// This function reverses the order of the waiters.
	// To avoid flicker and waste of computation power, we don't
	// explore list if no space is available
	if (available_space == 0) {
		return waitingList;
	}
	while (waitingList != NULL) {
		if (available_space > 0) {
			available_space--;
			temp = waitingList->next;
			waitingList->next = e->persons;
			e->persons = waitingList;
			waitingList = temp;
		} else {
			temp = waitingList->next;
			waitingList->next = personList;
			personList = waitingList;
			waitingList = temp;
		}
	}
	return personList;
}

void stepElevator(Building *b)
{
	if (b->elevator->currentFloor == b->elevator->targetFloor) {
		free_list(exitElevator(b->elevator));
		(b->waitingLists)[b->elevator->currentFloor] = enterElevator(b->elevator, (b->waitingLists)[b->elevator->currentFloor]);
	} else if (b->elevator->currentFloor < b->elevator->targetFloor) {
		b->elevator->currentFloor++;
	} else {
		b->elevator->currentFloor--;
	}
}
