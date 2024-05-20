#pragma once
#include <cliext\vector>
#include "Edge.h"
#include "list"


ref class Vertex {
private:
	long long id;
	Vertex^ next;
	Vertex^ prev;
protected:
public:
	cliext::vector<Edge^> adjacent; // список инцидентности
	bool hasNext;
	bool hasPrev;
	System::Windows::Forms::Label^ nextLabel;
	System::Windows::Forms::Label^ label;

	Vertex();
	Vertex(long long);
	void setNext(Vertex^);
	void setLabel(System::Windows::Forms::Label^);
	void setId(long long);
	long long getId();
	Vertex^ getNext();
	void setPrev(Vertex^);
	Vertex^ getPrev();
	~Vertex();
	void setEdge(Edge^ edge);
	void removeEdge(Edge^ edge);
};