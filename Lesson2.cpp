// Lesson2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <string>

class Person {
private:
    std::string _name;
    int _age;
public:
    Person(std::string name, int age) {
        _name = name;
        _age = age;
    }
    void showall() {
        std::cout << "Name: " << _name << std::endl;
        std::cout<<"Age: " << _age << std::endl;
    }
};
class Pupil {
private:
    std::string _name1;
    int _age1;
    std::vector<int>_marks;
public:
    Pupil(std::string name1, int age1, std::vector<int>marks) {
        _name1 = name1;
        _age1 = age1;
        _marks=marks;
    }
    void print() {
        std::cout << "Name of student:" << _name1 << std::endl;
        std::cout << "Age: " << _age1 << std::endl;
        std::cout << "Marks: " << std::endl;
        for (int i = 0; i < _marks.size(); i++)
            std::cout << _marks.at(i);
    }
    
};
class Professor {
private:
    std::string _name3;
    std::string _degree;
public:
    Professor(std::string name3, std::string degree) {
        _name3 = name3;
        _degree = degree;
    }
    
    void show() {
        std::cout << "Name:" << _name3 << std::endl;
        std::cout << "Degree: " << _degree << std::endl;
    }
};

class Client {
private:
    std::string _name4;
    int _age4;
    double _bill;
public:
    Client(std::string name, int age, double bill) {
        _name4 = name;
        _age4 = age;
        _bill = bill;
    }

    void ShowData() {
        std::cout << "1 Client's name: " << _name4 << std::endl;
        std::cout << "2 Client's age: " << _age4 << '\n';
        std::cout << "3 Client's bill: " << _bill << '\n';
    }
};
class Bank {
private:
    std::vector<Client*>_clients;
public:
    void AddClient(Client* client) {
        
        _clients.push_back(client);
    }
    void ShowClients() {
        
       for (const auto& it : _clients)
            it->ShowData(); // эквивалентна записи ниже, просто более короткий вариант
        
       /*std::vector<Client*>::iterator it;
       for (it = _clients.begin(); it != _clients.end(); it++)
           (*it)->showData();*/
    }
    void ShowClient(int index) {
        if (index > _clients.size())
            return;
        _clients.at(index)->ShowData();

    }
};


int main()
{
    /*std::vector<int> vec = {10,20,30};
    Person p1("Far", 18);
    Pupil T1("Hatt", 20, vec);
    Professor w1("Andrey", "Medium");
    p1.showall();
    T1.print();
    w1.show();*/

    Bank* bank = new Bank();
    Client* client1 = new Client("Bob", 20, 645);
    Client* client2 = new Client("Alex", 25, 688);
    Client* client3 = new Client("Monika", 40, 314);
    Client* client4 = new Client("Sara", 31, 648);
    Client* client5 = new Client("Afdes", 64, 645);

    bank->AddClient(client1);
    bank->AddClient(client2);
    bank->AddClient(client3);
    bank->AddClient(client4);
    bank->AddClient(client5);
    
    bank->ShowClients();
    bank->ShowClient(2);
    







    return 0;
}


