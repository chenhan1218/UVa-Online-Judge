//============================================================================
// Name        : 11631.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <set>
using namespace std;

const int V = 200000, E = 200000;
class Edge {
public:
	int a, b, c;
};

Edge edges[E];
int d[V];
int e[V];

// Disjoint-sets Forest
int p[V];
void init(int m) {
	for (int i = 0; i < m; ++i)
		p[i] = i;
}
int find(int x) {
	return x == p[x] ? x : (p[x] = find(p[x]));
}
void disjoint_union(int x, int y) {
	p[find(x)] = find(y);
}

// minimum spanning tree
set<int> Boruvka(int m, int n) {
	set<int> minimumSpanningTreeEdges;
	while (true) {
		int cross_edge = 0;
		for (int i = 0; i < m; ++i)
			d[i] = INT_MAX;

		for (int i = 0; i < n; ++i) {
			int a = find(edges[i].a);
			int b = find(edges[i].b);
			int c = edges[i].c;
			if (a == b)
				continue;
			cross_edge++;
			if (c < d[a] || (c == d[a] && i < e[a]))
				d[a] = c, e[a] = i;
			if (c < d[b] || (c == d[b] && i < e[b]))
				d[b] = c, e[b] = i;
		}

		if (cross_edge == 0)
			break;

		for (int i = 0; i < m; ++i) {
			if (d[i] != INT_MAX) {
				disjoint_union(edges[e[i]].a, edges[e[i]].b);
				minimumSpanningTreeEdges.insert(e[i]);
			}
		}
	}

	return minimumSpanningTreeEdges;
}

int main() {
	int m, n;
	while (cin >> m >> n && m != 0) {
		long long int totalMeters = 0;
		init(m);
		for (int i = 0; i < n; i++) {
			cin >> edges[i].a >> edges[i].b >> edges[i].c;
			totalMeters += edges[i].c;
		}

		const set<int> minimumSpanningTreeEdges = Boruvka(m, n);
		long long int sum = 0;
		for (set<int>::const_iterator iter = minimumSpanningTreeEdges.begin();
				iter != minimumSpanningTreeEdges.end(); ++iter) {
			sum += edges[*iter].c;
		}
		cout << totalMeters - sum << endl;
	}

	return 0;
}
