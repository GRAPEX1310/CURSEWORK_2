#include "LinkedList.h"

LinkedList::LinkedList() {
}

void LinkedList::addElem(Cell^ cell) {
	cells.push_back(cell);
}

void LinkedList::eraseElem(long long id) {
	if (cells.at(id)->hasNext) {
		cells.at(id)->setNext(gcnew Cell());
	}
	if (cells.at(id)->hasPrev) {
		cells.at(id)->setPrev(gcnew Cell());
	}

	cells.erase(cells.begin() + id);
}

void LinkedList::clear() {
	cells.clear();
}

int LinkedList::getSize() {
	return cells.size();
}

void LinkedList::renumerate() {
	for (int i = 0; i < cells.size(); i++) {
		cells.at(i)->setId(i);
	}
}

Cell^ LinkedList::getCell(long long ind) {
	return cells.at(ind);
}