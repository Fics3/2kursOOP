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
    Stack.push(32);
    Stack.pop();
    cout<<Stack<<endl;
    cout<<Stack.DelEvenNum(Stack1);

    return 0;
}
