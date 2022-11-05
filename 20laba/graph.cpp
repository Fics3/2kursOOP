#include "graph.h"
//bool tmp=false;
string c;
string strP(){
    string s;
    ifstream lin(R"(C:\Users\zxggx\CLionProjects\laba4\res.txt)");
    if (lin.is_open()) {
        getline(lin, s);
    }
    lin.close();
    return s;
}
void graph::dfs(int v,int v_start,int dc) {
    if (v>size && v<=0){
        out<<"ERROR SOBAKA";
        return;
    }
    if (visited[v] == 1 ) {
            path.push_back(v+1);
            int a=0;
            while(a<path.size()){
                if (v==path[a]-1)
                    break;
                a++;
            }
            if (path.size()-a>=dc){
                return;
            }
            string pp="res"+to_string(j) + ".dot";
            ofstream filename (pp);
            filename << "digraph E"<<j<<"{";
            while (a<path.size()-1) {
                filename << path[a] << "->";
                a++;
            }
            path.pop_back();
            filename<<path[a]<<"[shape=ellipse,style=filled,color=";
            if (j==0)
              filename<<"red]"<<strP()<<"}";
            if (j==1)
                filename<<"blue]"<<strP()<<"}";
            if (j==2)
                filename<<"green]"<<strP()<<"}";
            if (j>2) filename<<"purple]"<<strP()<<"}";
            j=j+1;
            return;
    }
    visited[v] = 1;
    path.push_back(v+1);
    for (int i = 0; i < size; i++) {
        if (g[v][i] != '0' ) {
            dfs(i,v, dc);
        }
    }
    path.pop_back();
}
void graph::dgr(int v) {
    if (used[v] == 1) {
        return;
    }
    used[v]=1;
    fullGraph.push_back(v+1);
    for (int i = 0; i < size; i++) {
        if (g[v][i]!='0') {
            dgr(i);
        }
    }
}

