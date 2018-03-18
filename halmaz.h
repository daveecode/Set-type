#pragma once
#include <iostream>


enum Hiba {Benne_van, Nincs_benne, Ures};
class Halmaz{


private:
    int *tomb;
    int meret;

public:
    Halmaz(int kapacitas = 0);
    ~Halmaz();
    Halmaz(const Halmaz &h);
    Halmaz& operator=(const Halmaz &h);
    void betesz(int be);
    void kivesz(int ki);
    bool ures_e() const;
    bool bennevan_e(int e) const;
    int elemszam() const;
    friend std::ostream& operator<<(std::ostream& os, Halmaz &kiiratas);
    void kiir() const;
    void urit();
    friend Halmaz operator + (Halmaz & A, Halmaz & B);
    Halmaz unio(Halmaz &B);
    friend bool operator ==(Halmaz &A, Halmaz &B);

};
