#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct tireNode
{
    char ch;
    tireNode *cr[52];

    bool isword;
    long cnt;
    string str;

    tireNode(char tch)
    {
        ch = tch;
        for (int i = 0; i < 52; ++i)
        {
            cr[i] = NULL;
        }
        isword = false;
    }
}TN;

int lo(string str1, string str2)
{
    int i;
    for (i = 0; i<str1.length() && i<str2.length(); ++i)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] > str2[i];
        }
    }

    return str1.length() > str2.length();
}

//< 0 less
int cmp(const TN *a, const TN *b)
{
    if (a->cnt != b->cnt)
    {
        return a->cnt < b->cnt;
    }
    else
    {

        return lo(a->str, b->str);
    }
}

class Solution
{
    private:
        TN *root;
        vector<TN*> words;
    public:
        Solution()
        {
            root = new TN('a');
            words.clear();
        }

        int getIndex(char ch)
        {
            if (ch>='a' && ch<='z')
            {
                return ch - 'a';
            }
            else
            {
                return ch - 'A' + 26;
            }
        }

        void insertWord(string str)
        {
            int index = getIndex(str[0]);
            TN *tmp = root;

            int i;
            for (i = 1; i < str.length(); ++i)
            {
                if (tmp->cr[index] == NULL)
                {
                    tmp->cr[index] = new TN(str[i-1]);
                    tmp->cr[index]->str = str.substr(0, i);
                }

                tmp = tmp->cr[index];
                index = getIndex( str[i] );
            }

            if (tmp->cr[index]== NULL)
            {
                tmp->cr[index] = new TN( str[i-1] );
                tmp->cr[index]->str = str.substr(0, i);
                tmp->cr[index]->isword = true;
                tmp->cr[index]->cnt = 1;
                words.push_back(tmp->cr[index]);
            }
            else
            {
                if (tmp->cr[index]->isword == false)
                {
                    tmp->cr[index]->isword = true;
                    tmp->cr[index]->cnt = 1;
                    words.push_back(tmp->cr[index]);
                }
                else
                {
                    ++tmp->cr[index]->cnt;
                }
            }
        }

        void output(long k)
        {
            int s = words.size();
            sort(words.begin(), words.end(), cmp);
        
            for (int i = s-1; i >= s-k; --i)
            {
                cout<<words[i]->str<<endl;//<<" "<<words[i]->cnt<<endl;
            }
        }
};

int main()
{
    Solution *sl = new Solution();
    long n;
    cin>>n;
    string str;
    while (n--)
    {
        cin>>str;
        sl->insertWord(str);
    }

    long k;
    cin>>k;
    sl->output(k);

    return 0;
}

