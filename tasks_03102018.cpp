#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
//can't do spiral and squares for ****
int power(int base, unsigned int exponent) //works
{ //unsigned for exponent since negative exponents produce floating point numbers
    if(exponent==0) //since anything to 0th power is 1
        return 1;
    else
        return base*power(base, exponent - 1); // x times 1 is x, x times x is x squared etc.
}
bool is_palindrome(string word)//works
{
    if(word.size()==1)//since a letter is always the same as itself
    {
        return true;
    }
    else if(word.size()==2)//function truncates a string by 2 chars, so number of chars will never change from even to odd
    {
        if(word[0]==word[1])
            return true;
        else return false;
    }
    else
    {
        string support = word.substr(1,word.size()-2);
        if(word[0]==word[word.size()-1])
            return is_palindrome(support);
        else
            return false;
    }
}
void print_asterisks(int n)//works
{//don't think it needs an explanation
    if(n>0)
    {
        cout<<"*";
        print_asterisks(n-1);
    }
}
double horners_method(vector<double> args, double b, double c)//works? did I do it right?
{//P(x)=a0*x^n+...+an*x^0; return P(b); c is just there for support
    c = c*b+args[1];
    args.erase(args.begin());
    if(args.size()==1)
    {
        return c;
    }
    else
    {
        return horners_method(args, b, c);
    }
}
int euclidean_algorithm(int a, int b)//works
{//euclidean algorithm, look it up
    if(a==0)
    {
        return b;
    }
    else if(b==0)
    {
        return a;
    }
    else
    {
        if(a>b)
        {
            a-=b;
        }
        else
        {
            b-=a;
        }
        return euclidean_algorithm(a,b);
    }

}
int main(void)
{
    vector<double> args;
    args.push_back(1);
    args.push_back(4);
    args.push_back(3);
    args.push_back(7);
    args.push_back(2);
    //cout<<power(2,10);
    //cout<<is_palindrome("kajak");
    //cout<<print_asterisks(5);
    //cout<<horners_method(args, 3, args[0]);
    cout<<euclidean_algorithm(252,147);
	return 0;
}
