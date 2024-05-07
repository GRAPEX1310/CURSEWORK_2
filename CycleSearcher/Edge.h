#pragma once


ref class Edge {
public:
	System::Windows::Forms::Label^ label;
	void setLabel(System::Windows::Forms::Label^);

	int start;
	int end;
	int weight;

	Edge(int s, int e, int w) {
		start = s;
		end = e;
		weight = w;
	}
};