#pragma once
#include "Edge.h"
#include <cliext\vector>

using namespace std;

ref class EdgeList {
private:
	cliext::vector<Edge^> edges;
protected:
public:
	EdgeList();
	void addElem(Edge^ edge);
	void eraseElem(long long id);
	void clear();
	int getSize();
	void renumerate();
	Edge^ getEdge(long long id);
	cliext::vector<Edge^> getList();
};