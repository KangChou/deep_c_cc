#include "dllfunc.h"
#include "static.h"

int main(void)
{
    printf("Main function\n");
    dllfunc();
    staticfunc();
    return 0;
}