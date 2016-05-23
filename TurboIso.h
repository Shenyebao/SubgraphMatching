//
// Created by louis on 16/5/5.
//

#ifndef SUBGRAPHMACHING_TURBOISO_H
#define SUBGRAPHMACHING_TURBOISO_H

#include <iostream>
#include <vector>
#include "CommonUtilities.h"
using namespace std;

class NECNode {
public:
    vector<int> vertices;
    vector<int> childs;
    int id;
};

class TurboIso {
public:
    TurboIso(std::string datafilename, std::string queryfilename);
    void rewriteToNECTree();
    void exploreCR();

private:
    vector<adjGraph> datagraphs;
    vector<adjGraph> querygraphs;


};


#endif //SUBGRAPHMACHING_TURBOISO_H
