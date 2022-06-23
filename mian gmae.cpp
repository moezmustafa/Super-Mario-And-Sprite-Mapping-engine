
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
using namespace sf; // SFML namespace
using namespace std;

int WindowWidth = 1000;
int WindowHeight = 700;

float  x;
float  y;

// float xToSave ;
// float yToSave;

int w = 16;
int h = 16;

float ReSizeVal = 4;
float ZoomRate = 0.4;



float KeyBoardSpeedValue = 0.5;

int xPos = 0;
int yPos = 0;


bool canZoom = true;

//for grid mapper

int wPos = 0;
int hPos = 0;

int wVel = 0;
int hVel = 0;





//////////////////////////////////////////////////

int main()
{


    RenderWindow window(VideoMode(WindowWidth, WindowHeight), "Mapping Engine");


    Texture tilemap;
    tilemap.loadFromFile("C:/Users/moeez/Desktop/Sprite Mapping Engine/Project2/data files/images/tileset.png");

    Sprite tilemapSprite(tilemap);

    tilemapSprite.scale(ReSizeVal, ReSizeVal);

    //game speed
    Clock GameClock;

    //adding second texture for the grid
    Texture grid;
    grid.loadFromFile("C:/Users/moeez/Desktop/Sprite Mapping Engine/Project2/data files/images/grid(hi).png");
    Sprite gridSprite(grid);
    gridSprite.scale(ReSizeVal, ReSizeVal);




    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();

            }
        }


        float fps = GameClock.restart().asMilliseconds();

        //keyboard events // controls goes here 
        //keyboard events // controls goes here 
        //keyboard events // controls goes here 


        ////////////////////////////////

        //zoom contorls 
        //zoom contorls 
        //zoom contorls 

      //  if (canZoom) {

        if (ReSizeVal <= 50) {
            if (Keyboard::isKeyPressed(Keyboard::Z))
            {
                ReSizeVal += ZoomRate;

                tilemapSprite.setScale(ReSizeVal, ReSizeVal);

                canZoom = false;


            }
        }
        if (ReSizeVal > 4) {
            if (Keyboard::isKeyPressed(Keyboard::X))
            {

                ReSizeVal -= ZoomRate;

                tilemapSprite.setScale(ReSizeVal, ReSizeVal);

                canZoom = false;


            }
        }
        //keys are released, set canZoom to true
        if (!Keyboard::isKeyPressed(Keyboard::Z) && !Keyboard::isKeyPressed(Keyboard::X))
        {

            canZoom = true;
        }

        //}



        // basic controls 
        // basic controls 
        // basic controls 


        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            y = -KeyBoardSpeedValue;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            y = +KeyBoardSpeedValue;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            x = -KeyBoardSpeedValue;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            x = +KeyBoardSpeedValue;
        }



        //Grid Mapper Controls

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            hVel = -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            hVel = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            wVel = -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            wVel = 1;
        }

        if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S))
        {
            hVel = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D))
        {
            wVel = 0;
        }


        //updating the x and y save file values 
        // xToSave = x;
        // yToSave = y;
        //updating the x and y save file values 



        //When keys are released, set the x and y to 0
        if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down))
        {
            y = 0;
        }

        if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right))
        {
            x = 0;
        }


        //zoom in and out
        // if (Keyboard::isKeyPressed(Keyboard::A))
        // {
        //     ReSizeVal1 += 1;

        // }
        // if (Keyboard::isKeyPressed(Keyboard::Z))
        // {
        //     ReSizeVal1 -= 1;
        // }



        cout << canZoom << endl;

        // save the 
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            ofstream myfile;
            myfile.open("C:/Users/moeez/Desktop/Sprite Mapping Engine/Project2/data files/save.txt");
            myfile << "value of x is " << xPos / - ZoomRate << endl;
            myfile << "value of y is " << yPos / - ZoomRate << endl;
            myfile << endl;
            myfile << "value of w is " << w << endl;
            myfile << "value of h is " << h << endl;
            myfile << endl;
            myfile << "value of ReSizeVal is " << ReSizeVal << endl;
            myfile << endl;
            myfile << "value of wPos is grid mapper " << (wPos / ZoomRate) + 16 << endl;
            myfile << "value of hPos is grid mapper " << (hPos / ZoomRate) + 16 << endl;

        }

        // cout << xToSave << endl;
        // cout << yToSave << endl;

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }


        xPos = tilemapSprite.getPosition().x;
        yPos = tilemapSprite.getPosition().y;

        wPos = gridSprite.getPosition().x;
        hPos = gridSprite.getPosition().y;



        window.clear(Color(55, 177, 223));

        window.draw(tilemapSprite); //drawing the tilemap
        window.draw(gridSprite); //drawing the grid
        tilemapSprite.move(x * fps, y * fps); // setting the position of the sprite 
        gridSprite.move(wVel * fps, hVel * fps); // setting the position of the sprite
        window.display();

    }


}