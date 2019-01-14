#include <cstdio>
#include <iostream>
#include <vector>


std::string rev(const std::string & a){
    int i, j;
    std::string b = "";
    for(i = 0,j = a.length() - 1; i < a.length(); i++, j--)
        b += a[j];

    return b;
}
std::string add(std::string e, std::string f){
    int i, j, x, y, sum, s;
    std::string c = "";
    std::string a, b, d;
    int temp = 0;
    a = rev(e);
    b = rev(f);
    for(i = 0; i < a.length(); i++)
    {
        if(i < b.length())
        {
            x = a[i] - '0';
            y = b[i] - '0';
            sum = x + y + temp;
            s = sum % 10;
            c += s + '0';
            temp = 0;
            if(sum > 9) temp = 1;
            if(i == a.length()-1 && temp==1)
                c+='1';
        }
        else {
            x = a[i]-'0';
            sum = temp+x;
            s = sum % 10;
            c += s + '0';
            temp = 0;
            if(sum > 9) temp = 1;
            if(i == a.length() - 1 && temp == 1)
                c += '1';
        }
    }
    d = rev(c);
    return d;
}


int main() {
    int n;
    std::vector<std::string> fibonacci;
    fibonacci.push_back("0");
    fibonacci.push_back("1");
    for (int i = 2; i <= 5000; i++) {
        fibonacci.push_back(add(fibonacci[i - 1], fibonacci[i - 2]));
    }
    while(scanf("%d", &n) == 1) {
        printf("The Fibonacci number for %d is %s\n", n, fibonacci[n].c_str());
    }

    return (0);
}
