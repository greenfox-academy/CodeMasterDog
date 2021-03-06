#include "UI.h"

UI::UI()
{
    //ctor
}

void UI::menu_src()
{
    cout << "Temperature Logger Application\n\
        \r==============================\n\
        \rCommands:\n\
        \rh        Show command list\n\
        \ro        Open port\n\
        \rs        Start logging / Stop logging\n\
        \rc        Close port\n\
        \rl        List validated data from memory\n\
        \re        Empty memory\n\
        \rr        Read log file (to screen or memory)\n\
        \rw        Write data to log file\n\
        \rd        Delete the log file\n\
        \rq        Exit from the program\n" << endl;
}

void UI::choice()
{
    string line, date, time;

    Storage stor;
    SerialPortWrapper *serial = new SerialPortWrapper("COM4", 115200);
    is_opened = false;
    is_running = false;

    while (1) {
        cout << "Press a command key>";
        key = getch();
        cout << key <<endl;
        switch (key) {
            case 'h':
                system("cls");
                menu_src();
                break;

            case 'o':
                if (is_opened) {
                    cout << "Port is already opened." << endl;
                    break;
                } else {
                    serial->openPort();
                    cout << "Port opened." << endl;
                    is_opened = true;
                }
                 break;

            case 's':
                {
                if (!is_opened) {
                    cout << "Please open the port first." << endl;
                    break;
                }
                string pressed = "a";
                cout << "Start logging" << endl;
                while(pressed != "s") {
                    serial->readLineFromPort(&line);
                    if (line.length() > 0) {
                      stor.correcting_format(line);
                        cout << line << endl;
                        try {
                            temperature_record good = stor.parseString(line);
                            stor.put_into_vector(line);
                            //cout << "good.temperature: " << good.temperature << ", good.timestamp: " << good.timestamp << endl;
                        } catch (const char *exception) {
                            cout << "Something went wrong: " << exception << endl;
                        }
                    }
                    if (_kbhit()) {
                        pressed = getch();
                        cout << "Stop logging" << endl;
                    }
                }
                break;
                }

            case 'c':
                if (!is_opened) {
                    cout << "Port is already closed." << endl;
                    break;
                } else {
                    serial->closePort();
                    is_opened = false;
                    cout << "Port closed." << endl;
                    break;
                }

            case 'l':
                cout << "Stored in memory:" << endl;
                stor.print_vector();
                break;

            case 'w':
                {
                    cout << "Write logged data to file" << endl;
                    FileIo fio;
                    fio.write_to_file(stor);
                    break;
                }

            case 'd':
                {
                    FileIo fio;
                    fio.delete_file();
                    break;
                }

            case ('e'):
                stor.empty_vector();
                break;

            case ('r'):
                {
                    FileIo fio;
                    fio.read_from_file(stor);
                    break;
                }

            case ( 'q'):
                cout << "Thanks for using Temperature logger!" << endl;
                cout << "See You soon!" << endl;
                exit(0);

            default :
                cout << "Invalid command." << endl;
        }
    }
}

UI::~UI()
{
    //dtor
}
