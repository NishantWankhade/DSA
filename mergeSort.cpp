#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int p, int q, int r)
{

    int size1 = q - p + 1;
    int size2 = r - q;
    vector<int> L(size1, 0), M(size2, 0);

    for (int i = 0; i < size1; i++)
    {
        L[i] = v[p + i];
    }

    for (int i = 0; i < size2; i++)
    {
        M[i] = v[q + 1 + i];
    }

    int i = 0, j = 0, k = p;

    while (i < size1 && j < size2)
    {
        if (L[i] <= M[j])
        {
            v[k] = L[i];
            k++;
            i++;
        }
        else
        {
            v[k] = M[j];
            j++;
            k++;
        }
    }

    while (i < size1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        v[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        
        int m = (l + r)/ 2;

        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main()
{
    vector<int> a = {10, 9, 8, 7, 6};

    mergeSort(a, 0, a.size() - 1);

    for (auto x : a)
    {
        cout << x << " ";
    }
}