#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

//global unordered map to store paired username and password pairs
unordered_map<string, string> users;

//Function to save the current users in the unordered map to the file
void saveUser()
{
    ofstream file("users.txt");
    for(const auto& pair : users)
    {
        file << pair.first <<" " << pair.second << endl;
    }
    file.close();
}


//function to load users from the file into the unordered map
void loadUsers()
{
    ifstream file("users.txt");
    string username, password;
    while(file >> username >> password)
    {
        users[username] = password;
    }
    file.close();
}

//Function to handle user sign-up
void signUp()
{
    system("cls");
    string username, password;
    cout <<" Enter a username: ";
    cin >> username;
    //check if the username exist in the users.txt
    if(users.find(username) != users.end())
    {
        cout << "Username already exist. Please try again" << endl;
        return;
    }
    cout << "Please enter a password: ";
    cin >> password;

    //add new username and password to the map
    users[username] = password;
    saveUser(); // save the updated map to the file

    cout << "sign up successful" << endl;
}

//Function to handle user log in
void logIn()
{
    system("cls");
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    //check if the username and password match
    if(users.find(username) != users.end() && users[username] == password)
        cout << "Log in successful!" <<endl;
    else{cout << "Invalid username or password." << endl;}
}

//Function to handle account deletion
void deleteAccount()
{
    system("cls");
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    //check if the username and password match
    if(users.find(username) != users.end() && users[username] == password)
    {
        users.erase(username);//remove the user from the map
        saveUser(); //save the updated map to the file
        cout <<"Account  deleted successfully" << endl;
    }
    else
    {
        cout <<"Invalid username or password." << endl;
    }

}

int main()
{
    loadUsers(); //load exiting users from the file
    int choice;

    do{ //Display the menu

        cout << "\nWelcome!\n";
        cout << "1. Sign up\n";
        cout << "2. Log In\n";
        cout << "3. Delete Account\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        //users choice
        switch(choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            logIn();
            break;
        case 3:
            deleteAccount();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again" << endl;
        }

    }while(choice != 4);

   return 0;

}



