//to convert a decimal number to binary (without using string)
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,bit,ans=0,exp=0;
    cout<<"Enter a Decimal number:";
    cin>>n;
    while(n!=0)
    {
        bit=n&1;
        ans+=(bit*pow(10,exp));
        exp++;
        n=n>>1;
    }//end of while loop
    cout<<"The Binary equivalent of the given Decimal number is as follows:"<<ans<<endl;
    return 0;
}//end of main