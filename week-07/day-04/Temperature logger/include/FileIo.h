#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include "Storage.h"
#include <conio.h>
#include <string>

class FileIo
{
    public:
        FileIo();
        virtual ~FileIo();
        void write_to_file(Storage);
        void read_from_file(Storage &);
        void delete_file();

    protected:

    private:
};

#endif // FILEIO_H
