#include <sstream>
#include "doctest.h"
#include <stdexcept>
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
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

        CHECK_EQ(p1.getX(), 0);
        CHECK_EQ(p1.getY(), 0);
        CHECK_EQ(p2.getX(), 3);
        CHECK_EQ(p2.getY(), 4);
    }

    TEST_CASE("Distance between two points")
    {
        Point p1{1, 1};
        Point p2{2, 3};
        Point n1{-1, 1};
        Point n2{1, -9};
        Point n3{-1, -1};

        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(n1.distance(n2), n2.distance(n1));
        CHECK_EQ(n3.distance(p1), p1.distance(n3));

        CHECK_EQ(n2.distance(p1), 10);
        CHECK_EQ(p2.distance(n3), 5);
        CHECK_EQ(p1.distance(p1), 0);
    }

    TEST_CASE("Move towards a destination point")
    {
        Point p1(1, 1);
        Point p2(4, 5);

        Point p3 = Point::moveTowards(p1, p2, 2.5); // halfway to p2
        CHECK_EQ(p3.getX(), 2.5);
        CHECK_EQ(p3.getY(), 3);

        Point p4 = Point::moveTowards(p2, p1, 1.5); // halfway to p1
        CHECK_EQ(p4.getX(), doctest::Approx(0).epsilon(3.1));
        CHECK_EQ(p4.getY(), doctest::Approx(0).epsilon(3.8));

        Point p5 = Point::moveTowards(p1, p2, 6); // should reach p2
        CHECK_EQ(p5.getX(), 4);
        CHECK_EQ(p5.getY(), 5);

        Point p6 = Point::moveTowards(p2, p1, 10); // should be same as p1
        CHECK_EQ(p6.getX(), 1);
        CHECK_EQ(p6.getY(), 1);

        // There is no such a thing as negative distance
        CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1), invalid_argument);
    }

    TEST_CASE("Print point coordinates")
    {
        Point p1(2.5, -3.8);
        Point p2(0, 0);

        CHECK_NOTHROW(p1.print());

        CHECK_NOTHROW(p2.print());
    }
}

