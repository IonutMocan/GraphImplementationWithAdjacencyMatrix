//
//
// Graph implementation using adjacency matrix 
//
//

#include <iostream>

using namespace std;

class Graph {
	int Size;
	int Matrix[10][10];
public:
	Graph(int _Size);
	void AddEdge(int Src, int Dest);
	int IsEdge(int Src, int Dest);
	void Print();
	void OutEdges(int Node);
	void Inedges(int Node);
	int OutGrade(int Node);
	int InGrade(int Node);
	int Grade(int Node);
	int EdgesNr();
	void ToIncidenceMatrix();
	int IsComplet();
	void CycleOf3(int X);
	void ToBecomeComplet();
	void ElementaryChain(int X, int Y);
	int OddChain();
	int EvenChain();
	int IsIsolNode(int Node);
};

Graph::Graph(int _Size)
	:Size(_Size) {
	for (int i = 0; i < _Size; ++i)
		for (int j = 0; j < _Size; ++j)
			Matrix[i][j] = 0;
}

void Graph::AddEdge(int Src, int Dest) {
	if (IsEdge(Src, Dest)) {
		cout << "\nEdge already exist!" << endl;
	}
	else {
		Matrix[Src][Dest] = 1;
	}
}

int Graph::IsEdge(int Src, int Dest) {
	if (Matrix[Src][Dest] == 1)
		return 1;
	return 0;

}

void Graph::Print() {
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j)
			cout << Matrix[i][j] << ", ";
		cout << endl;
	}
}

void Graph::OutEdges(int Node) {
	cout << "\nOut from " << Node << ": ";
	for (int i = 0; i < Size; ++i)
		if (Matrix[Node][i] == 1)
			cout << i << ", ";
	cout << "\n" << endl;
}

void Graph::Inedges(int Node) {
	cout << "\nInto " << Node << ": ";
	for (int i = 0; i < Size; ++i)
		if (Matrix[i][Node] == 1)
			cout << i << ", ";
	cout << "\n" << endl;
}

int Graph::OutGrade(int Node) {
	int Nr = 0;
	for (int i = 0; i < Size; ++i)
		if (Matrix[Node][i] == 1)
			++Nr;
	return Nr;
}

int Graph::InGrade(int Node) {
	int Nr = 0;
	for (int i = 0; i < Size; ++i)
		if (Matrix[i][Node] == 1)
			++Nr;
	return Nr;
}

int Graph::Grade(int Node) {
	return InGrade(Node) + OutGrade(Node);
}

int Graph::EdgesNr() {
	int Nr = 0;
	for (int i = 0; i < Size; ++i)
		Nr += InGrade(i);
	return Nr;
}

void Graph::ToIncidenceMatrix() {
	cout << "\n" << endl;

	int iMatrix[10][10];
	for (int i = 0; i < Size; ++i)
		for (int j = 0; j < EdgesNr(); ++j)
			iMatrix[i][j] = 0;

	int k = 0;
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j)
			if (Matrix[i][j] == 1) {
				iMatrix[i][k] = 1;
				iMatrix[j][k] = 1;
				++k;
			}
	}

	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < EdgesNr(); ++j)
			cout << iMatrix[i][j] << ", ";
		cout << endl;
	}
	cout << "\n" << endl;
}

int Graph::IsComplet() {
	for (int i = 0; i < Size; ++i)
		for (int j = i + 1; j < Size; ++j)
			if (Matrix[i][j] == 0 || Matrix[j][i])
				return 0;
	return 1;
}

void Graph::CycleOf3(int X) {
	cout << "\n" << endl;
	for (int i = 0; i < Size; ++i)
		if (Matrix[X][i] == 1)
			for (int j = 0; j < Size; ++j)
				if (Matrix[i][j] == 1 && Matrix[i][X] == 1)
					cout << "i: " << i << " j: " << j << " " << " X: " << X << endl;
	cout << "\n" << endl;
}

void Graph::ToBecomeComplet() {
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j)
			if (Matrix[i][j] == 0)
				cout << "( " << i << ", " << j << "), ";
		cout << endl;
	}
}

void Graph::ElementaryChain(int X, int Y) {
	cout << "\n" << endl;
	for (int i = 0; i < Size; ++i)
		if (Matrix[X][i] == 1)
			for (int j = 0; j < Size; ++j)
				if (Matrix[i][j] == 1 && Matrix[j][Y])
					cout << "X: " << X << " i: " << i << " j: " << j << " " << " Y: " << Y << endl;
	cout << "\n" << endl;
}

int Graph::OddChain() {
	cout << "\n" << endl;
	for (int i = 1; i < Size; i += 2)
		if (Matrix[i][i + 2] == 1)
			return 1;
	return 0;
}

int Graph::EvenChain() {
	cout << "\n" << endl;
	for (int i = 0; i < Size; i += 2)
		if (Matrix[i][i + 2] == 1)
			return 1;
	return 0;
}

int Graph::IsIsolNode(int Node) {
	cout << "\n" << endl;
	for (int i = 0; i < Size; ++i)
		if (Matrix[i][Node] == 1 || Matrix[Node][i] == 1)
			return 0;
	return 1;
}

void main() {
	Graph g(5);
	g.AddEdge(0, 4);
	g.AddEdge(1, 3);
	g.AddEdge(3, 4);
	g.AddEdge(1, 4);
	g.AddEdge(4, 3);

	g.Print();

	g.OutEdges(1);
	g.Inedges(1);

	cout << "\n-Grade: " << g.OutGrade(1) << endl;
	cout << "\n+Grade: " << g.InGrade(1) << endl;
	cout << "\nGrade: " << g.Grade(1) << endl;

	cout << "\nEdges number: " << g.EdgesNr() << endl;

	cout << "\nIs graph complet: " << g.IsComplet() << endl;

	g.ToIncidenceMatrix();

	g.ToBecomeComplet();

	g.CycleOf3(1);

	g.ElementaryChain(0, 3);

	cout << g.OddChain();
	cout << g.EvenChain();
	cout << "It's isolated node?: " << g.IsIsolNode(2) << endl;
}