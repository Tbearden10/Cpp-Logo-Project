#ifndef TRIANGLE_H
#define TRIAGNLE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "Coordinate.h"

class Triangle {
    public:
        Triangle();
        ~Triangle();
        void setColor( const sf::Color NEW_COLOR );
        void draw( sf::RenderTarget& window );
        virtual bool setCoordinates( Coordinate v1, Coordinate v2, Coordinate v3 ) = 0;
    protected:
        const int NUM_VERTICIES = 3;
        Coordinate* coordinateList;
    private:
        sf::Color mColor;
};

class ScaleneTriangle : public Triangle {
    public:
        bool setCoordinates( Coordinate v1, Coordinate v2, Coordinate v3 ) override;
};

class EquilateralTriangle : public Triangle {
    public:
        bool setCoordinates( Coordinate v1, Coordinate v2, Coordinate v3 ) override;
};

class IsoscelesTriangle : public Triangle {
    public:
        bool setCoordinates( Coordinate v1, Coordinate v2, Coordinate v3 ) override;
};

#endif