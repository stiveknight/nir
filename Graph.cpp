//
// Created by user on 13.04.2019.
//

#include <iostream>
#include <set>
#include "Graph.h"

Graph::~Graph() = default;

Graph::Graph(string g6) {
    int n = (int(g6[0]) - 63);
    vector<vector<int>> result(n, vector<int>(n, 0));

    int row = 0;
    int col = 1;
    for (int i = 1; i < g6.size(); i++) {
        int ch = g6[i] - 63;
        int bit = 0;
        for (int ibit = 5; ibit >= 0; --ibit) {
            bit = (ch >> ibit) & 1;
            result[row][col] = bit;
            result[col][row] = bit;
            row++;
            if (row == col) {
                row = 0;
                col++;
            }
            if (col == n) {

                this->graph = result;

                return;
            }
        }
    }
    this->graph = vector<vector<int> >();

}


void dfs(Graph *g, int v, vector<int> &used, vector<int> &p, set<int> &cycle) { //поиск в глубину
    used[v] = 1;
    for (int i = 0; i < g->graph[v].size(); i++) {
        if (g->graph[v][i] == 1) {
            int k = 0;
            int to = i;
            if (used[to] == 0) {
                p[to] = v;
                dfs(g, to, used, p, cycle);
            }
            else if (used[to] == 1 && to != p[v]) {
                int star = to;
                int fin = v;
                k = 0;
                for (int j = fin; j != star; j = p[j])
                    k++;
                cycle.insert(k + 1);
            }
        }
    }
    used[v] = 0;
}


set<int> Graph::girth() {
    vector<int> used;
    vector<int> p;
    int n = int(this->graph.size());
    set<int> cycle;
    for (int i = 0; i < n; i++) {
        p.push_back(-1);
        used.push_back(0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[j] = -1;
            used[j] = 0;
        }
        dfs(this, i, used, p, cycle);
    }
    return cycle;

}
