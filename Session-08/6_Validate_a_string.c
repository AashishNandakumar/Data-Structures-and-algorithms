#include <stdio.h>
// #include <regex.h>


int valid(char *name)  // normal method
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 65 && name[i] <= 90) && !(name[i] >= 97 && name[i] <= 122) && !(name[i] >= 48 && name[i] <= 57))
            return 0;
    }
    return 1;
}



int main()
{
    char *name = "Anil?321"; // is invalid -> want only no and alphabets
    if (valid(name))
        printf("A valid String");
    else
        printf("Not a vaalid string!!!!");
}