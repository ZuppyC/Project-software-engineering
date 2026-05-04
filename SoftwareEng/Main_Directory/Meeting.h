//
// Created by Dell on 26/02/2026.
//

  #ifndef SOFTWAREENG_MEETING_H
  #define SOFTWAREENG_MEETING_H
  #include <string>

#include "Catering.h"
  #include "Participation.h"
  using namespace std;

  class Meeting {
  private:
   Meeting* _initCheck;
   string label;
   string identifier;
   string room;
   tm* date= nullptr;
   bool isOnline= false;
   vector<Participation*> participants;
   bool isBezig= false;
   bool hasCatering= false;
   bool hasExternals= false;
   bool isCanceled= false;
   int hour;
   int occupancy=0;
   bool co2Tracked = false;



  public:

   Meeting();
   /*
    * Constructor voor Meeting
    */


   bool properlyInitialized();

   void setLabel(string label);
   string getLabel();
   /*
    *getters en setters voor de meeting LABEL
    *
    */

   void setId(string id);
   string getId();
   /*
    *
    * getters en setters voor de meetingID
    */

   void setRoom(string roomnr);
   string getRoom();
   /*
    *
    * getters en setters voor een room
    */

   void setDate(const string& string);
   tm* getDate() const;
   /*
    * getters en setters voor de meeting DATE
    *
    */

   void setPart(Participation* part);
   vector<Participation*> getPart() const;
   /*
    * getters en setters voor participations in de meeting
    *
    */

   tm* strToTm(const string& datum);
   /*
    * functie die een string omzet naar tm
    *
    */

   bool isPast();
   /*
    * functie die kijkt of de meeting in het verleden ligt
    *
    */

   bool conflictsWith(Meeting *m);
   /*
    * functie die checkt of deze meeting conflicteert met een andere meeting
    *
    */

   bool getBezig();
   void setBezig(bool bezig);
   /*
    * getters en setters voor bezig,
    * geeft aan of de meeting al heeft plaatsgevonden
    *
    */

   bool getCanceled();
   void setCanceled(bool canceled);
   /*
    * getters en setters voor canceled,
    * geeft aan of de meeting gecancelled is
    *
    */

   bool getOnline();
   void setOnline(bool online);
   /*
    * getters en setters voor online,
    * geeft aan of de meeting online is
    *
    */

   int getHour();
   void setHour(int h);
   /*
    * getters en setters voor het uur van de meeting
    *
    */

   bool getCo2Tracked();
   void setCo2Tracked(bool tracked);
   /*
    * getters en setters voor co2Tracked,
    * voorkomt dat CO2 meerdere keren wordt berekend
    *
    */

   bool getCatering();
   void setCatering(string catering);
   /*
    * getters en setters voor catering
    *
    */

   bool getExternals();
   void setExternals(string externals);
   /*
    * getters en setters voor externals
    *
    */

   void setOccupancy(int occupancy);
   int getOccupancy();
   /*
    * getters en setters voor occupancy (aantal deelnemers)
    *
    */

   void printMeeting(ofstream& outputFile);
   /*
    * print de meeting naar een output bestand
    *
    */

   double co2ZonderCatering();
   /*
    * berekent de CO2 uitstoot zonder catering
    *
    */

   ~Meeting();
   /*
    * destructor van Meeting
    *
    */
  };


  #endif //SOFTWAREENG_MEETING_H