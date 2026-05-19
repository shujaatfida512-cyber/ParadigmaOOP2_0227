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

class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(const char nama[], double saldoAwal)
        : RekeningBank(nama, saldoAwal) {
    }

    void potongAdmin() override
    {
        saldo -= 15000;

        cout << "\nConventional Account -> Admin fee Rp 15,000 deducted." << endl;
    }
};
class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(const char nama[], double saldoAwal)
        : RekeningBank(nama, saldoAwal) {
    }

    void potongAdmin() override
    {
        if (saldo > 10000000)
        {
            cout << "\nPremium Account -> No admin fee charged." << endl;
        }
        else
        {
            saldo -= 50000;

            cout << "\nPremium Account -> Admin fee Rp 50,000 deducted." << endl;
        }
    }
};
int main(){    RekeningBank* rekening1 =
        new RekeningSyariah("Ahmad", 5000000);

    RekeningBank* rekening2 =
        new RekeningKonvensional("Budi", 7000000);

    RekeningBank* rekening3 =
        new RekeningPremium("Siti", 9000000);

    RekeningBank* rekening4 =
        new RekeningPremium("Rina", 15000000);    rekening1->potongAdmin();
    rekening1->tampilkanSaldo();

    rekening2->potongAdmin();
    rekening2->tampilkanSaldo();

    rekening3->potongAdmin();
    rekening3->tampilkanSaldo();

    rekening4->potongAdmin();
    rekening4->tampilkanSaldo();
}