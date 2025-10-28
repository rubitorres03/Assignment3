// TO DO: Implementation of EventTicket340 functions
#include <iostream>
#include <string>
#include "EventTicket340.h"
#include "Organizer.h"


// TO DO: implement constructor
EventTicket340::EventTicket340(){}

// TO DO: implement destructor
EventTicket340::~EventTicket340(){}

void EventTicket340::createOrganizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
   // TO DO: implement function
   this->organizer = Organizer(username,email,password,bio,profilePicture);


}



Organizer EventTicket340::getOrganizer() const{
   // TO DO: implement function
   return this->organizer;
}

std::ostream& operator <<(std::ostream& os, const EventTicket340& event){
   os << "Welcome to EventTicket 340! " << std::endl;
   return os; 
}

std::istream& operator>>(std::istream& in, EventTicket340& userInput){
   std::string username;
	std::string email;
	std::string password;
	std::string bio;
	std::string profilePicture;

   std::cout << "Please enter a username: ";
	getline(in,username);

	std::cout << "Please enter an email: ";
	getline(in,email);

	std::cout << "Please enter a password: ";
	getline(in,password);

	std::cout << "Please enter a bio: ";
	getline(in,bio);

	std::cout << "Please enter a profile picture: ";
	getline(in,profilePicture);

   userInput.createOrganizer(username,email,password,bio,profilePicture);

   return in;
   
}

