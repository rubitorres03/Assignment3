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
				//      : e.g. organizer.displayProfile();
				organizer.displayProfile();
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
				Event* event = nullptr;

				cin.ignore();
				cout << "Which event type are you making (virtual or venue):  ";
				getline(cin,choice);
				if(choice == "virtual"){
				// 	create a Virtual event object
					string name;
					string description;
					int rating;
					int soldTicketsCount;
					
					string streamLink;
					string audience;

					cout<< "Enter name of Event:";
					getline(cin,name);

					cout<< "Enter description: ";
					getline(cin,description);

					cout<< "Enter rating:";
					cin >> rating;

					cout<< "Enter number of sold Tickets: ";
					cin >> soldTicketsCount;

					cin.ignore();
					cout<< "Enter Stream Link: ";
					getline(cin,streamLink);

					cin.ignore();
					cout<< "Enter audience type:  ";
					getline(cin, audience);

					event = new VirtualEvent(name,description,rating,soldTicketsCount,streamLink,audience);
					
				}else if(choice == "venue"){
				// 	create a Venue even object
					string name;
					string description;
					int rating;
					int soldTicketsCount;
					string venue;
					string dateTime;
					int capacity;
					

					cout<< "Enter name of Event:";
					getline(cin, name);

					cout<< "Enter description: ";
					getline(cin,description);

					cout<< "Enter rating:";
					cin >> rating;

					cout<< "Enter number of sold Tickets: ";
					cin >> soldTicketsCount;

					cin.ignore();
					cout<< "Enter venue name: ";
					getline(cin,venue);

					cin.ignore();
					cout<< "Enter date and Time: ";
					getline(cin,dateTime);

					cout<<"Enter capacity for event: ";
					cin >> capacity;
				
					event = new VenueEvent(name,description,rating,soldTicketsCount,venue,dateTime,capacity);
					
				}
				organizer.createEvent(event);
				// Create the event and add it to the organizer's events
				break;
			}
			case 4:{
				// TO DO: display all organizer's events
				//        You may re-use code from class demo
				organizer.displayAllEvents();
				
				break;
			}
			case 5: {
				// TO DO: ask the organizer for a value k
				// Find the Kth event, if k > LinkedBag size, 
				//    return an error message that includes the size of the LinkedBag
				cin.ignore();
				int k;
				cout <<"Enter what Kth element you want to view: ";
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
				cout <<"Enter what Kth element you want to modify: ";
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
				cout << "Enter the event index to sell tickets: ";
				cin >> k;
				cout << "Enter ticket quantity";
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
				cout <<"Enter what Kth element you want to delete: ";
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

	cout << "\n Welcome to EventTicket340:" << endl;
	// TO DO: Ask the organizer to enter their information 
	//        Instantiate a new Organizer object
	string username;
	string email;
	string password;
	string bio;
	string profilePicture;

	cout << "Please enter a username: ";
	getline(cin,username);

	cout << "Please enter an email: ";
	getline(cin,email);

	cout << "Please enter a password ";
	getline(cin,password);

	cout << "Please enter a bio: ";
	getline(cin,bio);

	cout << "Please enter a profile picture ";
	getline(cin,profilePicture);

	// call eventTicket340 createOrganizer function 
	// replace /*...*/ with the right parameters
	eventTicket340.createOrganizer(username,email,password,bio,profilePicture);

	// Retrieve the organizer 
	Organizer currentOrganizer = eventTicket340.getOrganizer();

	// Display the main menu
	displayOrganizerMenu(currentOrganizer);
				
	return 0;
}