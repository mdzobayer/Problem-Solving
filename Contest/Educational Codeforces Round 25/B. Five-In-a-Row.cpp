#include <cstdio>

char str[10][10];

int left (int i, int j) {
    int count = 0;
    for (--j; j >= 0; --j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int right (int i, int j) {
    int count = 0;
    for (++j; j < 10; ++j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int top (int i, int j) {
    int count = 0;
    for (--i; i >= 0; --i) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int down (int i, int j) {
    int count = 0;
    for (++i; i < 10; ++i) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}

int topLeft(int i, int j) {
    int count = 0;
    for (--i, --j; i >= 0 && j >= 0; --i, --j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int bottomRight(int i, int j) {
    int count = 0;
    for (++i, ++j; i < 10 && j < 10; ++i, ++j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int topRight(int i, int j) {
    int count = 0;
    for (--i, ++j; i >= 0 && j < 10; --i, ++j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}
int bottomLeft(int i, int j) {
    int count = 0;
    for (++i, --j; i < 10 && j >= 0; ++i, --j) {
        if (str[i][j] == 'X') {
            count++;
        }
        else {
            return count;
        }
    }
    return count;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int i, j, count;
    bool flag = false;

    for ( i = 0; i < 10; ++i) {
        gets(str[i]);
    }
    for ( i = 0; i < 10; ++i) {
        for ( j = 0; j < 10; ++j) {
            if (str[i][j] == '.') {
                count = 0;
                //printf("%d %d\n", i, j);
                if (left(i,j) + right(i, j) >= 4) {
                    printf("YES\n");
                    flag = true;
                    return (0);
                }
                else if (top(i,j) + down(i, j) >= 4) {
                    printf("YES\n");
                    flag = true;
                    return (0);
                }
                else if (topLeft(i,j) + bottomRight(i, j) >= 4) {
                    printf("YES\n");
                    flag = true;
                    return (0);
                }
                else if (bottomLeft(i,j) + topRight(i, j) >= 4) {
                    printf("YES\n");
                    flag = true;
                    return (0);
                }
            }
        }
    }
    if (flag == false) {
        printf("NO\n");
    }

    return (0);
}
