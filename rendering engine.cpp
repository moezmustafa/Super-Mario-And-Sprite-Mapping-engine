//fucking SFML



#include<iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


using namespace std;
using namespace sf;

int WindowWidth = 900;
int WindowHeight = 800;

int HalfWindowWidth = WindowWidth / 2;
int HalfWindowHeight = WindowHeight / 2;

int zoomValue = 5;








class SkyClass
{
public:


    Sprite image;
    float scale = 1;

    SkyClass(float initxPos, float inityPos, Sprite image)
    {
        this->image = image;
        image.setPosition(initxPos, inityPos);
        image.setScale(scale, scale);
    }
};

class PlatformClass
{
public:
    float xPos;
    float yPos;
    float xValue;
    float yValue;

    float topSide;
    float bottomSide;
    float rightSide;
    float leftSide;

    Sprite image;
    int scale;
    PlatformClass(float initxPos, float inityPos, Sprite sprite)
    {
        image = sprite;
        scale = 3;
        image.setPosition(initxPos, inityPos);
        image.setScale(scale, scale);

        leftSide = image.getPosition().x;
        rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
        topSide = image.getPosition().y;
        bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);


        /*  xPos = xPos;
          yPos = yPos;*/

    }
};



class PlayerClass {


public:

    bool OnGround = false;

    bool PlayerFaceRight;

    float xValue;
    float yValue;
    float xPos;
    float yPos;

    float topSide;
    float bottomSide;
    float rightSide;
    float leftSide;

    int scale = 1;


    Sprite image;

    PlayerClass(Sprite sprite) {

        image = sprite;
        cout << "You are inside the player class of this code " << endl;

        PlayerFaceRight = true;
        xPos = 0;
        yPos = 0;
        xValue = 0;
        yValue = 0;
        scale = 1;

    }

    //player update and controls class

    void Update(bool PlayerUp, bool PlayerDown, bool PlayerRight, bool PlayerLeft, PlatformClass platform)
    {
        if (PlayerRight)
        {
            PlayerFaceRight = true;

            xValue = -2;
        }
        if (PlayerLeft)
        {
            PlayerFaceRight = false;
            xValue = 2;
        }

        if (PlayerUp)
        {
            yValue = -2;
        }

        if (PlayerDown < HalfWindowWidth)
        {
            if (PlayerDown)
            {
                yValue = 2;
            }
        }

        if (!(PlayerRight || PlayerLeft))
        {
            xValue = 0;
        }
        if (!(PlayerUp || PlayerDown))
        {
            yValue = 0;
        }


        //gravity 

        if (OnGround == true)
        {
            yValue = 0;
        }

        xPos += xValue;
        yPos += yValue;


        // cout << xValue << endl;
        // cout << yValue << endl;

        cout << endl;
        cout << xPos << endl;
        cout << yPos << endl;
        cout << OnGround;
        cout << endl;



        leftSide = image.getPosition().x;
        rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
        topSide = image.getPosition().y;
        bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);

        //calling the collision function 
        //calling the collision function 
        //calling the collision function 
        Collide();                              //extra old code 
        Collision(platform);

        //calling the collision function 
        //calling the collision function 
        //calling the collision function 



    }

    //player collision classs

    void Collide()
    {
        /* if (xPos > 100)
         {
             xValue = 0;
         }

         */

        if (yPos > 500)
        {
            OnGround = true;
        }
        else
        {
            OnGround = false;
        }
    }


    void Collision(PlatformClass platform)
    {
        if (rightSide > platform.leftSide && leftSide < platform.rightSide &&
            bottomSide > platform.topSide && topSide < platform.bottomSide)
        {
            image.setPosition(Vector2f(platform.leftSide - image.getLocalBounds().width * scale, image.getPosition().y));
        }

    }

};


