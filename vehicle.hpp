#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include "ccc_shap.h"

using namespace std;

class Vehicle {
public:
    Vehicle();
    Vehicle(Point* c, double s = 1.0);
    virtual void design();
    vector<Point*> get_points();
    vector<Line> get_lines();
    vector<Circle> get_circles();

private:
    Point *center;
    double height, width, scale;
    double centerX, centerY, leftw_radius, rightw_radius;
    Circle leftw, rightw;
    Line roofT, roofB, roofR, roofL, bodyT, bodyB, bodyR, bodyL;
    Point *leftw_center, *rightw_center, *roofTL, *roofTR, *roofBR, *roofBL, *bodyTL, *bodyTR, *bodyBL, *bodyBR;
    /* ^Originally these points were not pointers. Before, #design & #get_points were returning (0, 0) for each point in the vector. This was because, for example, in 'double rooftLx = (center->get_x() + (1/4)*height); ... roofTL = Point(rooftLx, ...);' (1/4) was taken to be an integer, rather than a double, and was rounded to 0.
     I was very confused by this behavior for a long time before finally attempting to use 0.25 instead of 1/4, at which point Point was already changed to Point*.
     Leave it this way for now to see if any future extensions of the class would benefit from utilizing pointers. */
};

#endif /* vehicle_hpp */
