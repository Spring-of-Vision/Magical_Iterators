#ifndef Test_cpp
#define Test_cpp

#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;


TEST_CASE("Creating iterators")
{
        MagicalContainer container;

        //can create iterators on an empty container, and multiple iterators on the same container
        CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIterator(container));
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator sideIterator(container));
        CHECK_NOTHROW(MagicalContainer::PrimeIterator primeIterator(container));
}

TEST_CASE("Adding and deleting elements from a container") {
    MagicalContainer container;

    // Test adding elements and getting the size
    SUBCASE("Adding elements and getting size") {
        CHECK_NOTHROW(container.addElement(1));
        container.addElement(2);
        container.addElement(4);
        container.addElement(5);
        container.addElement(14);

        CHECK(container.size() == 5);
    }

    //Test adding existing elements and check size doesn't change
    SUBCASE("Element values are unique") {
        CHECK_NOTHROW(container.addElement(2));
        container.addElement(5);

        CHECK(container.size() == 5);
    }

    SUBCASE("Deleting elements") {
        CHECK_NOTHROW(container.removeElement(2));
        container.removeElement(4);
        CHECK_EQ(container.size(), 3);
    }
}

TEST_CASE("Changes to the container while iterating on a container") {

    SUBCASE("Ascending iterator- adding elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(5);
        container.addElement(7);
        
        MagicalContainer::AscendingIterator ascIterator(container);

        //add element pre-iteration
        container.addElement(3);
        CHECK_NOTHROW(++ascIterator);
        CHECK_EQ(*ascIterator, 3);

        //add element post-iteration
        ++ascIterator; //5
        container.addElement(4);
        CHECK_NOTHROW(++ascIterator);
        CHECK_EQ(*ascIterator, 7);
    }

    SUBCASE("Ascending iterator- removing elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(5);
        container.addElement(7);

        MagicalContainer::AscendingIterator ascIterator(container);

        //remove element pre-iteration
        container.removeElement(3);
        CHECK_NOTHROW(++ascIterator);
        CHECK_EQ(*ascIterator, 5);

        //remove element post-iteration
        container.removeElement(2);
        CHECK_NOTHROW(++ascIterator);
        CHECK_EQ(*ascIterator, 7);
    }

    SUBCASE("Side Cross iterator- adding elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(5);
        container.addElement(7);

        MagicalContainer::SideCrossIterator scIterator(container);

        //add element pre-iteration
        container.addElement(8);
        CHECK_NOTHROW(++scIterator);
        CHECK_EQ(*scIterator, 8);

        //add element post-iteration
        ++scIterator; //5
        container.addElement(4);
        CHECK_NOTHROW(++scIterator);
        CHECK_EQ(*scIterator, 7);
    }

    SUBCASE("Side Cross iterator- removing elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(5);
        container.addElement(7);

        MagicalContainer::SideCrossIterator scIterator(container);

        //remove element pre-iteration
        container.removeElement(7);
        CHECK_NOTHROW(++scIterator);
        CHECK_EQ(*scIterator, 5);

        //remove element post-iteration
        container.removeElement(2);
        CHECK_NOTHROW(++scIterator);
        CHECK_EQ(*scIterator, 3);
    }

    SUBCASE("Prime iterator- adding elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(7);
        container.addElement(11);

        MagicalContainer::PrimeIterator pIterator(container);

        //add element pre-iteration
        container.addElement(3);
        CHECK_NOTHROW(++pIterator);
        CHECK_EQ(*pIterator, 3);

        //add element post-iteration
        ++pIterator; //7
        container.addElement(5);
        CHECK_NOTHROW(++pIterator);
        CHECK_EQ(*pIterator, 7);
    }

    SUBCASE("Prime iterator- removing elements") {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(3);
        container.addElement(5);
        container.addElement(7);

        MagicalContainer::PrimeIterator pIterator(container);

        //remove element pre-iteration
        container.removeElement(3);
        CHECK_NOTHROW(++pIterator);
        CHECK_EQ(*pIterator, 5);

        //remove element post-iteration
        container.removeElement(2);
        CHECK_NOTHROW(++pIterator);
        CHECK_EQ(*pIterator, 7);
    }
}

//Test the begin and end functions of each iterator
TEST_CASE("begin and end functions") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::AscendingIterator ascIterator(container);
    MagicalContainer::SideCrossIterator scIterator(container);
    MagicalContainer::PrimeIterator pIterator(container);

    SUBCASE("begin() returns the first iterator") {
        auto ascBegin = ascIterator.begin();
        CHECK(*ascBegin == 1);

        auto sideBegin = scIterator.begin();
        CHECK(*sideBegin == 1);

        auto primeBegin = pIterator.begin();
        CHECK(*primeBegin == 2);
    }

    SUBCASE("end() returns past the last element") {
        auto ascEnd = ascIterator.end();
        CHECK_THROWS(*ascEnd);

        auto sideEnd = scIterator.end();
        CHECK_THROWS(*sideEnd);

        auto primeEnd = pIterator.end();
        CHECK_THROWS(*primeEnd);
    }
}

