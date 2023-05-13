#include <sstream>
#include "doctest.h"
#include <stdexcept>
#include "doctest.h"
#include "sources/Team.hpp"
#include <limits>
#include <vector>

using namespace std;
using namespace ariel;

TEST_SUITE("Point class")
{
    TEST_CASE("Parameterized constructor with zero numerator")
    {
        CHECK_NOTHROW(Point p1);
        CHECK_NOTHROW(Point p2(3, 4));

        Point p1;       // default constructor
        Point p2(3, 4); // (3, 4)

        CHECK_EQ(p1.getPointX(), 0);
        CHECK_EQ(p1.getPointY(), 0);
        CHECK_EQ(p2.getPointX(), 3);
        CHECK_EQ(p2.getPointY(), 4);
    }

    TEST_CASE("Distance between two points")
    {
        Point p1(1, 1);
        Point p2(4, 5);

        CHECK_EQ(p1.distance(p2), 5);
        CHECK_EQ(p2.distance(p1), 5);
    }

    TEST_CASE("Move towards a destination point")
    {
        Point p1(1, 1);
        Point p2(4, 5);

        Point p3 = p1.moveTowards(p2, 2.5); // halfway to p2
        CHECK_EQ(p3.getPointX(), 2.5);
        CHECK_EQ(p3.getPointY(), 3);

        Point p4 = p2.moveTowards(p1, 1.5); // halfway to p1
        CHECK_EQ(p4.getPointX(), 3.1);
        CHECK_EQ(p4.getPointY(), 3.8);

        Point p5 = p1.moveTowards(p2, 6); // should reach p2
        CHECK_EQ(p5.getPointX(), 4);
        CHECK_EQ(p5.getPointY(), 5);

        Point p6 = p2.moveTowards(p1, 10); // should be same as p1
        CHECK_EQ(p6.getPointX(), 1);
        CHECK_EQ(p6.getPointY(), 1);
    }

    TEST_CASE("Print point coordinates")
    {
        Point p1(2.5, -3.8);
        Point p2(0, 0);

        CHECK_NOTHROW(p1.print());

        CHECK_NOTHROW(p2.print());
    }
}

TEST_SUITE("Cowboy class")
{

    TEST_CASE("Default constructor")
    {
        Point location(1, 2);

        CHECK_NOTHROW(Cowboy Cowboy("John Snow", location));

        Cowboy Cowboy("John Snow", location);

        CHECK_EQ(Cowboy.getName(), "John Snow");
        CHECK_EQ(Cowboy.getLocation().getPointX(), 1);
        CHECK_EQ(Cowboy.getLocation().getPointY(), 2);
        CHECK_EQ(Cowboy.getHealth(), 110);
    }

    TEST_CASE("Copy constructor")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2 = Cowboy1;

        CHECK_EQ(Cowboy2.getName(), "John Snow");
        CHECK_EQ(Cowboy2.getLocation().getPointX(), 1);
        CHECK_EQ(Cowboy2.getLocation().getPointY(), 2);
        CHECK_EQ(Cowboy2.getHealth(), 110);
    }

    TEST_CASE("Move constructor")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2 = std::move(Cowboy1);

        CHECK_EQ(Cowboy2.getName(), "John Snow");
        CHECK_EQ(Cowboy2.getLocation().getPointX(), 1);
        CHECK_EQ(Cowboy2.getLocation().getPointY(), 2);
        CHECK_EQ(Cowboy2.getHealth(), 110);
    }

    TEST_CASE("Copy assignment operator")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2("Halici", Point(3, 4));

        Cowboy2 = Cowboy1;

        CHECK_EQ(Cowboy2.getName(), "John Snow");
        CHECK_EQ(Cowboy2.getLocation().getPointX(), 1);
        CHECK_EQ(Cowboy2.getLocation().getPointY(), 2);
        CHECK_EQ(Cowboy2.getHealth(), 110);
    }

    TEST_CASE("Move assignment operator")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2("Halici", Point(3, 4));

        Cowboy2 = move(Cowboy1);

        CHECK_EQ(Cowboy2.getName(), "John Snow");
        CHECK_EQ(Cowboy2.getLocation().getPointX(), 1);
        CHECK_EQ(Cowboy2.getLocation().getPointY(), 2);
        CHECK_EQ(Cowboy2.getHealth(), 110);
    }

    TEST_CASE("isAlive() method")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2("Halici", Point(3, 4));

        CHECK_EQ(Cowboy1.isAlive(), true);
        CHECK_EQ(Cowboy2.isAlive(), true);
    }

    TEST_CASE("distance() method")
    {
        Point location1(1, 2);
        Point location2(3, 4);
        Cowboy Cowboy1("John Snow", location1);
        Cowboy Cowboy2("Alice", location2);

        CHECK_EQ(Cowboy1.distance(&Cowboy2), 2.8284271247461903);
    }

    TEST_CASE("hit() method")
    {
        Point location(1, 2);
        Cowboy Cowboy("John", location);
    }

    TEST_CASE("Shooting an enemy")
    {
        Point location(0, 0);
        Cowboy cowboy("John", location);
        Cowboy enemy("Enemy", location);

        cowboy.shoot(&enemy);

        CHECK_EQ(enemy.getHealth(), 100);
        CHECK_EQ(cowboy.getBulletsAmount(), 5);
    }

    TEST_CASE("Shooting a dead character")
    {
        Point location(0, 0);
        Cowboy cowboy("John", location);
        Cowboy enemy("Enemy", location);

        enemy.hit(110); // Set enemy's health to 0

        cowboy.shoot(&enemy);

        CHECK_EQ(enemy.isAlive(), false);
        CHECK_EQ(cowboy.getBulletsAmount(), 5);
    }

    TEST_CASE("Reloading with bullets remaining")
    {
        Point location(0, 0);
        Cowboy cowboy("John", location);

        CHECK_THROWS(cowboy.reload());
    }

    TEST_CASE("Printing Cowboy's status")
    {
        Point location(0, 0);
        Cowboy cowboy("John", location);

        stringstream output;
        streambuf *coutBuf = cout.rdbuf();
        cout.rdbuf(output.rdbuf());

        cowboy.print();

        cout.rdbuf(coutBuf);

        CHECK_EQ(output.str(), "C(John)\n\nHit points: 0 Points left: 110\n\n");
    }
}

