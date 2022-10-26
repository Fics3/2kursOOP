#include <iostream>
#include "graph.h"
#include <gvc.h>


int main() {
    string line;
    ifstream fin("C:\\Users\\zxggx\\CLionProjects\\laba4\\enter.txt");
    int v,dc;
    fin>>v;
    fin>>dc;
    graph a;
    ifstream gr("C:\\Users\\zxggx\\CLionProjects\\laba4\\res.txt");

    a.dfs(v-1,v-1,dc);
    return 0;
}
