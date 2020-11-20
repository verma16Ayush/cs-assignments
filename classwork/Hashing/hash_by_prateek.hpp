#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> *next;

    node(string key, T v)
    {
        this->key = key;
        value = v;
    }
};

template <typename T> class Hashtable
{
    int cs; ///Current Size
    int ts; ///Max Arr Size
    node<T> **buckets;

    int hashFn(string key)
    {
        int L = key.length();
        int ans = 0;
        int p = 1; ///37^0 is 1 initially

        for (int i = 0; i < L; i++)
        {
            ans += key[L - i - 1] * p;
            p = p * 37;

            p %= ts;
            ans %= ts;
        }
        return ans;
    }

public:
    Hashtable(int ds = 7)
    {
        cs = 0;
        ts = ds;
        buckets = new node<T> *[ts];
        ///Make all addresses as NULL
        for (int i = 0; i < ts; i++)
        {
            buckets[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        ///Key i need the hash-index
        int i = hashFn(key);

        node<T> *n = new node<T>(key, value);
        n->next = buckets[i];
        buckets[i] = n;
    }
    ///Print it
    void print()
    {
        ///Iterate over buckets array
        for (int i = 0; i < ts; i++)
        {
            ///Print the LL for each buckets
            node<T> *temp = buckets[i];
            cout << "Bucket " << i << "->";
            while (temp != NULL)
            {
                cout << temp->key << ",";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Hashtable<int> hs;

    hs.insert("ayush", 10);

    return 0;

}
