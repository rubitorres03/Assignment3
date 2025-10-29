#ifndef VIRTUAL_EVENT_
#define VIRTUAL_EVENT_

#include "Event.h"

#include <iostream>
#include <string>
#include <memory>

class VirtualEvent : public Event{
public:
    VirtualEvent();
    VirtualEvent(const std::string& name, const std::string& description, int rating, int soldTicketsCount,
         const std::string& streamLink, const std::string& audience);

    ~VirtualEvent();  //destructor

    VirtualEvent(const VirtualEvent& otherVirtualEvent); //copy constructor

    VirtualEvent& operator=(const VirtualEvent& otherVirtualEvent); //assignment operator

    void setStreamLink(const std:: string& streamLink);
    std::string getStreamLink() const;

    void setAudience(const std:: string& audience);
    std::string getAudience() const;

    bool sell(int quantity) override;

    friend std::istream& operator>>(std::istream& in, std::shared_ptr<VirtualEvent>& VirEventInput);
    
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<VirtualEvent>& VirDisplay);
    private:
        std::string streamLink;
        std::string audience;
        std::string accessCode = "ZT4iWsVSdP";
};

#endif