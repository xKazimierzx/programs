#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

struct Point{
    double x,y;

    Point operator-(Point &other)
    {
        return {this->x - other.x,this->y - other.y};
    }

    Point operator+(Point &other)
    {
        return {this->x + other.x,this->y + other.y};
    }

    int sign(double x) //浮点数符号
    {
        if(fabs(x) < eps) return 0;
        if(x < 0) return -1;
        return 1;
    }

    int dcmp(double x,double y) //浮点数比较
    {
        if(fabs(x -  y) < eps) return 0;
        if(x < y) return -1;
        return 1;
    }

    double dot(Point a,Point b) //数量积 A·B = |A||B|cos(C)
    {
        return a.x * b.x + a.y * b.y;
    }

    double cross(Point a,Point b) //向量积 AxB = |A||B|sin(C)
    {
        return a.x * b.y - a.y * b.x;
    }

    double getLength(Point a) //向量模长
    {
        return sqrt(dot(a,a));
    }

    double getAngle(Point a,Point b) //两向量夹角
    {
        return acos(dot(a,b) / getLength(a) / getLength(b));
    }

    double area(Point a,Point b,Point c) //两个向量构成的平行四边形有向面积
    {
        return cross(b - a,c - a);
    }

    Point rotate(Point a,double angle) //顺时针旋转angle的向量
    {
        return {a.x * cos(angle) + a.y * sin(angle), -a.x * sin(angle) + a.y * cos(angle)};
    }
};