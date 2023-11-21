/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100
#define BASE_FARE 50.0
#define FARE_PER_KM 10.0
#define CANCELLATION_FEE 20.0

struct passenger
{
    char name[20];
    char location[20];
    char drop_location[20];
    int balance;
    int last_driver;
};

struct driver
{
    char name[20];
    char car[20];
    int status;
    char location[20];
};

struct passenger p[MAX];
struct driver d[MAX];
int n=0,m=0;

void add_driver()
{
    printf("Enter the name of the driver:\n");
    scanf("%s",d[n].name);
    printf("Enter the car details:\n");
    scanf("%s",d[n].car);
    printf("Enter the location:\n");
    scanf("%s",d[n].location);
    d[n].status=1;
    n++;
}

void add_passenger()
{
    printf("Enter the name of the passenger:\n");
    scanf("%s",p[m].name);
    printf("Enter the location:\n");
    scanf("%s",p[m].location);
    printf("Enter balance");
    scanf("%d",p[m].balance);
    m++;
}

void request_ride()
{
    if(n==0)
    {
        printf("Error: No drivers have been added. Please add a driver before requesting a ride");
        return;
    }
    if(m==0)
    {
        printf("Error: No passengers have been added. Please add a passenger before requesting a ride");
        return;
    }
    char same_driver;
    printf("Do you want to book the same driver again? (y/n)\n");
    scanf(" %c", &same_driver);
    if(same_driver == 'y' || same_driver == 'Y')
    {
        if(d[p[m].last_driver].status == 0)
        {
            printf("Driver %d has been booked.\n", p[m].last_driver);
            d[p[m].last_driver].status = 1;
        }
        else
        {
            printf("The last driver is not available.\n");
        }
    }
    float min_distance = -1;
    int min_index = -1;
    int i;
    printf("Enter your drop location:\n");
    scanf("%s",p[m].drop_location);
    for(i=0; i<n; i++)
    {
        if(d[i].status==1)
        {
            float distance;
            printf("Enter the distance of driver %s from the passenger:\n",d[i].name);
            scanf("%f",&distance);
            if(min_distance==-1 || distance<min_distance)
            {
                min_distance = distance;
                min_index = i;
            }
        }
    }
    if(min_index==-1)
    {
        printf("No drivers available\n");
        return;
    }
    printf("Driver %s is available\n",d[min_index].name);
    printf("Do you want to book this driver?\n");
    printf("1.Yes\n2.No\n");
    int j;
    scanf("%d",&j);
    if(j==1)
    {
        printf("Ride booked\n");
        d[min_index].status=0;
    }
    else
    {
        printf("Driver not booked\n");
    }
}

void complete_ride()
{
    int i;
    char loc[20];
    printf("Enter the location:\n");
    scanf("%s",loc);
    for(i=0; i<n; i++)
    {
        if(strcmp(p[i].drop_location,loc)==0)
        {
            printf("Ride completed\n");
            d[i].status=1;
            p[i].last_driver=i;
            break;
        }
    }
}

#define CANCELLATION_FEE 20.0

void cancel_ride()
{
    int i;
    char loc[20];
    printf("Enter the location:\n");
    scanf("%s", loc);
    for(i=0; i<n; i++)
    {
        if(strcmp(p[i].location, loc) == 0)
        {
            printf("Ride cancelled\n");
            p[i].balance -= CANCELLATION_FEE;
            printf("Cancellation fee of %.2lf has been deducted from your balance. Your new balance is: %.2lf\n", CANCELLATION_FEE, p[i].balance);
            d[i].status = 1;
            break;
        }
    }
}

double calculatefare(double distance)
{
    double totalfare = BASE_FARE + FARE_PER_KM*distance;
    return totalfare;
}

void display()
{
    int i;
    printf("Drivers:\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t%s\t%s\t%d\n",d[i].name,d[i].car,d[i].location,d[i].status);
    }
    printf("Passengers:\n");
    for(i=0; i<m; i++)
    {
        printf("%s\t%s\t%d\n",p[i].name,p[i].location,p[i].balance);
    }
}

