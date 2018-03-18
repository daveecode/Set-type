#include <iostream>
#include "halmaz.h"
#include "menu.h"

using namespace std;

#define NORMAL
#ifdef NORMAL

int main()
{
    /*Halmaz h, k;
    h.betesz(10);
    h.betesz(20);
    h.betesz(30);
    h.betesz(40);
    k.betesz(11);
    k.betesz(21);
    k.betesz(31);
    k.betesz(41);
    h.unio(k);*/

    Menu m;
    m.Run();
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("ures metodus tesztelese","Ha nem ures akkor return true egyebkent false")
{
    Halmaz h;
    CHECK(h.ures_e());
    h.betesz(10);
    CHECK(h.ures_e() == false);
}

TEST_CASE("bennevan metodus tesztelese", "Ha benne van akkor true egyebkent false")
{
    Halmaz h;
    CHECK(h.bennevan_e(5) == false);
    CHECK(h.bennevan_e(0) == false);
    h.betesz(5);
    h.betesz(0);
    CHECK(h.bennevan_e(5));
    CHECK(h.bennevan_e(0));
}

TEST_CASE("betesz metodus tesztelese", "kivetel elkapasa es betesz fuggveny vizsgalata")
{
    Halmaz h;
    h.betesz(10);
    CHECK(h.bennevan_e(10));
    h.betesz(0);
    h.betesz(-1);
    CHECK(h.bennevan_e(-1));
    CHECK(h.bennevan_e(0));
    CHECK(h.elemszam() == 3);
    CHECK_THROWS(h.betesz(10));
}

TEST_CASE("kivesz metodus tesztelese", "kivetel elkapasa es kivesz vizsgalata")
{
    Halmaz h;
    CHECK_THROWS(h.kivesz(10));
    for(int i = 1; i < 10; ++i)
    {
        h.betesz(i);
    }
    CHECK(h.elemszam() == 9);
    h.kivesz(1);
    CHECK(h.bennevan_e(1) == false);
    CHECK(h.elemszam() == 8);
    h.kivesz(9);
    CHECK(h.bennevan_e(9) == false);
    CHECK(h.elemszam() == 7);
    h.kivesz(4);
    h.kivesz(5);
    h.kivesz(7);
    CHECK(h.elemszam() == 4);
    CHECK(h.bennevan_e(4) == false);
    CHECK(h.bennevan_e(5) == false);
    CHECK(h.bennevan_e(7) == false);
    CHECK_THROWS(h.kivesz(1000));

}

TEST_CASE("elemszam metodus tesztelese,", "ures es nem ures kiprobalasa")
{
    Halmaz h;
    CHECK(h.elemszam() == 0);
    h.betesz(10);
    h.betesz(20);
    CHECK(h.elemszam() > 0);
}

TEST_CASE("unio metodus tesztelese", "ures es kulonbozo meretu halmazok uniozasa")
{
    Halmaz h;
    Halmaz k;
    for(int i = 0; i < 5; ++i)
    {
        h.betesz(i);
    }
    for(int j = 5; j < 10; ++j)
    {
        k.betesz(j);
    }

    CHECK((h.unio(k)).elemszam() == 10);
    CHECK((h.unio(k)).bennevan_e(3));
    CHECK((h.unio(k)).bennevan_e(8));

    h.kivesz(1);
    h.kivesz(2);
    h.kivesz(3);

    CHECK((h.unio(k)).elemszam() == 7);
    CHECK((h.unio(k)).bennevan_e(3) == false);
    CHECK((h.unio(k)).bennevan_e(6));

    Halmaz p;

    CHECK((p.unio(k)).elemszam() == k.elemszam());
    for(int i = 5; i < 10; ++i)
    {
        p.betesz(i);
    }

    CHECK((p.unio(k)).elemszam() == k.elemszam());
    CHECK((p.unio(k)).elemszam() == p.elemszam());

    p.kivesz(5);
    p.kivesz(6); ///a 6 benne van a másikban

    CHECK((p.unio(k)). elemszam() == k.elemszam());
    CHECK((p.unio(k)).bennevan_e(6));

    Halmaz a;
    Halmaz b;

    CHECK((a.unio(b)).ures_e());
    CHECK((a.unio(b)).elemszam() == 0);

    a.betesz(100);
    a.betesz(111);

    CHECK((a.unio(b)).elemszam() == a.elemszam());
    CHECK((a.unio(b)).ures_e() == false);




}

#endif // NORMAL
