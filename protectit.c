/**************************************************************************
Protectit is a program that will scan through a text file letter by letter*
and then shift the letter according to a given key, Also it will support  *
decryption of files encrypted in the same manner                          *
Made by: Omar E.Rakha for Harvard's CS50 Final project                    *
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int encrypt(char* key, char* filename, char* output);
int decrypt(char* key, char* filename, char* output);
int encrypt2(int key, char* filename, char* output);
int decrypt2(int key, char* filename, char* output);

int main()
{
    printf("Welcome to protectit!\n");
    printf("Please enter filename(FILENAME.txt)\n");
    char* filename = GetString();
    printf("Please enter output file name\n");
    char* output = GetString();
    printf("Would you like to use numbers or strings to encrypt?\n");
    char* type = GetString();
    char* numbers = "numbers";
    char* strings = "strings";
    if(strcmp(type, numbers) == 0)
    {
        printf("Please enter the Encryption/Decryption Key(A Number)\n");
        int key = GetInt();
        printf("Please input 1 for Encryption or 2 for Decryption\n");
        int mode = GetInt();
        //Check for Mode
        if(mode == 1)
        {
            //Start Encryption
                printf("Encrypting.......\n");
            encrypt2(key, filename, output);
            printf("Done encrypting, Please check outfile.txt :)\n");
        }
        else if(mode == 2)
        {
            //Start Decryption
            printf("Decrypting.......\n");
            decrypt2(key, filename, output);
            printf("Done decrypting, Please check outfile.txt :)\n");
          }
          else
          {
          //Yell at user
          printf("Sorry input must either be 1 or 2");
          }

    }
    else if(strcmp(type, strings) == 0)
    {
        printf("Please enter the Encryption/Decryption Key(A Letter or a Word)\n");
        char* key = GetString();
        int klen = strlen(key); //Key length variable
        for(int i = 0; i < klen; i++)
        {
            if(isalpha(key[i]))
            tolower(key[i]);
        }
        printf("Please input 1 for Encryption or 2 for Decryption\n");
        int mode = GetInt();
        //Check for Mode
        if(mode == 1)
        {
            //Start Encryption
            printf("Encrypting.......\n");
            encrypt(key, filename, output);
            printf("Done encrypting, Please check outfile.txt :)\n");
        }
        else if(mode == 2)
        {
            //Start Decryption
            printf("Decrypting.......\n");
            decrypt(key, filename, output);
            printf("Done decrypting, Please check outfile.txt :)\n");
        }
        else
        {
            //Yell at user
            printf("Sorry input must either be 1 or 2");
        }

    }
    else
    {
    //User didn't input (Numbers or Strings)
    printf("Error you should specify either numbers or strings\n");
    return 1;
    }
}

int encrypt(char* key, char* filename, char* output)
{
    FILE* text = fopen(filename, "r");
    FILE* out = fopen(output, "w");
    if(text == NULL)
    return 1;
    int c;
    int length = strlen(key);
    for(int i = 0; i > -1; i++)
    {
        
        int j = (i % length);
        c = fgetc(text);
        if(c == EOF)
        {
            break;
        }
        if(isalpha(key[j]) && isalpha(c))
        {        
            if(isupper(c))
            {
                c = (((c - 'A') + (key[j] - 'A'))% 26) + 'A'; 
            }
            if(islower(c))
            {
                c = (((c - 'a') + (key[j] - 'a')) % 26) +'a';
            }
        }
        fprintf(out, "%c" , c);    
        
    }
    fclose(text);
    fclose(out);
    return 0;
    
    
}
int encrypt2(int key, char* filename, char* output)
{
    FILE* text = fopen(filename, "r");
    FILE* out = fopen(output, "w");
    if(text == NULL)
    return 1;
    int c;
        for(int i = 0; i > -1; i++)
        {
        c = fgetc(text);
        if(c == EOF)
        {
            break;
        }
        if(isalpha(c))
        {        
            if(isupper(c))
            {
                c = (((c - 'A') + key)% 26) + 'A'; 
            }
            if(islower(c))
            {
                c = (((c - 'a') + key) % 26) +'a';
            }
        }
        fprintf(out, "%c" , c);    
        
        }
    fclose(text);
    fclose(out);
        return 0;
    }

int decrypt(char* key, char* filename, char* output)
{
    FILE* text = fopen(filename, "r");
    FILE* out = fopen(output, "w");
    if(text == NULL)
    return 1;
    int c;
    for(int i = 0; i > -1; i++)
    {
        int length = strlen(key);
        int j = (i % length);
        c = fgetc(text);
        if(c == EOF)
        {
            break;
        }
        if(isalpha(key[j]) && isalpha(c))
        {        
            if(isupper(c))
            {
                c = (((c - key[j]) + 26)% 26) + 'A'; 
            }
            if(islower(c))
            {
                c = (((c - key[j]) + 26) % 26) + 'a';
            }
        }
        fprintf(out, "%c" , c);    
        
    }
    fclose(text);
    fclose(out);
    return 0;
    
    
}
int decrypt2(int key, char* filename, char* output)
{

    FILE* text = fopen(filename, "r");
    FILE* out = fopen(output, "w");
    if(text == NULL)
    return 1;
    int c;
    for(int i = 0; i > -1; i++)
    {
        c = fgetc(text);
        if(c == EOF)
        {
            break;
        }
        if(isalpha(c))
        {        
            if(isupper(c))
            {
                c = (((c - 'A') - key + 26)% 26) + 'A'; 
            }
            if(islower(c))
            {
                c = (((c - 'a') - key + 26) % 26) + 'a';
            }
        }
        fprintf(out, "%c" , c);    
        
    }
    fclose(text);
    fclose(out);
    return 0;    
}

