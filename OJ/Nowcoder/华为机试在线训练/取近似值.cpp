#include <iostream>
using namespace std;

int main()
{
    double input;
    
    while (scanf("%lf", &input) != EOF)
        printf("%d\n", static_cast<int>(input + 0.5));
    
    return 0;
}