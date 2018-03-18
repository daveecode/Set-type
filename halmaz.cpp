#include <iostream>
#include "halmaz.h"

Halmaz::Halmaz(int kapacitas)
{
    meret = kapacitas;
    tomb = new int[meret];
}

Halmaz::~Halmaz()
{
    delete [] tomb;
}

Halmaz::Halmaz(const Halmaz &h)
{
    meret = h.meret;
    tomb = new int[meret];
    for(int i = 0; i < meret; i++)
    {
        tomb[i] = h.tomb[i];
    }
}

Halmaz& Halmaz::operator=(const Halmaz &h)
{
    if(this != &h)
    {
        delete [] tomb;
        this->meret = h.meret;
        this->tomb = new int[this->meret];
        for(int i = 0; i < this->meret; i++)
        {
            this->tomb[i] = h.tomb[i];
        }
    }
    return *this;
}

void Halmaz::betesz(int be)
{
    if(bennevan_e(be)) throw Benne_van;
    else
    {
        tomb[meret++] = be;
    }
}

bool Halmaz::bennevan_e(int e) const
{
    for (int i=0; i<meret; i++)
                if (tomb[i]==e)
                    return true;
            return false;

}

std::ostream& operator<<(std::ostream& os, Halmaz &kiiratas)
{

    os<<"{";
    for (int i=0; i<kiiratas.meret; ++i)
        os<<kiiratas.tomb[i]<<",";
    os<<"}"<<std::endl;
    return os;
} ///eddig fasza!!!

bool Halmaz::ures_e() const
{
    return meret == 0;
}

int Halmaz::elemszam() const
{
    return meret;
}

void Halmaz::kivesz(int ki)
{
    if(bennevan_e(ki))
    {
        int i = 0;
        while(i < meret)
        {
            if(ki == tomb[i])
            {
                tomb[i] = tomb[meret-1];
                meret = meret - 1;
            }
            i++;
        }
    }
    else if(ures_e()) throw Ures;
    else
    {
        throw Nincs_benne;
    }
}

void Halmaz::kiir() const
{
    std::cout << "{";
    for(int i = 0; i < meret; i++)
    {
        std::cout << tomb[i] << ",";
    }
    std::cout << "}" << std::endl;
}

/*Halmaz operator +(Halmaz &A, Halmaz &B)
{

    Halmaz C = A;
    Halmaz D;
    for(int i = 0; i < B.elemszam(); ++i)
    {
        if(C.bennevan_e(B.tomb[i]))
        {
            D.betesz(B.tomb[i]);
        }
        else
        {
            C.betesz(B.tomb[i]);
        }
    }

    return C;
}*/

/*bool operator==(Halmaz &A, Halmaz &B)
{
    int *Btomb = B.tomb;
    for(int i = 0; i < B.meret; ++i)
    {
        if(!A.bennevan_e(Btomb[i]))
        {
            return false;
        }
    }

    int *Atomb = A.tomb;
    for(int i = 0; i < A.meret; ++i)
    {
        if(!B.bennevan_e(Atomb[i]))
        {
            return false;
        }
    }
    return true;
}*/

Halmaz Halmaz::unio(Halmaz &B)
{
    Halmaz C = *this;
    for(int i = 0; i < B.elemszam(); ++i)
    {
        if(C.bennevan_e(B.tomb[i]) == false)
        {
            C.betesz(B.tomb[i]);
        }
    }
    std::cout << C;
    return C;

}

