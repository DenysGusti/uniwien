#include <iostream>

using namespace std;

using ld = long double;

/*
m workers can produce x pieces of a product in one hour. How many pieces can n workers produce in the same time?
A (novice) programmer wrote the following program for this simple proportion calculation:

#include <iostream>
using namespace std;

int main() {
  int worker, pieces, workerquestion;
  cin >> worker >> pieces >> workerquestion;
  cout << pieces/worker*workerquestion;
}
But now he gets the (mathematically) wrong answer 0 for m=10 x=5 and n=2.
Suggest two different ways of changing the expression to be printed in such a way that the order of operations remains unchanged,
but the program returns the correct result (for any input). Prove it by implementing a suitably improved program.
*/

int main() {
    int worker{}, pieces{}, workerquestion{};
    cout << "m, x, n = ";
    cin >> worker >> pieces >> workerquestion;
    cout << '\n' << static_cast<ld>(workerquestion) * pieces / worker;
    return 0;
}

/*
Input:
m, x, n = 10 5 2

Output:
1
*/