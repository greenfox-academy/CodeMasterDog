#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "..\SerialPortWrapper.h"
#include <windows.h>
#include "Storage.h"
#include "FileIo.h"

class UI
{
    public:
        UI();
        virtual ~UI();
        void menu_src();
        void choice();


    protected:

    private:
        char key;
        bool is_opened;
        bool is_running;
};

#endif // UI_H
