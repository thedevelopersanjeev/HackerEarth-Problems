#include<bits/stdc++.h>
using namespace std;
int x[110], y[110], r[110], n;
double PI = 3.14159265358979323l;
 
bool check(double xx, double yy)
{
    for(int i=0; i<n; i++)
    {
        if((x[i] - xx)*(x[i] - xx) + (y[i] - yy)*(y[i] - yy) <= r[i]*r[i])
        {
            return true;
        }
    }
    return false;
}
 
int main()
{
    double a, b, c;
    cin >> n >> a >> b >> c;
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
 
    default_random_engine generator;
    uniform_real_distribution<double> distribution1(0.0, c*c);
    uniform_real_distribution<double> distribution2(0.0, 2*PI);
    int inside = 0, total = 0;
    for(int i=0; i<1000000; i++)
    {
        double r = distribution1(generator);
        double theta = distribution2(generator);
        double tmp = sqrt(r);
        double X = a + tmp*cos(theta);
        double Y = b + tmp*sin(theta);
        if(check(X, Y))
        {
            inside++;
        }
        total++;
    }
    double ans = (double)(inside)/(double)(total);
    cout << fixed << setprecision(10) << ans*PI*c*c;
    return 0;
}