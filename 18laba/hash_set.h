//
// Created by zxggx on 24.09.2022.
//

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
//    ~hash_set();
    int hashdb(int value);


    bool insert(int value);
    int ssize();
    bool find(int value);
    void erase(int value);
};
    hash_set::hash_set(int raz){
        for(int i=0;i<size;i++){
            hash.push_back(val);
        }
    size=raz;
//    hash(size);
}
int hash_set::hashdb(int value){
        if (value<0) {
            return (-value % (size));
        }
    return (value%(size));
    }
int hash_set::ssize(){
    return size;
}
bool hash_set::insert(int value){
    int a = hashdb(value);
    int b=0;
    val.push_back(value);
    for (int i = 0;i<size;i++){
        if (i==a) {
            b = i;
            break;
        }
    }
    if(b==0){
        hash[b].push_back(value);
        return true;
    }
   if(hash[b].empty()){
       goto m1;
   }
   for(auto it=hash[b].begin();it!=hash[b].end();it++){
       if (value==*it){
           return false;
       }
   }

    m1:hash[b].push_back(value);
    return true;
 }
bool hash_set::find(int value){
    int a = hashdb(value);

}
void hash_set::erase( int value) {
    int a = hashdb(value);
    int b = 0;
    for (int i = 0; i < size; i++) {
        if (i == a) {
            b = i;
            break;
        }
    }
    if (hash[b].empty() || find(value)==0)
        return;
    for (auto it = hash[b].begin(); it != hash[b].end(); it++) {
        if (value == *it)
            hash[b].erase(it);
            break;
    }
}


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


#endif //YAREK2_HASH_SET_H
