/*
Exercise P8.10. Implement a base class Vehicle and derived classes Car and Truck. A vehicle has a position on the screen. Write virtual functions draw that draw cars and trucks as follows:
Car Truck
Then populate a vector of Vehicle* pointers with a mixture of cars and trucks, and draw all of them.
*/

/*
 Look into why std::cout and fstream do not work here. I would expect at least fstream to function properly. Somehow related to ccc_win_main() and cwin. Cannot output to Xquarts and console in same main function? 
 */

#include <iostream>
#include "ccc_x11.h"
#include "ccc_shap.h"
#include <vector>
#include <fstream>
#include <string>
#include "vehicle.hpp"

using namespace std ;

int ccc_win_main()
{
    Point topleft(-980, 980);
    vector<Vehicle> vehicles;
    
	Point* center1 = new Point(300.0,0.0);
    double scale1 = 1.0;
    Vehicle v1(center1, scale1);
    vehicles.push_back(v1);
    
    Point* center2 = new Point(525.0,-200);
    double scale2 = 2.0;
    Vehicle v2(center2, scale2);
    vehicles.push_back(v2);
    
    Point* center3 = new Point(-400.0,-200);
    double scale3 = 2.7;
    Vehicle v3(center3, scale3);
    vehicles.push_back(v3);
    
    Point* center4 = new Point(-500,600);
    double scale4 = 2.78;
    Vehicle v4(center4, scale4);
    vehicles.push_back(v4);
    
    for (int i = 0; i < vehicles.size(); i++){
        vector<Point*> points = vehicles[i].get_points();
        vector<Line> lines = vehicles[i].get_lines();
        vector<Circle> circles = vehicles[i].get_circles();
        for (int i = 0; i < points.size(); i++){
            //cwin << *(points[i]);
        }
        for (int i = 0; i < lines.size(); i++){
            cwin << lines[i];
        }
        for (int i = 0; i < circles.size(); i++){
            cwin << circles[i];
        }
    }
    
    return 0;
}


 // Useful to copy and paste some of this for tracing
 /*
 string msg1 = "Points[";
 msg1 += static_cast<char>(i);
 msg1 += "].get_x() ";
 string msg2 = "Points[";
 msg2 += i;
 msg2 += "].get_y() ";
 
 Message m1(topleft, msg1);
 topleft.move(650, 0);
 cwin << m1;
 Message m2(topleft, points[i]->get_x());
 topleft.move(300, 0);
 cwin << m2;
 Message m3(topleft, msg2);
 topleft.move(750, 0);
 cwin << m3;
 Message m4(topleft, points[i]->get_y());
 topleft.move(-1700, -50);
 cwin << m4;
 */

