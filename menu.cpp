#include <iostream>
#include "menu.h"

using namespace std;

Menu::Menu(int meret):
A(meret)
{
    cout << "A" << meret << " meretu halmaz letrejott!\n";
}

void Menu::Run()
{
    int v;

    do{
        v = MenuPrint();

        switch(v)
        {
        case 1:
            Halmazba();
            KiirHalmaz();
            break;
        case 2:
            Halmazbol();
            KiirHalmaz();
            break;
        case 3:
            Urese();
            KiirHalmaz();
            break;
        case 4:
            Benne();
            KiirHalmaz();
            break;
        case 5:
            _unio();
            break;
        case 6:
            KiirHalmaz();
            break;
        case 7:
            CopyTeszt();
            break;
        case 8:
            ErtekadasTeszt();
            break;
        default:
            cout << "\nViszontlatasra!\n";
        }
    } while(v != 0);

}

int Menu::MenuPrint()
{
    const int n = 8;
    int valasz;
    cout << "\n*********************************\n";
    cout << "0. Kilepes\n";
    cout << "1. Halmazba berak\n";
    cout << "2. Halmazbol kivesz\n";
    cout << "3. Ures-e a halmaz\n";
    cout << "4. Adott elem benne van-e a halmazban\n";
    cout << "5. 2 halmaz unioja\n";
    cout << "6. Halmaz kiirasa\n";
    cout << "7. Copy konstruktor tesztelese\n";
    cout << "8. Ertekado operator tesztelese\n";
    cout << "\n*********************************\n";

    do{
        cout << "Valasztas: ";
        cin >> valasz;
    } while(valasz < 0 || valasz > n);
    return valasz;

}

void Menu::KiirHalmaz()
{
    A.kiir();
}

void Menu::Halmazba()
{
    int be;
    cout << "Mit tegyunk a halmazba?";
    cin >> be;

    try{
        A.betesz(be);
    } catch(Hiba ex)
    {
        switch(ex) {

    case Benne_van:
        cout << "Az elem mar benne van a halmazban.\n";
        break;
    case Ures:
        cout << "Nincs mit kivenni, hiszen a halmaz ures.\n";
        break;
    case Nincs_benne:
        cout << "Az elem nincs benne a halmazban.\n";
        break;
        }
    }
}

void Menu::Halmazbol()
{
    int ki;
    if(A.ures_e())
    {
        cout << "Nincs mit kivenni, hiszen a halmaz ures.\n";
    }
    else
    {


    cout << "Mit vegyunk ki a halmazbol?";
    cin >> ki;

    try {
        A.kivesz(ki);
    } catch(Hiba ex)
    {
        switch(ex)
        {
    case Benne_van:
        cout << "Az elem mar benne van a halmazban.\n";
        break;
    case Ures:
        cout << "Nincs mit kivenni, hiszen a halmaz ures.\n";
        break;
    case Nincs_benne:
        cout << "Az elem nincs benne a halmazban.\n";
        break;
        }
    }
    }
}

void Menu::Urese()
{
    if(A.ures_e())
    {
        cout << "A halmaz ures.\n";
    }
    else
    {
        cout << "A halmaz nem ures.\n";
    }
}

void Menu::Benne()
{
    if(A.ures_e())
    {
        cout << "Nincs mit vizsgalni, hiszen a halmaz ures. Eloszor rakjon valamit a halmazba.\n";
    }
    else
    {
    int e;
    cout << "Melyik elemet vizsgaljuk?\n";
    cin >> e;

    if(A.bennevan_e(e))
    {
        cout << "A(z)" << e << " elem benne van a halmazban.\n";
    }
    else
    {
        cout << "A(z)" << e <<" elem nincs benne a halmazban.\n";
    }
    }


}

void Menu::CopyTeszt()
{
    Halmaz B(A);

    cout << "Az eredeti halmaz: " << A;
    cout << "A masolat halmaz: " << B;

    int k;
    cout << "Tegyen valamit az eredeti halmazba: ";
    cin >> k;

    A.betesz(k);

    cout << "Tegyen valamit a masolat halmazba: ";
    cin >> k;

    B.betesz(k);

    cout << "Hasonlitsa ossze az igy kapott halmazokat!\n";
    cout << "A = " << A;
    cout << "B = " << B;
}

void Menu::ErtekadasTeszt()
{
    try{cout << "Az A halmaz aktualis tartalma: " << A << endl;
    Halmaz B;
    int e;
    cout << "Tegyen valamit B halmazba: ";
    cin >> e;

    B.betesz(e);

    cout << "Berakas utan a B tartalma: ";
    cout << B;

    B = A;

    cout << "B = A ertekadas utan a B halmaz tartalma:";
    cout << B;
    cout << "Ertekadas utan az A halmaz tartalma:";
    cout << A;

    cout << "Tegyen valamit a B halmazba: ";
    cin >> e;

    B.betesz(e);

    cout << "Berakas utan a B halmaz tartalma:";
    cout << B;
    cout << "Tegyen valamit az A halmazba: ";
    cin >> e;

    A.betesz(e);

    cout << "Berakas utan az A halmaz tartalma:";
    cout << A;

    A = A;

    cout << "A = A ertekadas utan az A halmaz tartalma:";
    cout << A << endl;
    cout << "A = A ertekadas utan a B halmaz tartalma:";
    cout << B << endl;

    cout << "A teszt vegetert.";
    } catch(Hiba ex)
    {
        switch(ex)
        {
        case Benne_van:
            cout << "Mar benne van az elem\n";
            break;
        }
    }
}

void Menu::_unio()
{
   try{ cout << "Az aktualis halmaz elemei: ";
    A.kiir();
    cout << "Tegyen elemeket a B halmazba!\n";
    Halmaz B;
    cout << "Hany elemet szeretne beletenni?";
    int elem;
    cin >> elem;
    int i;
    while(B.elemszam() < elem)
    {
        cout << "Adja meg a " << B.elemszam() + 1 << ". elemet!\n";
        cin>>i;
        B.betesz(i);
    }

    cout << "A 2 halmaz unioja: ";
    A.unio(B);
   } catch(Hiba ex)
   {
       switch(ex)
       {
       case Benne_van:
           cout << "Az elemet mar beletette a halmazba.\n";
           break;
       }
   }
}
