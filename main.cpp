//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator + (Complex x, Complex y) {
    string concatNum = "";
    int num1 = 0;
    int num2 = 0;
    int newNum = 0;
    int imaginary1 = 0;
    int imaginary2 = 0;
    int newImaginary = 0;
    Complex newComplex;

    num1 = x.a;
    num2 = y.a;
    newNum = num1 + num2;
    imaginary1 = x.b;
    imaginary2 = y.b;
    newImaginary = imaginary1 + imaginary2;
    newComplex.a = newNum;
    newComplex.b = newImaginary;

    return newComplex;
}

ostream& operator << (ostream& os, Complex summedComplex) {
    int realNum = 0;
    int imaginaryNum = 0;
    realNum = summedComplex.a;
    imaginaryNum = summedComplex.b;
    os << realNum << "+i" << imaginaryNum;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
