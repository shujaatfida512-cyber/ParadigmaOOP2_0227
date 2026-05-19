#include <iostream>

using namespace std;
class RekeningBank
{
protected:
    char namaNasabah[50];
    double saldo;
public:
    RekeningBank(const char nama[], double saldoAwal)
    {
        int i = 0;

        // Copy character array manually
        while (nama[i] != '\0')
        {
            namaNasabah[i] = nama[i];
            i++;
        }

        namaNasabah[i] = '\0';
        saldo = saldoAwal;
    }int main(){}