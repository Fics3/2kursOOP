#include <iostream>
#include "stack.h"
#include "point.h"

using namespace std;
//
int main() {
    int N;
    cin>>N;
    Point p1(1, 2 ,4);
    Point p2(1,3,4);
    Point p3(2,16,24);
    Stack<int> Stack1(N);
    Stack<int> Stack(N);
    Stack.push(6);
    Stack.push(25);
    Stack.push(6);
   Stack.push(144);
//   Stack.push(7);
   Stack.push(32);
//   cout<<Stack<<endl;
//   Stack.clear();
//   Stack.pop();
    cout<<Stack<<endl;
//    Stack.ReverseStack();
//    cout<<Stack<<endl;
    cout<<Stack.DelEvenNum(Stack1);
 //   cout<<Stack1;
// cout<<Stack;
    //Stack.push(3);
    //cout<<Stack<<endl;
    //Stack.pop();
    //cout<<Stack;
    //Stack.clear();
    //cout << Stack;
    //cout<<"\nStack is Clear";
    //Stack.pop();
    //cout<<Stack;
    return 0;
}
