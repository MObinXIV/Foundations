/*     #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

*/

#include <iostream>
using namespace std;

void space (int &k){
    while (k > 0)
        cout << " ", k--;
}

void print(int c){
    for (int j = 0; j < c; j++)
        cout << "#";
}
int main()
{
    int n ; 
    do
    {
        cout<<"Please, enter a number between 1->8\n";
        cin>>n;}while(n<=0 ||n>8);

    
        int i = n;
    for (; i>0;i--)
    {
        int k = i-1;
        int c = n-k;
        space(k);
       
        print(c);
        cout<<" "<<" ";
        k=i-1;
    
        print(c);

        space(k);
        cout << endl;
    }
}