TEST_SUITE("Ninja Subclasses Tests")
{
    TEST_CASE("Creating a YoungNinja")
    {
        Point location(0, 0);
        YoungNinja youngNinja("Young", location);

        CHECK_EQ(youngNinja.getName(), "Young");
        CHECK_EQ(youngNinja.getLocation().getPointX(), 0);
        CHECK_EQ(youngNinja.getLocation().getPointY(), 0);
        CHECK_EQ(youngNinja.getHealth(), 100);
        CHECK_EQ(youngNinja.getSpeed(), 14);
    }

    TEST_CASE("Creating a TrainedNinja")
    {
        Point location(0, 0);
        TrainedNinja trainedNinja("Trained", location);

        CHECK_EQ(trainedNinja.getName(), "Trained");
        CHECK_EQ(trainedNinja.getLocation().getPointX(), 0);
        CHECK_EQ(trainedNinja.getLocation().getPointY(), 0);
        CHECK_EQ(trainedNinja.getHealth(), 120);
        CHECK_EQ(trainedNinja.getSpeed(), 12);
    }

    TEST_CASE("Creating an OldNinja")
    {
        Point location(0, 0);
        OldNinja oldNinja("Old", location);

        CHECK_EQ(oldNinja.getName(), "Old");
        CHECK_EQ(oldNinja.getLocation().getPointX(), 0);
        CHECK_EQ(oldNinja.getLocation().getPointY(), 0);
        CHECK_EQ(oldNinja.getHealth(), 150);
        CHECK_EQ(oldNinja.getSpeed(), 8);
    }

    TEST_CASE("Moving a Ninja")
    {
        Point location(0, 0);
        YoungNinja ninja("Ninja", location);
        Point enemyLocation(100, 100);
        Cowboy enemy("Enemy", enemyLocation);

        ninja.move(&enemy);

        CHECK(ninja.getLocation().getPointX() > 0); // Assuming the move method updates the location correctly
        CHECK(ninja.getLocation().getPointY() > 0);
    }

    TEST_CASE("Slashing an enemy with a Ninja")
    {
        Point location(0, 0);
        YoungNinja ninja("Ninja", location);
        Point enemyLocation(10, 10);
        Cowboy enemy("Enemy", enemyLocation);

        ninja.slash(&enemy);

        CHECK_EQ(enemy.getHealth(), 70); // Assuming the slash method reduces enemy health correctly
    }
}

TEST_SUITE("Team Tests")
{
    TEST_CASE("Checking attack function")
    {

        Cowboy *a = new Cowboy("Tom", Point(1, 1));

        Team team_a(a);

        team_a.add(new Cowboy("Asher", Point(5, 5)));

        TrainedNinja *b = new TrainedNinja("Roy", Point(5.5, 5.5));

        Team team_b(b);

        for (int i = 0; i < 10; i++)
        {

            team_b.attack(&team_a);
        }

        CHECK(a->getHealth() <= 0);

        CHECK(team_a.stillAlive() < 2);

    }

    TEST_CASE("Checking stillAlive function")
    {

        Cowboy *a = new Cowboy("Yoni", Point(2, 2));

        Team team_a(a);

        Cowboy *b = new Cowboy("Dani", Point(5, 5));

        Team team_b(b);

        // checking after added, stillAlive is 1
        CHECK_EQ(team_b.stillAlive(), 1);

        // making sure that leader of team b is dead

        team_a.attack(&team_b);

        // checking that after he dead, stillAlive is 0
        CHECK(team_b.stillAlive() == 0);
    }
}

