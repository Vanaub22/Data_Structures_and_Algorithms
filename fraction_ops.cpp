#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef struct {
        bool sign; // true for positive, false otherwise
        int numerator,denominator;
    } rational;
    void init_rational(rational& x, string fraction) {
        x.sign=fraction[0]=='+';
        int i=fraction.find('/'),n=fraction.length();
        x.numerator=stoi(fraction.substr(1,i-1));
        x.denominator=stoi(fraction.substr(i+1));
        // cout<<x.numerator<<endl;
        // cout<<x.denominator<<endl;
    }
    string fractionAddition(string exp) {
        if(exp[0]!='+' && exp[0]!='-') exp='+'+exp;
        int n=exp.length(),start=0;
        vector<rational> rational_arr;
        for(int i=1;i<n;i++) if(exp[i]=='+' || exp[i]=='-') {
            string fraction=exp.substr(start,i-start);
            // cout<<fraction<<endl;
            rational rat_no;
            init_rational(rat_no,fraction);
            rational_arr.emplace_back(rat_no);
            start=i;
        }
        rational rat_no;
        init_rational(rat_no,exp.substr(start));
        // cout<<exp.substr(start)<<endl;
        rational_arr.emplace_back(rat_no);
        for(auto rat:rational_arr) {
            cout<<rat.numerator<<" "<<rat.denominator<<" "<<rat.sign<<endl;
        }
        rational result;
        result.denominator=1,result.numerator=0;
        denom_lcm_convert(rational_arr);
                for(auto rat:rational_arr) {
            cout<<rat.numerator<<" "<<rat.denominator<<" "<<rat.sign<<endl;
        }
        for(auto& i:rational_arr) {
            if(i.sign) result.numerator+=i.numerator;
            else result.numerator-=i.denominator;
            result.sign=result.numerator>=0;
        }
        make_irreducible(result);
        return to_string(result.numerator)+"/"+to_string(result.denominator);
    }
    void make_irreducible(rational& x) {
        int gcd=hcf(x.numerator,x.denominator);
        x.numerator/=gcd;
        x.denominator/=gcd;
    }
    int hcf(int a, int b) {
        a=abs(b),b=abs(b);
        return b%a==0?a:hcf(b%a,a);
    }
    int lcm(int a, int b) {
        return (a*b)/hcf(a,b);
    }
    void denom_lcm_convert(vector<rational>& arr) {
        int multiple=1;
        for(auto& i:arr) multiple=lcm(multiple,i.denominator);
        for(auto& i:arr) {
            i.numerator*=(multiple/i.denominator);
            i.denominator=multiple;
        }
    }
};
    int main() {
        Solution* obj=new Solution();
        string str="1/2-4/1+33/2-7/15";
        // cout<<"Enter a valid fraction string: ";
        // cin>>str;
        cout<<obj->fractionAddition(str)<<endl;
        return 0;
    } // end of main