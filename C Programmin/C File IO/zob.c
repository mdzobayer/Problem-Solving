#include <stdio.h>
#include <stdlib.h>

int main(void){
    int ch;
    FILE *pt;
    pt=fopen("c:/Users/Zobayer/Desktop/zuobayer.html","w");

    fprintf(pt,"<html>\n");
    fprintf(pt,"<title>\n");
    fprintf(pt,"This is Programming World\n");
    fprintf(pt,"</title>\n");
    fprintf(pt,"<body>\n");
    fprintf(pt,"<h1>\n");
    fprintf(pt,"You are welcome here.\n");
    fprintf(pt,"</h1>\n");
    fprintf(pt,"</body>\n");
    fprintf(pt,"</html>\n");
    fclose(pt);

    return EXIT_SUCCESS;
}
