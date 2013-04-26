#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Circularbuffer 
{
    private:
        int N;
        int head;
        int tail;
        vector<string> buffer; 
    public:
        Circularbuffer(int tn)
        {
            N = tn+1;
            buffer.resize(N);
            head = 0;
            tail = 0;
        }

        void movehead()
        {
            //empty
            if (head == tail)
            {
                return;
            }

            ++head;
            head = head % N;
        }

        void movetail()
        {
            //full
            if ((tail+1)%N == head)
            {
                movehead();
            }
            ++tail;
            tail = tail % N;
        }

        void insert(string elem)
        {
            buffer[tail] = elem;
            movetail();
        }

        void remove()
        {
            movehead();
        }

        void listelem()
        {
            int it = head;
            while (it != tail)
            {
                cout<<buffer[it]<<endl;
                ++it;
                it %= N;
            }
        }

        void read()
        {
            char cd;
            int tn;
            string str;
            while (cin>>cd)
            {
                if (cd == 'A')
                {
                    cin>>tn;
                    while (tn--)
                    {
                        cin>>str;
                        insert(str);
                    }
                }
                else if (cd == 'R')
                {
                    cin>>tn;
                    while (tn--)
                    {
                        remove();
                    }
                }
                else if (cd == 'L')
                {
                    listelem();
                }
                else if (cd == 'Q')
                {
                    break;
                }
            }
        }

};

int main()
{
    int tn;
    cin>>tn;
    Circularbuffer *cb = new Circularbuffer(tn);
    cb->read();
    return 0;
}
