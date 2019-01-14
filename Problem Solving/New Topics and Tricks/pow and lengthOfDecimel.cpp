long long int pow(int x, int y) {
    long long int result = x;
    for (int i = 1; i < y; ++i) {
        result *= x;
    }
    return result;
}
int length(long long int n) {
    int len = 0;
    if (n < 0) n *= (-1);
    while(n > 0) {
        ++len;
        n /= 10;
    }
    return len;
}
