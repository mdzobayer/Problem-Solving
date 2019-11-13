#include <iostream>

using namespace std;


int main()
{
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	
	int test, t, n, i;
	string s, s1,s2, wd;
	cin>> test;
	while(test--) {
		cin >> n;
        s = "";
		s1 = "";
		s2 = "";
		wd = "";
		bool flag = true;
		for (i = 0; i< n; ++i) {
			cin >> s;
			if (isalpha(s[0]) && flag) {
				wd = s;
				flag = false;
				continue;
			}
			else if (flag){
				if (s1 != "") {
					s1 += " ";
				}
                s1 += s;
			}
			else {
				if (s2 != "") {
					s2 += " ";
				}
				s2 += s;
			}
		}
        //cout << "S1 = " << s1 << endl;
        //cout << "S2 = " << s2 << endl;
        if (s2 == "" && s1 == "") {
            cout << wd << endl;
        }
        else if (wd == "") {
            cout << s1 << endl;
        }
        else {
            if (s2 != "") {
                cout << s2 << " ";
            }

            cout << wd;
            if (s1 != "") {
                cout << " " << s1;
            }
            cout << endl;
        }
		
	}

    return 0;
}