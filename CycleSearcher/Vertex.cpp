#include "Vertex.h"
#include "FordFulkersonAlgorithm.h"

Vertex::Vertex() {
	this->id = -1;
	hasNext = false;
	hasPrev = false;
}

Vertex::Vertex(long long id) {
	this->id = id;
	hasNext = false;
	hasPrev = false;
}

void Vertex::setLabel(System::Windows::Forms::Label^ label) {
	this->label = label;
}

void Vertex::setNext(Vertex^ next) {
	this->next = next;
}

void Vertex::setId(long long id) {
	this->id = id;
	this->label->Text = id.ToString();
}

long long Vertex::getId() {
	return id;
}

Vertex^ Vertex::getNext() {
	return next;
}

Vertex::~Vertex() {
	delete next;
}

void Vertex::setEdge(Edge^ edge)
{
	adjacent.push_back(edge);
}

void Vertex::removeEdge(Edge^ edge)
{
	for (int i = 0; i < adjacent.size(); i++) {
		auto current = adjacent[i];
		if (edge->start == current->start && edge->end == current->end) {
			adjacent.erase(adjacent.begin() + i);
			return;
		}
	}
}

void Vertex::setPrev(Vertex^ prev) {
	this->prev = prev;
}

Vertex^ Vertex::getPrev() {
	return prev;
}