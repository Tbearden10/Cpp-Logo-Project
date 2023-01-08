#include "Triangle.h"

Triangle::Triangle() {
    mColor = sf::Color(255, 255, 255); 
    coordinateList = new Coordinate[3];
}

Triangle::~Triangle() {
    delete[] coordinateList;
    coordinateList = nullptr;
}

void Triangle::setColor(const sf::Color NEW_COLOR) {
    mColor = NEW_COLOR;
}

void Triangle::draw(sf::RenderTarget& window) {

    // Create convex shape for a new triangle
    sf::ConvexShape newTriangle;

    // Set number of points
    newTriangle.setPointCount(NUM_VERTICIES);

    // for each point on triangle
    for (unsigned int i=0; i < newTriangle.getPointCount(); i++) {
        newTriangle.setPoint(i, sf::Vector2f(coordinateList[i].x, coordinateList[i].y));
    }

    newTriangle.setFillColor(mColor);
    
    window.draw(newTriangle);
    
}


bool ScaleneTriangle::setCoordinates(Coordinate v1, Coordinate v2, Coordinate v3) {

    int s1, // side 1
        s2, // side 2
        s3; // side 3

    // Get side(s) length using distance formula
    s1 = sqrt( pow( (v2.x - v1.x), 2) + pow( (v2.y - v1.y), 2) ); // length of side 1
    s2 = sqrt( pow( (v3.x - v1.x), 2) + pow( (v3.y - v1.y), 2) ); // length of side 2
    s3 = sqrt( pow( (v3.x - v2.x), 2) + pow( (v3.y - v2.y), 2) ); // length of side 3

    // no sides equal 0 AND at least 2 are greater than the 3rd
    if ( (s1 != 0 && s2 != 0 && s3 != 0) && (s2+s3 > s1 || s1+s3 > s2 || s1+s2 > s3) ) 
    {
        // set the cooresponding vertex to the list
        coordinateList[0] = v1;
        coordinateList[1] = v2;
        coordinateList[2] = v3;
        return true;
    } 
    else { return false; }
}

bool EquilateralTriangle::setCoordinates(Coordinate v1, Coordinate v2, Coordinate v3) {

    int s1, // side 1
        s2, // side 2
        s3; // side 3

    // Get side(s) length using distance formula
    s1 = sqrt( pow( (v2.x - v1.x), 2) + pow( (v2.y - v1.y), 2) ); // length of side 1 
    s2 = sqrt( pow( (v3.x - v1.x), 2) + pow( (v3.y - v1.y), 2) ); // length of side 2
    s3 = sqrt( pow( (v3.x - v2.x), 2) + pow( (v3.y - v2.y), 2) ); // length of side 3
    
    bool equalSides = false;

    // checks if all sides are equal
    if ( s1==s2 && s1==s3 && s2==s3 ) 
    {
        equalSides = true;
    }

    // no sides equal 0 AND at least 2 are greater than the 3rd AND all sides are equal
    if ( ( (s1 != 0 && s2 != 0 && s3 != 0) && (s2+s3 > s1 || s1+s3 > s2 || s1+s2 > s3) ) 
        && (equalSides == true) ) 
    {
        // set the cooresponding vertex to the list
        coordinateList[0] = v1;
        coordinateList[1] = v2;
        coordinateList[2] = v3;
        return true;
    } 
    else { return false; }
}

bool IsoscelesTriangle::setCoordinates(Coordinate v1, Coordinate v2, Coordinate v3) {

    int s1, // side 1
        s2, // side 2
        s3; // side 3

    // Get side(s) length using distance formula
    s1 = sqrt( pow( (v2.x - v1.x), 2) + pow( (v2.y - v1.y), 2) ); // length of side 1 
    s2 = sqrt( pow( (v3.x - v1.x), 2) + pow( (v3.y - v1.y), 2) ); // length of side 2
    s3 = sqrt( pow( (v3.x - v2.x), 2) + pow( (v3.y - v2.y), 2) ); // length of side 3
    
    // number of equal sides
    int equalSides = 0;

    // checks if 2 sides are equal
    if ( s1==s2 || s1==s3 || s2==s3 ) { equalSides = 2; }

    // no sides equal 0 AND opposite sides are greater than the 3rd AND 2 sides are equal
    if ( ( (s1 != 0 && s2 != 0 && s3 != 0) && (s1+s3 > s2) ) && (equalSides == 2) ) 
    {
        // set the cooresponding vertex to the list
        coordinateList[0] = v1;
        coordinateList[1] = v2;
        coordinateList[2] = v3;
        return true;
    } 
    else { return false; }
}