int main(void)
{
    int ch;
    double distance;
    while(1)
    {
        printf("1.Add a driver\n2.Add a passenger\n3.Request a ride\n4.Complete a ride\n5.Cancel a ride\n6.Calculate ride fare\n7.Display\n8.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: add_driver();
                    break;
            case 2: add_passenger();
                    break;
            case 3: request_ride();
                    break;
            case 4: complete_ride();
                    break;
            case 5: cancel_ride();
                    break;
            case 6: printf("Enter the distance in km: ");
                    scanf("%lf",&distance);
                    printf("Total fare: %lf\n",calculatefare(distance));
                    break;
            case 7: display();
                    break;
            case 8: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define structures for Location,Driver, Passenger, and Ride
typedef struct{
    double x;
    double y;
}Coordinate;

typedef struct {
    char name[50];
    char carDetails[50];
    int availability; // 1 if available, 0 if not available
    Coordinate location;
} Driver;

typedef struct {
    char name[50];
    Coordinate location;
} Passenger;

typedef struct {
    int driverIndex;
    int passengerIndex;
    Coordinate startLocation;
    Coordinate endLocation;
    double distance;
    double fare;
    int completed; // 1 if completed, 0 if not completed
} Ride;

// Define arrays to store information
#define MAX_DRIVERS 100
#define MAX_PASSENGERS 100
#define MAX_RIDES 100
Driver drivers[MAX_DRIVERS];
Passenger passengers[MAX_PASSENGERS];
Ride rides[MAX_RIDES];

int numDrivers = 0;
int numPassengers = 0;
int numRides = 0;

double calculateFare(double distance) {
    // Assuming a base fare of $1 per kilometer
    return 30 * distance;
}
// Function to add a driver
void addDriver(char name[], char carDetails[], Coordinate location) {
    if (numDrivers < MAX_DRIVERS) {
        Driver newDriver;
        strcpy(newDriver.name, name);
        strcpy(newDriver.carDetails, carDetails);
        newDriver.availability = 1; // Initially available
        newDriver.location = location;

        drivers[numDrivers++] = newDriver;
        printf("Driver %s added successfully.\n", name);
    } else {
        printf("Maximum number of drivers reached.\n");
    }
}

// Function to add a passenger
void addPassenger(char name[], Coordinate location) {
    if (numPassengers < MAX_PASSENGERS) {
        Passenger newPassenger;
        strcpy(newPassenger.name, name);
        newPassenger.location = location;

        passengers[numPassengers++] = newPassenger;
        printf("Passenger %s added successfully.\n", name);
    } else {
        printf("Maximum number of passengers reached.\n");
    }
}

double calculateDistance(Coordinate a, Coordinate b) {
    double xDiff = a.x - b.x;
    double yDiff = a.y - b.y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Function to request a ride
void requestRide(char passengerName[]) {
    if (numPassengers == 0 || numDrivers == 0) {
        printf("No passengers or drivers available.\n");
        return;
    }

    // Check if the passenger exists in the system
    int passengerExists = 0;
    int passengerIndex = -1;
    for (int i = 0; i < numPassengers; ++i) {
        if (strcmp(passengerName, passengers[i].name) == 0) {
            passengerExists = 1;
            passengerIndex = i;
            break;
        }
    }

    if (!passengerExists) {
        printf("Passenger %s not found in the system.\n", passengerName);
        return;
    }

    // Retrieve the passenger's location
    Coordinate destination = passengers[passengerIndex].location;

    // Find the nearest available driver
    int nearestDriverIndex = -1;
    double minDistance = INFINITY;
    for (int i = 0; i < numDrivers; ++i) {
        if (drivers[i].availability == 1) {
            double distance = calculateDistance(drivers[i].location,destination);
            if (distance < minDistance) {
                minDistance = distance;
                nearestDriverIndex = i;
            }
        }
    }

    if (nearestDriverIndex == -1) {
        printf("No drivers available.\n");
        return;
    }

    // Create a new ride
    // Create a new ride
    Ride newRide;
    newRide.driverIndex = nearestDriverIndex;
    newRide.passengerIndex = passengerIndex;
    newRide.startLocation = passengers[passengerIndex].location;
    newRide.endLocation = destination;
    newRide.distance = minDistance;
    newRide.fare = calculateFare(minDistance);
    newRide.completed = 0;
    if (nearestDriverIndex != -1 && drivers[nearestDriverIndex].availability == 1) 
    {
        // Assign the ride to the nearest available driver
        Ride newRide;
        newRide.driverIndex = nearestDriverIndex;
        newRide.passengerIndex = passengerIndex; // Index of the requesting passenger
        newRide.distance = minDistance;
        newRide.fare = calculateFare(minDistance);
        newRide.completed = 0;
        rides[numRides++] = newRide;
        // Update driver's availability and location
        drivers[nearestDriverIndex].availability = 0;
        drivers[nearestDriverIndex].location = destination;

        printf("Ride index: %d assigned to driver %s. Start location: (%.2f, %.2f). End location: (%.2f, %.2f). Distance: %.2f km. Fare: $%.2f\n",
       numRides - 1, drivers[nearestDriverIndex].name, newRide.startLocation.x, 
       newRide.startLocation.y, newRide.endLocation.x, newRide.endLocation.y, minDistance, newRide.fare);
    } 
    else 
    {
        printf("No available drivers or drivers are not available.\n");
    }
}



void completeRide(int rideIndex)
{
    if (rideIndex >= 0 && rideIndex < numRides && rides[rideIndex].completed == 0) 
    {
        // Update ride status to completed
        rides[rideIndex].completed = 1;
        // Update driver's availability and location
        int driverIndex = rides[rideIndex].driverIndex;
        drivers[driverIndex].availability = 1;
        drivers[driverIndex].location = passengers[rides[rideIndex].passengerIndex].location;
        printf("Ride completed successfully. Total distance: %.2f km. Total fare: $%.2f\n",
               rides[rideIndex].distance, rides[rideIndex].fare);
    } 
    else 
    {
        printf("Invalid ride index or ride already completed.\n");
    }
}


// Function to cancel a ride
void cancelRide(int rideIndex)
 {
    if (rideIndex >= 0 && rideIndex < numRides && rides[rideIndex].completed == 0) 
    {
        // Update driver's availability and location
        int driverIndex = rides[rideIndex].driverIndex;
        drivers[driverIndex].availability = 1;
        drivers[driverIndex].location = passengers[rides[rideIndex].passengerIndex].location;

        // Remove the ride from the list
        for (int i = rideIndex; i < numRides - 1; ++i)
        {
            rides[i] = rides[i + 1];
        }
        numRides--;
        printf("Ride canceled successfully.\n");
    } 
    else
    {
        printf("Invalid ride index or ride already completed.\n");
    }
}

// Main function for testing
int main(void) 
{
    int choice;
    char name[50], carDetails[50];
    Coordinate location,destination;

    while (1) 
    {
        printf("\n--- Ride Sharing System Menu ---\n");
        printf("1. Add Driver\n");
        printf("2. Add Passenger\n");
        printf("3. Request Ride\n");
        printf("4. Complete Ride\n");
        printf("5. Cancel Ride\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter driver name: ");
                scanf("%s", name);
                printf("Enter car details: ");
                scanf("%s", carDetails);
                printf("Enter location: ");
                scanf("%lf %lf", &location.x, &location.y);
                addDriver(name, carDetails, location);
                break;
            case 2:
                printf("Enter passenger name: ");
                scanf("%s", name);
                printf("Enter location: ");
                scanf("%lf %lf", &location.x, &location.y);
                addPassenger(name, location);
                break;
            case 3:
                printf("Enter passenger name: ");
                scanf("%s", name);
                requestRide(name);
                break;
            case 4:
                printf("Enter ride index to complete: ");
                scanf("%d", &choice);
                completeRide(choice);
                break;
            case 5:
                printf("Enter ride index to cancel: ");
                scanf("%d", &choice);
                cancelRide(choice);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
}