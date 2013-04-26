#include <iostream>
using namespace std;
#define LL long long

class Solution
{
    private:
        int n;
        bool flag;
        int zeroIndex;
        LL p;
        LL arr[1005];
    public:
        Solution()
        {
            flag = true;
            zeroIndex = -1;
            p = 1;
        }
        void read()
        {
            cin>>n;
            LL tmp;
            for (int i = 0; i < n; ++i)
            {
                cin>>tmp;
                if (tmp == 0)
                {
                    if (zeroIndex == -1)
                    {
                        zeroIndex = i;
                        continue;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                p *= tmp;
                arr[i] = tmp;
            }
        }

        void output()
        {
            for (int i = 0; i < n; ++i)
            {
                if (flag == false)
                {
                    cout<<0<<endl;
                }
                else if (zeroIndex != -1)
                {
                    if (zeroIndex == i)
                    {
                        cout<<p<<endl;
                        continue;
                    }
                    cout<<0<<endl;
                }
                else
                {
                    cout<<p/arr[i]<<endl;
                }
            }
        }
};

int main()
{
    Solution *sl = new Solution();
    sl->read();
    sl->output();
    return 0;
}

