#include "VertexList.h"

VertexList::VertexList() {
}

void VertexList::addElem(Vertex^ cell) {
	vertices.push_back(cell);
}

void VertexList::eraseElem(long long id) {
	if (vertices.at(id)->hasNext) {
		vertices.at(id)->setNext(gcnew Vertex());
	}
	if (vertices.at(id)->hasPrev) {
		vertices.at(id)->setPrev(gcnew Vertex());
	}

	vertices.erase(vertices.begin() + id);
}

void VertexList::clear() {
	vertices.clear();
}

int VertexList::getSize() {
	return vertices.size();
}

void VertexList::renumerate() {
	for (int i = 0; i < vertices.size(); i++) {
		vertices.at(i)->setId(i);
	}
}

Vertex^ VertexList::getVertex(long long ind) {
	return vertices.at(ind);
}