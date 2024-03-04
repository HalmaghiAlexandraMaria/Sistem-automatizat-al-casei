/*
Header pentru implementarea senzorilor

    Nr. de senzori: 2
    Senzori cu functionalitate multipla: 1

    Senzor nr.1 : BMP280
        Functionalitate: Senzor de presiune
        Raza de masurare: 300 -> 1100 hPa
        Acuratete Presiune Absoluta: +- hPa intre 0*C -> 40*C

    Senzor nr.2 : AM2320
        Functionalitate: Senzor de temperatura si de umiditate
        Raza de masurare temperatura: -40 *C -> 80*C
        Raza de masurare umiditate: 0% -> 99.9%
        Acuratete Temperatura : +- 0.5
        Acuratete Umiditate: +-3% la 25*C
*/
#pragma once //directiva pentru preprocesare
#include <stdlib.h>
#include <iostream>
#include "stdio.h"
#include <time.h>
#ifndef ISENSOR_H
#define ISENSOR_H
using namespace std;
class ISensor
{
public:
    virtual double readSensor() const = 0; // metoda virtuala pura
};

class PressureSensor : public ISensor
{
    double generatePresure() const; // 300 -> 1100 hPa
public:
    virtual double readSensor() const;
};

class TemperatureSensor : public ISensor
{
    double generateTemperature() const; //-40 *C -> 80*C
public:

    virtual double readSensor() const;
};

class HumiditySensor : public ISensor
{
    double generateHumidity() const; // 0% -> 99.9%
public:

    virtual double readSensor() const;
};

// metode ale claselor
double PressureSensor::generatePresure() const
{
    // 300 -> 1100 hPa
    srand(clock());
    return rand() % 801 + 300;
}

double PressureSensor::readSensor() const
{
    return generatePresure();
}

double TemperatureSensor::generateTemperature() const
{
    //-40 *C -> 80*C
    srand(clock());
    double temp = (rand() % 121 + 1) - 40;
    return temp;
}
double TemperatureSensor::readSensor() const
{
    return generateTemperature();
}

double HumiditySensor::generateHumidity() const
{
    // 0% -> 99.9%
    srand(clock());
    return (rand() & 999) / 10.0;
}
double HumiditySensor::readSensor() const
{
    return generateHumidity();
}
#endif

