#include <iostream>
#include <string>

using namespace std;

/*
The class Secret is used to store important information that can be protected with passwords.
In addition to the information to be saved (string), each object also contains a second string, the password.
If the password is empty, the object is open, otherwise it is locked. Implement and test at least the following methods:

Secret::Secret(const string& information) // open object with corresponding information
Secret::Secret(const string& information, const string& password) // object protected with a password
bool Secret::lock(const string& password) // locks an object with password. This may only work if the object was previously open.
Otherwise, this function must return false and leave the object unchanged.
bool Secret::unlock(const string& password) // unlocks an object if the password is correct. Otherwise false is returned.
Secret Secret::operator+(const Secret&) //Only works if the two objects to be concatenated are open.
Then the two character strings are simply concatenated in the result object. Otherwise, a runtime_error type exception is thrown.
int Secret::len() //Length of information. Returns 0 for locked objects
Output operator << //Outputs the information. Nothing is output for locked objects.

Think about which methods should not make any changes to the this object and define them appropriately as const methods.
*/

class Secret {
private:
    string _information, _password;
public:
    explicit Secret(const string& information, const string& password="") : _information{information}, _password{password} {}

    bool lock(const string& password) noexcept {
        if (_password.empty()) {
            _password = password;
            return true;
        }
        return false;
    }

    bool unlock(const string& password) noexcept {
        if (_password == password) {
            _password = "";
            return true;
        }
        return false;
    }

    Secret operator+(const Secret& other) const {
        if (!_password.empty() && !other._password.empty())
            throw runtime_error("secret is locked");
        return Secret{_information + other._information};
    }

    int len() const noexcept {
        return _password.empty() ? _information.length() : 0;
    }

    friend ostream& operator<<(ostream &os, const Secret &secret) {
        os << (secret._password.empty() ? secret._information : "");
        return os;
    }
};

int main() {
    Secret o1{"abc"}, o2{"def"};
    auto o3 = o1 + o2;
    o3.lock("");
    cout << o3 << '\n';
    o3.lock("123");
    cout << o3 << '\n';
    o3.unlock("");
    cout << o3.len() << '\n';
    o3.unlock("123");
    cout << o3.len() << '\n';
    return 0;
}

/*
Input:

Output:
abcdef

0
6
*/