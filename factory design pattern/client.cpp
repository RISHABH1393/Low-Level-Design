#include "vehicle_factory.hpp"
using namespace std;

int main(){
    string vehiceType;
    cin>>vehiceType;
    Vehicle* vehicle = vehicleFactory::getVehicle(vehiceType);
    vehicle->createVehicle();
    return 0;
}
