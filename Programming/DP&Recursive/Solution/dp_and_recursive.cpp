#include<iostream>
#include<ctime>
#define SIZE 1000001
using namespace std;
long int fib[SIZE];
int recurcive(int n)
{
    if(n==1||n==2)
    {
        return 1;
    }
    return recurcive(n-1)+recurcive(n-2);
}
int dp(int n)
{
    fib[1]=1;
    fib[2]=1;
    if(n>2)
    {
        for(int i = 3 ; i <= n ; i++)
        {
            fib[i]=fib[i-1]+fib[i-2];
        }
    }
    return fib[n];
}
int main()
{
    int n = 47;
    long int r,d;
    float time_r,time_d;
    clock_t begin_r,end_r,begin_d,end_d;
    begin_r = clock();
    r = recurcive(n);
    end_r = clock();
    time_r = (end_r-begin_r)/CLOCKS_PER_SEC;
    begin_d = clock();
    d = dp(n);
    end_d = clock();
    time_d = (end_d-begin_d)/CLOCKS_PER_SEC;
    cout << "When n = "<<n<<endl;
    cout <<"time between dp and recursion is "<< time_r-time_d<<endl;
}