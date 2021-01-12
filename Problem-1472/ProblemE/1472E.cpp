#include <cstdio>
typedef long long ll;

int main()
{
    ll nTests;
    scanf("%lld", &nTests);
    for (ll i = 0; i < nTests; i++)
    {
        ll nValues;

        scanf("%lld", &nValues);

        ll values[nValues][2] = {};

        for (ll j = 0; j < nValues; j++)
        {
            scanf("%lld", &values[j][0]);
            scanf("%lld", &values[j][1]);
        }

        int resultValues[nValues] = {};

        int smallestPerson = 0;
        int smallestPerson2 = 0;

        for (int x = 0; x < nValues; x++)
        {
            if (values[x][0] <= values[smallestPerson][0] && values[x][1] <= values[smallestPerson][1])
            {
                smallestPerson = x;
            }
            if (values[x][0] <= values[smallestPerson2][1] && values[x][1] <= values[smallestPerson2][0])
            {
                smallestPerson2 = x;
            }
        }

        printf("s1: %d s2: %d \n", smallestPerson, smallestPerson2);

        for (int x = 0; x < nValues; x++)
        {
            if (values[x][0] > values[smallestPerson][0] && values[x][1] > values[smallestPerson][1])
            {
                resultValues[x] = smallestPerson + 1;
            }
            else if (values[x][0] > values[smallestPerson2][1] && values[x][1] > values[smallestPerson2][0])
            {
                resultValues[x] = smallestPerson2 + 1;
            }
            else
            {
                resultValues[x] = -1;
            }
        }

        for (int i = 0; i < nValues; i++)
        {
            if (i == nValues - 1)
            {
                printf("%d\n", resultValues[i]);
            }
            else
            {
                printf("%d ", resultValues[i]);
            }
        }
    }
    return 0;
}