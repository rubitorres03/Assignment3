#include <iostream>
#include <string>
#include "VenueEvent.h"

VenueEvent::VenueEvent() : Event(), venue(""), dateTime(""), capacity(0) {}

VenueEvent::VenueEvent(const std::string& name, const std::string& description, int rating, int soldTicketsCount,const std::string& venue,const std::string&dateTime, int capacity): 
Event(name,description, rating, soldTicketsCount),venue(venue),dateTime(dateTime),capacity(capacity){}

VenueEvent::~VenueEvent(){}

void VenueEvent::setVenue(const std::string& venue) {
    this->venue = venue;
}

std::string VenueEvent::getVenue() const{
    return venue;
}

void VenueEvent::setDateTime(const std::string& dateTime) {
    this->dateTime = dateTime;
}
std::string VenueEvent::getDateTime() const{
    return dateTime;
 }

void VenueEvent::setCapacity(int capacity){
    this->capacity = capacity;
}

int VenueEvent::getCapacity() const{
    return capacity;
}

bool VenueEvent::sell(int quantity) {
    if(capacity >= quantity) {
            capacity -= quantity;
            setSoldTicketsCount(getSoldTicketsCount() + quantity);
            return true;
    } else {
            std::cout << "Sold out" <<std::endl;
            return false;
     }
}

std::istream& operator>>(std::istream& in, std::shared_ptr<VenueEvent>& VenEventInput){
    std::string name;
	std::string description;
    std::string venue;
	std::string dateTime;
    std::string convert;
	int rating;
	int soldTicketsCount;
    int capacity;

        std::cout<< "Enter name of Event:";
		std::getline(in,name);

		std::cout<< "Enter description: ";
		std::getline(in,description);

		std::cout<< "Enter rating:";
		std::getline(in,convert);
        rating = std::stoi(convert);

		std::cout<< "Enter number of sold Tickets: ";
		std::getline(in,convert);
        soldTicketsCount = std::stoi(convert);

		
		std::cout<< "Enter Venue Name: ";
		std::getline(in,venue);

		
	    std::cout<< "Enter Date and Time: (Month/Day/Year)  ";
		std::getline(in, dateTime);

        std::cout<< "Enter capacity for event: "
        std::getline(in,convert);
        capacity = std::stoi(convert);

        EvntPtr = std::make_shared<VenueEvent>(name,description,rating,soldTicketsCount,venue,dateTime,capacity);

        return in;
}

