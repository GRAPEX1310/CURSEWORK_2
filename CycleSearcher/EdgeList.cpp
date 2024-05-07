#include "EdgeList.h"

EdgeList::EdgeList()
{
}


void EdgeList::addElem(Edge^ edge)
{
	edges.push_back(edge);
}

void EdgeList::eraseElem(long long id)
{
	edges.erase(edges.begin() + id);
}

void EdgeList::clear()
{
	edges.clear();
}

int EdgeList::getSize()
{
	return edges.size();
}

void EdgeList::renumerate()
{
}

Edge^ EdgeList::getEdge(long long id)
{
	return edges.at(id);
}

cliext::vector<Edge^> EdgeList::getList()
{
	return edges;
}
