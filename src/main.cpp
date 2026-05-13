#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include "Pig.h"
#include "Bird.h"
#include <set>
#include <vector>
#include <list>

int main() {
    // --- 1. WINDOW SETUP ---
    sf::RenderWindow window(sf::VideoMode(800, 600), "Annoyed_Flocks");
    window.setFramerateLimit(60);

    //Box2D works in meters. SFML works in pixels.
    const float SCALE = 30.0f;

    //Can set a definition for PI.
    const float PI = 3.1415927;

    //Set up Mouse Position variables
    float MousePosX;
    float MousePosY;

    //setup world.
    b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
    b2World world(b2_gravity);

    //Setup ground for the circle to move / bounce on.
    //Needs to have a body definition and a body. We use a raw pointer for the b2Body as Box2d does the management itself.
    //A body can be defined as having a position, velocity, and mass. 
    b2BodyDef b2_groundBodyDef;
    b2_groundBodyDef.position.Set(400.0f / SCALE, 590.0f / SCALE);
    b2Body* b2_groundBody = world.CreateBody(&b2_groundBodyDef);

    //Define a fixture shape that relates to the collision for the ground.
    b2PolygonShape b2_groundBox;
    b2_groundBox.SetAsBox(400.0f / SCALE, 10.0f / SCALE);
    b2_groundBody->CreateFixture(&b2_groundBox, 0.0f);

    //Set up the ground visualisation.
    sf::RectangleShape sf_groundVisual(sf::Vector2f(800.0f, 20.0f));
    sf_groundVisual.setOrigin(400.0f, 10.0f);
    sf_groundVisual.setFillColor(sf::Color(34, 139, 34)); // Forest Green

    //Setting up a wall for the ball to hit.
    b2BodyDef b2_wallDef;
    b2_wallDef.position.Set(750.0f / SCALE, 500.0f / SCALE);
    b2Body* b2_wallBody = world.CreateBody(&b2_wallDef);


    b2PolygonShape b2_wallBox;
    b2_wallBox.SetAsBox(10.0f / SCALE, 80.0f / SCALE);
    b2_wallBody->CreateFixture(&b2_wallBox, 0.0f);

    sf::RectangleShape sf_wallVisual(sf::Vector2f(20.0f, 160.0f));
    sf_wallVisual.setOrigin(10.0f, 80.0f);
    sf_wallVisual.setFillColor(sf::Color::Red);

    //Rather than having an immovable wall, we can use the dynamic body type to create one that can have velocity etc.
    b2BodyDef b2_plankDef;

    b2_plankDef.type = b2_dynamicBody;
    b2_plankDef.position.Set(550.0f / SCALE, 450.0f / SCALE);
    b2Body* b2_plankBody = world.CreateBody(&b2_plankDef);

    b2PolygonShape b2_plankBox;
    b2_plankBox.SetAsBox(10.0f / SCALE, 60.0f / SCALE);

    b2FixtureDef b2_plankFixture;
    b2_plankFixture.shape = &b2_plankBox;
    b2_plankFixture.density = 1.5f;   // Light wood
    b2_plankFixture.friction = 0.3f;
    b2_plankBody->CreateFixture(&b2_plankFixture);

    sf::RectangleShape sf_plankVisual(sf::Vector2f(20.0f, 120.0f));
    sf_plankVisual.setOrigin(10.0f, 60.0f);
    sf_plankVisual.setFillColor(sf::Color(139, 69, 19)); // Brown

    //Create a ball that is fired when space is pressed. We need to first have a dynamic ball to do it.
    //b2BodyDef b2_ballDef;
    //b2_ballDef.type = b2_dynamicBody;
    //b2_ballDef.position.Set(100.0f / SCALE, 500.0f / SCALE);
    //b2Body* b2_ballBody = world.CreateBody(&b2_ballDef); //HEREEEEEEEEEEEEEEEEE

    //b2CircleShape b2_circleShape;
    //b2_circleShape.m_radius = 15.0f / SCALE;

    //b2FixtureDef b2_ballFixture;
    //b2_ballFixture.shape = &b2_circleShape;
    //b2_ballFixture.density = 1.0f;
    //b2_ballFixture.restitution = 0.5f; // Bounciness
    //b2_ballBody->CreateFixture(&b2_ballFixture);

    /*sf::CircleShape sf_ballVisual(15.0f);
    sf_ballVisual.setOrigin(15.0f, 15.0f);*/
    //sf_ballVisual.setFillColor(sf::Color::Yellow);

    /*sf::Texture sf_ballTexture;
    if (!sf_ballTexture.loadFromFile("../assets/Ang_Birds/red.png"))
    {
        std::cout << "Could not load from file";
        return 0;
    }*/

    /*sf::Sprite sf_ballSprite;
    sf_ballSprite.setTexture(sf_ballTexture);
    sf_ballSprite.setScale(sf::Vector2f(0.05, 0.05));*/

    //Setting velocity and Position of bird
    const b2Vec2 SlingshotPos = b2Vec2(100.0f / SCALE, 500.0f / SCALE);
    
    //Move the bird back to beginning
    const b2Vec2 ResetVel = b2Vec2(0, 0);

    //Make a pig
    //Header, would need to change minor things
    //Pig EnemyPig("../assets/Ang_Birds/sprite_1.png");
    b2Vec2 b2_PigPos; //Position of pig
    b2BodyDef b2_PigBodyDef; //Body definition for the object in box2d physics engine
    b2FixtureDef b2_PigFixtureDef; //fixture definition for the object in box2d physics engine
    b2Body* b2_PigBody; //The body for the object
    b2CircleShape b2_dynamicCircle; //The shape of the object, defined as a circle

    //Constructor
    //produce an object in Box2D
    //b2_PigBodyDef.type = b2_dynamicBody;
    //b2_PigBodyDef.position.Set(600.0f / SCALE, 400.0f / SCALE); //orignally in pixels, divide to scale
    ////Create the body in the world
    //b2_PigBody = world.CreateBody(&b2_PigBodyDef);
    //b2_dynamicCircle.m_radius = 15.0f / SCALE; //15 pixels wide

    ////Set up fixtures
    //b2_PigFixtureDef.shape = &b2_dynamicCircle;
    //b2_PigFixtureDef.density = 1.0f;
    //b2_PigFixtureDef.friction = 0.3f;
    //b2_PigFixtureDef.restitution = 0.5f;

    ////Attach to body
    //b2_PigBody->CreateFixture(&b2_PigFixtureDef);

    //New Pig
    Pig BigEnemyPig("../assets/Ang_Birds/EnemyPig.png", b2Vec2(500.0f, 200.0f), world);
    //Pig GeneralPig("../assets/Ang_Birds/sprite_3.png", sf::IntRect(7, 5, 101, 90), sf::Vector2f(650.0f, 200.f), world);
    Bird bird("../assets/Ang_Birds/red.png", b2Vec2(100.0f, 200.0f), world);
    
    //List of Pigs
    std::list < std::unique_ptr<Pig>> ls_pigs; //Make list unique pointers

    for (int i = 0; i < 3; i++) 
    {
        //Create a new bird on the heap and move it into the list
        ls_pigs.push_back(std::make_unique<Pig>("../assets/Ang_birds/EnemyPig.png", b2Vec2(500.0f * 2, 200.0f), world));
    }

    //Make a bird
    //Bird PlayerBird("../assets/Ang_Birds/Angry_Birds.png");

    // --- 7. MAIN LOOP ---
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) 
            {
                MousePosX = (event.mouseMove.x);
                MousePosY = (event.mouseMove.y);
            }

            // INPUT HANDLING: Press MOUSEKEY to launch
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    // Reset position of the ball so that it can be fired again from its original poisition.
                    /*b2_ballBody->SetTransform(b2Vec2(100.0f / SCALE, 500.0f / SCALE), 0);
                    b2_ballBody->SetLinearVelocity(b2Vec2(0, 0));
                    b2_ballBody->SetAngularVelocity(0);*/

                    //Apply impulse (X-axis, Y-axis) Negative Y is UP in Box2D because gravity is positive.
                    //b2_ballBody->ApplyLinearImpulse(b2Vec2(5.0f, -5.0f), b2_ballBody->GetWorldCenter(), true);

                    bird.setVelocity(ResetVel);
                    bird.setPosition(SlingshotPos, 0);
                    bird.Impluse(b2Vec2(MousePosX / 5, -MousePosY / 8), true);

                    std::cout << "Firing!!!!" << std::endl;
                }
            }
        }

        // Update Physics
        world.Step(1.0f / 60.0f, 8, 3);

        //All of the visuals needs to be synced with the physics.

        /*sf_ballVisual.setPosition(b2_ballBody->GetPosition().x * SCALE, b2_ballBody->GetPosition().y * SCALE);
        sf_ballVisual.setRotation(b2_ballBody->GetAngle() * (180.0f / PI));*/

        //Static objects usually don't move, but we set the position once.
        sf_groundVisual.setPosition(b2_groundBody->GetPosition().x * SCALE, b2_groundBody->GetPosition().y * SCALE);
        sf_wallVisual.setPosition(b2_wallBody->GetPosition().x * SCALE, b2_wallBody->GetPosition().y * SCALE);

        // Dynamic wall.
        sf_plankVisual.setPosition(b2_plankBody->GetPosition().x * SCALE, b2_plankBody->GetPosition().y * SCALE);
        sf_plankVisual.setRotation(b2_plankBody->GetAngle() * (180.0f / PI));

        //Pig Update
        //EnemyPig.UpdateSprite(sf::Vector2f( b2_PigBody->GetPosition().x * SCALE, b2_PigBody->GetPosition().y * SCALE)); //Fro pixels and to box2d/vice versa
        BigEnemyPig.UpdateSprite(); //Update every tick based on constructor
        bird.UpdateSprite();
        //GeneralPig.UpdateSprite();
        

        //Render all of the content at each frame. Remember you need to clear the screen each iteration or artefacts remain.
        window.clear(sf::Color(135, 206, 235)); // Sky Blue

        for (std::unique_ptr<Pig>& p : ls_pigs) 
        {
            //p->setLocation(b2Vec2(2.f, 2.f));
            p->UpdateSprite();
            p->render(window);
        }

        window.draw(sf_groundVisual);
        window.draw(sf_wallVisual);
        window.draw(sf_plankVisual);
        //window.draw(sf_ballSprite);
        BigEnemyPig.render(window);
        //GeneralPig.render(window);
        //EnemyPig.render(window);
        bird.render(window);

        window.display();
    }

    return 0;
}