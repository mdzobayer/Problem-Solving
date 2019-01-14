#include <stdio.h>
#include <stdlib.h>

int main()
{
    char decision;
    printf("Are you sure ? you want to Reboot (Y/N): ");
    scanf("%c",&decision);

    if(decision == 'y' || decision == 'Y'){
        system("C:\\Windows\\System32\\shutdown /r");
        /*
        To shutdown immediately use
        "C:\\WINDOWS\\System32\\ shutdown /r /t 0"
        */

        /*
        For Windows XP
        "C:\\WINDOWS\\System32\\shutdown -r"
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
