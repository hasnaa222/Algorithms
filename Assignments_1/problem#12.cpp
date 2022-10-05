//problem#12
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct Point
{
    int x, y;
};
int compY(const void* a, const void* b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->y - p2->y);
}
int compX(const void* a, const void* b){
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return (p1->x - p2->x);
}
float dist(Point p1, Point p2){
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
float bruteForce(Point P[], int n){
    float min =  5e3 + 10;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
float min(float x, float y){
    if (x<y) return x;
    else return y;
}
float stripClosest(Point strip[], int size, float d){
    float min = d;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}
float closestUtil(Point Px[], Point Py[], int n){
    if (n <= 3)
        return bruteForce(Px, n);
    int mid = n/2;
    Point midPoint = Px[mid];
    Point Pyl[mid+1];
    Point Pyr[n-mid-1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++){
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    float d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
    return min(d, stripClosest(strip, j, d) );
}
float closest(Point P[], int n){
    Point Px[n];
    Point Py[n];
    for (int i = 0; i < n; i++){
        Px[i] = P[i];
        Py[i] = P[i];}
    qsort(Px, n, sizeof(Point), compX);
    qsort(Py, n, sizeof(Point), compY);
    return closestUtil(Px, Py, n);
}
int main(){
    Point P[] = {{4,4},{-2,-2},{-3,-4},{-1,3},{2,3},{-4,0},{1,1},{-1,-1},{3,-1},{-4,2},{-2,4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is: " << closest(P, n);
    return 0;
}
/*Closest Pair of Points:
 * to do implement in O(nLogn):
  first step: sort all points according to x
  second: Divide all points in two halves.
  third : find the smallest distances by Recursive.
  then Take the minimum of two smallest distances.
  Create an array strip[] that stores all points
  which are at most d distance away from the middle line dividing the two sets.
  Find the smallest distance in strip[].
  Return the minimum of d and the smallest distance calculated in above step.
*/