//Test the overriden operators in each iterator
TEST_CASE("Ascending Iterator Operator Tests") {
    MagicalContainer container;
    container.addElement(14);
    container.addElement(4);
    container.addElement(1);
    container.addElement(-2);
    container.addElement(5);

    MagicalContainer::AscendingIterator it(container);
    auto itB = it.begin();
    auto itE = it.end();
    MagicalContainer::AscendingIterator itNext(container);
    ++itNext;

    SUBCASE("Equality comparison (operator==)") {
        CHECK((it == it) == true);
        CHECK((it == itB) == true);
        CHECK((it == itE) == false);
        CHECK((itB == itE) == false);
    }

    SUBCASE("Inequality comparison (operator!=)") {
        CHECK((it != it) == false);
        CHECK((it != itB) == false);
        CHECK((it != itE) == true);
        CHECK((itB != itE) == true);
    }

    SUBCASE("Greater than comparison (operator>)") {
        CHECK((itNext > itB) == true);
        CHECK((itE > itNext) == true);
        CHECK((itE > itB) == true); //transitive property holds
        CHECK((itB > itNext) == false);
        CHECK((itNext > itE) == false);
    }

    SUBCASE("Less than comparison (operator<)") {
        CHECK((itB < itNext) == true);
        CHECK((itNext < itE) == true);
        CHECK((itB < itE) == true); //transitive property holds
        CHECK((itNext < itB) == false);
        CHECK((itE < itNext) == false);
    }

    SUBCASE("Dereference operator (operator*)") {
        CHECK(*it == -2);
        CHECK(*itNext == 1);
        CHECK_THROWS(*itE);
    }

    SUBCASE("Pre-increment operator (operator++)") {
        ++it;
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 4);
    }
}

TEST_CASE("Side Cross Iterator Operator Tests") {
    MagicalContainer container;
    container.addElement(14);
    container.addElement(4);
    container.addElement(1);
    container.addElement(-2);
    container.addElement(5);

    MagicalContainer::SideCrossIterator it(container);
    auto itB = it.begin();
    auto itE = it.end();
    MagicalContainer::SideCrossIterator itNext(container);
    ++itNext;

    SUBCASE("Equality comparison (operator==)") {
        CHECK((it == it) == true);
        CHECK((it == itB) == true);
        CHECK((it == itE) == false);
        CHECK((itB == itE) == false);
    }

    SUBCASE("Inequality comparison (operator!=)") {
        CHECK((it != it) == false);
        CHECK((it != itB) == false);
        CHECK((it != itE) == true);
        CHECK((itB != itE) == true);
    }

    SUBCASE("Greater than comparison (operator>)") {
        CHECK((itNext > itB) == true);
        CHECK((itE > itNext) == true);
        CHECK((itE > itB) == true); //transitive property holds
        CHECK((itB > itNext) == false);
        CHECK((itNext > itE) == false);
    }

    SUBCASE("Less than comparison (operator<)") {
        CHECK((itB < itNext) == true);
        CHECK((itNext < itE) == true);
        CHECK((itB < itE) == true); //transitive property holds
        CHECK((itNext < itB) == false);
        CHECK((itE < itNext) == false);
    }

    SUBCASE("Dereference operator (operator*)") {
        CHECK(*it == -2);
        CHECK(*itNext == 14);
        CHECK_THROWS(*itE);
    }

    SUBCASE("Pre-increment operator (operator++)") {
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(*it == 1);
    }
}

TEST_CASE("Prime Iterator Operator Tests") {
    MagicalContainer container;
    container.addElement(14);
    container.addElement(-3);
    container.addElement(2);
    container.addElement(1);
    container.addElement(5);

    MagicalContainer::PrimeIterator it(container);
    auto itB = it.begin();
    auto itE = it.end();
    MagicalContainer::PrimeIterator itNext(container);
    ++itNext;

    SUBCASE("Equality comparison (operator==)") {
        CHECK((it == it) == true);
        CHECK((it == itB) == true);
        CHECK((it == itE) == false);
        CHECK((itB == itE) == false);
    }

    SUBCASE("Inequality comparison (operator!=)") {
        CHECK((it != it) == false);
        CHECK((it != itB) == false);
        CHECK((it != itE) == true);
        CHECK((itB != itE) == true);
    }

    SUBCASE("Greater than comparison (operator>)") {
        CHECK((itNext > itB) == true);
        CHECK((itE > itNext) == true);
        CHECK((itE > itB) == true); //transitive property holds
        CHECK((itB > itNext) == false);
        CHECK((itNext > itE) == false);
    }

    SUBCASE("Less than comparison (operator<)") {
        CHECK((itB < itNext) == true);
        CHECK((itNext < itE) == true);
        CHECK((itB < itE) == true); //transitive property holds
        CHECK((itNext < itB) == false);
        CHECK((itE < itNext) == false);
    }

    SUBCASE("Dereference operator (operator*)") {
        CHECK(*it == 2);
        CHECK(*itNext == 5);
        CHECK_THROWS(*itE);
    }

    SUBCASE("Pre-increment operator (operator++)") {
        ++it;
        CHECK(*it == 5);
        CHECK_THROWS(++it);
    }
}

