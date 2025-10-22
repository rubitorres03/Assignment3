#ifndef VIRTUAL_EVENT_
#define VIRTUAL_EVENT_

#include "Event.h"

#include <iostream>
#include <string>

class VirtualEvent : public Event{
public:
    VirtualEvent();
    VirtualEvent(const std::string& name, const std::string& description, int rating, int soldTicketsCount,
         const std::string& streamLink, const std::string& audience);

    ~VirtualEvent();

    void setStreamLink(const std:: string& streamLink);
    std::string getStreamLink() const;

    void setAudience(const std:: string& audience);
    std::string getAudience() const;

    bool sell(int quantity) override;

    private:
        std::string streamLink;
        std::string audience;
        std::string accessCode = "ZT4iWsVSdP";
};

#endif