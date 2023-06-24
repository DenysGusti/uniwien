#include <iostream>
#include <random>

using namespace std;

/*
(*) A deterministic finite state machine can assume a set of different states. A state in which the machine is located at the beginning is considered to be the initial state. Any number of states can be declared as final states. In each state, the automaton reads a character and, depending on the character read, transitions to the next state. A table is used to determine which characters cause which subsequent status. If the character that was read does not result in a new state (that is, if it is not listed accordingly in the table), then this is considered an error. When the automaton reaches a final state, the string of all characters that have been entered up to that point are regarded as 'accepted by the automaton'. Implement a class Automat that can be used to simulate regular automata, e.g. B. (Of course, this table is only an example, it must be 'programmable' for your class accordingly): automaton The following letters are entered after starting the machine (the corresponding output is noted in brackets, incorrectly entered characters are simply ignored.): ad(error)abbc(accepted: aabbc)c(error)abd(accepted aabbcabd) Note that no further characters are read in as soon as state 4 is reached because there are no subsequent states specified for state 4 in the table.
*/

int main() {

    return 0;
}

/*
Input:

Output:

*/