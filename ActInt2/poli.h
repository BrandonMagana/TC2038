#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Point {
  int x, y;
};

Point p0;

//Función auxiliar que retorna el siguente elemento despues del tope del stack
Point nextToTop(stack<Point> &poliStack) {
  Point p = poliStack.top();
  poliStack.pop();
  Point res = poliStack.top();
  poliStack.push(p);
  return res;
}

//Función auxiliar para intercambiar dos puntos
void swap(Point &p1, Point &p2) {
  Point temp = p1;
  p1 = p2;
  p2 = temp;
}

//Función que retorna el cuadraddo de la dustancia entre dos puntos 
int distSq(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

//Retorna la orinetación del trio de puntos
// 0: colinear, 1: clockwise, 2: counterclockwise
int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (val == 0)
    return 0;
  return (val > 0) ? 1 : 2;
}

//Fucnión auxiliar para el ordenamiento de puntos de qsort()
int compare(const void *vp1, const void *vp2) {
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;

  int o = orientation(p0, *p1, *p2);
  if (o == 0)
    return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

  return (o == 2) ? -1 : 1;
}

//Función que retorna el poligono convexo más pequeño que contenga todos los puntos
//Utilizando Graham Scan
//O(n log n): siendo n los puntos ingresados 
void grahamScan(vector<Point> points, int n) {
  int ymin = points[0].y, min = 0;

  for (int i = 1; i < n; i++) {
    int y = points[i].y;

    if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
      ymin = points[i].y, min = i;
  }

  swap(points[0], points[min]);

  p0 = points[0];
  qsort(&points[1], n - 1, sizeof(Point), compare);

  int m = 1;
  for (int i = 1; i < n; i++) {

    while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
      i++;

    points[m] = points[i];
    m++;
  }

  if (m < 3){
    cout<<"Need more than 2 points to build up a convex hull. Please try again!"<<endl;
    return;
  }
  stack<Point> poliStack;
  poliStack.push(points[0]);
  poliStack.push(points[1]);
  poliStack.push(points[2]);

  for (int i = 3; i < m; i++) {
    while (poliStack.size() > 1 && orientation(nextToTop(poliStack), poliStack.top(), points[i]) != 2)
      poliStack.pop();
    poliStack.push(points[i]);
  }

  vector<string> convexPoli;
  while (!poliStack.empty()) {

    Point p = poliStack.top();
    poliStack.pop();
    convexPoli.insert(convexPoli.begin(),
                      "(" + to_string(p.x) + ", " + to_string(p.y) + ")");
  }

  for (int i = 0; i < convexPoli.size(); i++) {
    if(i == convexPoli.size() - 1)
      cout<<convexPoli[i]<<endl;
    else
      cout << convexPoli[i] << " -> ";
  }
}