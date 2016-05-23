//
// Created by louis on 16/5/11.
//

#include "CommonUtilities.h"
void adjGraph::insert(Vertex v)
{
    vertices.push_back(v);
}

void adjGraph::insert(Edge e)
{
    int dst = e.dst;
    int src = e.src;
    const Vertex * srcv = getVertexbyId(src);
    const Vertex * dstv = getVertexbyId(dst);
    if(srcv == nullptr || dstv == nullptr)
    {
        cout << "warning : wrong parameters while inserting edges, insertion abort." << endl;
        return;
    }
    auto result = find(srcv->adjlist.begin(), srcv->adjlist.end(), dst);
    if(result == srcv->adjlist.end())
        srcv->adjlist.push_back(dst);
    result = find(dstv->adjlist.begin(), dstv->adjlist.end(), src);
    if(result == dstv->adjlist.end())
        dstv->adjlist.push_back(src);
}

const Vertex* adjGraph::getVertexbyId(int id)
{
    auto it = vertices.begin();
    while(it != vertices.end())
        if(it->id == id)
        {
            return &(*it);
        }
    return nullptr;
}

void adjGraph::buildInverseLabelList()
{
    sort(vertices.begin(), vertices.end(), VertexCompareByLabel());
    int left = 0;
    int right = left;
    while(left != vertices.size())
    {
        int newlabel = vertices[left].label;
        while(vertices[right].label == newlabel && right != vertices.size())
            right++;
        inverselabellist.insert(make_pair(newlabel, make_pair(left, right)));
        left = right;
    }
}

//Vertices[left] to Vertices[right-1] are marked with the same label l
pair<int, int> adjGraph::getLabelList(int l)
{
    int left = inverselabellist[l].first;
    int right = inverselabellist[l].second;
    return make_pair(left, right);
}

void adjGraph::buildAdjLabelList()
{
    for(int vertexindex = 0; vertexindex < vertices.size(); vertexindex++)
    {
        Vertex & vertex = vertices[vertexindex];
        vector<int> & adjlist = vertex.adjlist;
        sort(adjlist.begin(), adjlist.end(), idCompareByLabel);
        int left = 0;
        int right = left;
        while(left != adjlist.size())
        {
            int newlabel = getVertexbyId(adjlist[left])->label;
            while(getVertexbyId(adjlist[right])->label == newlabel && right != adjlist.size())
                right++;
            vertex.adjlabellist.insert(make_pair(newlabel, make_pair(left, right)));
        }
    }
}

int loadGraphs(std::string filename, vector<adjGraph> & graphs)
{
    const char* dfile = filename.data();
    std::ifstream GraphFile(dfile, std::ios_base::in);
    if(!GraphFile.is_open()) {
        cout << filename << " :file doesn't exist" << endl;
        return -1;
    }
    string line;
    getline(GraphFile, line);
    while ( line.size() != 0 && (*line.begin()) == 't')
    {
        graphs.push_back(adjGraph());
        adjGraph & graph = *(graphs.end() - 1);
        while(getline (GraphFile,line) && (*line.begin() == 'v'))
        {
            istringstream iss(line);
            string string1;
            int num1, num2;
            iss>>string1;
            iss>>num1;
            iss>>num2;
            Vertex vertex(num1, num2);
            graph.insert(vertex);
        }
        do{
            istringstream iss(line);
            string string1;
            int num1, num2;
            iss>>string1;
            iss>>num1;
            iss>>num2;
            Edge e(num1, num2, false);
            graph.insert(e);
        }while(getline (GraphFile,line) && (*line.begin() == 'e'));
    }
}