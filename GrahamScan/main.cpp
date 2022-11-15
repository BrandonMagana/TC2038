/*
    Autores:
        - A01640162 Brandon Josué Magaña Mendoza
        - A01640114 José Antonio Chaires Monroy

    El presente programa tiene como objetivo determinar el polígono convexo más pequeño 
    que contiene dentro a todo el conjunto de puntos dados como entrada al programa, utilizando
    el algoritmo "Graham's Scan".
    
    Complejidad Temporal: O(n log n)

    Uso:
        - g++ main.cpp -o main
        - ./main < ./tests/test-1.txt

    Resultado esperado:
    Convex Polygon Points(Counter Clock Wise Ordered): 
    (4, 1), (8, 2), (9, 9), (1, 7)
*/
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;
 
struct Point{
    int x, y;
    Point(int x, int y): x(x), y(y){}
    Point() {x = 0; y = 0;};
};

Point p0;
 
Point nextToTop(stack<Point> &S){
    Point currentTop = S.top();
    S.pop();
    Point nextToTop = S.top();
    S.push(currentTop);
    return nextToTop;
}
 
void swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
int squareDistance(Point p1, Point p2){
    return int(pow((p1.x - p2.x), 2) +
        pow((p1.y - p2.y), 2));
}
 
int getOrientation(Point p0, Point p1, Point p2){
    int val = (p1.y - p0.y) * (p2.x - p1.x) -
            (p1.x - p0.x) * (p2.y - p1.y);
 
    if (val == 0) return 0;
    return (val > 0) ? 1: 2;
}
 
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
 
    int orientation = getOrientation(p0, *p1, *p2);
    if (orientation == 0)
        return (squareDistance(p0, *p2) >= squareDistance(p0, *p1))? -1 : 1;
 
    return (orientation == 2)? -1: 1;
}
 
stack<Point> getConvexPolygonPoints(vector<Point> points){
    int ymin = points[0].y; 
    int min = 0;
    int n = points.size();
    for (int i = 1; i < n; i++){
        int y = points[i].y;
    
        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x)){
                ymin = points[i].y;
                min = i;
        }
    }
    
    swap(points[0], points[min]);
    
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);
    
    int m = 1;
    for (int i=1; i<n; i++){
        while (i < n-1 && getOrientation(p0, points[i], points[i+1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    
    for (int i = 3; i < m; i++){
        while (S.size()>1 && 
            getOrientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    
    return S;
}

vector<Point> createPoint(int nPoints){
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

void printPolygonPointsCCW(stack<Point> s){
    stack<Point> aux;
    while (!s.empty()){
        Point p = s.top();
        aux.push(p);
        s.pop();
    }

    cout<<"Convex Polygon Points(Counter Clock Wise Ordered): " << endl;
    while ( !aux.empty() ){
        Point p = aux.top();
        if( aux.size() == 1 )
            cout<< "(" << p.x << ", " <<  p.y << ")" << endl;
        else
            cout << "(" << p.x << ", " << p.y <<"), ";
        aux.pop();
    }
}

int main(){
    int nPoints = 0;
    cin >> nPoints;

    if(nPoints < 3){
        cout<<"Can't create convex hull out of " << nPoints
            << " points"<< endl;
        return 0;
    }

    vector<Point> points = createPoint(nPoints);
    stack<Point> polygonPoints = getConvexPolygonPoints(points);
    printPolygonPointsCCW(polygonPoints);
    return 0;
}