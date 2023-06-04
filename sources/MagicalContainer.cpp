#include "MagicalContainer.hpp"

namespace ariel
{
    //constructor
    MagicalContainer::MagicalContainer()
    {

    }

    //fuctions
    void MagicalContainer::addElement(int elem)
    {

    }

    void MagicalContainer::removeElement(int elem)
    {

    }

    int MagicalContainer::size()
    {
        return dynamicArray.size();
    }

    //Ascending Iterator

    //constructors
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : myContainer(container)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : myContainer(other.myContainer)
    {
    }

    //destructor
    MagicalContainer::AscendingIterator::~AscendingIterator()
    {
    }

    //functions
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return *this;
    }
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return *this;
    }

    //operator functions
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator== (const AscendingIterator&) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator!= (const AscendingIterator&) const
    {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator< (const AscendingIterator&) const
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator> (const AscendingIterator&) const
    {
        return true;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return 0;
    }


    //Side Cross Iterator

    //constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : myContainer(container)
    {
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other) : myContainer(other.myContainer)
    {
    }

    //destructor
    MagicalContainer::SideCrossIterator::~SideCrossIterator()
    {
    }

    //functions
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return *this;
    }
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return *this;
    }

    //operator functions
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        return *this;
    }
    bool MagicalContainer::SideCrossIterator::operator== (const SideCrossIterator&) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!= (const SideCrossIterator&) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator< (const SideCrossIterator&) const
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator> (const SideCrossIterator&) const
    {
        return true;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return 0;
    }

    //Prime Iterator

    //constructors
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : myContainer(container)
    {
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) : myContainer(other.myContainer)
    {
    }

    //destructor
    MagicalContainer::PrimeIterator::~PrimeIterator()
    {
    }

    //functions
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return *this;
    }
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return *this;
    }

    //operator functions
    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
        return *this;
    }
    bool MagicalContainer::PrimeIterator::operator== (const PrimeIterator&) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!= (const PrimeIterator&) const
    {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator< (const PrimeIterator&) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator> (const PrimeIterator&) const
    {
        return true;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
    {
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return 0;
    }
}