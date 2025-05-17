#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Room {
public:
    string room_number;
    int chair_capacity;
    vector<pair<string, string>> bookings;  // Stores (start_time, end_time)

    Room(string num, int chairs) : room_number(num), chair_capacity(chairs) {}

    bool isAvailable(const string& start, const string& end) {
        for (const auto& booking : bookings) {
            if (!(end <= booking.first || start >= booking.second)) {
                return false;
            }
        }
        return true;
    }

    bool bookRoom(const string& start, const string& end) {
        if (isAvailable(start, end)) {
            bookings.emplace_back(start, end);
            return true;
        }
        return false;
    }
};

class RoomAllotmentSystem {
    map<string, Room> rooms;

public:
    void addRoom(const string& number, int chairs) {
        if (rooms.find(number) == rooms.end()) {
            rooms.emplace(number, Room(number, chairs));
            cout << "Room " << number << " added successfully.\n";
        } else {
            cout << "Room " << number << " already exists.\n";
        }
    }

    bool bookRoom(const string& number, const string& start, const string& end) {
        auto it = rooms.find(number);
        if (it != rooms.end()) {
            return it->second.bookRoom(start, end);
        }
        return false;
    }

    void displayRoomStatus(const string& number, const string& start, const string& end) {
        auto it = rooms.find(number);
        if (it != rooms.end()) {
            if (it->second.isAvailable(start, end)) {
                cout << "Room " << number << " is available.\n";
            } else {
                cout << "Room " << number << " is occupied.\n";
            }
        } else {
            cout << "Room " << number << " not found.\n";
        }
    }
};

void displayMenu() {
    cout << "\nIS Robotics Room Allotment System\n";
    cout << "1. Add New Room\n";
    cout << "2. Book a Room\n";
    cout << "3. Check Room Status\n";
    cout << "4. Exit\n";
}

int main() {
    RoomAllotmentSystem system;
    int choice;
    
    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string roomNumber;
                int chairs;
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter chair capacity: ";
                cin >> chairs;
                system.addRoom(roomNumber, chairs);
                break;
            }
            case 2: {
                string roomNumber, start, end;
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter start time (HH:MM): ";
                cin >> start;
                cout << "Enter end time (HH:MM): ";
                cin >> end;
                if (system.bookRoom(roomNumber, start, end)) {
                    cout << "Booking successful!\n";
                } else {
                    cout << "Booking failed - room occupied or invalid!\n";
                }
                break;
            }
            case 3: {
                string roomNumber, start, end;
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter check start time (HH:MM): ";
                cin >> start;
                cout << "Enter check end time (HH:MM): ";
                cin >> end;
                system.displayRoomStatus(roomNumber, start, end);
                break;
            }
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
