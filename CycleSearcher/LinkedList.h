#pragma once
#include "Cell.h"
#include <cliext\vector>

using namespace std;

ref class LinkedList {
private:
	cliext::vector<Cell^> cells;
protected:
public:
	LinkedList();
	void addElem(Cell^);
	void eraseElem(long long);
	void clear();
	int getSize();
	void renumerate();
	Cell^ getCell(long long);
};