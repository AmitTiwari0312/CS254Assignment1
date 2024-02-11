#include <bits/stdc++.h>
using namespace std;

const int NV = 5;

bool isBipartiteUtil(int graph[][NV], int src, int colorArr[]) {
	colorArr[src] = 1;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < NV; ++v) {
			if (graph[u][v] && colorArr[v] == -1) {
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}
			else if (graph[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}
	return true;
}

bool iB(int graph[][NV]) {
	int colorArr[NV];
	for (int i = 0; i < NV; ++i)
		colorArr[i] = -1;
	for (int i = 0; i < NV; i++)
		if (colorArr[i] == -1)
			if (isBipartiteUtil(graph, i, colorArr) == false)
				return false;
	return true;
}

bool canbedivided(int graph[][NV]) {
	int complementGraph[NV][NV];
	for (int i = 0; i < NV; i++)
		for (int j = 0; j < NV; j++)
			complementGraph[i][j] = (i != j) ? !graph[i][j] : 0;
	return iB(complementGraph);
}

int main() {
	int graph[NV][NV] = {
		{0, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};
	canbedivided(graph) ? cout << "Yes" : cout << "No";
	return 0;
}

