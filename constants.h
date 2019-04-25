#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

const int TRAVEL_DURATION = 150; //2h 30m

/*
* Number of the total seats in the flight
*/
const string FIRST_CLASS = "First Class";
const string ECONOMY_CLASS = "Economy Class";
const float ECONOMY_CLASS_PRICE = 1600.00;
const int SEAT_ROWS = 9;
const int SEAT_COLUMS = 6;

/*
* Number of the flight times 
*/
const int NUMBER_OF_FLIGHT_TIMES = 5;

const char LETTERS[] = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
};


const string DEPARTURE_TIMES[] = {
    "7.00",
    "9.00",
    "11.00",
    "13.00",
    "15.00",
};

const string MERIDIEMS[] = {
    "a.m",
    "a.m",
    "a.m",
    "p.m",
    "p.m",
};

const string ARRIVAL_TIMES[] = {
    "9.30",
    "11.30",
    "13.30",
    "15.30",
    "17.30",
};