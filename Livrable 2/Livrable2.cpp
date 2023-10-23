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

RTC_DS3231 rtc; // Créez un objet RTC_DS3231

typedef struct variables
{                    // Définition de la structure
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
} variables;         // Définition du nom de la structure

typedef struct capteurs
{
  float humidity;
  float pressure;
  float temp;
  int luminosity;
} capteurs;

void modeStandard()
{                           // Fonction du mode standard
  allumer();                // J'allume la LED pour indiquer que le mode standard est activé
  if (file > FILE_MAX_SIZE) // Si le fichier est plein
  {
    copieFichier(); // Je copie le fichier
  }
  acquisition(); // J'acquiers les données
  // TO DO : Ajouter le code pour le mode standard
}

void modeEco()
{                  // Fonction du mode économique
  allumer();       // allumer la LED en BLEU
  Mesure_inter = 0 // Initialisation de Mesure_intermediaire

      if (file > FILE_MAX_SIZE) // Si le fichier est plein
  {
    copieFichier(); // Je copie le fichier
  }
  acquisition(); // J'acquiers les données

  if (Mesure_inter = 0)
  {
    Mesure_inter = 1
  }
  else
  {
    Mesure_inter = 0 acquisition() // acquisition des valeurs GPS
  }
  // TO DO : Ajouter le code pour le mode économique
}

void modeMaintenance()
{            // Fonction du mode maitenance
  allumer(); // allumer la LED en orange
  // désacivation de la sauvegarde du système
  // Ouverture interface série
  // afficher les valeurs de chaque paramètres ci-dessus
  // TO DO : Ajouter le code pour le mode maintenance
}

void modeConfig()
{            // Fonction du mode config
  allumer(); // Allumer la LED en jaune
  // désactivation des capteurs
  // Ouverture interface série
  inputRTC();         // Cette ligne appelle la fonction inputRTC pour modifier les données de date et d'heure du module RTC.
  inputHumidite();    //  Cette ligne appelle la fonction inputHumidity pour modifier les paramètres d'humidité à partir du moniteur série.
  inputPression();    // Cette ligne appelle la fonction inputPression pour modifier les paramètres de pression à partir moniteur série.
  inputTemperature(); // Cette ligne appelle la fonction inputTemperature pour modifier les paramètres de température à partir du moniteur série.
  inputLuminosite();  // Cette ligne appelle la fonction inputLuminosite pour modifier les paramètres de luminosité à partir du moniteur série.
  inputGPS();         // Cette ligne appelle la fonction inputGPS pour modifier les paramètres GPS à partir du moniteur série.
  // TO DO : Ajouter le code pour le mode config
}

void inputLuminosite()
{ // Fonction appelée lors du mode config
  // Assigner à une variable "lumi" la lecture analogique de la broche A0
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
  DateTime now = rtc.now(); 

  Serial.print("Date: ");
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);  
  Serial.print("  Heure: ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  // TO DO : Ajouter le code pour configurer le RTC
}

void acquisition()
{ // Acquisition de données avec cette fonction dans le mode standard et eco
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
{                                                                           // Fonction d'initialisation de l'interruption
  attachInterrupt(digitalPinToInterrupt(INTERRUPTR), inputButtonR, CHANGE); // J'attache l'interruption au bouton rouge
  // TO DO : Ajouter le code pour le rebond du bouton
}

void interruption_initV(void)
{                                                                           // Fonction d'initialisation de l'interruption
  attachInterrupt(digitalPinToInterrupt(INTERRUPTV), inputButtonV, CHANGE); // J'attache l'interruption au bouton vert
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

void copieFichier()
{ // Fonction de copie du fichier
  // TO DO : Ajouter le code pour copier le fichier
}

void checkGPS()
{ // Fonction de vérification du GPS
  // TO DO : Ajouter le code pour vérifier le GPS
  if (/* Vérification concluante */)
  {
    return; // Je sors de la fonction
  }
  else
  {                               // Sinon
    Serial.println("Erreur GPS"); // J'affiche l'erreur
    while (true)
    {
      allumer(); // J'allume la LED pour indiquer l'erreur (1s rouge et 1s jaune)
    }
  }
}

void checkCapteurs()
{ // Fonction de vérification des capteurs
  // TO DO : Ajouter le code pour vérifier les capteurs
  if (/* Vérification concluante */)
  {
    return; // Je sors de la fonction
  }
  else
  {                                    // Sinon
    Serial.println("Erreur capteurs"); // J'affiche l'erreur
    while (true)
    {
      allumer(); // J'allume la LED pour indiquer l'erreur (1s rouge et 1s verte)
    }
  }
}

void checkEnregistrement()
{ // Fonction de vérification de l'enregistrement
  // TO DO : Ajouter le code pour vérifier l'enregistrement
  if (/* Vérification concluante */)
  {
    return; // Je sors de la fonction
  }
  else
  {                                          // Sinon
    Serial.println("Erreur enregistrement"); // J'affiche l'erreur
    while (true)
    {
      allumer(); // J'allume la LED pour indiquer l'erreur (1s rouge et 2s blanche)
    }
  }
}

void checkSD()
{ // Fonction de vérification de la carte SD
  // TO DO : Ajouter le code pour vérifier la carte SD
  if (/* Vérification concluante */)
  {
    return; // Je sors de la fonction
  }
  else
  {                                    // Sinon
    Serial.println("Erreur carte SD"); // J'affiche l'erreur
    while (true)
    {
      allumer(); // J'allume la LED pour indiquer l'erreur (1s rouge et 1s blanche)
    }
  }
}

void checkConsistency()
{ // Fonction de vérification de la cohérence des données
  // TO DO : Ajouter le code pour vérifier la cohérence des données
  if (/* Vérification concluante */)
  {
    return; // Je sors de la fonction
  }
  else
  {                                             // Sinon
    Serial.println("Erreur cohérence données"); // J'affiche l'erreur
    while (true)
    {
      allumer(); // J'allume la LED pour indiquer l'erreur (1s rouge et 2s verte)
    }
  }
}

void setup()
{
  Serial.begin(9600);      // Initialisation port série
  rtc.begin();             // Initialisation du module RTC
  pinMode(LEDPIN, OUTPUT); // Initialisation LED
  pinMode(BUTTONV, INPUT); // Initialisation bouton
  pinMode(BUTTONR, INPUT); // Initialisation bouton
  interruption_initR();    // Initialisation interruption
  interruption_initV();    // Initialisation interruption
}

void loop()
{
  // ajout d'un switch case avec une variable mode pour pouvoir switch entre les 4 modes

  // TO DO : Ajouter le code pour que la station fonctionne
}
