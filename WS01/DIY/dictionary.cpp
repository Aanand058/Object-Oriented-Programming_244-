/*
*****************************************************************************
                              Workshop - 1 (DIY)
Full Name  : Aanand Aman
Student ID: 166125211
Email      : aaman8@myseneca.ca

Speaking Honestly, This part was very hard for me to understand, This work is not completly wine, some friends and classmates helped me to learn this code work. 
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "dictionary.h"
#include "word.h"

using namespace std;

namespace sdds
{
    dictionary mainDict1;
    char endLine = '\n';
    char *lastTxt = &endLine;

    int LoadDictionary(const char *filename)
    {
        dictionary dict2 = {0, 0};
        int wordCount = 0;
        int defCount = 0;
        FILE *fp = NULL;
        fp = fopen(filename, "r");
        char wordRead[MAX_WORD_CHAR];
        char defRead[MAX_WORD_DEF_TXT];
        if (fp != NULL)
        {
            while (fgets(wordRead, MAX_WORD_CHAR, fp) != NULL)
            {
                int i = 0;
                int flagW = 0;
                int flagD = 0;
                defCount = 0;
                while (flagW == 0) //storing the words in struct 
                {
                    if (wordRead[i] == '\n')
                    {
                        wordRead[i] = '\0';
                        flagW = 1;
                    }
                    i++;
                }
                strcpy(dict2.wordStruct[wordCount].word, wordRead);
                i = 0;
                while (flagD == 0) 
                {
                    char defi[MAX_WORD_CHAR] = {0};
                    char defi2[MAX_WORD_CHAR] = {0};

                    int eof = 0;
                    if (fgets(defRead, MAX_WORD_DEF_TXT, fp) == NULL)
                    {
                        eof = 1;
                    }
                    if (defRead[0] == '\n' || eof == 1) 
                    {
                        flagD = 1;
                    }
                    else
                    {
                        defCount++;
                        char *column = strchr(defRead, ':');
                        strcpy(dict2.wordStruct[wordCount].definition[defCount], (column + 2));
                        strncpy(defi, defRead, int(column - defRead));
                        int flag2 = 0;
                        int j = 0;
                        int k = 0;
                        while (flag2 == 0)
                        {
                            if (defi[j] != '\t')
                            {
                                defi2[k] = defi[j];
                                k++;
                            }
                            j++;
                            if (defi[j] == '\0')
                            {
                                flag2 = 1;
                            }
                        }
                        strcpy(dict2.wordStruct[wordCount].defType[defCount], defi2);
                    }
                }
                dict2.wordStruct[wordCount].noOfDef = defCount;
                dict2.noOfWords = wordCount;
                wordCount++;
            }
            fclose(fp);
            mainDict1 = dict2;
            return 0;
        }
        mainDict1 = dict2;
        return 1;
    }

    void SaveDictionary(const char *filename)
    {
        FILE *fp2 = NULL;
        fp2 = fopen(filename, "w");
        int i = 0;
        int j = 0;
        int totalWords = mainDict1.noOfWords;
        for (i = 0; i < totalWords; i++)
        {
            fputs(mainDict1.wordStruct[i].word, fp2);
            fputc('\n', fp2);

            int totalDef = mainDict1.wordStruct[i].noOfDef;
            for (j = 1; j <= totalDef; j++)
            {
                fputc('\t', fp2);
                fputs(mainDict1.wordStruct[i].defType[j], fp2);
                fputc(':', fp2);
                fputc(' ', fp2);
                fputs(mainDict1.wordStruct[i].definition[j], fp2);
            }
            fputc('\n', fp2);
        }
        fclose(fp2);
    }

    int UpdateDefinition(const char *word, const char *type, const char *definition)
    {
        int flag = 0;
        int i = 0;
        for (i = 0; flag == 0; i++)
        {
            if (i == mainDict1.noOfWords)
            {
                flag = 1;
            }
            if (strcmp(mainDict1.wordStruct[i].word, word) == 0)
            {
                if (mainDict1.wordStruct[i].noOfDef > 1)
                {
                    cout << "The word [" << word << "] has multiple definitions:\n";

                    int count = 1;
                    int j = 0;

                    for (j = 1; j <= mainDict1.wordStruct[i].noOfDef; j++)
                    {
                        cout << count << ". {" << mainDict1.wordStruct[i].defType[j] << "} " << mainDict1.wordStruct[i].definition[j];
                        count++;
                    }
                    int input;
                    
                    cout << "Which one to update? ";
                    cin >> input;
                    strcpy(mainDict1.wordStruct[i].defType[input], type);
                    strcpy(mainDict1.wordStruct[i].definition[input], definition);
                    strcat(mainDict1.wordStruct[i].definition[input], lastTxt);
                }
                flag = 1;
            }
        }
        return 0;
    }

    void Printing(const char *word)
    {
        int flag = 0;
        int i = 0;
        for (i = 0; flag == 0; i++)
        {
            if (strcmp(mainDict1.wordStruct[i].word, word) == 0)
            {
                cout << "FOUND: [" << word << "] has [" << mainDict1.wordStruct[i].noOfDef << "] definitions:\n";
                int count = 1;
                int j = 0;
                for (j = 1; j <= mainDict1.wordStruct[i].noOfDef; j++)
                {
                    cout << count << ". {" << mainDict1.wordStruct[i].defType[j] << "} " << mainDict1.wordStruct[i].definition[j];
                    count++;
                }
                flag = 1;
            }
            else if (i == mainDict1.noOfWords)
            {
                cout << "NOT FOUND: word [" << word << "] is not in the dictionary.\n";
                flag = 1;
            }
        }
    }

    void Adding(const char *word, const char *type, const char *definition)
    {
        int flag = 0;
        int i = 0;
        for (i = 0; flag == 0; i++)
        {
            if (strcmp(mainDict1.wordStruct[i].word, word) == 0)
            {
                mainDict1.wordStruct[i].noOfDef++;
                int place = mainDict1.wordStruct[i].noOfDef;
                strcpy(mainDict1.wordStruct[i].defType[place], type);
                strcpy(mainDict1.wordStruct[i].definition[place], definition);
                strcat(mainDict1.wordStruct[i].definition[place], lastTxt);
                flag = 1;
            }
            if (i == mainDict1.noOfWords)
            {
                i++;
                mainDict1.noOfWords++;
                mainDict1.wordStruct[i].noOfDef = 1;
                strcpy(mainDict1.wordStruct[i].word, word);
                strcpy(mainDict1.wordStruct[i].defType[1], type);
                strcpy(mainDict1.wordStruct[i].definition[1], definition);
                strcat(mainDict1.wordStruct[i].definition[1], lastTxt);
                flag = 1;
            }
        }
    }

}