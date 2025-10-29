#ifndef EVENTTICKET340_H
#define EVENTTICKET340_H

#include "LinkedBagDS/LinkedBag.h"
#include "Organizer.h"
// TO DO include necessary libraries

 

// This class only contains a single organizer
class EventTicket340 {
	private:
		Organizer organizer;

	public:
		EventTicket340();
		~EventTicket340();

		EventTicket340(const EventTicket340& other);		     // Copy constructor

		EventTicket340& operator=(const EventTicket340& other); // Assignment operator



		// Create a new organizer profile
		void createOrganizer(const std::string& username, const std::string& email, 
			const std::string& password, const std::string& bio,
			 const std::string& profilePicture);

		// Retrieve the organizer object
		Organizer getOrganizer() const;

		//friend function
		friend std::ostream& operator<<(std::ostream& os, const EventTicket340& event);

		friend std::istream& operator>>(std::istream& in, EventTicket340& userInput);
};

#endif // EVENTTICKET340_H