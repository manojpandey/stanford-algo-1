#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

class point
{
    public:
        double x;
        double y;
};
bool operator<(point a, point b)
{
    if(a.x < b.x)
        return true;
    else 
         return false;
}

//Finds minimum x value among a set of points
double min_x(vector<point> p)
{
    double min = p[0].x;

    for(int i = 1; i < p.size(); i++) 
        if(p[i].x < min)
            min = p[i].x;
    return min;
}

//Finds modulus of a
double mod(double a)
{
    if( a < 0 )
        return -a;
        else return a;
}

//Finds maximim x among a set of points
double max_x(vector<point> p)
{

    double max = p[0].x;
    for( int i = 1; i < (int)(p.size()); i++){ 
         if( p[i].x > max)
             max = p[i].x;
    }
    return max;
}

//Finds distance between 2 points    
double dist(point a, point b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}
                    
vector<point> merge(vector<point> lside, vector<point> rside, double mid, vector<point> send)
{
 vector<point> p(4);
 p[0] = send[0]; //First point in (apparent)closest pair
 p[1] = send[1]; //Second point in (apparent)closest pair
 double  dmin = dist(p[0], p[1]); //Closest distance
 for(int i = 0; i < lside.size(); i++) 
 {
    if(mid - lside[i].x <= dmin) //if midpoint is closer to any of the leftside points than the distance between the (apparent)closest pair
    {
      for(int j = 0; j < rside.size(); j++) {
          if(mod(lside[i].x - rside[i].x) <= dmin && mod(lside[i].y - rside[i].y) <= dmin)  
          {
             if(dist(lside[i], rside[j]) < dmin) 
             {
                dmin = dist(lside[i], rside[j]);
                p.clear();
                //Changing the (apparent)closest pair to the correct closest pair
                p.push_back(lside[i]); 
                p.push_back(rside[j]);
              }
             }
            }
          }
        }
    return p;
}

vector<point> divide(vector<point> p, double min, double max) //min gives xmin, max gives xmax, p is set of points sorted xwise
{
   vector<point> pair(2);
   if(p.size() <= 1)  
   {
        point val;
        val.x = INT_MAX; val.y = INT_MAX;
        pair[0] = val; pair[1] = val;
        return pair;
   }
   if(p.size() == 2) 
   {
       pair[0] = p[0];
       pair[1] = p[1];
       return pair;
   }    
   if(p.size() == 3) //if there are 3 points, do simple comparison between them, this is another form of base case
   {
        double d;
        double a = dist(p[0], p[1]);
        double b = dist(p[1], p[2]);
        double c = dist(p[0], p[2]);

        if(a <= b && a <= c) 
        {
            d =  a;
            pair[0] = p[0];
               pair[1] = p[1];
               return pair;
         }        
        if(b <= a && b <= c) 
        {
            d = b;
            pair[0] = p[2];
              pair[1] = p[1];
              return pair;
        }
        if(c <= a && c <= b) 
        {
            d = c;
            pair[0] = p[0];
            pair[1] = p[2];
            return pair;
        }
    }
   //if we have more than 3 points
   double mid = (min + max)/2;
   vector<point> lside; //Creating a set of points to the left of the midpoint
   vector<point> rside;

   //Pushing points to left or right side, according to their x position
    for(int i = 0; i < p.size(); i++) 
    {
        if(p[i].x <= mid)
            lside.push_back(p[i]);
            else 
                 rside.push_back(p[i]);
   }

    vector<point> p1 = divide(lside, min, mid); //Calculating closest leftwise pair recursively
    vector<point> p2 = divide(rside, mid, max); //Calculating closest rightwise pair
    vector<point> send(2);

  if(dist(p1[0], p1[1]) <= dist(p2[0], p2[1]))  //Comparing shortest distances of closest leftwise and rightwise pairs
    send = p1;
  else   
    send = p2;
  return merge(lside, rside, mid, send);
  //Sending leftwise set of points, rightwise set of points, midpoint and (apparent)closest pair to merge
}
             
int main()
{
    int i, n;
    vector<point> p;

    cout << "Enter the no of points." << endl;
    cin >> n;
    if (n == 1)
       cout << "Enter at least 2 points." << endl;
    else
    {
    cout << "Enter the points." << endl;

    for(i = 0; i < n; i++ ) {
        point val;
        cin >> val.x >> val.y;
        p.push_back(val);
    }
    sort(p.begin(), p.end());
    vector<point> ans = divide(p, min_x(p), max_x(p));
    cout << "The closest pair of points are: (" << ans[0].x << ", " <<  ans[0].y << ") and (" << ans[1].x << ", " << ans[1].y << ")" << endl;
    cout << "The distance between them = " << dist(ans[0], ans[1]) << endl; 
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}