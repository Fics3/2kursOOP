#include "hash_set.h"

hash_set::hash_set(int raz){
    for(int i=0;i<size;i++){
        hash.push_back(val);
    }
    size=raz;
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
    int b = 0;
    for (int i = 0; i < size; i++) {
        if (i == a) {
            b = i;
            break;
        }
    }
    for (auto it = hash[b].begin(); it != hash[b].end(); it++) {
        if (value == *it) {
            return true;
        }
    }
    return false;

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

