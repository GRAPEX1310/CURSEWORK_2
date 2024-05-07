#include "Cell.h"
#include "FordFalersonAlgorithm.h"

Cell::Cell() {
	this->id = -1;
	hasNext = false;
	hasPrev = false;
	intoCycle = false;
}

Cell::Cell(long long id) {
	this->id = id;
	hasNext = false;
	hasPrev = false;
	intoCycle = false;
}

void Cell::setLabel(System::Windows::Forms::Label^ label) {
	this->label = label;
}

void Cell::setNext(Cell^ next) {
	this->next = next;
}

void Cell::setId(long long id) {
	this->id = id;
	this->label->Text = id.ToString();
}

long long Cell::getId() {
	return id;
}

Cell^ Cell::getNext() {
	return next;
}

Cell::~Cell() {
	delete next;
}

void Cell::setEdge(Edge^ edge)
{
	adjacent.push_back(edge);
}

void Cell::removeEdge(Edge^ edge)
{
	for (int i = 0; i < adjacent.size(); i++) {
		auto current = adjacent[i];
		if (edge->start == current->start && edge->end == current->end) {
			adjacent.erase(adjacent.begin() + i);
			return;
		}
	}
}

void Cell::setPrev(Cell^ prev) {
	this->prev = prev;
}

Cell^ Cell::getPrev() {
	return prev;
}