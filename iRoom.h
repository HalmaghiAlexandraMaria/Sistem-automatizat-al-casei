//Header pentru obiectele de tip camera;
#pragma once //directiva pentru preprocesare
#include <vector>
#include <iostream>
#include <fstream>
#include "iSensor.h"
#ifndef IROOM_H
#define IROOM_H
using namespace std;

class IRoom  // base class template
{
public:
    virtual void createRoom() const = 0;
    virtual void readRoom() const = 0;
    virtual void updateRoom() const = 0;
    virtual void deleteRoom() const = 0;
};

class ILiving : public IRoom
{
private:
    vector <ISensor*> sensor =
    {
        new PressureSensor,
        new PressureSensor,
        new TemperatureSensor,
        new HumiditySensor
    };

public:
    virtual void createRoom() const
    {
        ofstream fisier;
        fisier.open("Living.txt");
        cout<<"Living creat\n";
        fisier.close();
    }
    virtual void readRoom() const
    {
        cout<<"*Citire Senzori\n*";
        for (int i = 0; i < sensor.size() ; i++)
        {
            cout<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
    }
    virtual void updateRoom() const
    {
        cout<<"Masuram senzori\n";
        ofstream fisier;
        fisier.open("Living.txt");

        if (fisier.good() == false) //verificare daca exista un fisier pentru stocare
        {
            createRoom();           //parte putin inutila deoarece ofstream iti creeaza deja un fisier
        }
        for (int i = 0; i < sensor.size() ; i++)
        {
            fisier<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
        fisier.close();
    }
    virtual void deleteRoom() const
    {
        if (remove("Living.txt") != 0)
        {
            cout<<"Eroare, nu exista:"<<"Living.txt\n";
        }
        else
        {
            cout<<"S-a sters:"<<"Living.txt\n";
        }
    }
    //metoda pentru introducerea unor noi senzori intr-o camera
    // void newSens(char x){
    //     if (x == 'p'){
    //         sensor.push_back(new PressureSensor);
    //         cout<<"S-a introdus un nou senzor de presiune\n";
    //     }
    //     else if(x == 't'){
    //         sensor.push_back(new TemperatureSensor);
    //         cout<<"S-a introdus un nou senzor de temperatura\n";;
    //     }
    //     else if(x == 'h'){
    //         sensor.push_back(new HumiditySensor);
    //         cout<<"S-a introdus un nou senzor de umiditate\n";
    //     }
    //     else{
    //         cout<<"Argument invalid\n";
    //     }
    // }
};

class IBedroom : public IRoom
{
public:
    virtual void createRoom() const
    {
        ofstream fisier;
        fisier.open("Bedroom.txt");
        cout<<"Bedroom creat\n";
        fisier.close();
    };
    virtual void readRoom() const
    {
        cout<<"*Citire Senzori\n*";
        for (int i = 0; i < sensor.size() ; i++)
        {
            cout<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
    };
    virtual void updateRoom() const
    {
        cout<<"Masuram senzori\n";
        ofstream fisier;
        if (fisier.good() == false) //verificare daca exista un fisier pentru stocare
        {
            createRoom();
        }
        fisier.open("Bedroom.txt");
        for (int i = 0; i < sensor.size() ; i++)
        {
            fisier<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
        fisier.close();
    };
    virtual void deleteRoom() const
    {
        if (remove("Bedroom.txt") != 0)
        {
            cout<<"Eroare, nu exista:"<<"Bathroom.txt\n";
        }
        else
        {
            cout<<"S-a sters:"<<"Bathroom.txt\n";
        }
    };
private:
    vector <ISensor*> sensor
    {
        new PressureSensor,
        new TemperatureSensor,
        new TemperatureSensor,
        new HumiditySensor,
        new PressureSensor,
    };
};

class IBathroom : public IRoom
{
public:
    virtual void createRoom() const
    {
        std::ofstream fisier;
        fisier.open("IBathroom.txt");
        std::cout<<"Bathroom creat\n";
        fisier.close();
    };
    virtual void readRoom() const
    {
        std::cout<<"*Citire Senzori\n*";
        for (int i = 0; i < sensor.size() ; i++)
        {
            std::cout<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
    };
    virtual void updateRoom() const
    {
        std::cout<<"Masuram senzori\n";
        std::ofstream fisier;
        if (fisier.good() == false) //verificare daca exista un fisier pentru stocare
        {
            createRoom();
        }
        fisier.open("Bathroom.txt");
        for (int i = 0; i < sensor.size() ; i++)
        {
            fisier<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
        fisier.close();
    };
    virtual void deleteRoom() const
    {
        if (std::remove("Bathroom.txt") != 0)
        {
            std::cout<<"Eroare, nu exista:"<<"Bathroom.txt\n";
        }
        else
        {
            std::cout<<"S-a sters:"<<"Bathroom.txt\n";
        }
    };
private:
    std::vector <ISensor*> sensor
    {
        new PressureSensor,
        new TemperatureSensor,
        new TemperatureSensor,
        new HumiditySensor,
        new HumiditySensor
    };
};

class IKitchen : public IRoom
{
public:
    virtual void createRoom() const
    {
        std::ofstream fisier;
        fisier.open("Kitchen.txt");
        std::cout<<"Kitchen creat\n";
        fisier.close();
    };
    virtual void readRoom() const
    {
        std::cout<<"Citire Senzori\n";
        for (int i = 0; i < sensor.size() ; i++)
        {
            std::cout<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
    };
    virtual void updateRoom() const
    {
        std::cout<<"Masuram senzori\n";
        std::ofstream fisier;
        fisier.open("Kitchen.txt");

        if (fisier.good() == false) //verificare daca exista un fisier pentru stocare
        {
            createRoom();
        }

        for (int i = 0; i < sensor.size() ; i++)
        {
            fisier<<"Senzor"<< i <<" :"<<sensor.at(i)->readSensor()<<"\n";
        }
        fisier.close();
    };
    virtual void deleteRoom() const
    {
        if (std::remove("Kitchen.txt") != 0)
        {
            std::cout<<"Eroare, nu exista:"<<"Kitchen.txt\n";
        }
        else
        {
            std::cout<<"S-a sters:"<<"Kitchen.txt\n";
        }
    };
private:
    std::vector <ISensor*> sensor
    {
        new PressureSensor,
        new TemperatureSensor,
        new TemperatureSensor,
        new HumiditySensor,
        new HumiditySensor
    };
};
#endif
