#include "constants.h"

struct Flight
{
public:
    string TravelTicketClass;
    float TravelTicketClassPrice;
    int counter;
    string seats[SEAT_ROWS][SEAT_COLUMS];
    string arrival_time;
    string meridiem;
    string departure_time;
    string fullName;
    string seat;
};

float getFirstClassPrice();
void intializeFlights(Flight flights[]);
void displayClassPrice(string TravelTicketClass, float flightPrice);
void displaySeats(Flight flight);
bool bookSeat(string chosenSeat, Flight &flight);
void displayBookings(Flight flights[]);
bool validateFlightTimeOption(int travelTimeOption);
void displayTravelTicket(Flight flight);

float getTravelTicketClassPrice()
{
    return ECONOMY_CLASS_PRICE * 1.2;
}

void intializeFlights(Flight flights[])
{
    for (int i = 0; i < NUMBER_OF_FLIGHT_TIMES; i++)
    {
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

                seat << LETTERS[x] << y + 1;

                flights[i].seats[x][y] = seat.str();
            }
        }
    }
}

void displayClassPrice(string TravelTicketClass, float flightPrice)
{
    cout << TravelTicketClass << "(" << std::fixed << std::setprecision(2) << flightPrice << ")" << endl;
}

void displaySeats(Flight flight)
{
    cout << "The available seats for " << flight.departure_time << " are as follows:" << endl;
    displayClassPrice(FIRST_CLASS, getTravelTicketClassPrice());
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

bool bookSeat(string chosenSeat, Flight &flight)
{
    flight.TravelTicketClass = FIRST_CLASS;
    flight.TravelTicketClassPrice = getTravelTicketClassPrice();
    for (int x = 0; x < SEAT_ROWS; x++)
    {
        for (int y = 0; y < SEAT_COLUMS; y++)
        {
            if (x == 8 && y == 2)
            {
                break;
            }
            if (flight.seats[x][y].compare(chosenSeat) == 0)
            {
                if (x > 3)
                {
                    flight.TravelTicketClass = ECONOMY_CLASS;
                    flight.TravelTicketClassPrice = ECONOMY_CLASS_PRICE;
                }
                flight.seat = flight.seats[x][y];
                flight.seats[x][y] = "**";
                flight.counter++;
                return true;
            }
        }
    }
    cout << "Sorry, the seat is taken. Please choose a seat that is available" << endl;
    return false;
}

void displayBookings(Flight flights[])
{
    for (int i = 0; i < NUMBER_OF_FLIGHT_TIMES; i++)
    {
        cout << "Number of  bookings made for " << flights[i].departure_time << " " << flights[i].meridiem << ":" << flights[i].counter << endl;
    }
}

bool validateFlightTimeOption(int travelTimeOption)
{
    bool optionCorrect;
    switch (travelTimeOption)
    {
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

void displayTravelTicket(Flight flight)
{
    int nameAreaSize = 21;
    int numberOfWhiteSpaces = nameAreaSize - flight.fullName.size();
    string whiteSpaces = "";
    for (int x = 0; x < numberOfWhiteSpaces; x++)
    {
        whiteSpaces += " ";
    }
    cout << "****************************" << endl;
    cout << "Travel ticket for FLIGHT" << endl;
    cout << "****************************" << endl;
    cout << "Name\t\t : " << flight.fullName << whiteSpaces << "Travel Ticket class\t: " << flight.TravelTicketClass << endl;
    cout << "\t\t\t\t\tSeat No \t\t: " << flight.seat << endl;
    cout << "Departure   \t : Johannesburg\t\tDeparture\t\t: " << flight.departure_time << endl;
    cout << "Destination \t : Cape Town\t\tArrival Time\t\t: " << flight.arrival_time << endl;
    cout << "***************************" << endl;
    cout << "Amount :" << flight.TravelTicketClassPrice << " Thank you for booking with COS1511. Your travel agent for queries is Annie Mathew" << endl;
}
