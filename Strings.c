#include <stdio.h>

int strlength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}
char *strconcat(char concatstr[], char str2[])
{
    int length = strlength(concatstr);
    int i = 0;
    while (str2[i] != '\0')
    {
        concatstr[length + i] = str2[i];
        i++;
    }
    concatstr[length + i] = '\0';
    return concatstr;
}
char *strcopy(char str1[], char str2[])
{
    int i = 0;
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return str1;
}
int strcomp(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}
char *strrev(char reversestr[])
{
    int length = strlength(reversestr);
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = reversestr[start];
        reversestr[start] = reversestr[end];
        reversestr[end] = temp;
        start++;
        end--;
    }
    return reversestr;
}
void removeNewline(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
    }
}
int main()
{
    int choice;
    char str1[51];
    char str2[51];
    printf("Enter string 1:\n");
    fgets(str1, sizeof(str1), stdin);
    removeNewline(str1);

    printf("Enter string 2:\n");
    fgets(str2, sizeof(str2), stdin);
    removeNewline(str2);

    printf("Length of string 1 is: %d\n", strlength(str1));
    printf("Length of string 2 is: %d\n", strlength(str2));

    char concatstr[200];
    strcopy(concatstr, str1);
    printf("String after concatenation: %s\n", strconcat(concatstr, str2));

    printf("String after copy is: %s\n", strcopy(str1, str2));

    int result = strcomp(str1, str2);
    if (result == 0)
        printf("Both strings are equal\n");
    else if (result < 0)
        printf("String 2 is greater than string 1\n");
    else
        printf("String 1 is greater than string 2\n");

    char reversestr[200];
    strcopy(reversestr, str1); 
    printf("The reverse of string is: %s\n", strrev(reversestr));

    return 0;
}