#ifndef YAREK_POINT_H
#define YAREK_POINT_H
#include <iostream>

class Point {
public:
    int x;
    int y;
    int z;
public:
    Point();
    Point(int a, int b, int c);
    ~Point(){};
};
inline std::istream& operator>>(std::istream &in , Point &t) {
    in >> t.x;
    in >> t.y;
    in >> t.z;
    return in;
}

inline std::ostream& operator<<(std::ostream &out ,const Point &t) {
    out << t.x<<' ';
    out << t.y<<' ';
    out << t.z<<' ';
    return out;
}
//inline Point operator%(const Point& a,const Point& b){
//    return Point(a.x%b.x,a.y%b.y,a.z%b.z);
//    if (((a.x%b.x)==0)&&((a.y%b.y)==0)&&((a.z%b.z)==0))
//    return 0;
//    el
//}

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}
Point::Point(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
}



#endif //YAREK_POINT_H
