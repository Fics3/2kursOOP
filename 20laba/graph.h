//
// Created by zxggx on 16.10.2022.
//
//
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#ifndef LABA4_GRAPH_H
#define LABA4_GRAPH_H
class graph {
public:
    vector<string> g;
    vector<int> visited;
    vector<int> path;
    int size=0;
    bool flag=0;
    ofstream out;
public:
    graph() {
        string line;
        ifstream in("C:\\Users\\zxggx\\CLionProjects\\laba4\\beg3.txt"); // окрываем файл для чтения
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << line << std::endl;
                g.push_back(line);
                size++;
            }
        }
        in.close();
        visited.resize(size);
        out.open("C:\\Users\\zxggx\\CLionProjects\\laba4\\res.txt"); // окрываем файл для записи
    }
    void dfs(int v,int v_start,int dc);
};
void graph::dfs(int v,int v_start,int dc) {
    if (v>=size && v<=0){
        out<<"ERROR SOBAKA";
        return;
    }
        if (visited[v] == 1 ) {
            if (v != v_start){
                visited.clear();
                int a=0;
                while(a<path.size()){
                    if (v==path[a]-1)
                        break;
                    a++;
                }
                if (path.size()-a>=dc){
                    return;
                }
                while (a<path.size()) {
                    out << path[a];
                    a++;
                }
                out<<endl;
                return;
            }
            else {
                visited.clear();
                if (path.size() >= dc) {
                    return;
                }
                for (int j = 0; j < path.size(); j++)
                    out << path[j];
                out << endl;
                return;
            }
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

#endif //LABA4_GRAPH_H
