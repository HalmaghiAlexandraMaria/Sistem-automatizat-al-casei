#include "iRoom.h"
#ifndef HOUSE_H
#define HOUSE_H
using namespace std;

class House
{
private:
    vector <IRoom*> rooms; // parametru ca si pointer catre un obiect

public:
    void addRoom(IRoom* room)  //parametru ca referinta la un obiect
    {
        rooms.push_back(room);
        cout<<"Camera adaugata\n";
    };
    void removeRoom(int i)
    {
        if (i >= rooms.size())
        {
            cout<<"[EROARE]Indexul de stergere este prea mare\n";
        }
        else
        {
            rooms.erase(rooms.begin() + i);
            cout<<"Camera eliberata"<<endl;
        }
        //vector.begin() returneaza un iterator catre primul element
        //vector.erase(i) sterge containerul la iteratorul i
    };
    void collectRoomData()
    {
        for (int i = 0; i < rooms.size() ; i++)
        {
            rooms.at(i)->updateRoom();
        }
        cout<<"Masurari salvate"<<endl;
    };
    void viewRoomData()
    {
        for (int i = 0; i < rooms.size() ; i++)
        {
            rooms.at(i)->readRoom();
        }
    };
};
#endif
