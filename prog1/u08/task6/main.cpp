#include <iostream>

using namespace std;

/*
Write a class whose objects represent a traffic light. The traffic light has the states green, flashing green, yellow, red, red+yellow in the usual order. There is also the yellow flashing status. At least implement the methods switch_on (sets the traffic light to the state blinking yellow), continue (changes to the next following state; the next state after blinking yellow is red) and print (outputs the current status of the traffic light).

Write

the necessary constructors, so that the following definitions of objects are possible (assuming that the class has the name Traffic_light):
Traffic_light a; // creates a traffic light in the blinking yellow state
Traffic_light b{actStatus}; // creates a traffic light in the state specified by ActState
An operator ++ that causes the traffic light to advance to the next state
Write a main program that uses at least two instances of your class and illustrates the use of the different methods.
Note: The ++ operator can be used in C++ in both postfix (a++) and prefix (++a) form. There are therefore two different options when defining the methods for overloading the ++ operator:

void operator++() defines the prefix form
void operator++(int) defines the postfix form
The additional parameter in the postfix form only distinguishes between the two options and has no other use. To solve the example, you only need to implement one of the two options. Instead of void, a suitable type can of course also be selected for the result of the operation if required.
*/

int main() {

    return 0;
}

/*
Input:


Output:

*/