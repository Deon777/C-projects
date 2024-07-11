#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string passwordGenerator(int length)
{
    const char characters[] = {
    'A', 'B', 'C', 'D','E', 'F', 'G', 'H','I', 'J', 'K', 'L','M', 'N', 'O', 'P','Q', 'R', 'S', 'T','U', 'V', 'W', 'X','Y','Z',
    'a', 'b', 'c', 'd','e', 'f', 'g', 'h','i', 'j', 'k', 'l','m', 'n', 'o', 'p','q', 'r', 's', 't','u', 'v', 'w', 'x','y','z',
    '0', '1', '2', '3','4', '5', '6', '7','8', '9',
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '|', ';', ':', ',', '.', '<', '>'};

    int charactersLength = sizeof(characters)/sizeof(characters[0]);

    srand(time(0)); //sets the random number generator to change in reference to realtime.

    //password generator
    string password = "";
    for(int i=0; i< length; ++i)
    {
        int index = rand() % charactersLength;
        password += characters[index];
    }
    return password;

}

int main()
{
    int length;
    //takes the length of the password from the user
    cout << "Please enter the password lenght: ";
    cin >> length;

    string password = passwordGenerator(length);
    cout << "Generated Password: " << password << endl;

    return 0;
}
