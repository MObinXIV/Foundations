// Using functional way to print sum
#include <bits/stdc++.h>
using namespace std;
/*
func(5)
/
func(5)-> return 5+func(4)(10)->15
/
func(4)->return 4 +func(3)(6)->10
/
func(3)->return 3+func(2)(3)->6
/
func(2)->return 2+func(1)(1) ->3
/
 func(1)->return 1+func(0)(0) -> 1
/
func(0) return 0
*/
int func(int n) // 5
{
    if(n==0)
    return 0;

    return n+func(n-1);
}
int fact(int n){
    if(n==1)
    return 1;

    return n*fact(n-1);
}
int main()
{
    cout<<fact(5)<<endl;
}