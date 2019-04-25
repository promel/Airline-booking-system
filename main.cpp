#include "flight.h"

using namespace std;

int main()
{
    Flight flights[NUMBER_OF_FLIGHT_TIMES]; 
    intializeFlights(flights);//Arrays are passed by reference 
    bool isDone = false;
    do{
        /*
        *Struct in the flight header file 
        */
        string name,surname;
        cout << "Welcome to COS1511 Filght Booking System"<< endl;
        cin >> name>>surname;
        cout << "The available travel times for flights are:" << endl;
        cout << "\tDepart \tArrive" << endl;
        for (int i = 0; i < NUMBER_OF_FLIGHT_TIMES; i++)
        {
            cout << i + 1<< " \t" << DEPARTURE_TIMES[i] << " \t" << ARRIVAL_TIMES[i] << endl;
        }
        int travelTimeOption;
        bool optionCorrect = false;
        int option;
        do{
            cout << "Choose the time by entering the option number from the displayed list" << endl;
            cin >> travelTimeOption; 
            optionCorrect = validateFlightTimeOption(travelTimeOption);
            option = travelTimeOption-1;
        } while (!optionCorrect);
       

        displaySeats(flights[option]);
        bool seatBooked = false;
        do
        {
            string chosenSeat;
            cout <<"Seats that are already taken are inmdicated with an asterisk"<<endl;
            cout <<"Please key in seat number to choose a seat(eg:A2)"<<endl;
            cin>>chosenSeat;
            flights[option].fullName = name + " " + surname;

            seatBooked = bookSeat(chosenSeat,flights[option]);
            displaySeats(flights[option]);

        } while (!seatBooked);
        
    } while (!isDone);
    return 0;
}