/*
String Matching
    for 0 to n-m do
        j=0
        while j<m and p[i]=t[i+j]
            j=j+1
        if j=m return i
    return -1
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char p[100], t[100];
    printf("ENter the string:\n");
    fgets(t);
    printf("Enter the pattern:\n");
    fgets(p);
    int s = stringMatch(t, p);
    if (s != -1)
        printf("The position is %d", s);
    else
        printf("Not found");
}
int stringMatch(char t[], char p[])
{
    int i, j, m, n;
    n = strlen(t);
    m = strlen(p);
    for (i = 0; i < n - m; i++)
    {
        j = 0;
        while (j < m && p[i] == t[i + j])
        {
            j = j + 1;
        }
        if (j == m)
            return i;
    }
    return -1;
}