/*
    Autores:
        - A01640162 Brandon Josué Magaña Mendoza
        - A01630329 Santiago González de Cosío Romero

    El presente programa tiene como objetivo determinar la intersección entre 2 pares de rectas.

    Uso:
        - g++ main.cpp -o main
        - ./main < test1.txt

    Resultado esperado:
        Line segments intersecting results:
        1, 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define clock 0
#define counter 1
#define collinear 2

using namespace std;

struct Point{
    int x;
    int y;

    Point(int x, int y): x(x), y(y){}
};

struct Segment {
    Point p1;
    Point p2;

    Segment(Point p1, Point p2): p1(p1), p2(p2){}
};

int crossProd(Point p0, Point p1, Point p2){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

int lineOrientation(Point p0, Point p1, Point p2){
    int crossProductResult = crossProd(p0, p1, p2);
    
    if(crossProductResult < 0)
        return clock;

    if(crossProductResult > 0)
        return counter;
    
    return collinear;
}

bool onProjection(Point p0, Point p1, Point p2){
    return (p1.x <= max(p0.x, p2.x)) 
        && (p1.x >= min(p0.x, p2.x))
        && (p1.y <= max(p0.y, p2.y)) 
        && (p1.y >= min(p0.y, p2.y));
}

bool areIntersecting(Segment a,Segment b){
    int aOrientation1 = lineOrientation(a.p1, a.p2, b.p1);
    int aOrientation2 = lineOrientation(a.p1, a.p2, b.p2);
    int bOrientation1 = lineOrientation(b.p1, b.p2, a.p1);
    int bOrtientation2 = lineOrientation(b.p1, b.p2, a.p2);
    
    if (aOrientation1 != aOrientation2 && bOrientation1 != bOrtientation2)
        return true;     
    if ((aOrientation1 == collinear) && onProjection(a.p1, b.p1, a.p2))
        return true;
    if ((aOrientation2 == collinear) && onProjection(a.p1, b.p2, a.p2))
        return true;
    if ((bOrientation1 == collinear) && onProjection(b.p1, a.p1, b.p2))
        return true;
    if ((bOrtientation2 == collinear) && onProjection(b.p1, a.p2, b.p2))
        return true;

    return false;
}

vector<Point> definePoints(int nPoints){
    vector<Point> points;
    int x, y;

    for(int i = 0; i < nPoints; i++){
        cin >> x;
        cin >> y;
        Point newPoint(x, y);
        points.push_back(newPoint);
    }

    return points;
}

vector<Segment> defineSegments(vector<Point> points){
    vector<Segment> segments;

    for(int i = 0; i < points.size(); i+=2){
        Point a = points[i];
        Point b = points[i+1];
        Segment newSegment(a, b);
        segments.push_back(newSegment);
    }    

    return segments;
}

vector<bool> getAreIntersectingResults(vector<Segment> segments){
    vector<bool> areIntersectingResults;
    for(int i = 0; i < segments.size(); i+=2){
        Segment a = segments[i];
        Segment b = segments[i+1];
        areIntersectingResults.push_back(areIntersecting(a, b));
    }
    return areIntersectingResults;
}

void printResults(vector<bool> results){
    cout<<"Line segments intersecting results:\n";
    for(int i = 0; i < results.size(); i++){
        if(i != results.size() - 1)
            cout << results[i] << ", ";
        else
            cout << results[i] << endl;
    }
}

int main(){
    int nPoints = 0;
    cin >> nPoints;

    while (nPoints % 4 != 0) {
        cin >> nPoints;
    }
    
    vector<Point> points = definePoints(nPoints);
    vector<Segment> segments = defineSegments(points);
    vector<bool> results = getAreIntersectingResults(segments);
    
    printResults(results);
    return 0;
}