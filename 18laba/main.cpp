#include <iostream>
#include "hash_set.h"
//лист листов лишние не создавать
int main() {
    hash_set s(4);
  s.insert(11);
  s.insert(12);
  s.insert(111);
  s.insert(111);
  s.insert(-1);
  s.insert(23);
  s.insert(444);
  s.insert(106);
  s.insert(123);
  int a=s.find(123);
  s.erase(11);
  cout<<a<<endl;
  int key=1;
  cout<<s;
    return 0;
}
