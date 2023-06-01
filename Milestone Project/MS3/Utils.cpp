

#include <iostream>
#include "Utils.h"


using namespace std;

namespace sdds
{
    int strlen(const char* str)
    {
        int len = 0;
        while (str[len])
        {
            len++;
        }
        return len;
    }
    void strcpy(char* des, const char* src, int len)
    {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++)
        {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    int strcmp(const char* s1, const char* s2)
    {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

   const char* toUpperCase(char* string) {
        // ref: https://www.digitalocean.com/community/tutorials/string-uppercase-lowercase-c-plus-plus
        for (int i = 0; i < strlen(string); i++) {
            string[i] = toupper(string[i]);
        }
        return string;
    }






}