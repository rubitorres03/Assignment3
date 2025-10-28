#ifndef VENUE_EVENT_
#define VENUE_EVENT_

#include <iostream>
#include <string>
#include <memory>
#include "Event.h"

class VenueEvent : public Event{
public:
    VenueEvent();

    VenueEvent(const std::string& name, const std::string& description,int rating, int soldTicketsCount,
         const std::string& venue, const std::string& dateTime, int capacity);

    ~VenueEvent();

    void setVenue(const std:: string& venue);
    std::string getVenue() const;

    void setDateTime(const std:: string& dateTime);
    std::string getDateTime() const;

    void setCapacity(int capacity);
    int getCapacity() const;
    

    bool sell(int quantity);

    friend std::istream& operator>>(std::istream& in, std::shared_ptr<VenueEvent>& VenEventInput);

private: 
    std::string venue;       //data fields
    std::string dateTime;
    int capacity;
};

#endif