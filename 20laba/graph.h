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
    vector<int> visited,used;
    vector<int> path;
    string s;
    vector <int> fullGraph;
    int size=0;
    ofstream out;
    int j=0;
public:
    graph() {
        string line;
        ifstream in("C:\\Users\\zxggx\\CLionProjects\\laba4\\beg3.txt");
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << line << endl;
                g.push_back(line);
                size++;
            }
        }
        in.close();
        visited.resize(size);
        used.resize(10);
        out.open("C:\\Users\\zxggx\\CLionProjects\\laba4\\res.txt");
    }
    void dfs(int v,int v_start,int dc);
    void dgr(int v);
};
#endif //LABA4_GRAPH_H