TEST_SUITE("Classes initialization tests and distance() isAlive()")
{

    //---------------Cowboy-------------------

    TEST_CASE("Cowboy - Default constructor")
    {
        Point location(1, 2);

        CHECK_NOTHROW(Cowboy Cowboy("John Snow", location));

        Cowboy cowboy("John Snow", location);

        CHECK_EQ(cowboy.getName(), "John Snow");
        CHECK(cowboy.hasboolets());
        CHECK_EQ(cowboy.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(cowboy.getLocation().distance(Point{2, 1}), 0);
        CHECK_EQ(cowboy.getHealth(), 110);
        CHECK(cowboy.isAlive());
    }

    TEST_CASE("Cowboy - Copy constructor")
    {
        Point location(1, 2);
        Cowboy cowboy1("John Snow", location);
        Cowboy cowboy2 = cowboy1;

        CHECK_EQ(cowboy2.getName(), "John Snow");
        CHECK(cowboy2.hasboolets());
        CHECK_EQ(cowboy2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(cowboy2.getLocation().distance(Point{2, 1}), 0);
        CHECK_EQ(cowboy2.getHealth(), 110);
        CHECK(cowboy2.isAlive());
    }

    TEST_CASE("Cowboy - Copy assignment operator")
    {
        Point location(1, 2);
        Cowboy cowboy1("John Snow", location);
        Cowboy cowboy2("Halici", Point(3, 4));

        cowboy2 = cowboy1;

        CHECK_EQ(cowboy2.getName(), "John Snow");
        CHECK(cowboy2.hasboolets());
        CHECK_EQ(cowboy2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(cowboy2.getLocation().distance(Point{2, 1}), 0);
        CHECK(cowboy2.isAlive());
    }

    TEST_CASE("Cowboy - isAlive() method")
    {
        Point location(1, 2);
        Cowboy Cowboy1("John Snow", location);
        Cowboy Cowboy2("Halici", Point(3, 4));

        CHECK_EQ(Cowboy1.isAlive(), true);
        CHECK_EQ(Cowboy2.isAlive(), true);
    }

    TEST_CASE("Cowboy - distance() method")
    {
        Point location1(1, 2);
        Point location2(3, 4);
        Cowboy Cowboy1("John Snow", location1);
        Cowboy Cowboy2("Alice", location2);

        CHECK_EQ(Cowboy1.distance(&Cowboy2), 2.8284271247461903);
    }

    //---------------YoungNinja-------------------

    TEST_CASE("youngNinja - Default constructor")
    {
        Point location(1, 2);

        CHECK_NOTHROW(YoungNinja Cowboy("John Snow", location));

        YoungNinja youngNinja("John Snow", location);

        CHECK_EQ(youngNinja.getName(), "John Snow");
        CHECK_EQ(youngNinja.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(youngNinja.getLocation().distance(Point{2, 1}), 0);
        CHECK(youngNinja.isAlive());
    }

    TEST_CASE("YoungNinja - Copy constructor")
    {
        Point location(1, 2);
        YoungNinja youngNinja1("John Snow", location);
        YoungNinja youngNinja2 = youngNinja1;

        CHECK_EQ(youngNinja2.getName(), "John Snow");
        CHECK_EQ(youngNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(youngNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(youngNinja2.isAlive());
    }

    TEST_CASE("YoungNinja - Copy assignment operator")
    {
        Point location(1, 2);
        YoungNinja youngNinja1("John Snow", location);
        YoungNinja youngNinja2("Halici", Point(3, 4));

        youngNinja1 = youngNinja2;

        CHECK_EQ(youngNinja2.getName(), "John Snow");
        CHECK_EQ(youngNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(youngNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(youngNinja2.isAlive());
    }

    TEST_CASE("YoungNinja - isAlive() method")
    {
        Point location(1, 2);
        YoungNinja youngNinja1("John Snow", location);
        YoungNinja youngNinja2("Halici", Point(3, 4));

        CHECK_EQ(youngNinja1.isAlive(), true);
        CHECK_EQ(youngNinja1.isAlive(), true);
    }

    TEST_CASE("YoungNinja - distance() method")
    {
        Point location1(1, 2);
        Point location2(3, 4);
        YoungNinja youngNinja1("John Snow", location1);
        YoungNinja youngNinja2("Halici", location2);

        CHECK_EQ(youngNinja1.distance(&youngNinja2), 2.8284271247461903);
    }

    //---------------TrainedNinja-------------------

    TEST_CASE("TrainedNinja - Default constructor")
    {
        Point location(1, 2);

        CHECK_NOTHROW(TrainedNinja Cowboy("John Snow", location));

        TrainedNinja TrainedNinja("John Snow", location);

        CHECK_EQ(TrainedNinja.getName(), "John Snow");
        CHECK_EQ(TrainedNinja.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(TrainedNinja.getLocation().distance(Point{2, 1}), 0);
        CHECK(TrainedNinja.isAlive());
    }

    TEST_CASE("TrainedNinja - Copy constructor")
    {
        Point location(1, 2);
        TrainedNinja TrainedNinja1("John Snow", location);
        TrainedNinja TrainedNinja2 = TrainedNinja1;

        CHECK_EQ(TrainedNinja2.getName(), "John Snow");
        CHECK_EQ(TrainedNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(TrainedNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(TrainedNinja2.isAlive());
    }

    TEST_CASE("TrainedNinja - Copy assignment operator")
    {
        Point location(1, 2);
        TrainedNinja TrainedNinja1("John Snow", location);
        TrainedNinja TrainedNinja2("Halici", Point(3, 4));

        TrainedNinja1 = TrainedNinja2;

        CHECK_EQ(TrainedNinja2.getName(), "John Snow");
        CHECK_EQ(TrainedNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(TrainedNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(TrainedNinja2.isAlive());
    }

    TEST_CASE("TrainedNinja - isAlive() method")
    {
        Point location(1, 2);
        TrainedNinja TrainedNinja1("John Snow", location);
        TrainedNinja TrainedNinja2("Halici", Point(3, 4));

        CHECK_EQ(TrainedNinja1.isAlive(), true);
        CHECK_EQ(TrainedNinja1.isAlive(), true);
    }

    TEST_CASE("TrainedNinja - distance() method")
    {
        Point location1(1, 2);
        Point location2(3, 4);
        TrainedNinja TrainedNinja1("John Snow", location1);
        TrainedNinja TrainedNinja2("Halici", location2);

        CHECK_EQ(TrainedNinja1.distance(&TrainedNinja2), 2.8284271247461903);
    }

    //---------------OldNinja-------------------

    TEST_CASE("OldNinja - Default constructor")
    {
        Point location(1, 2);

        CHECK_NOTHROW(OldNinja Cowboy("John Snow", location));

        OldNinja OldNinja("John Snow", location);

        CHECK_EQ(OldNinja.getName(), "John Snow");
        CHECK_EQ(OldNinja.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(OldNinja.getLocation().distance(Point{2, 1}), 0);
        CHECK(OldNinja.isAlive());
    }

    TEST_CASE("OldNinja - Copy constructor")
    {
        Point location(1, 2);
        OldNinja OldNinja1("John Snow", location);
        OldNinja OldNinja2 = OldNinja1;

        CHECK_EQ(OldNinja2.getName(), "John Snow");
        CHECK_EQ(OldNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(OldNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(OldNinja2.isAlive());
    }

    TEST_CASE("OldNinja - Copy assignment operator")
    {
        Point location(1, 2);
        OldNinja OldNinja1("John Snow", location);
        OldNinja OldNinja2("Halici", Point(3, 4));

        OldNinja1 = OldNinja2;

        CHECK_EQ(OldNinja2.getName(), "John Snow");
        CHECK_EQ(OldNinja2.getLocation().distance(Point{1, 2}), 0);
        CHECK_NE(OldNinja2.getLocation().distance(Point{2, 1}), 0);
        CHECK(OldNinja2.isAlive());
    }

    TEST_CASE("OldNinja - isAlive() method")
    {
        Point location(1, 2);
        OldNinja OldNinja1("John Snow", location);
        OldNinja OldNinja2("Halici", Point(3, 4));

        CHECK_EQ(OldNinja1.isAlive(), true);
        CHECK_EQ(OldNinja1.isAlive(), true);
    }

    TEST_CASE("OldNinja - distance() method")
    {
        Point location1(1, 2);
        Point location2(3, 4);
        OldNinja OldNinja1("John Snow", location1);
        OldNinja OldNinja2("Halici", location2);

        CHECK_EQ(OldNinja1.distance(&OldNinja2), 2.8284271247461903);
    }
}

TEST_SUITE("Battle related methods")
{
    TEST_CASE("Cowboy shoot() and reload() methods")
    {
        Cowboy cowboy("John", Point(0, 0));
        YoungNinja enemyNinja("Young", Point(0, 0));
        OldNinja oldNinja("Old", Point(0, 0));

        for (int i = 0; i < 6; i++)
            cowboy.shoot(&enemyNinja);

        CHECK_FALSE(cowboy.hasboolets());
        CHECK_NOTHROW(cowboy.shoot(&enemyNinja)); // Shooting with no bullets should have no effect
        cowboy.reload();

        for (int i = 0; i < 3; i++)
            cowboy.shoot(&enemyNinja);

        CHECK(enemyNinja.isAlive());
        cowboy.shoot(&enemyNinja);
        CHECK_FALSE(enemyNinja.isAlive());

        CHECK_THROWS_AS(cowboy.shoot(&enemyNinja), runtime_error);
        CHECK_THROWS_AS(cowboy.shoot(nullptr), invalid_argument);

        while (cowboy.isAlive())
        {
            oldNinja.slash(&cowboy);
        }
        CHECK_THROWS_AS(cowboy.shoot(&enemyNinja), runtime_error);
        CHECK_THROWS_AS(cowboy.reload(), runtime_error);
    }

    TEST_CASE("Ninjas hit points are different")
    {
        OldNinja oldNinja("Old Ninja", Point(0, 0));
        TrainedNinja trainedNinja("Trained Ninja", Point(1, 1));
        YoungNinja youngNinja("Young Ninja", Point(2, 2));
        Cowboy cowboy("John", Point(4, 4));

        for (int i = 0; i < 15; i++)
        {
            cowboy.reload();
            if (i < 10)
            {
                CHECK(youngNinja.isAlive());
                cowboy.shoot(&youngNinja);
            }
            if (i < 12)
            {
                CHECK(trainedNinja.isAlive());
                cowboy.shoot(&trainedNinja);
            }
            CHECK(oldNinja.isAlive());
            cowboy.shoot(&oldNinja);
        }

        CHECK_FALSE((oldNinja.isAlive() || youngNinja.isAlive() || trainedNinja.isAlive()));
    }

    TEST_CASE("ninja move")
    {
        OldNinja oldNinja("Old Ninja", Point(0, 0));
        TrainedNinja trainedNinja("Trained Ninja", Point(1, 1));
        YoungNinja youngNinja("Young Ninja", Point(2, 2));
        Cowboy cowboy("John", Point(4, 4));

        oldNinja.move(&cowboy);
        trainedNinja.move(&cowboy);
        youngNinja.move(&cowboy);

        CHECK(oldNinja.getLocation() != Point(0, 0));
        CHECK(trainedNinja.getLocation() != Point(1, 1));
        CHECK(youngNinja.getLocation() != Point(2, 2));

        CHECK_THROWS_AS(oldNinja.move(nullptr), runtime_error);

        while (cowboy.isAlive())
        {
            oldNinja.slash(&cowboy);
        }

        CHECK_THROWS_AS(oldNinja.move(&cowboy), runtime_error);
    }

    TEST_CASE("Ninjas slash()")
    {

        OldNinja oldNinja("Old Ninja", Point(0, 0));
        TrainedNinja trainedNinja("Trained Ninja", Point(1, 1));
        YoungNinja youngNinja("Young Ninja", Point(2, 2));
        Cowboy cowboy("John", Point(2, 2));

        oldNinja.slash(&cowboy);
        CHECK_EQ(cowboy.getHealth(), 110);

        youngNinja.slash(&cowboy);
        CHECK_EQ(cowboy.getHealth(), 70);

        while (oldNinja.isAlive())
        {
            cowboy.shoot(&oldNinja);
            cowboy.reload();
        }

        CHECK_THROWS_AS(oldNinja.slash(&trainedNinja), runtime_error);
        CHECK_THROWS_AS(trainedNinja.slash(&oldNinja), runtime_error);
    }

    TEST_CASE("Sending negative value to hit()")
    {
        Cowboy cowboy("John", Point(0, 0));
        YoungNinja youngNinja("Young", Point(0, 0));
        OldNinja oldNinja("Old", Point(0, 0));
        TrainedNinja trainedNinja("Trained", Point(0, 0));

        CHECK_THROWS_AS(cowboy.hit(-10), std::invalid_argument);
        CHECK_THROWS_AS(youngNinja.hit(-20), std::invalid_argument);
        CHECK_THROWS_AS(oldNinja.hit(-30), std::invalid_argument);
        CHECK_THROWS_AS(trainedNinja.hit(-40), std::invalid_argument);
    }

    TEST_CASE("No self harm")
    {
        Cowboy cowboy("John", Point(0, 0));
        YoungNinja youngNinja("Young", Point(0, 0));
        OldNinja oldNinja("Old", Point(0, 0));
        TrainedNinja trainedNinja("Trained", Point(0, 0));

        CHECK_THROWS_AS(cowboy.shoot(&cowboy), runtime_error);
        CHECK_THROWS_AS(youngNinja.slash(&youngNinja), runtime_error);
        CHECK_THROWS_AS(oldNinja.slash(&oldNinja), runtime_error);
        CHECK_THROWS_AS(trainedNinja.slash(&trainedNinja), runtime_error);
    }
}

TEST_SUITE("Team Tests")
{
    TEST_CASE("Creating a team with a leader")
    {
        Cowboy *cowboy = new Cowboy("John", Point(0, 0));

        //"Creating a team with a valid leader"

        Team team(cowboy);

        CHECK(team.getLeader() == cowboy);
        CHECK(team.getTeam().size() == 1);
        CHECK(team.stillAlive() == 1);

        //"Creating a team with a null leader"

        CHECK_THROWS_AS(Team(nullptr), std::invalid_argument);
    }

    TEST_CASE("Adding members to a team")
    {
        Cowboy *cowboy = new Cowboy("John", Point(0, 0));
        OldNinja *oldNinja = new OldNinja("Old Ninja", Point(1, 1));
        TrainedNinja *trainedNinja = new TrainedNinja("Trained Ninja", Point(2, 2));
        YoungNinja *youngNinja = new YoungNinja("Young Ninja", Point(3, 3));
        Cowboy *cowboy1 = new Cowboy("John", Point(0, 0));
        OldNinja *oldNinja1 = new OldNinja("Old Ninja", Point(1, 1));
        TrainedNinja *trainedNinja1 = new TrainedNinja("Trained Ninja", Point(2, 2));
        YoungNinja *youngNinja1 = new YoungNinja("Young Ninja", Point(3, 3));
        Cowboy *cowboy2 = new Cowboy("John", Point(0, 0));
        OldNinja *oldNinja2 = new OldNinja("Old Ninja", Point(1, 1));

        Team team(cowboy);

        //"Adding valid characters to the team"

        team.add(oldNinja);
        team.add(trainedNinja);
        team.add(youngNinja);

        CHECK(team.getTeam().size() == 4);
        CHECK(team.stillAlive() == 4);

        team.add(cowboy1);
        team.add(oldNinja1);
        team.add(trainedNinja1);
        team.add(youngNinja1);
        team.add(cowboy2);
        team.add(oldNinja2);

        // Attempting to add another character should throw an exception
        CHECK_THROWS_AS(team.add(new Cowboy("Another Cowboy", Point(4, 4))), std::runtime_error);

        //"Adding invalid characters to the team"

        // Adding characters that are already in the team or not alive should throw an exception
        CHECK_THROWS_AS(team.add(cowboy), std::runtime_error);
        CHECK_THROWS_AS(team.add(oldNinja), std::runtime_error);
        CHECK_THROWS_AS(team.add(trainedNinja), std::runtime_error);
        CHECK_THROWS_AS(team.add(youngNinja), std::runtime_error);
    }

    TEST_CASE("Attacking an enemy team")
    {
        Cowboy *cowboy = new Cowboy("John", Point(0, 0));
        OldNinja *oldNinja = new OldNinja("Old Ninja", Point(1, 1));
        TrainedNinja *trainedNinja = new TrainedNinja("Trained Ninja", Point(2, 2));
        YoungNinja *youngNinja = new YoungNinja("Young Ninja", Point(3, 3));

        Team team1(cowboy);
        Team team2(oldNinja);

        team2.add(trainedNinja);
        team2.add(youngNinja);

        //"Attacking an enemy team"

        team1.attack(&team2);

        CHECK(team2.stillAlive() == 3); // All members of team2 should still be alive
    }
}
