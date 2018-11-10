#include "vehicle.hpp"

/******************* VEHICLE **********************/
Vehicle::Vehicle(){
    scale = 1.0;
    center = new Point(0, 0);
    centerX = center->get_x();
    centerY = center->get_y();
    height = 9; // default - but can change
    width = 20; // default - but can change
    this->design();
}
Vehicle::Vehicle(Point* c, double s){
    scale = s;
    center = new Point(c->get_x(), c->get_y());
    centerX = center->get_x();
    centerY = center->get_y();
    height = 90 * scale;
    width = 200 * scale;
    
    this->design();
}
void Vehicle::design(){
    
    double roofTLx = (centerX - ((0.25) * width));
    double roofTLy = (centerY + ((0.50) * height));
    double roofTRx = (centerX + ((0.25) * width));
    double roofTRy = roofTLy;
    
    roofTL = new Point(roofTLx, roofTLy);
    roofTR = new Point(roofTRx, roofTRy);
    
    double roofBLx = roofTLx;
    double roofBLy = centerY + ((0.08) * height);
    double roofBRx = roofTRx;
    double roofBRy = roofBLy;
    
    roofBL = new Point(roofBLx, roofBLy);
    roofBR = new Point(roofBRx, roofBRy);
    roofT = Line(*roofTL, *roofTR);
    roofB = Line(*roofBL, *roofBR);
    roofR = Line(*roofTR, *roofBR);
    roofL = Line(*roofTL, *roofBL);
    
    
    double bodyTLx = centerX - ((0.50) * width);
    double bodyTLy = roofBLy;
    double bodyTRx = centerX + ((0.50) * width);
    double bodyTRy = roofBRy;
    
    bodyTL = new Point(bodyTLx, bodyTLy);
    bodyTR = new Point(bodyTRx, bodyTRy);
    
    
    double bodyBLx = bodyTLx;
    double bodyBLy = centerY - ((0.58) * height);
    double bodyBRx = bodyTRx;
    double bodyBRy = bodyBLy;
    
    bodyBL = new Point(bodyBLx, bodyBLy);
    bodyBR = new Point(bodyBRx, bodyBRy);
    
    bodyT = Line(*bodyTL, *bodyTR);
    bodyB = Line(*bodyBL, *bodyBR);
    bodyR = Line(*bodyTR, *bodyBR);
    bodyL = Line(*bodyTL, *bodyBL);
    
    
    double leftwx = centerX - ((0.28) * width);
    double leftwy = centerY - ((0.875) * height);
    leftw_radius = (bodyBLy - leftwy);
    
    double rightwx = centerX + ((0.30) * width);
    double rightwy = leftwy;
    rightw_radius = (bodyBRy - rightwy);
    
    leftw_center = new Point(leftwx, leftwy);
    rightw_center = new Point(rightwx, rightwy);
    leftw = Circle(*leftw_center, leftw_radius);
    rightw = Circle(*rightw_center, rightw_radius);
    
    leftw.move(0, (height/12));
    rightw.move(0, (height/12));
}

vector<Point*> Vehicle::get_points(){
    vector<Point*> points;
    points.push_back(roofTL);
    points.push_back(roofTR);
    points.push_back(roofBL);
    points.push_back(roofBR);
    points.push_back(bodyTL);
    points.push_back(bodyTR);
    points.push_back(bodyBL);
    points.push_back(bodyBR);
    return points;
}
vector<Line> Vehicle::get_lines(){
    vector<Line> lines;
    lines.push_back(roofT);
    lines.push_back(roofB);
    lines.push_back(roofR);
    lines.push_back(roofL);
    lines.push_back(bodyT);
    lines.push_back(bodyB);
    lines.push_back(bodyR);
    lines.push_back(bodyL);
    return lines;
}
vector<Circle> Vehicle::get_circles(){
    vector<Circle> circles;
    circles.push_back(leftw);
    circles.push_back(rightw);
    return circles;
}

/*
 private:
 double scale;
 double height, width;
 double centerX, centerY;
 Circle leftw, rightw;
 Line roofT, roofB, roofR, roofL, bodyT, bodyB, bodyR, bodyL;
 Point center, leftw_center, rightw_center,
 roofTL, roofTR, roofBR, roofBL,
 bodyTL, bodyTR, bodyBL, bodyBR;
 std::vector<Point> points;
 std::vector<Line> lines;
 std::vector<Circle> circles;
 */

