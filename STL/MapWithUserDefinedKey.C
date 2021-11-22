#include <iostream>
#include <map>
#include <string>

using namespace std;

class Vehicle{
private:
  int wheels;
  string name;
  
public:
  Vehicle(int w, string n):wheels(w), name(n){}
  
  const string& getName() const{
    return this->name;
  }
  
  int getWheels() const {
    return this->wheels;
  }
  
  bool operator < (const Vehicle &v) const {
    if (this->wheels < v.wheels)
      return true;
    else 
      return false;
  }
};

void example_with_less_than_operator_overload()
{
  map<Vehicle, int> vehicle_map;
  
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(2, "scooter"), 100));
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(4, "car"), 1000));
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(3, "rickshaw"), 100));
  
  for (auto [key, value]:vehicle_map){
    cout << "Cost of " << key.getName() << " is " << value << endl;
  }
}

struct vehicleComparator{
  bool operator() (const Vehicle& v1, const Vehicle& v2 ){
    if (v1.getWheels() < v2.getWheels())
      return true;
    else
      return false;
  }
};
  
void example_with_user_defined_comparator()
{
  map<Vehicle, int, vehicleComparator> vehicle_map;
  
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(2, "scooter1"), 100));
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(4, "car1"), 1000));
  vehicle_map.insert(make_pair<Vehicle, int>(Vehicle(3, "rickshaw1"), 100));
  
  for (auto [key, value]:vehicle_map){
    cout << "Cost of " << key.getName() << " is " << value << endl;
  }
}

int main(){
  example_with_less_than_operator_overload();
  example_with_user_defined_comparator();
}

