/*
Matthew Chan					    PIC 10B Intermediate Programming
ID: 604178275          		  		Winter 2015
Email: matthew.a.chan@gmail.com		Assignment #8
Section: 2B
Honesty Pledge:

I, Matthew Chan, pledge that this is my own independent
work,which conforms to the guidelines of academic honesty as
described in the course syllabus.

List of known bugs: None.
*/

#include "Arrival.h"
#include "Departure.h"
#include <iostream>
#include <iomanip>


Arrival::Arrival(Customer* c, Simulation* s, double time, string description) : Event(time, description) {
	this->c = c;
	this->s = s;
}


void Arrival::act() {
	// If there is an open seat, the customer takes the seat
	if (s->seat.size() < 3) {
		s->seat.push_back(c);
		cout << fixed << setprecision(2) << "time: " << get_time() << " Customer is seated." << endl;
		// Adds a random number of hot dog orders to our map
		s->hot_dog_orders[get_time()] = (rand() % 4) + 1;
		// Adds a departure event to our queue
		Event* seated = new Departure(c, s, get_time_later(), "Customer finishes eating, leaves.");
		s->event_queue.push(seated);
	}
	// Customer arrives and waits for some random period of time, then leaves.
	else {
		Event* not_seated = new Departure(c, s, get_time_later(), "Customer unable to find a seat, leaves.");
		s->event_queue.push(not_seated);
	}
}