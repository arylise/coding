#include <queue>
#include <iostream>

int *_merge(int *a, int lenthA, int *b, int lenthB)
{
    int ai = 0;
    int bi = 0;
    std::queue<int> queue;

    while (ai < lenthA && bi < lenthB)
    {
        queue.push(a[ai] < b[bi] ? a[ai++] : b[bi++]);
    }

    while (ai < lenthA)
    {
        queue.push(a[ai++]);
    }
    while (bi < lenthB)
    {
        queue.push(b[bi++]);
    }

    int *c = new int[lenthA + lenthB];
    int ci = 0;

    while (!queue.empty())
    {
        c[ci++] = queue.front();
        queue.pop();
    }
    return c;
}

int main()
{
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    int *c=_merge(a,5,b,5);
    for(int i=0;i<10;i++){
        std::cout<<c[i]<<std::endl;
    }
    return 0;
}