int main()
{



    RenderWindow window(VideoMode(WindowWidth, WindowHeight), "Super Mario Clone");
    // CircleShape shape(100.f);
     //shape.setFillColor(Color::Blue);

    bool PlayerUp, PlayerDown, PlayerLeft, PlayerRight;

   


    // Loading The Texture Files 
   /* Texture apple;
    apple.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/Project1/apple.png");
    Sprite appleSprite(apple);*/


    //PlayerTexture 
    //PlayerTexture 
    //PlayerTexture 
    Texture player;
    player.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/characters.png");
    Sprite playerSprite(player);
    playerSprite.setTextureRect(IntRect(0, 0, 15.5, 32));
    playerSprite.setScale(zoomValue, zoomValue);


    //Platform Texture
    //Platform Texture
    //Platform Texture
    Texture platform;
    platform.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/platform.png");
    Sprite PlatformSprite(platform);
    PlatformSprite.setScale(zoomValue, zoomValue);

    Texture  Tree;
    Tree.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/tree.png");
    Sprite TreeSprite(Tree);
    TreeSprite.setScale(zoomValue, zoomValue);



    Texture Sky;
    Sky.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/sky(4).png");
    Sprite SkySprite(Sky);
    SkySprite.setScale(zoomValue, zoomValue);


    Texture Water;
    Water.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/water.png");
    Sprite WaterSprite(Water);
    WaterSprite.setScale(zoomValue, zoomValue);

    Texture mushroom;
    mushroom.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/images/mushroom.png");
    Sprite mushroomSprite(mushroom);
    mushroomSprite.setScale(zoomValue, zoomValue);





    float MainXPos = 0;
    float MainYPos = 0;


 /*   SoundBuffer MusicBuffer;
    MusicBuffer.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/data files/audio/audio.wav");

    Sound Music(MusicBuffer);
    Music.play();
    Music.setVolume(50.f);*/

    PlayerClass PlayerObject(playerSprite);

    PlatformClass PlatformObject(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject2(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject3(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject4(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject5(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject6(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject7(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject8(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject9(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject10(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject11(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject12(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject13(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject14(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject15(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject16(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject17(MainXPos, MainYPos, PlatformSprite);
    PlatformClass PlatformObject18(MainXPos, MainYPos, PlatformSprite);

    SkyClass SkyObject(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject2(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject3(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject4(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject5(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject6(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject7(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject8(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject9(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject10(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject11(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject12(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject13(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject14(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject15(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject16(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject17(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject18(MainXPos, MainYPos, SkySprite);
    SkyClass SkyObject19(MainXPos, MainYPos, SkySprite);








    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        /*window.clear();
        window.draw(apple);
        window.display();*/


        //While shit is being pressed 
        //While shit is being pressed 
        //While shit is being pressed 

        if (Keyboard::isKeyPressed(Keyboard::Right)) PlayerRight = true;
        if (Keyboard::isKeyPressed(Keyboard::Left)) PlayerLeft = true;
        if (Keyboard::isKeyPressed(Keyboard::Up)) PlayerUp = true;
        if (Keyboard::isKeyPressed(Keyboard::Down)) PlayerDown = true;

        //While shit is not being pressed
        //While shit is not being pressed
        //While shit is not being pressed
        if (!(Keyboard::isKeyPressed(Keyboard::Right))) PlayerRight = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Left))) PlayerLeft = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Up))) PlayerUp = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Down))) PlayerDown = false;



        PlayerObject.Update(PlayerUp, PlayerDown, PlayerLeft, PlayerRight, PlatformObject);


        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
       /* cout << PlayerDown << endl;
        cout << PlayerUp << endl;
        cout << PlayerRight << endl;
        cout << PlayerLeft << endl;*/
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 







        //clearing the screen 
        window.clear();

        PlayerObject.image.move(Vector2f(PlayerObject.xValue, PlayerObject.yValue));






        window.draw(SkyObject.image);
        window.draw(SkyObject2.image);
        window.draw(SkyObject3.image);
        window.draw(SkyObject4.image);
        window.draw(SkyObject5.image);
        window.draw(SkyObject6.image);
        window.draw(SkyObject7.image);
        window.draw(SkyObject8.image);
        window.draw(SkyObject9.image);
        window.draw(SkyObject10.image);
        window.draw(SkyObject11.image);
        window.draw(SkyObject12.image);
        window.draw(SkyObject13.image);
        window.draw(SkyObject14.image);
        window.draw(SkyObject15.image);
        window.draw(SkyObject16.image);
        window.draw(SkyObject17.image);
        window.draw(SkyObject18.image);
        window.draw(SkyObject19.image);







        /* window.draw(appleSprite);*/
        window.draw(PlatformObject.image);
        window.draw(PlatformObject2.image);
        window.draw(PlatformObject3.image);
        window.draw(PlatformObject4.image);
        window.draw(PlatformObject5.image);
        window.draw(PlatformObject6.image);
        window.draw(PlatformObject7.image);
        window.draw(PlatformObject8.image);
        window.draw(PlatformObject9.image);
        window.draw(PlatformObject10.image);
        window.draw(PlatformObject11.image);
        window.draw(PlatformObject12.image);
        window.draw(PlatformObject13.image);
        window.draw(PlatformObject14.image);
        window.draw(PlatformObject15.image);
        window.draw(PlatformObject16.image);
        window.draw(PlatformObject17.image);
        window.draw(PlatformObject18.image);



        window.draw(TreeSprite);



        window.draw(mushroomSprite);

        window.draw(PlayerObject.image);








        PlatformObject.image.setPosition(0, 650);
        PlatformObject2.image.setPosition(50, 650);
        PlatformObject3.image.setPosition(100, 650);
        PlatformObject4.image.setPosition(150, 650);
        PlatformObject5.image.setPosition(200, 650);
        PlatformObject6.image.setPosition(250, 650);
        PlatformObject7.image.setPosition(300, 650);
        PlatformObject8.image.setPosition(350, 650);
        PlatformObject9.image.setPosition(400, 650);
        PlatformObject10.image.setPosition(450, 650);
        PlatformObject11.image.setPosition(500, 650);
        PlatformObject12.image.setPosition(550, 650);
        PlatformObject13.image.setPosition(600, 650);
        PlatformObject14.image.setPosition(650, 650);
        PlatformObject15.image.setPosition(700, 650);
        PlatformObject16.image.setPosition(750, 650);
        PlatformObject17.image.setPosition(800, 650);
        PlatformObject18.image.setPosition(850, 650);


        TreeSprite.setPosition(50, 420);
        mushroomSprite.setPosition(400, 575);

        SkyObject.image.setPosition(0, 0);
        SkyObject2.image.setPosition(50, 0);
        SkyObject3.image.setPosition(100, 0);
        SkyObject4.image.setPosition(150, 0);
        SkyObject5.image.setPosition(200, 0);
        SkyObject6.image.setPosition(250, 0);
        SkyObject7.image.setPosition(300, 0);
        SkyObject8.image.setPosition(350, 0);
        SkyObject9.image.setPosition(400, 0);
        SkyObject10.image.setPosition(450, 0);
        SkyObject11.image.setPosition(500, 0);
        SkyObject12.image.setPosition(550, 0);
        SkyObject13.image.setPosition(600, 0);
        SkyObject14.image.setPosition(650, 0);
        SkyObject15.image.setPosition(700, 0);
        SkyObject16.image.setPosition(750, 0);
        SkyObject17.image.setPosition(800, 0);
        SkyObject18.image.setPosition(850, 0);
        SkyObject19.image.setPosition(900, 0);





        //Draw the sprite 


        //update the window
        window.display();
    }

    return 0;
}


