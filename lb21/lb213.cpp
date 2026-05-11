#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; }
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking() {
    id = 0; capacity = 0; reserved = 0;
}

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
    if (id != 0) {
        double percentage = 0;
        if (capacity > 0) {
            percentage = (static_cast<double>(reserved) / capacity) * 100.0;
        }
        cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << static_cast<int>(percentage) << "%) seats reserved" << endl;
    }
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

void printAllFlights(FlightBooking bookings[], int size) {
    bool hasFlights = false;
    for (int i = 0; i < size; i++) {
        if (bookings[i].getId() != 0) {
            bookings[i].printStatus();
            hasFlights = true;
        }
    }
    if (!hasFlights) {
        cout << "No flights in the system" << endl;
    }
}

int getFlightIndex(FlightBooking bookings[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (bookings[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int getFreeIndex(FlightBooking bookings[], int size) {
    for (int i = 0; i < size; i++) {
        if (bookings[i].getId() == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    FlightBooking bookings[10];
    string command = "";

    while (command != "quit") {
        printAllFlights(bookings, 10);
        cout << "What would you like to do?: ";
        getline(cin, command);

        stringstream ss(command);
        string cmd;
        ss >> cmd;

        if (cmd == "create") {
            int id, cap;
            ss >> id >> cap;
            if (getFlightIndex(bookings, 10, id) != -1) {
                cout << "Cannot perform this operation: flight " << id << " already exists" << endl;
            } else {
                int freeIndex = getFreeIndex(bookings, 10);
                if (freeIndex != -1) {
                    bookings[freeIndex] = FlightBooking(id, cap, 0);
                } else {
                    cout << "Cannot perform this operation: maximum number of flights reached" << endl;
                }
            }
        } else if (cmd == "delete") {
            int id;
            ss >> id;
            int idx = getFlightIndex(bookings, 10, id);
            if (idx != -1) {
                bookings[idx] = FlightBooking();
            } else {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
        } else if (cmd == "add") {
            int id, n;
            ss >> id >> n;
            int idx = getFlightIndex(bookings, 10, id);
            if (idx != -1) {
                if (!bookings[idx].reserveSeats(n)) {
                    cout << "Cannot perform this operation: capacity reached" << endl;
                }
            } else {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
        } else if (cmd == "cancel") {
            int id, n;
            ss >> id >> n;
            int idx = getFlightIndex(bookings, 10, id);
            if (idx != -1) {
                if (!bookings[idx].cancelReservations(n)) {
                    cout << "Cannot perform this operation: too many seats to cancel" << endl;
                }
            } else {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
            }
        } else if (cmd != "quit") {
            cout << "Unknown command" << endl;
        }
    }
    return 0;
}