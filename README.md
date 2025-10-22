# Assignment3
EventTicket340 Assignment 3
You will enhance your implementation of the simplified version of an event-ticketing system.
To do so, you will implement the following features:

1. use smart pointers instead of raw pointers to manage the list of objects,
2. add operator overloading for specific operators, and
3. add the implementation of the BIG 3 functions in your program classes.
   
For extra credit, you may choose to do one or more of the following:

1. Add the overload Assignment (=) Operator to the linked-list implementation of the
ADT Bag (LinkedBag).
2. Submit one non-trivial test cases for the new implementation of EventTicket340.

Application requirements { EventTicket340
Your client is happy with your product and would like to improve it with new features. Your
application will still only implement one main aspect: managing an organizer’s events. You
do not have to implement any other features.

Your application should still allow a user to perform the tasks described in assignment 2
handout. In addition, you should implement the following 5 parts.

Part 1: Smart Pointers { 25 points
There is one list of objects in your program: a list of Event objects. In order to take advan-
tage of polymorphism, your lists should hold pointers to objects. Because the LinkedBag
does not help manage dynamically allocated items, you should use smart pointers.
Convert all raw pointers to the appropriate type of smart pointers and revise the application
to use these exclusively.
Note: Do not modify the Node pointers used in the LinkedBag implementation. However,
you may need to adjust some functions now that you no longer use raw pointers.

Part 2: Friend Functions { 25 points
Your program prompts the user for information to initialize (1) an Organizer’s profile and
(2) both types of Events, and provides functionality to displays this information.
• You should overload both the output operator << and the input operator >> in all
classes to perform these tasks.
• Revise your implementation to use these operators when requesting user input or dis-
playing information.
• In EventTicket340, you only need to overload the output operator << to display the
following message: “Welcome to EventTicket340!”

Part 3: BIG 3 { 40 points
You should implement the BIG 3 functions in all program classes. The BIG 3 are three of the
BIG 5 functions: the destructor, the copy constructor, and overload assignment operator.

Part 4: Design Decisions – 10 points
Thinking about EventTicket340, what data structure(s) do you think would be most efficient
for it (time and space efficiency). In your analysis, you should think about the main points
discussed in class: 
(1) data volume, (2) operation frequency (how frequently do you do
searches), (3) data growth (how fast does data grow), and (4) search needs (how is data
retrieved? simple vs. complex queries).

Extra Credit
Part EC1: LinkedBag operator(=) overloading { 10 points
You will use the same LinkedBag implementation of the interface for Bag ADT provided to
you as part of assignment 2 in the folder LinkedBagDS.
For this assignment, you will continue using the LinkedBag implementation of the Bag
ADT interface provided in Assignment 2, found in LinkedBagDS.
Add the implementation of the following function:

1. LinkedBag<ItemType>& operator=(const LinkedBag<ItemType>& aBag);
It is very similar to the copy constructor (already provided in the current implemen-
tation), except you will be modifying the this object.
You need to first check if the this is the same as aBag. If not, you need to clear this,
i.e. if (this != &aBag) you need to clear the this object.

Part EC2: Non-trivial test case { 5 points
You should provide one non-trivial test case to show that you have tested your program for
correctness. Your test case should include sample inputs and expected outputs.
• Sample input could be a sequence of prompts or menu options a user would choose
• Sample output would be the expected behavior of the program or next step
Save the sample inputs in input01.txt and its expected output in output01.txt.
Include it in your ZIP file.
