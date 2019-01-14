#include <stdio.h>
#include <stdlib.h>

int main()
{
    char decision;
    printf("Are you sure you want to Shutdown (Y/N): ");
    scanf("%c",&decision);

    if(decision == 'y' || decision == 'Y'){
        system("C:\\Windows\\System32\\shutdown /s");
        /*
        To shutdown immediately use
        "C:\\WINDOWS\\System32\\ shutdown /s /t 0"

        For Windows XP
        "C:\\WINDOWS\\System32\\shutdown -s"
        */

        /*
        For Ubuntu
        system("shutdown -P now");
        */
    }
    else
        exit(0);

    return (0);

}
