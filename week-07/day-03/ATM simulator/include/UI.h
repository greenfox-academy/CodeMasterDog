#ifndef UI_H
#define UI_H

#include "DataBase.h"
#include <vector>

using namespace std;

class UI
{
    public:
        UI();
        void menu_src();
        void login(/*string, string*/);
        string getter_entered_pin();
        virtual ~UI();

    protected:

    private:
        string entered_pin;
};

#endif // UI_H