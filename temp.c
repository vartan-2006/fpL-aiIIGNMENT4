#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int compare(char* str1, char** str2);
char * replace(char *s, char match, char repChar);
char *trim(char *s);
char *rtrim(char *s);
char *ltrim(char *s);
int matchIndex=0;
int main() 
{
    int tr,v,d=0,k=0;
    char* Name,DIV[20],*Name2;
    char* Name1[]={"Ved Panchwadkar","Sumegh Bhamre","Tanish Moro","Akansha Dhage"};
    //printf("String 1 : %s\n", Name1[3]);
    printf("Enter your full Name : ");
    fgets(Name,60, stdin);
    Name[strcspn(Name,"\n")]='\0';
    if (strlen(Name)>50)
    {
       printf("Error:entered name exceeds the maximum no. of characters");
       return 0;
    }
        //printf("Before Compare\n");
        tr=compare(Name,Name1);
        //printf("Index %d\n", matchIndex);
        if (tr==1)
        {
          printf("Entered name is correct\n");
        }
        else if (tr==0)
        {
            printf("Entered name is incorrect");
            return 0;
        }
    printf("Enter your DIV:");
    fgets(DIV,20, stdin);
    printf("Your name is %s\n",Name);
    Name2=replace(Name,' ','_');
    //printf("Name is %s\n",Name2);
    printf("Your Div is %s\n",DIV);
    //char* rollprefix = itoa(matchIndex,DIV,matchIndex);
    //DIV=strcat(DIV,itoa(matchIndex));
    //printf("Your pre no. is B24%s",rollprefix);
    DIV[strcspn(DIV,"\n")]='\0';
    printf("Your roll no. is B24%s0%d\n",DIV,matchIndex+1);
    //printf("%s", Name2[50]);
    printf("Your e-mail is\n%s2024@mmcoe.edu.in",Name2);
    return 0;   
}

int compare(char* str1, char** str2)
{
    // Iterating through the characters of both the strings
    //printf("Here");
    //printf("str1 %s\n", &str1);
    //printf("str2 %s\n", &str2[0]);
    //printf("Post");
    for (matchIndex=0;matchIndex<4; matchIndex++)
    {
      //  printf("str2 length %d\n", strlen(str2[matchIndex]));
      //  printf("str2  %s\n", str2[matchIndex]);
        /* code */
        char* str3 = str2[matchIndex];
       // printf("str3  %s\n", str3);
        while (*str1 == *str3) 
        {
        //    printf("Inside While str1 = %c  str2= %c\n", *str1,*str3);
            if (*str1 == '\0' || *str3 == '\0')
            {
                //printf("Match Found");
                return 1;
            }
            str1++;
            str3++;
          //  printf("end While str1 = %c  str2= %c\n", *str1,*str3);
        }
    }
    return 0;
}

 char * replace(char *s, char match, char repChar)
{
    int i=0;
    char* str1;
    //printf("s length %d\n", strlen(s));
    for (i = 0;i<strlen(s); i++)
    {
        //printf("s i %c\n", s[i]);
        if (s[i]==' ')
        {
            str1[i]=repChar;
        }
        else if (s[i]=='\0')
        {
            str1[i]='\0';
            break;
        } 
        else 
        {
            str1[i]=s[i];
            //printf("s i %c\n", s[i]);
            //printf("str1 i %c\n", str1[i]);
        }
        
    }
    //printf("email %s\n", str1);
    return str1;
}

 char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}