#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    
    if (reserved < 0) {
        this->reserved = 0;
    } else if (reserved > capacity * 1.05) {
        this->reserved = capacity * 1.05;
    } else {
        this->reserved = reserved;
    }
}

void FlightBooking::printStatus() {
    double percentage = 0;
    if (capacity > 0) {
        percentage = (static_cast<double>(reserved) / capacity) * 100.0;
    }
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << static_cast<int>(percentage) << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats > 0 && (reserved + number_of_seats) <= capacity * 1.05) {
        reserved += number_of_seats;
        return true;
    }
    return false;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats > 0 && (reserved - number_of_seats) >= 0) {
        reserved -= number_of_seats;
        return true;
    }
    return false;
}

int main() {
    int reserved = 0, capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    cin.ignore();
    
    FlightBooking booking(1, capacity, reserved);
    string command = "";

    while (command != "quit") {
        booking.printStatus();
        cout << "What would you like to do?: ";
        getline(cin, command);

        if (command.find("add") == 0) {
            int n = stoi(command.substr(4));
            if (!booking.reserveSeats(n)) {
                cout << "Cannot perform this operation" << endl;
            }
        } else if (command.find("cancel") == 0) {
            int n = stoi(command.substr(7));
            if (!booking.cancelReservations(n)) {
                cout << "Cannot perform this operation" << endl;
            }
        } else if (command != "quit") {
             cout << "Cannot perform this operation" << endl;
        }
    }
    return 0;
}