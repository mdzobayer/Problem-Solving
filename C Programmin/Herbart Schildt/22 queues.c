#include <stdio.h>

#define MAX 100

char queue[MAX];
int spos = 0;
int rpos = 0;

void qStore(char value)
{
    if(spos == MAX) {
        printf("List is Full\n");
        return;
    }
    queue[spos] = value;
    spos++;
}

char qRetrieve() {
    if(rpos == spos) {
        printf("No more appointment.\n");
        return '\0';
    }
    rpos++;
    return queue[rpos - 1];
}
void showQueue() {
    if(rpos == spos) {
        printf("No more appointment.\n");
        return ;
    }
    for (int i = rpos; i <= spos; i++) {
        printf("%c\n",queue[i]);
    }
}


int main() {

    showQueue();
    qStore('Z');
    qStore('o');
    qStore('b');
    qStore('a');
    qStore('y');
    qStore('e');
    qStore('r');
    showQueue();
    qRetrieve();
    qRetrieve();
    showQueue();

    return (0);
}
