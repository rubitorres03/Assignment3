#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "EventTicket340.h"
#include "VirtualEvent.h"
#include "VenueEvent.h"
#include "Organizer.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Organizer
 * @param organizer object to interact with
 * 
 * */
void displayOrganizerMenu(Organizer& organizer){
	int organizerChoice = 0;
	do {
		
		cout << "\n Hi, "<< organizer.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Event\n"
		<< "4. Display All Events\n"
		<< "5. Display Kth Event\n"
		<< "6. Modify Event\n"
		<< "7. Sell Tickets\n"
		<< "8. Delete Event\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> organizerChoice;

		switch (organizerChoice) {
			case 1:{
				// TO DO: display organizer's profile information
				// displays Organizer Profile using an overloaded operator 
				cout << organizer;
				break;
			}
			case 2: {
				// TO DO: ask for new password and update organizer's password
				// Ask user to input a new password -> string
				cin.ignore();
				string newPassword;
				cout << "Please Enter new Password: ";
				getline(cin,newPassword);
				organizer.modifyPassword(newPassword);
				
				break;
			}
			case 3: {
				// TO DO: ask organizer to choose event type, then ask them to input event details.
				string choice;
				
				cin.ignore();
				cout << "Which event type are you making (virtual or venue):  ";
				getline(cin,choice);
				if(choice == "virtual"){
					// 	Declare a Virtual event object
					std::shared_ptr<VirtualEvent> EvntPtr = nullptr;
				
					// Initialize Virtual Event Object using an overload operator inside Virtual Event Class
					std::cin >> EvntPtr;
					
					// Stores Event inside Event List of Organizer
					organizer.createEvent(EvntPtr);
				}else if(choice == "venue"){
					// Declare a Venue event object
					std::shared_ptr<VenueEvent> EvntPtr = nullptr;

					// Initialize Venue Event Object using an overload operator inside Venue Event Class
					std::cin >> EvntPtr;

					//Stored Event inside Event List of Organizer
					organizer.createEvent(EvntPtr);
				}
				
				break;
			}
			case 4:{
				// TO DO: display all organizer's events
				//        You may re-use code from class demo
				//organizer.displayAllEvents();
				organizer.getLinkedBag();

				
				
				break;
			}
			case 5: {
				// TO DO: ask the organizer for a value k
				// Find the Kth event, if k > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cin.ignore();
				int k;
				cout <<"Enter the event index you want to view (1 being the latest event created): ";
				cin >> k;
				int size = organizer.getNumberOfEvents();
				if(k > size){
					cout << "Error Out of Range. Size of LinkedBag" << size << endl;
				}else{
					cin.ignore();
					organizer.displayEventK(k);
				}

				
				break;
			}
			case 6: {
				// TO DO: ask the organizer for the index of the event they want to modify.
				// Find the event, then prompt them for the new name and description.
				// Modify the event accordingly. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cin.ignore();
				int k;
				cout <<"Enter the event index you want to modify (1 being the latest event created): ";
				cin >> k;

				int size = organizer.getNumberOfEvents();

				if(k > size){
					cout << "Error Out of Range. Size of LinkedBag" << size << endl;
				}else{
					organizer.modifyEvent(k);
				}
				
				break;
			}
			case 7: {
				// TO DO: ask the organizer for the index of the event 
				// Find the event, then sell the tickets. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cin.ignore();
				int k;
				int quantity;
				cout << "Enter the event index to sell tickets (1 being the latest event created):  ";
				cin >> k;
				cout << "Enter ticket quantity: ";
				cin >> quantity;

				int size = organizer.getNumberOfEvents();
				if(k > size){
					cout << "Error Out of Range. Size of LinkedBag" << size << endl;
				}else{
					organizer.sellTicket(k,quantity);
				}
				
				break;
			}
			case 8:{
				// TO DO: ask the organizer for the index of the event they want to delete 
				// Find the event, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cin.ignore();
				int k;
				cout <<"Enter the event index you want to delete (1 being the latest event created): ";
				cin >> k;
				int size = organizer.getNumberOfEvents();
				if(k > size){
					cout << "Error Out of Range. Size of LinkedBag" << size << endl;
				}else{
					organizer.deleteEvent(k);
				}


				break;
			}
			case 0: {
				cin.ignore();
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cin.ignore();
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (organizerChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one organizer
	EventTicket340 eventTicket340; 

	cout << eventTicket340; // calls the operator<< overload inside EventTicket340

	
	// TO DO: Ask the organizer to enter their information 
	//        Instantiate a new Organizer object

	cin >> eventTicket340; // calls the operator>> overload inside EventTicket340
	

	// Retrieve the organizer 
	Organizer currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
				
	return 0;
}