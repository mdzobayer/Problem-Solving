    #include <stdio.h>

    int main(int argc, char *argv[])
    {
        char pszRequest[1000]= {0};
        char pszResourcePath[]="api/user.info?handles=DmitriyH";
        char pszHostAddress[]="https://codeforces.com";
        sprintf(pszRequest, "GET /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: text/plain\r\n\r\n", pszResourcePath, pszHostAddress);
        printf("Created Get Request is below:\n\n\n");
        printf("Result: %s", pszRequest);
        return 0;
    }