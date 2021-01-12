#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;

int main()
{
    ll nTests;
    scanf("%lld", &nTests);
    for (ll i = 0; i < nTests; i++)
    {
        ll nValues;
        scanf("%lld", &nValues);
        std::vector<ll> values(nValues);
        for (ll j = 0; j < nValues; j++)
        {
            scanf("%lld", &values[j]);
        }
        ll scoreAlice = 0;
        ll scoreBob = 0;
        std::sort(values.begin(), values.end());

        int turn = 0;
        for (ll x = nValues - 1; x >= 0; x--)
        {
            if (turn == 0)
            {
                if (values[x] % 2 == 0)
                {
                    scoreAlice += values[x];
                }
                turn = 1;
            }
            else
            {
                if (values[x] % 2 != 0)
                {
                    scoreBob += values[x];
                }
                turn = 0;
            }
        }

        if (scoreAlice < scoreBob)
        {
            printf("Bob");
        }
        else if (scoreBob < scoreAlice)
        {
            printf("Alice");
        }
        else
        {
            printf("Tie");
        }
        printf("\n");
    }
    return 0;
}