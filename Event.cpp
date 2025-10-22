
// TO DO: #include all the standard libraries and your own libraries here
   #include <iostream>
   #include <string>
   #include "Event.h"
// TO DO: function implementations

   Event::Event() : name(""), description(""), rating(0), soldTicketsCount(0){}


   Event::Event(const std::string& name, const std::string& description, int rating, int soldTicketsCount) :
   name(name), description(description),rating(rating), soldTicketsCount(soldTicketsCount){}

   Event::~Event(){
      std::cout << "Event: " << name <<std::endl;
   }
   
   void Event::setName(const std::string& name){
      this->name = name;
   }

   std::string Event::getName() const{
      return this->name;
   }

   void Event::setDescription(const std::string& description){
      this->description = description;
   }


   std::string Event::getDescription() const{
      return this->description;
   }

   void Event::setRating(int rating) {
      this->rating = rating;
   }

   int Event::getRating() const {
      return this->rating;
   }

   int Event::getSoldTicketsCount() const{
      return this->soldTicketsCount;
   }

   void Event::setSoldTicketsCount(int count){
      this->soldTicketsCount = count;
   }

   void Event::display() const {
      std::cout << "Event name: " << name << std::endl;
      std::cout << "Description: " << description << std::endl;
      std::cout << "Rating: " << rating << std::endl;
      std::cout << "Tickets sold: " << soldTicketsCount << std::endl;
   }

   bool Event::modify(){
      std::string newValue;
      int newRating;
      
      
      std::cout << "Modify event: " << name << std::endl;
      std::cin.ignore();
      std::cout << "Enter new event name: ";
      std::getline(std::cin, newValue);
      if (!newValue.empty()) setName(newValue);
   
      std::cout << "Enter new description: ";
      std::getline(std::cin, newValue);
      if (!newValue.empty()) setDescription(newValue); 

      std::cout << "Enter new rating: ";
      std::cin >> newRating;
      if(!newValue.empty()) setRating(newRating);

      return true;
   }

   bool Event::sell(int quantity) {
      if(quantity <= 0 ){
         return false;
      } else {
         soldTicketsCount += quantity;
         return true;
      }
   }

   
   // ------------------------------------------------------------------------------
   // Operator overloading implementation
   bool Event::operator==(const Event& otherEvent) const {
      return Event::name == otherEvent.name;
   }






