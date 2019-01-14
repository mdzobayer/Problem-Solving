#include <cstdio>

int main()
{
    int n, ballRemain, ballPlayed, opponentRun, currentRun;
    double currentRunRate, askingRunRate;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &opponentRun, &currentRun, &ballRemain);
        ballPlayed = 300 - ballRemain;
        currentRunRate = ((double)currentRun / ballPlayed) * 6;
        askingRunRate = ((((double)opponentRun - currentRun) + 1) / ballRemain ) * 6;

        printf("%0.2lf %0.2lf\n",currentRunRate, askingRunRate);
    }

    return (0);
}
