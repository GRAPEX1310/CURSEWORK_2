#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <cliext\vector>


ref class Solver
{
public:

    const int MAX_E = (int)1e6;
    const int MAX_V = (int)1e3;
    const int INF = (int)1e9;


    int* capacity;
    int* onEnd;
    int* nextEdge;

    int* firstEdge;
    bool* visited;

    int numOfVertex, numOfEdge, sourceVertex, destinationVertex, edgeCount;

    Solver() {
        capacity = new int[MAX_E];
        onEnd = new int[MAX_E];
        nextEdge = new int[MAX_E];

        firstEdge = new int[MAX_V]; 
        visited = new bool[MAX_V];
        edgeCount = 0;

        std::fill(firstEdge, firstEdge + MAX_V, -1);
        std::fill(visited, visited + MAX_V, false);
        /*
        for (int i = 0; i < MAX_V; ++i) {
            firstEdge[i] = -1;
        }
        */
    }

    ~Solver() {
        delete [] firstEdge;
        delete [] visited;
        delete [] capacity;
        delete [] onEnd;
        delete [] nextEdge;
    }

    

    int solve(int source, int final, int numOfV, int numOfE, cliext::vector<Edge^> edges) {
        std::fill(firstEdge, firstEdge + MAX_V, -1);     // -1 означает ребра нет
        sourceVertex = source;
        destinationVertex = final;
        numOfVertex = numOfV;
        numOfEdge = numOfE;

        for (int i = 0; i < edges.size(); i++) {
            addEdge(edges[i]->start, edges[i]->end, edges[i]->weight);
        }

        // Нахождение максимального потока
        int maxFlow = 0;
        int iterationResult = 0;
        while ((iterationResult = findFlow(sourceVertex, INF)) > 0) {
            std::fill(visited, visited + MAX_V, false);
            maxFlow += iterationResult;
        }

        // Выводим максимальный поток
        return maxFlow;
    }


    int findFlow(int u, int flow) {
        if (u == destinationVertex) return flow; // возвращяем полученный минимум на пути
        visited[u] = true;
        for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
            int to = onEnd[edge];
            int isVisited = !visited[to];
            int capa = capacity[edge];
            int noEmptyEdge = (capa > 0) ? 1 : 0;
            if (isVisited && noEmptyEdge) {
                int minResult = findFlow(to, std::min(flow, capacity[edge])); // ищем поток в поддереве
                if (minResult > 0) {                    // если нашли
                    capacity[edge] -= minResult;   // у прямых ребер вычетаем поток
                    capacity[edge ^ 1] += minResult;   // к обратным прибавляем
                    return minResult;
                }
            }
        }
        return 0; // если не нашли поток из этой вершины вернем 0
    }

    void addEdge(int u, int v, int cap) {
        // Прямое ребро
        onEnd[edgeCount] = v;                   // на конце прямого v
        nextEdge[edgeCount] = firstEdge[u];     // добавляем в начало списка для u
        firstEdge[u] = edgeCount;               // теперь начало списка - новое ребро
        capacity[edgeCount++] = cap;            // устанавливаем пропускную способность
        // Обратное ребро
        onEnd[edgeCount] = u;                   // на конце обратного u
        nextEdge[edgeCount] = firstEdge[v];     // добавляем в начало списка для v
        firstEdge[v] = edgeCount;               // теперь начало списка - новое ребро
        capacity[edgeCount++] = 0;              // устанавливаем пропускную способность
    }
};