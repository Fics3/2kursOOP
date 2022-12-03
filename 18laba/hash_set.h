
#ifndef YAREK2_HASH_SET_H
#define YAREK2_HASH_SET_H
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <iomanip>

using namespace std;


class hash_set{
public:
    int size;
    list <int> val;
    vector<list<int>> hash;
public:
    hash_set(int raz);
    ~hash_set(){};
    int hashdb(int value);


    bool insert(int value);
    int ssize();
    bool find(int value);
    void erase(int value);
};
inline std::ostream& operator<<(std::ostream& out,const list<int>&  a){
    for (auto const &v : a)
        out << v << " ";
    return out;
}

inline std::ostream& operator<<(ostream& out, const hash_set& hv) {
    int i=0;
    while(i<hv.size){
 //       if (hv.hash[i].empty()==1){
   //         i++;
     //       continue;
     //   }
        out<<"key:"<<i<<"  "<<hv.hash[i]<<endl;
        ++i;
    }
    return out;
}


#endif
