//
// Created by user on 13.04.2019.
//

#ifndef NIR_GRAPH_H
#define NIR_GRAPH_H

#include <string>
#include <vector>
#include <set>

using namespace std;


class Graph {
public:
    explicit Graph(string g6);
    virtual ~Graph();
    vector<vector<int>> graph;
    set<int> girth();

private:




};


#endif //NIR_GRAPH_H
