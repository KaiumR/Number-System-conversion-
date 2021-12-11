#include<bits/stdc++.h>
using namespace std;
int hexadecimalToDecimal(string n){
    int lastChar;
    int power=0, result=0, initial=n.size()-1;

    while(n[initial]){
        if(n[initial]>='A' && n[initial]<='F'){
            lastChar=n[initial]-'A' + 10;
        }
        else{
            lastChar = n[initial]-'0';
        }

        result += lastChar*pow(16,power);
        power++;
        initial--;
    }

    return result;
}
string decimalTohHexadecimal(int n){
    int x=1;
    string ans = "";

    while(x<=n)
        x*=16;
    x/=16;

    while(x>0){
        int lastDigit = n/x;
        n-=lastDigit*x;
        x/=16;

        if(lastDigit<=9)
            ans = ans + to_string(lastDigit);
        else{
            char c = 'A'+lastDigit-10;
            ans.push_back(c);
        }
    }
    return ans;
}
int decimalToOctal(int n){
    int base=1,  result=0;

    while(base<=n)
        base*=8;
    base/=8;

    while(base>0){
        int lastDigit = n/base;
        n -=lastDigit*base;
        base/=8;
        result = result* 10 + lastDigit;
    }
    return result;
}
int octalToDecimal(int n){
    int lastDigit, power=0, result=0;

    while(n>0){
        lastDigit = n%10;
        result = result+ (lastDigit*pow(8,power));
        n/=10;
        power++;
    }
    return result;
}
int decimalToBinary(int n){
    //There are two way to solve this problem
    //both have time complexity o(n)
    //Second solution based on "reverse the number" solution.
    int base=1, number=0, reverse=0;

    while(base<=n)
        base*=2;
    base/=2;

    while(base>0){
        int lastDigit = n/base;
        n -=lastDigit*base;
        base/=2;
        reverse = reverse* 10 + lastDigit;
    }

    /*while(n>0){
        int lastDig = n%2;
        number = number*10 + lastDig;
        n/=2;
    }
    while(number>0){
        int lastDigit= number%10;
        reverse = reverse*10 + lastDigit;
        number/=10;
    }*/
    return reverse;
}
int binaryToDecimal(int n){
    int lastDigit, power=0, result=0;

    while(n>0){
        lastDigit = n%10;
        result = result+ (lastDigit*pow(2,power));
        n/=10;
        power++;
    }
    return result;
}

int addBinary(int a, int b){
    int x, y, z;
    x=BinaryToDecimal(a);
    y=BinaryToDecimal(b);

    z=x+y;

    return DecimalToBinary(z);
}
int reverseNumber(int n){
    int lastDig, reverse=0;

    while(n>0){
        lastDig = n%10;
        reverse = reverse*10+ lastDig;
        n/=10;
    }
    return reverse;
}
int main(){
    int num, num2;
    cin>>num>>num2;
    //int result = octalToDecimal(num);
    


    cout<<addBinary(num, num2)<<endl;
}
