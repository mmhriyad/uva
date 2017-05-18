#include <stdio.h>

#define MAXN 20000

typedef struct
{
    double num1;
    double num2;
    double num3;
    double sum;
}stdnt;

stdnt s[MAXN];
int rank[MAXN], n;

#define GETMAX(x, y) (x>y ? x : y)

double getsum(double csum, int i, bool allow_equal)
{
    double m = 0;
    double m1 = s[i].sum - s[i].num1;
    double m2 = s[i].sum - s[i].num2;
    double m3 = s[i].sum - s[i].num3;

    double m12 = s[i].sum - s[i].num1 - s[i].num2;
    double m13 = s[i].sum - s[i].num1 - s[i].num3;
    double m23 = s[i].sum - s[i].num2 - s[i].num3;

    if(allow_equal)
    {
        if(m1 <= csum)
            m = GETMAX(m, m1);
        if(m2 <= csum)
            m = GETMAX(m, m2);
        if(m3 <= csum)
            m = GETMAX(m, m3);

        if(m12 <= csum)
            m = GETMAX(m, m12);
        if(m13 <= csum)
            m = GETMAX(m, m13);
        if(m23 <= csum)
            m = GETMAX(m, m23);
    }
    else
    {
        if(m1 < csum)
            m = GETMAX(m, m1);
        if(m2 < csum)
            m = GETMAX(m, m2);
        if(m3 < csum)
            m = GETMAX(m, m3);

        if(m12 < csum)
            m = GETMAX(m, m12);
        if(m13 < csum)
            m = GETMAX(m, m13);
        if(m23 < csum)
            m = GETMAX(m, m23);
    }
    

    s[i].sum = m;

    return m;
}

double findmax()
{
    double msum, nsum;
    int nr, cr = rank[1], i;
    msum = s[cr].sum;

    for(i=2; i<=n; i++)
    {
        nr = rank[i];
        if(cr > nr) //sum must greater than
        {
            if(msum == 0)
                return -1;
            if(s[nr].sum < msum)
            {
                msum = s[nr].sum;
            }
            else
            {
                msum = getsum(msum, nr, false);
            }
        }
        else
        {
            if(msum == 0)
                s[nr].sum = 0;
            else if(msum < s[nr].sum)
            {
                msum = getsum(msum, nr, true);
            }
            else
                msum = s[nr].sum;
        }
        cr = nr;
    }

    return msum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int i, T=1;
    double sum;
    while(scanf("%d", &n) == 1 && n)
    {
        //scanf("%d", &n);
        if(n == 0)
            return 0;

        for(i=1; i<=n; i++)
        {
            scanf("%lf %lf %lf", &s[i].num1, &s[i].num2, &s[i].num3);
            s[i].sum = s[i].num1 + s[i].num2 + s[i].num3;
        }

        for(i=1; i<=n; i++)
            scanf("%d", &rank[i]);

        printf("Case %d: ", T++);
        sum = findmax();
        if(sum < 0)
            printf("No solution\n");
        else
            printf("%.2lf\n", sum);
    }
}

 