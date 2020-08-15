#include <bits/stdc++.h>
#include <typeinfo>
using namespace std;

class Publication
{
protected:
    double price$;
    int length$;
public:
    Publication(double price, int length):price$(price), length$(length){ cout << "Call Publication's constructor!" << endl;}
    virtual ~Publication(){ cout << "Call Publication's de-constructor!" << endl;}
    virtual double getTotalPrice()const = 0;
    double getPrice() const { return price$;}
    int    getLength()const { return length$;}
};

class Book: public Publication
{
public:
    Book(double price, int length):Publication(price, length){ cout << "Call Book's constructor!" << endl;}
    ~Book(){ cout << "Call Book's de-constructor!" << endl;}
    double getTotalPrice()const {return length$* price$;}
};

class Tape: public Publication
{
public:
    Tape(double price, int length):Publication(price, length){cout << "Call Tape's constructor!" << endl;}
    ~Tape(){cout << "Call Tape's de-constructor!" << endl;}
    double getTotalPrice()const 
    {
        int de = length$ % 10, ttl = length$;
        if(de != 0){ttl -= de; ttl += 10; }
        return (ttl/ 10) * price$;
    }
};


class BookStore
{
private:
    Publication **pubs;
    int num;

public:
    BookStore(Publication **p, int n)
    {
        pubs = new Publication *[n];
        num = n;
        for (int i = 0; i < n; i++)
        {
            if (typeid(*(p[i])) == typeid(Book))
            {
                pubs[i] = new Book(p[i]->getPrice(), p[i]->getLength());
            }
            else
            {
                pubs[i] = new Tape(p[i]->getPrice(), p[i]->getLength());
            }
        }
    }
    int getNumOfBook()
    {
        int c = 0;
        for (int i = 0; i < num; i++)
        {
            if (typeid(*(pubs[i])) == typeid(Book))
                c++;
        }
        return c;
    }
    int getNumOfTape()
    {
        int c = 0;
        for (int i = 0; i < num; i++)
        {
            if (typeid(*(pubs[i])) == typeid(Tape))
                c++;
        }
        return c;
    }
    ~BookStore()
    {
        for (int i = 0; i < num; i++)
        {
            delete pubs[i];
        }
        delete[] pubs;
        cout << "Call BookStore's de-constructor!\n";
    }
};
int main()
{
    //freopen("src.txt", "w", stdout);
    int cases, date;
    char type;
    double total, price;
    Publication **pub;
    cin >> cases;
    pub = new Publication *[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> type >> price >> date;
        switch (type)
        {
        case 'B':
            pub[i] = new Book(price, date);
            break;
        case 'T':
            pub[i] = new Tape(price, date);
            break;
        }
    }
    BookStore bookStore(pub, cases);
    cout << "There are " << bookStore.getNumOfBook() << " books and " << bookStore.getNumOfTape() << " tapes.";
    total = 0;
    for (int i = 0; i < cases; i++)
    {
        total += pub[i]->getTotalPrice();
    }
    cout << " Their total price is " << setprecision(2) << fixed << total << "." << endl;
    for (int i = 0; i < cases; i++)
    {
        delete pub[i];
    }
    delete[] pub;
    return 0;
}/* 



Problem F
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4728  Solved: 2709
[Submit][Status]

Sample Input
3
B 0.10 201
T 0.50 100
T 0.40 105
Sample Output
Call Publication's constructor!
Call Book's constructor!
Call Publication's constructor!
Call Tape's constructor!
Call Publication's constructor!
Call Tape's constructor!
Call Publication's constructor!
Call Book's constructor!
Call Publication's constructor!
Call Tape's constructor!
Call Publication's constructor!
Call Tape's constructor!
There are 1 books and 2 tapes. Their total price is 29.50.
Call Book's de-constructor!
Call Publication's de-constructor!
Call Tape's de-constructor!
Call Publication's de-constructor!
Call Tape's de-constructor!
Call Publication's de-constructor!
Call Book's de-constructor!
Call Publication's de-constructor!
Call Tape's de-constructor!
Call Publication's de-constructor!
Call Tape's de-constructor!
Call Publication's de-constructor!
Call BookStore's de-constructor!


Append Code
append.cc, */