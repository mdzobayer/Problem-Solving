#include <cstdio>
#include <cstring>

struct player {
public:
    int attack;
    int defend;
    char name[128];
};

void swap(player &t1, player &t2) {
    struct player temp = t1;
    t1 = t2;
    t2 = temp;
}

int main() {

    int t, testCase, i, j;
    struct player players[15], temp;

    scanf("%d", &testCase);

    for (t = 1; t <= testCase; ++t) {

        for (i = 0; i < 10; ++i){
            scanf("%s %d %d", &players[i].name, &players[i].attack, &players[i].defend);
            getchar();
        }
        for (i = 0; i < 9; ++i) {
            for (j = i + 1; j < 10; ++j) {
                if (players[i].attack < players[j].attack) {
                    swap(players[i], players[j]);
                }
                else if (players[i].attack == players[j].attack) {
                    if (players[i].defend > players[j].defend) {
                        swap(players[i], players[j]);
                    }
                    else if (players[i].defend == players[j].defend) {
                        if (strcmp(players[i].name, players[j].name) > 0) {
                            swap(players[i], players[j]);
                        }
                    }
                }
            }
        }

        for (i = 0; i < 4; ++i) {
            for (j = i + 1; j < 5; ++j) {
                if (strcmp(players[i].name, players[j].name) > 0) {
                    swap(players[i], players[j]);
                }
            }
        }
        for (i = 5; i < 9; ++i) {
            for (j = i + 1; j < 10; ++j) {
                if (strcmp(players[i].name, players[j].name) > 0) {
                    swap(players[i], players[j]);
                }
            }
        }
        printf("Case %d:\n", t);
        printf("(");
        for (i = 0; i < 5; ++i) {
            printf("%s", players[i].name);
            if (i < 4) printf(", ");
        }
        printf(")\n");
        printf("(");
        for ( i = 5 ; i < 10; ++i) {
            printf("%s", players[i].name);
            if (i < 9) printf(", ");
        }
        printf(")\n");
    }
    return (0);
}
