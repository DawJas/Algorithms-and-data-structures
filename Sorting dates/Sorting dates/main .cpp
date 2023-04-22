#include <stdio.h>
using namespace std;

struct Data {
    int d;
    int m;
    int y;
};

bool OlderDate(Data date1, Data date2) {
    if (date1.y < date2.y) return false;
    else if (date1.y > date2.y) return true;
    if (date1.m < date2.m) return false;
    else if (date1.m > date2.m) return true;
    if (date1.d < date2.d) return false;
    else return true;
}

void quickSort(Data* tab, int left, int right) {
    if (left >= right) return;

    int border = left - 1;
    int i = left;

    while (i < right)
    {
        if (OlderDate(tab[right], tab[i])) {
            border++;
            if (border != i) {
                Data temp = tab[i];
                tab[i] = tab[border];
                tab[border] = temp;
            }
        }
        i++;
    }
    border++;
    if (border != right) {
        Data temp = tab[i];
        tab[i] = tab[border];
        tab[border] = temp;
    }
    quickSort(tab, left, border - 1);
    quickSort(tab, border + 1, right);
}

void sort(Data* tab, int size) {
    if (size == 0) return;
    quickSort(tab, 0, size - 1);
}
int main()
{
    int array_size;
    scanf("%d", &array_size);
    int d, m, y;
    Data* tab = new Data[array_size];
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d-%d-%d", &d, &m, &y);
        tab[i].d = d;
        tab[i].m = m;
        tab[i].y = y;
    }
    sort(tab, array_size);
    for (int i = 0; i < array_size; i++)
    {
        printf("%02d-%02d-%04d\n", tab[i].d, tab[i].m, tab[i].y);
    }
    delete[] tab;
    return 0;
}