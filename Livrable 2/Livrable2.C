#include <Arduino.h>        // Inclut la bibliothèque Arduino
#include <BME280I2C.h>      // Inclut la bibliothèque BME280I2C
#include <Wire.h>           // Inclut la bibliothèque Wire
#include <SPI.h>            // Inclut la bibliothèque SPI
#include <SoftwareSerial.h> // Inclut la bibliothèque SoftwareSerial
#include <SD.h>             // Inclut la bibliothèque SD
#include <stdio.h>          // Inclut la bibliothèque standard
#include <stdlib.h>         // Inclut la bibliothèque standard
#define LEDPIN 9            // Définition de la broche de la LED
#define BUTTONV 2           // Définition de la broche du bouton
#define BUTTONR 3           // Définition de la broche du bouton
#define INTERRUPTV 2        // Définition de la broche du bouton
#define INTERRUPTR 3        // Définition de la broche du bouton
#define baudrate 9600       // Définition du baudrate

typedef struct
{                      // Définition de la structure
    bool TEMP_AIRB;    // Activation désactivation du capteur de température de l'air
    int MIN_TEMP_AIR;  // Définition de la température minimale de l'air acceptée par le capteur
    int MAX_TEMP_AIR;  // Définition de la température maximale de l'air acceptée par le capteur
    bool PRESSUREB;    // Activation désactivation du capteur de pression
    int MIN_PRESSURE;  // Définition de la pression minimale acceptée par le capteur
    int MAX_PRESSURE;  // Définition de la pression maximale acceptée par le capteur
    bool HYGRB;        // Activation désactivation du capteur d'hygrométrie
    int MIN_HYGRT;     // Définition de l'hygrométrie minimale acceptée par le capteur
    int MAX_HYGRT;     // Définition de l'hygrométrie maximale acceptée par le capteur
    bool LUMINB;       // Activation désactivation du capteur de luminosité
    int MIN_LUMIN;     // Définition de la luminosité minimale acceptée par le capteur
    int MAX_LUMIN;     // Définition de la luminosité maximale acceptée par le capteur
    int LOG_INTERVAL;  // Définition de l'intervalle de temps entre chaque enregistrement
    int TIMEOUT;       // Définition du temps d'attente
    int FILE_MAX_SIZE; // Définition de la taille maximale du fichier
} variables;           // Définition du nom de la structure

void modeStandard()
{ // Fonction du mode standard
  // TO DO : Ajouter le code pour le mode standard
}

void modeEco()
{ // Fonction du mode économique
  // TO DO : Ajouter le code pour le mode économique
}

void modeMaintenance()
{ // Fonction du mode avancé
  // TO DO : Ajouter le code pour le mode maintenance
}

void modeConfig()
{ // Fonction du mode avancé
  // TO DO : Ajouter le code pour le mode config
}

void inputLuminosite()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer la luminosité
}

void inputTemperature()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer la température
}

void inputHumidite()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer l'humidité
}

void inputPression()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer la pression
}

void inputHygro()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer l'hygrométrie
}

void inputGPS()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer le GPS
}

void inputTime()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer la date et l'heure
}

void version()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour afficher la version
}

void inputRTC()
{ // Fonction appelée lors du mode config
  // TO DO : Ajouter le code pour configurer le RTC
}

void acquisition()
{ // Acquisition de données avec cette fonction
  // TO DO : Ajouter le code pour acquérir les données
}

void inputButtonV()
{ // Fonction appelée lors de l'interruption
  // TO DO : Ajouter le code pour basculer entre les modes
}

void inputButtonR()
{ // Fonction appelée lors de l'interruption
  // TO DO : Ajouter le code pour basculer entre les modes
}

void interruption_initR(void)
{                                                                             // Fonction d'initialisation de l'interruption
    attachInterrupt(digitalPinToInterrupt(INTERRUPTR), inputButtonR, CHANGE); // J'attache l'interruption au bouton
    // TO DO : Ajouter le code pour le rebond du bouton
}

void interruption_initV(void)
{                                                                             // Fonction d'initialisation de l'interruption
    attachInterrupt(digitalPinToInterrupt(INTERRUPTV), inputButtonV, CHANGE); // J'attache l'interruption au bouton
    // TO DO : Ajouter le code pour le rebond du bouton
}

void allumer()
{ // Fonction d'allumage de la LED
    digitalWrite(LEDPIN, HIGH);
    // TO DO : Ajouter le code pour allumer la LED selon le mode choisi
}

void eteindre()
{ // Fonction d'extinction de la LED
    digitalWrite(LEDPIN, LOW);
}

void setup()
{
    Serial.begin(9600);      // Initialisation port série
    pinMode(LEDPIN, OUTPUT); // Initialisation LED
    pinMode(BUTTONV, INPUT); // Initialisation bouton
    pinMode(BUTTONR, INPUT); // Initialisation bouton
    interruption_initR();    // Initialisation interruption
    interruption_initV();    // Initialisation interruption
}

void loop()
{
    // TO DO : Ajouter le code pour que la station fonctionne
}