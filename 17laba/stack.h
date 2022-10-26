#ifndef YAREK_STACK_H
#define YAREK_STACK_H
#include <iostream>
using namespace std;
//метод, который из стека удаляет чётные элементы, нужно сделать с помощью пуш и поп
template<class T> class Stack{
public:
    int top;
    T* arr;
    int raz;
public:
    Stack(int size = 10);
    ~Stack(){
        delete[] arr;
    }
    unsigned size() const;
    void push(const T& value);
//    unsigned Get() const;
    T pop();
    T clear();
    Stack<T> DelEvenNum(Stack<T> & a);
    void ReverseStack();
};
template<class T>
Stack<T>::Stack(int size) {
    raz = size;
    arr = new T[raz];
    top = -1;
}
template<class T>
unsigned Stack<T>::size() const {
    return top+1;
}
template<class T>
void Stack<T>::push(const T& value) {
    if(raz >= top)
    arr[++top] = value;
    else{
        T *new_stack = new T[raz + 1];
        for (int i = 0; i < raz; ++i) {
            new_stack[i] = arr[i];
        }
        delete[] arr;
        arr= new T[raz+1];
        for (int i = 0; i <= raz; ++i)
            arr[i] = new_stack[i];
        arr[++top] = value;
    }
    if (raz==top){
        raz++;
    }
}
template<class T>
void Stack<T>::ReverseStack(){
    int i=top;
    int j=0;
    while (i>=j){
        swap(arr[i],arr[j]);
        i--;
        j++;
    }
}
template<class T>
Stack<T> Stack<T>::DelEvenNum(Stack<T>& a){
     int i = top;
//     int k = top;
     while( i != -1){
         if(arr[i] % 2 != 0){
             a.push(this->arr[i]);
             pop();
         }
         else {
            pop();
         }
         i--;
     }
     a.ReverseStack();
    return a;
}
//template<class T>
//unsigned Stack<T>::Get() const {
//    return arr[top];
//}

template<class T>
T Stack<T>::pop()
{ int flag = 0;
    try{
        if(this->top == -1) throw flag;
        return arr[top--];
    }
    catch(int flag)
    {
        cout << "\nout of bounds" << endl;
    }
}
template<class T>
T Stack<T>::clear() {
    while(top!=-1)
    {
        //a.pop();
        this->top--;
    }
}
template<class T>
inline std::ostream& operator<<(std::ostream& out, const Stack<T>& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a.arr[i] << " ";
    }

    return out;
}
#endif

