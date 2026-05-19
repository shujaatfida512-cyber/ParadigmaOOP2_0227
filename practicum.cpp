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
    }    virtual void potongAdmin() = 0;

    void tampilkanSaldo()
    {
        cout << "Customer Name : " << namaNasabah << endl;
        cout << "Current Balance : Rp " << saldo << endl;
    }    virtual ~RekeningBank() {}
};
class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(const char nama[], double saldoAwal)
        : RekeningBank(nama, saldoAwal) {
    }

    void potongAdmin() override
    {
        cout << "\nSyariah Account -> No admin fee charged." << endl;
    }
};
int main(){}