#include <iostream>
#include <stdlib.h>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

int main()
{

    int *ptr;
    char *ch;
    float *ft;
    double *db;
    struct rectangle *p;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(ch)<<endl;
    cout<<sizeof(ft)<<endl;
    cout<<sizeof(db)<<endl;
    cout<<sizeof(p)<<endl;

    return 0;
}