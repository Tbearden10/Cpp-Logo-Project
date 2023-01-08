#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "Triangle.h"
#include "Coordinate.h"

int main() {

    // Create window
    sf::RenderWindow window( sf::VideoMode(640, 640), "Triangle Land" );

    /////////////////////////////////////
    // BEGIN FILE LOADING

    std::ifstream fin;
    fin.open("data/triangles.dat");

    // Check if file failed to open
    if ( fin.fail() ) { std::cerr << "File failed to open"; }

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // Create list of triangle pointers
    std::vector<Triangle*> triangles;

    char T; // triangle type ( S, I, or E )

    double x1, // x coord for vertex 1
           y1, // y coord for vertex 1
           x2, // x coord for vertex 2
           y2, // y coord for vertex 2
           x3, // x coord for vertex 3
           y3; // y coord for vertex 3

    int r, // the integer component of the color red
        g, // the integer component of the color green
        b; // the integer component of the color blue

    // Create coordinate object for each vertex
    Coordinate vertex1, vertex2, vertex3;

    // Read each element until end of file reached
    while ( fin >> T >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b ) 
    {

        // Write x/y values to each vertex
        vertex1.x = x1; vertex1.y = y1;
        vertex2.x = x2; vertex2.y = y2;
        vertex3.x = x3; vertex3.y = y3;

        // type == equilateral 
        if ( T == 'E' ) 
        {

            // Create new equilateral pointer object
            EquilateralTriangle* newEquilateral = new EquilateralTriangle;

            // if valid equilateral, set color and append to triangle list
            if ( newEquilateral->setCoordinates( vertex1, vertex2, vertex3 ) == true ) 
            {
                newEquilateral->setColor( sf::Color( r, g, b ) );
                triangles.push_back( newEquilateral );

            } 
            else 
            {
                std::cout << "triangle is invalid - " << T << " " 
                          << x1 << " " << y1 << " "
                          << x2 << " " << y2 << " " 
                          << x3 << " " << x3 << " " 
                          << r << " " << g << " " << b << std::endl;
            }
        }

        // type == isoceles
        if ( T == 'I' ) 
        {
            // Create new isosceles pointer object
            IsoscelesTriangle* newIsosceles = new IsoscelesTriangle;

            // if valid isosceles, set color and append to triangle list
            if ( newIsosceles->setCoordinates( vertex1, vertex2, vertex3 ) == true ) 
            {
                newIsosceles->setColor( sf::Color( r, g, b ) );
                triangles.push_back( newIsosceles );

            } 
            else 
            {
                std::cout << "triangle is invalid - " << T << " " 
                          << x1 << " " << y1 << " "
                          << x2 << " " << y2 << " " 
                          << x3 << " " << x3 << " " 
                          << r << " " << g << " " << b << std::endl;
            }
        }

        // type == scalene
        if ( T == 'S' ) 
        {
            // Create new scalene pointer object
            ScaleneTriangle* newScalene = new ScaleneTriangle;

            // if valid scalene, set color and append to triangle list
            if ( newScalene->setCoordinates( vertex1, vertex2, vertex3 ) == true ) 
            {
                newScalene->setColor( sf::Color( r, g, b ) );
                triangles.push_back( newScalene );
                

            } 
            else 
            {
                std::cout << "triangle is invalid - " << T << " " 
                          << x1 << " " << y1 << " "
                          << x2 << " " << y2 << " " 
                          << x3 << " " << x3 << " " 
                          << r << " " << g << " " << b << std::endl;
            }
        }
    }

    // Create event object
    sf::Event event;

    // while the window is open
    while( window.isOpen() ) {

        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE
        
        // for each triangle in 'triangles', draw to window
        for ( unsigned int i=0; i < triangles.size(); i++ ) {
            triangles.at( i )->draw( window );
        }

        //  END  DRAWING HERE
        /////////////////////////////////////

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE

        // check if any events happened since the last time checked
        while( window.pollEvent( event ) ) 
        {
            // if event type is 'Closed'
            if ( event.type == sf::Event::Closed ) 
            {
                // close window
                window.close();
            }
        }

        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}