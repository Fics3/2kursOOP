#include <iostream>
#include "hash_set.h"
//лист листов лишние не создавать
int main() {
    hash_set s(17);
  s.insert(118);
  s.insert(1111);
  s.insert(127);
  s.insert(161);
  s.insert(11);
  s.insert(-10);
  s.insert(334);
  s.insert(423);
  s.insert(-15);
  s.insert(-105);
  s.insert(123);
  int a=s.find(122);
  s.erase(12);
  cout<<a<<endl;
  cout<<s;
    return 0;
}
