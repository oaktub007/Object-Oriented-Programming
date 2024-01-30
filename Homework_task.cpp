#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
  string name;
  int age;
  string emailAddress;
  string phoneNumber;
  bool treated;
  string riskStatus;
};

class Trolley {
public:
    string trolleyID;
};

class TrackerDevice {
public:
   string trackerID;
};


int main() {
  Patient patient1;
  Trolley trolley1;
  TrackerDevice tracker1;

  patient1.name = "Callum";
  patient1.age = 18;
  patient1.emailAddress = "Churches@gmail.com";
  patient1.phoneNumber = "072849382";
  patient1.treated = false;
  patient1.riskStatus = "High";

  trolley1.trolleyID = "T195";
  tracker1.trackerID = "TRK035";

  displayInformation(patient1, trolley1, tracker1);

  return 0;
};