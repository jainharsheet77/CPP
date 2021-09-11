#include <bits/stdc++.h>
using namespace std;

enum RideStatus
{
    IDLE,
    CREATED,
    WITHDRAWN,
    COMPLETED
};

class Ride
{
private:
    int id;
    int origin, dest;
    int seats;
    RideStatus rideStatus;

public:
    static const int AMT_PER_KM = 20;
    int calculateFare(bool isPriorityRider)
    {
        int dist = dest - origin;
        if (seats < 2)
        {
            return dist * AMT_PER_KM * (isPriorityRider ? 0.75 : 1);
        }
        return dist * AMT_PER_KM * (isPriorityRider ? 0.75 : 1);
    }
    void setDest(int Dest)
    {
        this->dest = dest;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setOrigin(int origin)
    {
        this->origin = origin;
    }
    void setRideStatus(RideStatus rideStatus)
    {
        this->rideStatus = rideStatus;
    }
    void setSeats(int seats)
    {
        this->seats = seats;
    }
    int getId()
        const
    {
        return id;
    }
    RideStatus getRideStatus()
    {
    }
    Ride()
    {
        id = origin = dest = seats = 0;
        rideStatus = RideStatus::IDLE;
    }
};

class Person
{
public:
    string name;
};

class Driver : private Person
{
public:
    Driver(string name)
    {
        this->name = name;
    }
};

class Rider
{
};
