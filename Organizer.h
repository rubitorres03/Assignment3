#ifndef ORGANIZER_H
#define ORGANIZER_H
// TO DO: #include all the standard libraries and your own libraries here
   #include <iostream>
   #include <string>
   #include "Event.h"
   #include "LinkedBagDS/LinkedBag.h"




// To DO: define the class Organizer with the necessary functions and data fields
   class Organizer{
      protected:
      std::string username;
      std::string email;
      std::string password;
      std::string bio;
      std::string profilePic;

      LinkedBag<Event*> organizerEvents;


      public:
         Organizer();
         Organizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePic);
         virtual ~Organizer();


         void setUsername(const std::string& username);
         std::string getUsername() const;


         void setEmail(const std::string& email);
         std::string getEmail() const;


         void setPassword(const std::string& password);
         std::string getPassword() const;


         void setBio(const std::string& bio);
         std::string getBio() const;


         void setProfilePic(const std::string& profilePic);
         std::string getProfilePic() const;

         int getNumberOfEvents() const;
         
         void displayProfile() const;

         bool modifyPassword(const std::string& password);
         bool createEvent(Event* event);
         void displayEventK(int k) const;
         void displayAllEvents();
         bool modifyEvent(int k);
         bool sellTicket(int k, int quantity);
         bool deleteEvent(int k);




         bool operator==(const Organizer& otherOrganizer) const;
   };


// This is a function that allows you to compare two organizers based on their username and email address. 
// You may directly include it in your class definition.
// You don't need to modify it but will have to put it inside your class.
// Operator == overloading function prototype:
#endif
