#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
typedef struct Race
{
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriveName[20];
    char firstPlaceRaceCarColor[20];
}Race;

typedef struct RaceCar
{
    char drivername[20];
    char raceCarColor[20];
    int totalLapTime;
}RaceCar;
// Print functions section
void printIntro(){
    printf("Welcome to our main event digital race fans!\nI hope everybody has thier snacks because we are about to\nbegin!\n");
}

void printCountDown(){
    printf("Racers Ready! In...\n");
    for(int i =5 ; i > 0 ; i--){
        printf("%d\n", i);
    }
    printf("Race!\n");
}

void printFirstPlaceAfterLap(Race race)
{


    printf("After lap number %d\n", race.currentLap);
    printf("First place is: %s in the %s race car!\n", race.firstPlaceDriveName , race.firstPlaceRaceCarColor);
    race.currentLap++;

}
void printCongratulation(Race race){
    printf("let's all congratulate %s in the %s race car for an amazing\n"
           "performance.\nIt truly was a great race for everybody have a goodnight!", race.firstPlaceDriveName , race.firstPlaceRaceCarColor);
}


// Logic functions section
int calculateTimeToCompleteLap(){
    int speed, acceleration, nerves;
    speed =(rand() % 3) + 1 ;
    acceleration = (rand() % 3) + 1 ;
    nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;

}

void updateRaceCar(RaceCar* raceCar)
{
    raceCar->totalLapTime += calculateTimeToCompleteLap();

}

void updateFirstPlace(Race* race, RaceCar* raceCar1, RaceCar* raceCar2)
{
    if(raceCar1->totalLapTime <= raceCar2->totalLapTime)
    {
        strcpy( race-> firstPlaceDriveName , raceCar1->drivername);
        strcpy(race-> firstPlaceRaceCarColor, raceCar1 ->raceCarColor );
    }
    else
    {
        strcpy(race-> firstPlaceDriveName , raceCar2->drivername );
        strcpy(race-> firstPlaceRaceCarColor, raceCar2 ->raceCarColor);
    }
}

void startRace(RaceCar* raceCar1, RaceCar* raceCar2)
{
    Race race = { 3, 1, "David", "green"};
    for(int i=0 ; i < race.numberOfLaps ; i++)
    {
        updateRaceCar(raceCar1);// 7
        updateRaceCar(raceCar2);// 9
        updateFirstPlace(&race , raceCar1 , raceCar2);// car1:12 <= 16 -> car 1 first
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    }
    printCongratulation(race);
}

int main() {

    RaceCar raceCar1 = {"Alon", "red", 6};
    RaceCar raceCar2 = {"Binny", "blue", 6};

    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
    srand(time(0));

};