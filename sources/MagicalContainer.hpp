#pragma once

#include <typeinfo>
#include <vector>

using namespace std;

namespace ariel
{
    //template <typename T>
    class MagicalContainer
    {
        private:
            vector<int> dynamicArray;

        public:
            //constructors
            MagicalContainer();
            //MagicalContainer(const MagicalContainer& other);

            //destructor
            //~MagicalContainer();

            //general fuctions
            void addElement(int elem);
            void removeElement(int elem);
            int size();

            class AscendingIterator
            {
                private:
                    MagicalContainer& myContainer;
                    int index;

                public:
                    //constructor
                    AscendingIterator(MagicalContainer& container);
                    AscendingIterator(const AscendingIterator& other);

                    ~AscendingIterator();

                    //functions
                    AscendingIterator begin();
                    AscendingIterator end();

                    //operator functions
                    AscendingIterator& operator=(const AscendingIterator& other);
                    bool operator== (const AscendingIterator&) const;
                    bool operator!= (const AscendingIterator&) const;
                    bool operator< (const AscendingIterator&) const;
                    bool operator> (const AscendingIterator&) const;
                    AscendingIterator& operator++();
                    int operator*() const;
            };

            class SideCrossIterator
            { 
                private:
                    MagicalContainer& myContainer;
                    int index;

                public:
                    //constructor
                    SideCrossIterator(MagicalContainer& container);
                    SideCrossIterator(const SideCrossIterator& other);

                    ~SideCrossIterator();

                    //functions
                    SideCrossIterator begin();
                    SideCrossIterator end();

                    //operator functions
                    SideCrossIterator& operator=(const SideCrossIterator& other);
                    bool operator== (const SideCrossIterator&) const;
                    bool operator!= (const SideCrossIterator&) const;
                    bool operator< (const SideCrossIterator&) const;
                    bool operator> (const SideCrossIterator&) const;
                    SideCrossIterator& operator++();
                    int operator*() const;
            };

            class PrimeIterator
            {
                private:
                    MagicalContainer& myContainer;
                    int index;

                public:
                    //constructor
                    PrimeIterator(MagicalContainer& container);
                    PrimeIterator(const PrimeIterator& other);

                    ~PrimeIterator();

                    //functions
                    PrimeIterator begin();
                    PrimeIterator end();

                    //operator functions
                    PrimeIterator& operator=(const PrimeIterator& other);
                    bool operator== (const PrimeIterator&) const;
                    bool operator!= (const PrimeIterator&) const;
                    bool operator< (const PrimeIterator&) const;
                    bool operator> (const PrimeIterator&) const;
                    PrimeIterator& operator++();
                    int operator*() const;
            };
    };
}
