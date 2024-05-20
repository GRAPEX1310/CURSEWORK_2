#pragma once
#include "Vertex.h"
#include <cliext\vector>

using namespace std;

ref class VertexList {
private:
	cliext::vector<Vertex^> vertices;
protected:
public:
	VertexList();
	void addElem(Vertex^);
	void eraseElem(long long);
	void clear();
	int getSize();
	void renumerate();
	Vertex^ getVertex(long long);
};