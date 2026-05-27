#include <gtest/gtest.h>
#include "Enemy.h"
#include "Bird.h"
#include "Pig.h"
#include "../include/Bird.h"
#include "Slingshot.h"
#include <vector>
#include <list>

/// <summary>
///Taken from the GoogleTest primer. 
/// </summary>

//extern std::list < std::unique_ptr<Bird>> ls_birds;

// The fixture for testing class Foo.
class EnemyTest : public testing::Test {
public:
    std::unique_ptr<Enemy> enemy;
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    EnemyTest() {
        // You can do set-up work for each test here.
                    
    }

    ~EnemyTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        enemy = std::make_unique<Enemy>(50); // All enemnies in this test suite start with 50 HP.
                    
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }


};

class BirdTest : public testing::Test {
public:
    std::list < std::unique_ptr<Bird>> ls_birds;


protected:


    BirdTest() {
        //Set up variables
        b2Vec2 b2_gravity(0.0f, 9.8f); // Earth-like gravity
        b2World world(b2_gravity);
        const float SCALE = 30.0f;

        //Bird bird("../assets/Ang_Birds/red.png", b2Vec2(150.0f, 200.0f), world);
        ls_birds.push_back(std::make_unique<Bird>("../assets/Ang_birds/Chuck.png", b2Vec2((75.0f / SCALE), 200.0f / SCALE), world));
        ls_birds.push_back(std::make_unique<Bird>("../assets/Ang_birds/Jay.png", b2Vec2((70.0f / SCALE), 200.0f / SCALE), world));
    }

    ~BirdTest() override {

    }

    //Function
    void TestFunction() {
        for (std::unique_ptr<Bird>& b : ls_birds)
        {
            b->UpdateSprite();
        }

    }
};

class PigTest : public testing::Test {
public:
    std::list < std::unique_ptr<Pig>> ls_pigs;

protected:


    PigTest() {
        //Set up variables
        b2Vec2 b2_gravity(0.0f, 9.8f);
        b2World world(b2_gravity);
        const float SCALE = 30.0f;
        
        //Create a new bird on the heap and move it into the list
        ls_pigs.push_back(std::make_unique<Pig>("../assets/Ang_birds/EnemyPig.png", b2Vec2((200.0f / SCALE) * 1, 200.0f / SCALE), world));
        ls_pigs.push_back(std::make_unique<Pig>("../assets/Ang_birds/EnemyPig.png", b2Vec2((200.0f / SCALE) * 2, 200.0f / SCALE), world));
        ls_pigs.push_back(std::make_unique<Pig>("../assets/Ang_birds/EnemyPig.png", b2Vec2((200.0f / SCALE) * 3, 200.0f / SCALE), world));
        
    }


    ~PigTest() override {

    }

    //Function
    void TestFunction() {
        for (std::unique_ptr<Pig>& b : ls_pigs)
        {
            b->UpdateSprite();
        }

    }
};

//A single test, not a fixture. No setup is called.
TEST(Enemy, First_test) {
    Enemy e(100);
    EXPECT_EQ(e.getHealth(), 100);
    /*SUCCEED() << "Test test passed";
    FAIL() << "Test didn't pass";*/
}

TEST_F(EnemyTest, LethalDamagePopsPig) {
    enemy->takeDamage(60);
    EXPECT_TRUE(enemy->checkIfPopped());
}

//my own test
TEST(Slingshot, Tension_Check) {
    Slingshot s;
    EXPECT_EQ(s.getTension(), 0);
}

TEST(EnemyTest1, XPosition_Test) {
    Enemy e(0);
    std::cout << "X Position: " << e.getX() << std::endl;
    EXPECT_EQ(e.getX(), 0);
}

TEST(EnemyTest2, YPosition_Test) {
    Enemy e(0);
    std::cout << "Y Position: " << e.getY() << std::endl;
    EXPECT_EQ(e.getY(), 0);
}

TEST_F(BirdTest, SpriteLoader) 
{
    Bird& bird = *ls_birds.front(); //Get the first bird from the list 
    const sf::Texture* texture = bird.getSprite().getTexture();
    ASSERT_NE(texture, nullptr); //Make sure the sprite DOES NOT EQUAL (NE) nothing
}

TEST_F(BirdTest, NumOfBirds) 
{
    //ls_birds b;
    std::cout << "Number of birds: " << ls_birds.size() << std::endl;
    EXPECT_EQ(ls_birds.size(), 2);
}

TEST_F(BirdTest, RelationTest) {
    Bird& bird = *ls_birds.front(); //Grab the first bird in the list
    float xBirdPos = bird.getBody()->GetPosition().x; //Grab the x position of the bird

    for (const std::unique_ptr<Pig>& pig : ls_pigs) //Loop through every pig in the list. The "&" is referencing Pig, not copying
    {                                               //Do that so 
        float xPigPos = pig->getBody()->GetPosition().x;

        EXPECT_NE(xBirdPos, xPigPos);
    }

    //EXPECT_NE(ls_birds.front()->getBody()->GetPosition().x, ls_pigs.front()->getBody()->GetPosition().x);
}


//
//TEST(BirdTest2, CollisionTest) 
//{
//
//}
//
//TEST(PigTest, NumOfPigs) 
//{
//    std::cout << "Number of pigs: " << ls_pigs.size() << std::endl;
//    EXPECT_EQ(ls_pigs.size(), 3);
//}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}