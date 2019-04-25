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
float firstClassPrice;
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

struct Flight
{
    public:
        string TravelClass;
        float TravelClassPrice;
        int counter;
        string seats[SEAT_ROWS][SEAT_COLUMS];
        string arrival_time;
        string meridiem;
        string departure_time;
        string fullName;
        string seat;
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

void intializeFlights(Flight flights[])
{
    firstClassPrice = getFirstClassPrice();
    for(int i = 0; i < NUMBER_OF_FLIGHT_TIMES; i++){
        flights[i].counter = 0;
        flights[i].arrival_time = ARRIVAL_TIMES[i];
        flights[i].departure_time = DEPARTURE_TIMES[i];
        flights[i].meridiem = MERIDIEMS[i];
        for (int x = 0; x < SEAT_ROWS; x++)
        {
            for (int y = 0; y < SEAT_COLUMS; y++)
            {
                if (x == 8 && y == 2)
                {
                    break;
                }
                
                stringstream seat;

                seat << LETTERS[x] <<y + 1;
                
                flights[i].seats[x][y] = seat.str();
            }
        }
    }
}

float getFirstClassPrice(){
    return ECONOMY_CLASS_PRICE * 1.2;
}

void displayClassPrice(string TravelClass, float flightPrice)
{
    cout << TravelClass << "(" << std::fixed << std::setprecision(2) << flightPrice << ")" << endl;
}

void displaySeats(Flight flight)
{
    cout << "The available seats for " << flight.departure_time << " are as follows:"<<endl;
    displayClassPrice(FIRST_CLASS, firstClassPrice);
    for (int x = 0; x < SEAT_ROWS; x++)
    {
        if (x == 4)
        {
            displayClassPrice(ECONOMY_CLASS, ECONOMY_CLASS_PRICE);
        }

        for (int y = 0; y < SEAT_COLUMS; y++)
        {
            if (x == 8 && y == 2)
            {
                break;
            }
            cout << "|" << flight.seats[x][y] << "|";
        }
        cout << endl;
    }
}

bool bookSeat(string chosenSeat, Flight& flight)
{
    flight.TravelClass = FIRST_CLASS;
    flight.TravelClassPrice = firstClassPrice;
    for (int x = 0; x < SEAT_ROWS; x++)
    {
        for (int y = 0; y < SEAT_COLUMS; y++)
        {
            if (x == 8 && y == 2)
            {
                break;
            }
            if (flight.seats[x][y].compare(chosenSeat)==0)
            {
                if(x>3){
                    flight.TravelClass = ECONOMY_CLASS;
                    flight.TravelClassPrice = ECONOMY_CLASS_PRICE;
                }
                flight.seats[x][y] = "**";
                return true;
            }
        }
    }
    cout <<"Sorry, the seat is taken. Please choose a seat that is available" <<endl;
    return false;
}

void displayBookings(Flight flight)
{
    cout << "Number of  bookings made for " << flight.departure_time << " " << flight.meridiem << ":" << flight.counter << endl;
}

bool validateFlightTimeOption(int travelTimeOption){
    bool optionCorrect;
    switch(travelTimeOption){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            optionCorrect = true;
            break;
        default:
            cout << "Incorrect option! Please choose 1-5." << endl;
            optionCorrect = false;
            break;
    }
    return optionCorrect;
}


void displayTravelTicket(Flight flight){
    cout<< "****************************"<<endl;
    cout<< "Travel ticket for FLIGHT"<<endl;
    cout<< "****************************"<<endl;
    cout<< "Name\t : "<< flight.fullName<<"\t"<<"Travel Ticket class : "<<flight.TravelClass<<endl;
    cout<< "\t\t\t\t\tSeat No \t:"<<flight.seat<<endl;
    cout<< "Departure\t\t : Johannesburg\t\t Departure : "<<flight.departure_time<<endl;
    cout<< "Destination\t\t : Cape Town\t\t Arrival Time : "<<flight.arrival_time<<endl;
    cout<< "***************************"<<endl;

}