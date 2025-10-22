#ifndef EVENT_H
#define EVENT_H
// TO DO: #include all the standard libraries and your own libraries here

	#include <iostream>
	#include <string>

// To DO: define the class Event with the necessary functions' prototypes and data fields

	class Event{
	protected:
	std::string name;
	std::string description;
	int rating;
	int soldTicketsCount;

	public:
	Event();
	Event(const std::string& name, const std::string& description, int rating, int soldTicketsCount);
	virtual ~Event();

	void setName(const std::string& name);
	std::string getName() const;

	void setDescription(const std::string& description);
	std::string getDescription() const;

	void setRating(int rating);
	int getRating() const;

	int getSoldTicketsCount() const;
	void setSoldTicketsCount(int count);

	//Functions that Event should have
	void display() const;
	virtual bool modify();
	virtual bool sell(int quantity);

	// This is a function that allows you to compare two events based on their name.
	// You may directly include it in your class definition.
	// You don't need to modify it but will have to put it inside your class.
	// Operator overloading function prototype:
	bool operator==(const Event& otherEvent) const;
	};
	
#endif

