#include <iostream>
#include <string>
using namespace std;
class Train
{
private:
    struct ticket
    {
        string passengerName;
        int ticketID;
        int seatNum;
        string destination;
        ticket* next;
    } *p;
    int ticketIDnum;

public:
    Train();
    bool isSeatBooked(int snum);
    void bookTicket(string n, int snum, string d);
    void searchTicket(int id);
    void cancelTicket(int id);
    void displayTickets_count();
};
Train::Train()
{
    p = NULL;
    ticketIDnum = 100;
}

bool Train::isSeatBooked(int snum)
{
    ticket* temp = p;
    while (temp != NULL)
    {
        if (temp->seatNum == snum)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void Train::bookTicket(string n, int snum, string d)
{
    if (1 > snum || snum > 50)
    {
        cout << "The train only has 1-50 seats" << endl;
        return;
    }
    ticket* temp, * r;
    if (p == NULL)
    {
        temp = new ticket;
        temp->passengerName = n;
        temp->ticketID = ++ticketIDnum;
        temp->seatNum = snum;
        temp->destination = d;
        temp->next = NULL;
        p = temp;
    }
    else
    {
        if (isSeatBooked(snum))
        {
            cout << "Seat number " << snum << " is already booked!" << endl;
            return;
        }
        else
        {
            temp = p;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            r = new ticket;
            r->passengerName = n;
            r->ticketID = ++ticketIDnum;
            r->seatNum = snum;
            r->destination = d;
            r->next = NULL;
            temp->next = r;
        }
    }
    cout << "TicketID: " << ticketIDnum << " has been booked!" << endl;
}

void Train::searchTicket(int id)
{
    ticket* temp;
    temp = p;
    while (temp != NULL)
    {
        if (temp->ticketID == id)
        {
            cout << "Ticket Found!" << endl;
            cout << "Passenger: " << temp->passengerName << endl;
            cout << "Seat Number: " << temp->seatNum << endl;
            cout << "Destination: " << temp->destination << endl;
            cout << "Ticket ID: " << temp->ticketID << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Ticket ID: " << id << " is not found.." << endl;
}

void Train::cancelTicket(int id)
{
    ticket* temp;
    ticket *old = NULL;
    temp = p;
    while (temp != NULL)
    {
        if (temp->ticketID == id)
        {
            if (temp == p)
            {
                p = temp->next;
                cout << "TicketID: " << id << " is Canceled." << endl;
                delete temp;
                return;
            }
            else
            {
                old->next = temp->next;
                delete temp;
                cout << "TicketID: " << id << " is Canceled." << endl;
                delete temp;
                return;
            }
        }
        else
        {
            old = temp;
            temp = temp->next;
        }
    }
    cout << "Ticket ID: " << id << " is not found.." << endl;
}



void Train::displayTickets_count()
{
    ticket* temp;
    int count = 0;
    temp = p;
    if (p == NULL)
    {
        cout << "There are no Tickets booked!" << endl;
        return;
    }
    else
    {
        cout << "The Tickets Booked in this Train: " << endl;
        while (temp != NULL)
        {
            cout << "Passenger Name: " << temp->passengerName << endl;
            cout << "Ticket ID: " << temp->ticketID << endl;
            cout << "Seat Number: " << temp->seatNum << endl;
            cout << "Destination: " << temp->destination << endl;
            cout << endl;
            count++;
            temp = temp->next;
        }
        cout << "---------------------------------" << endl;
        cout << "The Total number of Tickets Booked in this Train is: " << count << endl;
    }
}
int main()
{
    int choice = 0;
    string n;
    int tid;
    int snum;
    string d;
    Train t1;
    while (true)
    {
        cout << "=========================================" << endl;
        cout << "what would you like to do?" << endl;
        cout << "1-Book a Ticket\n2-Cancel a Ticket\n3-Search for a Ticket\n4-Display all Tickets and their Count\n5-End" << endl;
        cout << endl;
        cin >> choice;
        if (choice == 5)
            break;
        cout << "==========================================" << endl;
        switch (choice)
        {
        case 1:
            cout << "To book a Ticket Please Fill the Following Information..\n";
            cout << "Enter the name of the Passenger: ";
            cin >> n;
            cout << endl;
            cout << "Enter the Seat Number(1-50): ";
            cin >> snum;
            cout << endl;
            cout << "Enter the Destination: ";
            cin >> d;
            cout << endl;
            t1.bookTicket(n, snum, d);
            break;
        case 2:
            cout << "Enter the TicketID you want to Cancel: ";
            cin >> tid;
            cout << endl;
            t1.cancelTicket(tid);
            break;
        case 3:
            cout << "Enter the TicketID you want to Search for: ";
            cin >> tid;
            cout << endl;
            t1.searchTicket(tid);
            break;
        case 4:
            t1.displayTickets_count();
            cout << endl;
            break;
        default:
            cout << "Wrong Choice. Please Try Again" << endl;
        }
    }

    return 0;
}
