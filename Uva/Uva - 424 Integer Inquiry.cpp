#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

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
    FastRead

    //fRead("in.txt");

    string sum, temp;
    sum = "0";
    while(cin >> temp) {

        if (temp == "0") {
            printf("%s\n", sum.c_str());
            break;
        }
        if (temp.size() > sum.size())
            sum = add(temp, sum);
        else
            sum = add(sum, temp);
    }

    return (0);
}
