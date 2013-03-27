//============================================================================
// Name        : 10977.cpp
// Author      : swem
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> cell;

int r, c, m, n, x, y, L;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

enum state {
	walkable, notWalkable
};

const int MAX_DIM = 200;
int dist[MAX_DIM][MAX_DIM] = { { 0 } };
state forest[MAX_DIM][MAX_DIM];

int bound(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

int bfs() {
	queue<cell> q;
	dist[0][0] = 0;
	q.push(cell(0, 0));
	while (!q.empty()) {
		cell u = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx, ny;
			nx = u.first + dx[d];
			ny = u.second + dy[d];
			if (bound(nx, ny) && INT_MAX == dist[nx][ny]
					&& walkable == forest[nx][ny]) {
				dist[nx][ny] = dist[u.first][u.second] + 1;
				if (nx == r - 1 && ny == c - 1)
					return dist[nx][ny];
				q.push(cell(nx, ny));
			}
		}
	}
	return -1;
}

int main() {
	const int MAX_Jigglypuff = 100;
	int Jigglypuff[MAX_Jigglypuff][3] = { { 0 } };

	while (cin >> r >> c) {
		if (r == 0) {
			break;
		}

		int m = 0;
		int n = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				dist[i][j] = INT_MAX;
				forest[i][j] = walkable;
			}
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			x--;
			y--;
			forest[x][y] = notWalkable;
		}

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> Jigglypuff[i][0] >> Jigglypuff[i][1] >> Jigglypuff[i][2];
			Jigglypuff[i][0]--;
			Jigglypuff[i][1]--;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				for (int k = 0; k < n; k++) {
					int diffx = i - Jigglypuff[k][0];
					int diffy = j - Jigglypuff[k][1];
					if (diffx * diffx + diffy * diffy
							<= Jigglypuff[k][2] * Jigglypuff[k][2]) {
						forest[i][j] = notWalkable;
						break;
					}
				}
			}
		}

		int answer = bfs();
		if (answer == -1) {
			cout << "Impossible." << endl;
		} else {
			cout << answer << endl;
		}
	}

	return 0;
}
