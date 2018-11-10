#ifndef truck_hpp
#define truck_hpp

#include <stdio.h>
#include "vehicle.hpp"

class Truck : public Vehicle{
public:
    Truck();
    Truck(Point* c, double s = 1.0);
    virtual void design();
    
private:
    /*
     Point *center;
     double height, width, scale;
     double centerX, centerY, leftw_radius, rightw_radius;
     Circle leftw, rightw;
     Line roofT, roofB, roofR, roofL, bodyT, bodyB, bodyR, bodyL;
     Point *leftw_center, *rightw_center, *roofTL, *roofTR, *roofBR, *roofBL, *bodyTL, *bodyTR, *bodyBL, *bodyBR;
     */
};

#endif /* truck_hpp */
