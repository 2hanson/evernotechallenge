#include <iostream>
using namespace std;

class TopFour
{
    private:
        int n;
        int minheap[4];
    public:
        TopFour()
        {
            n = 0;
        }

        void SiftUp(int index)
        {
            while (index>0)
            {
                int p = (index-1)/2;
                if (minheap[p] > minheap[index])
                {
                    swap(minheap[p], minheap[index]);
                }
                else
                {
                    break;
                }

                index = p;
            }
        }

        void SiftDown(int index)
        {
            int tmp;
            while (index < n)
            {
                tmp = 2*index + 1;
                if (tmp >= n)
                {
                    break;
                }

                if (tmp+1<n && minheap[tmp]>minheap[tmp+1])
                {
                    tmp = tmp + 1;
                }

                if (minheap[tmp] < minheap[index])
                {
                    swap(minheap[tmp], minheap[index]);
                }
                else
                {
                    break;
                }

                index = tmp;
            }
        }

        void read()
        {
            int tmp;
            cin>>tmp;
            if (n < 4)
            {
                minheap[n] = tmp;
                ++n;
                SiftUp(n-1);
            }
            else
            {
                if (minheap[0] < tmp)
                {
                    minheap[0] = tmp;
                    SiftDown(0);
                }
            }
        }

        void output()
        {
            while (n > 0)
            {
                //cout<<minheap[0]<<endl;
                swap(minheap[0], minheap[n-1]);
                --n;
                SiftDown(0);
            }

            for (int i = 0; i < 4; ++i)
            {
                cout<<minheap[i]<<endl;
            }
        }
};

int main()
{
    int n;
    cin>>n;
    TopFour *tf = new TopFour();
    while (n--)
    {
        tf->read();
    }

    tf->output();
    return 0;
}

