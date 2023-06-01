
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#define MAX_WORDS 100
#define MAX_WORD_DEF 8
#define MAX_WORD_CHAR 64
#define MAX_WORD_DEF_TXT 1024

namespace sdds
{
    struct word
    {

        char definition[MAX_WORD_DEF][MAX_WORD_DEF_TXT];

        char defType[MAX_WORD_DEF][MAX_WORD_CHAR];

        char word[MAX_WORD_CHAR];
        int noOfDef;
    };

    struct dictionary
    {
        int noOfWords;

        word wordStruct[MAX_WORDS];
    };

    int LoadDictionary(const char *filename);

    void SaveDictionary(const char *filename);

    int UpdateDefinition(const char *word, const char *type, const char *definition);

    void Printing(const char *word);

    void Adding(const char *word, const char *type, const char *definition);
}

#endif