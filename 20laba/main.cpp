#include <iostream>
#include "graph.h"


int main() {
    string line;
    ifstream fin("C:\\Users\\zxggx\\CLionProjects\\laba4\\enter.txt");
    int v,dc;
    fin>>v;
    fin>>dc;
    graph a;
    a.dgr(0);
    for (int i = 0; i < a.fullGraph.size()-1;i++) {
        a.out<<a.fullGraph[i]<<"->";
    }
    a.out<<a.fullGraph.back();
    a.out.close();
    a.dfs(v-1,v-1,dc);

    return 0;
}
