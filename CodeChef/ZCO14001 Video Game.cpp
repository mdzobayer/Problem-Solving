#include <stdio.h>



int stack[100000+5], crane, H, N, cmd, prePos;
bool craneBox;

void MoveLeft() {
    if (crane > 0) {
        --crane;
    }
}
void MoveRight() {
    if (crane < (N - 1)) {
        ++crane;
    }
}

void PickBox() {
    if (craneBox == false) {
        if (stack[crane] > 0) {
            craneBox = true;
            --stack[crane];
            prePos = crane;
        }
    }
}

void DropBox() {
    if (craneBox == true) {
        if (stack[crane] < H) {
            craneBox = false;
            ++stack[crane];
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    int i;
    scanf("%d %d", &N, &H);
    // Take initial position
    for (i = 0; i < N; ++i) {
        scanf("%d", &stack[i]);
    }
    
    crane = 0;
    craneBox = false;
    prePos = -1;

    // Take command and process
    while(scanf("%d", &cmd) && cmd > 0) {

        if (cmd == 1) {
            MoveLeft();
        }
        else if (cmd == 2) {
            MoveRight();
        }
        else if (cmd == 3) {
            PickBox();
        }
        else if (cmd == 4) {
            DropBox();
        }
    }
    //printf("%d %d\n", craneBox, crane);
    // if (craneBox) {
    //     if (prePos > -1) {
    //         crane = prePos;
    //         DropBox();
    //     }
    // }
    

    // Print final position
    printf("%d", stack[0]);
    for (i = 1; i < N; ++i) {
        printf(" %d", stack[i]);
    }
    puts("");

    return (0);
}