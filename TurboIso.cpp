//
// Created by louis on 16/5/5.
//

#include "TurboIso.h"
TurboIso::TurboIso(std::string datafilename, std::string queryfilename)
{
    loadGraphs(datafilename, datagraphs);
    loadGraphs(queryfilename, querygraphs);
    for(int datagraphindex = 0; datagraphindex < datagraphs.size(); datagraphindex++)
        datagraphs[datagraphindex].buildInverseLabelList();
    for(int datagraphindex = 0; datagraphindex < datagraphs.size(); datagraphindex++)
        datagraphs[datagraphindex].buildAdjLabelList();
    for(int querygraphindex = 0; querygraphindex < querygraphs.size(); querygraphindex++)
        querygraphs[querygraphindex].buildAdjLabelList();
}