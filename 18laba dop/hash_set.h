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
    list<list<int>> hash;
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
bool hash_set::insert(int value) {
    int a = hashdb(value);
    if (hash.empty()) { ;
        val.push_back(value);
        hash.push_back(val);
        val.clear();
        return true;
    }
    for (auto it = hash.begin(); it != hash.end(); ++it) {
        auto c = it->begin();
        {
            if (abs(*c % size) == a) {
                for (auto v = it->begin(); v != it->end(); v++) {
                    if (*v == value) {
                        return false;
                    }
                }
                it->push_back(value);
                return true;
            }
        }
    }
    val.push_back(value);
    hash.push_back(val);
    val.clear();
    return true;
}
bool hash_set::find(int value){
    int a = hashdb(value);
    for (auto it = hash.begin(); it != hash.end(); ++it) {
        auto c = it->begin();
        {
            if (abs(*c % size) == a) {
                for (auto v = it->begin(); v != it->end(); v++) {
                    if (*v == value) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
}
void hash_set::erase( int value) {
    int a = hashdb(value);
    for (auto it = hash.begin(); it != hash.end(); it++) {
        auto c = it->begin();
        if (abs(*c % size) == a) {
            for (auto v = it->begin(); v != it->end(); v++) {
                if (*v == value) {
                    it->remove(value);
                    if (it->empty()) {
                        hash.erase(it);
                        return;
                    }
                    return;
                }
            }
        }
    }
}

    inline std::ostream &operator<<(std::ostream &out, const list<int> &a) {
        for (auto const &v: a)
            out << v << " ";
        return out;
    }

    inline std::ostream &operator<<(ostream &out, const hash_set &hv) {
        auto i = hv.hash.begin();
        while (i != hv.hash.end()) {
            out<<"key:"<< abs(i->front()%(hv.size)) <<"   "<< *i << endl;
            ++i;
        }
        return out;
    }

#endif //YAREK2_HASH_SET_H