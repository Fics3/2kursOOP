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
