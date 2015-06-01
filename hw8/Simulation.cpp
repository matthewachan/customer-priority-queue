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

#include "Simulation.h"
#include "Arrival.h"
#include <ctime>
#include <iostream>

Simulation::Simulation() {
	// Seed the random number function
	srand(time(0));
	// Adds a random number of arrival events to the priority queue between 0 and 26
	int arrivals = rand() % 26;
	for (int i = 0; i < arrivals; i++) {
		Event* new_arrival = new Arrival(new Customer, this, ((double)rand()/RAND_MAX) + 0.01, "Customer arrived.");
		event_queue.push(new_arrival);
	}
	
}

void Simulation::run() {
	while (event_queue.size() > 0) {
		// Grabs the first event in the queue
		Event* next_event = event_queue.top();
		current_time = next_event->get_time();
		// Adds any additional corresponding events
		next_event->act();
		// Removes the event from the priority queue
		delete next_event;
		event_queue.pop();
	}

	// Prints out the number of hot dog orders
	map<double, int>::iterator i;
	cout << "Hot dog orders" << endl;
	cout << "time dogs" << endl;
	int total = 0;
	for (i = hot_dog_orders.begin(); i != hot_dog_orders.end(); i++) {
		cout << i->first << " " << i->second << endl;
		total += i->second;
	}
	cout << "Total: " << total << endl;
}