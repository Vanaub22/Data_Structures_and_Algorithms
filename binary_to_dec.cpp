//to convert a binary number to decimal
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,ans=0,bit,exp=0;
    cout<<"Enter a Binary Number:";
    cin>>n;
    while(n!=0)
    {
        bit=n%10;
        ans+=(bit*pow(2,exp));
        n/=10;
        exp++;
    }//end of while loop
    cout<<"The Decimal equivalent of the given Binary number is as follows: "<<ans<<endl;
    return 0;
}//end of main