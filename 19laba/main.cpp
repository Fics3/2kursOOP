#include <iostream>
#include <vector>

using namespace std;
ostream& operator<<(ostream& out, vector<int> a){
    for (auto & it : a) {
        cout << it << " ";
    }
    cout << endl;
}
void foo(int n,int c,vector<int>& j){
    if (c==n){
        cout<<j;
        return;
    }
    for(int i = c;i<n;i++){
        swap(j[i],j[c]);
        foo(n,c+1,j);
        swap(j[i],j[c]);
    }
}
int main(){
    vector<int> j={1,2,3};
    foo(j.size(),0,j);
}
