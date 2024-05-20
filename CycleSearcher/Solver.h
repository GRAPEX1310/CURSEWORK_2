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
        std::fill(firstEdge, firstEdge + MAX_V, -1);     // -1 �������� ����� ���
        sourceVertex = source;
        destinationVertex = final;
        numOfVertex = numOfV;
        numOfEdge = numOfE;

        for (int i = 0; i < edges.size(); i++) {
            addEdge(edges[i]->start, edges[i]->end, edges[i]->weight);
        }

        // ���������� ������������� ������
        int maxFlow = 0;
        int iterationResult = 0;
        while ((iterationResult = findFlow(sourceVertex, INF)) > 0) {
            std::fill(visited, visited + MAX_V, false);
            maxFlow += iterationResult;
        }

        // ������� ������������ �����
        return maxFlow;
    }


    int findFlow(int u, int flow) {
        if (u == destinationVertex) return flow; // ���������� ���������� ������� �� ����
        visited[u] = true;
        for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
            int to = onEnd[edge];
            int isVisited = !visited[to];
            int capa = capacity[edge];
            int noEmptyEdge = (capa > 0) ? 1 : 0;
            if (isVisited && noEmptyEdge) {
                int minResult = findFlow(to, std::min(flow, capacity[edge])); // ���� ����� � ���������
                if (minResult > 0) {                    // ���� �����
                    capacity[edge] -= minResult;   // � ������ ����� �������� �����
                    capacity[edge ^ 1] += minResult;   // � �������� ����������
                    return minResult;
                }
            }
        }
        return 0; // ���� �� ����� ����� �� ���� ������� ������ 0
    }

    void addEdge(int u, int v, int cap) {
        // ������ �����
        onEnd[edgeCount] = v;                   // �� ����� ������� v
        nextEdge[edgeCount] = firstEdge[u];     // ��������� � ������ ������ ��� u
        firstEdge[u] = edgeCount;               // ������ ������ ������ - ����� �����
        capacity[edgeCount++] = cap;            // ������������� ���������� �����������
        // �������� �����
        onEnd[edgeCount] = u;                   // �� ����� ��������� u
        nextEdge[edgeCount] = firstEdge[v];     // ��������� � ������ ������ ��� v
        firstEdge[v] = edgeCount;               // ������ ������ ������ - ����� �����
        capacity[edgeCount++] = 0;              // ������������� ���������� �����������
    }
};