//Test full iteration of each iterator
TEST_CASE("Iterator Function Tests") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    // Test Ascending Iterator
    SUBCASE("Ascending Iterator") {
        vector<int> expected = {1, 2, 4, 5, 14};
        vector<int> result;

        MagicalContainer::AscendingIterator asc(container);

        for (auto it = asc.begin(); it != asc.end(); ++it)
        {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    // Test Side Cross Iterator
    SUBCASE("Side Cross Iterator") {
        vector<int> expected = {1, 14, 2, 5, 4};
        vector<int> result;

        MagicalContainer::SideCrossIterator scross(container);

        for (auto it = scross.begin(); it != scross.end(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }

    // Test Prime Iterator
    SUBCASE("Prime Iterator") {
        vector<int> expected = {2, 5};
        vector<int> result;

        MagicalContainer::SideCrossIterator prime(container);

        for (auto it = prime.begin(); it != prime.end(); ++it) {
            result.push_back(*it);
        }

        CHECK(result == expected);
    }
}

TEST_CASE("Incrementing iterators") {
    MagicalContainer container;
    container.addElement(-11);
    container.addElement(144);
    container.addElement(77);
    container.addElement(-19);
    container.addElement(21);

    SUBCASE("Ascending Iterators- incrementing a valid iterator vs an end iterator") {
        MagicalContainer::AscendingIterator ascIterator(container);
        CHECK_NOTHROW(++ascIterator);
        CHECK_EQ(*ascIterator, -11);
        auto ascEndIterator = ascIterator.end();
        CHECK_THROWS(++ascEndIterator);
    }

    SUBCASE("Side Cross Iterators- incrementing a valid iterator vs an end iterator") {
        MagicalContainer::SideCrossIterator scIterator(container);
        CHECK_NOTHROW(++scIterator);
        CHECK_EQ(*scIterator, 144);
        auto scEndIterator = scIterator.end();
        CHECK_THROWS(++scEndIterator);
    }

    SUBCASE("Prime Iterators- incrementing an iterator when there are no primes") {
        MagicalContainer::PrimeIterator pIterator(container);
        CHECK_THROWS(++pIterator);
    }

    SUBCASE("Prime Iterators- incrementing a valid iterator vs an end iterator") {
        container.addElement(7);
        container.addElement(19);
        container.addElement(23);

        MagicalContainer::PrimeIterator pIterator(container);
        CHECK_NOTHROW(++pIterator);
        CHECK_EQ(*pIterator, 19);
        auto pEndIterator = pIterator.end();
        CHECK_THROWS(++pEndIterator);
    }
}

TEST_CASE("Illegal comparisons between iterators") {
    MagicalContainer container1;
    container1.addElement(1);
    MagicalContainer container2;
    container2.addElement(2);

    MagicalContainer::AscendingIterator ascIterator1(container1);
    MagicalContainer::AscendingIterator ascIterator2(container2);
    MagicalContainer::SideCrossIterator sideIterator1(container1);
    MagicalContainer::SideCrossIterator sideIterator2(container2);
    MagicalContainer::PrimeIterator prIterator1(container1);
    MagicalContainer::PrimeIterator prIterator2(container2);

    /*SUBCASE("Comparing iterators of different classes") {
        CHECK_THROWS(ascIterator1 == sideIterator1);
        CHECK_THROWS(ascIterator1 != sideIterator2);
        CHECK_THROWS(ascIterator1 < prIterator1);
        CHECK_THROWS(ascIterator1 > prIterator2);
    }*/

    SUBCASE("Comparing iterators referencing different container objects") {
        bool exprResultUsed;

        CHECK_THROWS(exprResultUsed = (ascIterator1 == ascIterator2));
        CHECK_THROWS(exprResultUsed = (ascIterator1 != ascIterator2));
        CHECK_THROWS(exprResultUsed = (ascIterator1 < ascIterator2));
        CHECK_THROWS(exprResultUsed = (ascIterator1 > ascIterator2));

        CHECK_THROWS(exprResultUsed = (sideIterator1 == sideIterator2));
        CHECK_THROWS(exprResultUsed = (sideIterator1 != sideIterator2));
        CHECK_THROWS(exprResultUsed = (sideIterator1 < sideIterator2));
        CHECK_THROWS(exprResultUsed = (sideIterator1 > sideIterator2));

        CHECK_THROWS(exprResultUsed = (prIterator1 == prIterator2));
        CHECK_THROWS(exprResultUsed = (prIterator1 != prIterator2));
        CHECK_THROWS(exprResultUsed = (prIterator1 < prIterator2));
        CHECK_THROWS(exprResultUsed = (prIterator1 > prIterator2));
    }
}

#endif