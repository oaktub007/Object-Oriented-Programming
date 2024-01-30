#include <iostream>
using namespace std;

class patient{
    public:
    int patient_id;
    string myState;
    bool conscious;
    string trolleyId;
    string affliction;
};

class trolley{
    public:
    string trolleyId;
    bool TrolleyInUse;
};

class tracker{
    public:
    int DeviceId;
    string Location;
    bool TrolleyInUse;
};


