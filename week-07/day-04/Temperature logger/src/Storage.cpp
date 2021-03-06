#include "Storage.h"

Storage::Storage()
{
    //ctor
}

void Storage::put_into_vector(string var)
{
    stored_data.push_back(var);
}

void Storage::print_vector()
{
    for (unsigned int i = 0; i < stored_data.size(); ++i) {
        cout << stored_data.at(i) << endl;
    }
}

void Storage::empty_vector()
{
    char key;

    cout << "Are you sure you want to empty the memory?" << endl;
    cout << "\t \t y / n"<< endl;

    while (1) {
        key = getch();

        switch (key) {
        case 'y':
            stored_data.clear();
            cout << "Memory emptied." << endl;
            return;

        case 27:
        case 'n':
            return;

        default :
            cout << "Invalid command." << endl;
            cout << "Choice: y / n." << endl;
        }
    }
}

temperature_record Storage::parseString(string line) {
	int temperature;
    time_t current_time;
    time(&current_time);

	istringstream exampleStream(line);
	tm parsedDateTime;
	exampleStream >> get_time(&parsedDateTime, "%Y.%m.%d %H:%M:%S")
			>> temperature;
	if (exampleStream.fail()) {
		throw "Invalid string format!";
	}

	if (-273 > temperature || 1000 < temperature) {
		throw "Temperature is out of range!";
	}

	long timestamp = mktime(&parsedDateTime);

    if (timestamp > current_time)
       throw "No future time allowed";

	temperature_record rec;
	rec.temperature = temperature;
	rec.timestamp = timestamp;

	return rec;
}

vector<string> Storage::getter_vektor()
{
    return stored_data;
}

void Storage::correcting_format(string &var)
{// Hacking the year 2038 problem
    string tmp = var.substr(0, 4);
    int check_year;

    check_year = stoi(tmp);
    if (check_year > 2036)
        var = "kitten" + var;

    if (var[7] != '.') //month
        var.insert(5, "0");

    if (var[10] != ' ') // day
        var.insert(8, "0");

    if (var[13] != ':') //hour
        var.insert(11, "0");

    if (var[16] != ':') //minute
        var.insert(14, "0");

    if (var[19] != ' ') //second
        var.insert(17, "0");
}

Storage::~Storage()
{
    //dtor
}
