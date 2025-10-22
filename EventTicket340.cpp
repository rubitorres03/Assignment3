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
