// TO DO: #include needed standard libraries and your own libraries here
   #include <iostream>
   #include <string>
   #include "Organizer.h"
   #include <vector>


Organizer::Organizer(){}


Organizer::Organizer(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePic):
username(username), email(email), password(password), bio(bio), profilePic(profilePic){
}
// TO DO: function implementations
Organizer::~Organizer(){
   std::cout << "Organizer: " << Organizer::username <<std::endl;
}


void Organizer::setUsername(const std::string& username){
   Organizer::username = username;
}


std::string Organizer::getUsername() const{
      return Organizer::username;
}


void Organizer::setEmail(const std::string& email){
   Organizer::email = email;
}


std::string Organizer::getEmail() const{
   return Organizer::email;
}


void Organizer::setPassword(const std::string& password){
   Organizer::password = password;
}


std::string Organizer::getPassword() const{
   return Organizer::password;
}


void Organizer::setBio(const std::string& bio) {
   Organizer::bio = bio;
}


std::string Organizer::getBio() const{
   return Organizer::bio;
}


void Organizer::setProfilePic(const std::string& profilePic){
   Organizer::profilePic = profilePic;
}


std::string Organizer::getProfilePic() const{
   return Organizer::profilePic;
}

int Organizer::getNumberOfEvents() const {
   return this->organizerEvents.getCurrentSize();
}

void Organizer::displayProfile() const {
   std::cout << "User name: " << username << std::endl;
   std::cout << "Email:  " << email << std::endl;
   std::cout << " Bio: " << bio << std::endl;
   std::cout << " Profile Picture:  " << profilePic << std::endl;
}


bool Organizer::modifyPassword(const std::string& password){
   

      setPassword(password);
      return true;
   
}
bool Organizer::createEvent(Event* event){
   if(event != nullptr){
      return organizerEvents.add(event);
   }
   return false;
   
}
void Organizer::displayEventK(int k) const{
   Node<Event*>* node = organizerEvents.findKthItem(k-1);
   if(node && node->getItem() != nullptr){
      node->getItem()->display();
   }

}

void Organizer::displayAllEvents(){
   std::vector<Event*> bagItems = organizerEvents.toVector();
   int numberOfEntries = bagItems.size();
   for(int i = 0; i < numberOfEntries;i++){
      bagItems[i]->display();
   }
   
}
bool Organizer::modifyEvent(int k){
   Node<Event*>* node = organizerEvents.findKthItem(k-1);
   if(node && node->getItem() != nullptr){
      return node->getItem()->modify();

   }
   return false;

}
bool Organizer::sellTicket(int k, int quantity){
   Node<Event*>* node = organizerEvents.findKthItem(k-1);
   if(node && node->getItem() != nullptr){
      return node->getItem()->sell(quantity);

   }
   return false;

}
bool Organizer::deleteEvent(int k){
   Node<Event*>* node = organizerEvents.findKthItem(k-1);
   if(node && node->getItem() != nullptr){
      Event* ev = node->getItem();
      organizerEvents.remove(ev);
      return true;

   }
   return false;

}

// Operator == overloading implementation
bool Organizer::operator==(const Organizer& otherOrganizer) const {
   return (Organizer::username == otherOrganizer.username) && (Organizer::email == otherOrganizer.email);
}
