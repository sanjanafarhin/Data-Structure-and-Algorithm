#include "bits/stdc++.h"

using namespace std;

int main()
{
    string TEXT="ababcabbabcabacabcbabc";
    string Pattern="abc";

    int text_len= TEXT.length();
    int Pattern_len=Pattern.length();

    int count=0;
    vector<int>Index_record;

    int bit=256;
    int MOD=101;

    int HASH_TEXT=0;
    int HASH_PATTERN=0;

    int c=1;
    for (int i=0; i < Pattern_len-1;i++)
    {
        c=(c*bit) % MOD;
    }

    for(int i=0; i < Pattern_len; i++)
    {
        HASH_TEXT=(bit*HASH_TEXT+TEXT[i])% MOD;
        HASH_PATTERN=(bit*HASH_PATTERN+Pattern[i])% MOD;
    }

    int i=0;
    while( i <= text_len - Pattern_len)
    {
        if(HASH_TEXT ==HASH_PATTERN)
        {
            bool match = true;

            for(int j=0; j<Pattern_len;j++)
            {
                if(Pattern[j] != TEXT[i+j])
                {
                    match = false;
                    break;
                }
            }

            if(match == true)
            {
                count++;
                Index_record.push_back(i);
            }
        }
        if(i < text_len - Pattern_len)
        {
            HASH_TEXT=(bit*(HASH_TEXT-TEXT[i]*c)+TEXT[i+Pattern_len]) % MOD;
            if(HASH_TEXT < 0)
            {
                HASH_TEXT+=MOD;
            }
        }
        i++;
    }

    cout << "count of abc :" <<count;

}