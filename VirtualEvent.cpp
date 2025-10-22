#include <iostream>
#include <string>
#include "VirtualEvent.h"
#include "Event.h"


VirtualEvent::VirtualEvent() : Event(), streamLink(""), audience("") {}

VirtualEvent::VirtualEvent(const std::string& name, const std::string& description, int rating,
    int soldTicketsCount, const std::string& streamLink, const std::string& audience): Event (name, description,
    rating, soldTicketsCount), streamLink(streamLink), audience(audience){}

    VirtualEvent::~VirtualEvent(){
        std::cout << "Virtual Event deconstructor: " << name << std::endl;
    }

    void VirtualEvent::setStreamLink(const std::string& streamLink) {
        this -> streamLink = streamLink;
    }

    std::string VirtualEvent::getStreamLink() const{
        return streamLink;
    }

    void VirtualEvent::setAudience(const std::string& audience) {
        this -> audience = audience;
    }

    std::string VirtualEvent::getAudience() const{
        return audience;
    }

     bool VirtualEvent::sell(int quantity) {
        for(int i = 0;i < quantity;i++) {
            soldTicketsCount++;
            std::string newCode = accessCode + std::to_string(soldTicketsCount); //new access code each time
            std::cout << "Your access code is : " << newCode << std::endl;
        }
        return true;
    }


