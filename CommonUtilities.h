//
// Created by louis on 16/5/11.
// Edegs do not have labels.
// Graphs are indirected.
//

#ifndef SUBGRAPHMACHING_COMMONUTILITIES_H
#define SUBGRAPHMACHING_COMMONUTILITIES_H

#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

/*struct node {
    int id;
    node * next;
    node(int x, node *t){id = x; next = t;};
};
*/
struct Vertex {
    int id;
    int label;
    //node * adjlist;
    vector<int> adjlist;
    map<int, pair<int, int>> adjlabellist;
    Vertex(int vertexid, int vertexlabel)
    {
        id = vertexid; label = vertexlabel;
    };
    Vertex()
    {
        id = -1; label = -1;
    }
};

class VertexCompareById {
public:
    bool operator() (const Vertex& left, const Vertex& right)
    {
        return (left.id < right.id);
    }
};

class VertexCompareByLabel {
public:
    bool operator() (const Vertex& left, const Vertex& right)
    {
        return (left.label < right.label);
    }
};

struct Edge {
    int src;
    int dst;
    bool directed;
    Edge(int s, int d, bool di)
    {
        src = s;
        dst = d;
        directed = di;
    }
    Edge(int s, int d)
    {
        src = s;
        dst = d;
        directed = false;
    }
    Edge()
    {
        src = -1;
        dst = -1;
        directed = false;
    }
};

class adjGraph {
public:
    void insert(Vertex v);
    void insert(Edge e);
    const Vertex* getVertexbyId(int id);
    void buildInverseLabelList();
    pair<int, int> getLabelList(int l);
    void buildAdjLabelList();
    pair<int, int> getAdjLabelList(int vertexlabel, int l);
private:
    bool idCompareByLabel(const int & left, const int & right)
    {
        return (getVertexbyId(left)->label > getVertexbyId(right)->label);
    }
    vector<Vertex> vertices;
    map<int, pair<int, int>> inverselabellist;
};

int loadGraphs(std::string filename, vector<adjGraph> & graphs);


#endif //SUBGRAPHMACHING_COMMONUTILITIES_H
