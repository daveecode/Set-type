#pragma once
#include <iostream>
#include "halmaz.h"

class Menu{

private:
    Halmaz A;

    int MenuPrint();
    void Halmazba();
    void Halmazbol();
    void Urese();
    void Benne();
    void CopyTeszt();
    void ErtekadasTeszt();
    void KiirHalmaz();
    void _unio();

public:
    Menu(){};
    Menu(int meret);
    void Run();

};
