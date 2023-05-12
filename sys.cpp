#include <random>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <bitset>
#include <intrin.h>
using namespace std;

void Bubble_sort(int* arr, int len) 
{
    int j = 0;

    __asm 
    {
        mov ecx, len
        dec ecx
        mov edi, 0
        I:
        cmp edi, ecx
            jg END 
            inc edi
            mov j, 0
            mov edx, ecx
            sub edx, edi
            mov esi, arr
            J :
        cmp j, edx
            jg I 
            mov eax, [esi]
            cmp[esi + 4], eax
            jl EXCHANGE
            NEXT :
        inc j
            add esi, 4
            jmp J
            EXCHANGE :
        mov ebx, [esi + 4]
            mov[esi], ebx
            mov[esi + 4], eax
            jmp NEXT
            END :
    }
}

int main() 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-100, 100);

    cout << "Enter array length: ";

    int n;
    cin >> n;
    int *a = new int[n];

    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        a[i] = dist(gen);
    }


    cout << "Array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout <<  "\n\n";

    Bubble_sort(a, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n";

    return 0;
}
