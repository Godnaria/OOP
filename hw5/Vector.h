#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include "Trace.h"

template<class T> class vector      //this class used to get vector none pointer type data
{
    T* v;       //pointer point to an array, and array used to store data
    int sz;
    static int countv;      //count each vector if each type uses the same base
    public:
        vector(int size) : sz(size)     //constructor
        {
            v = new T [size];
            Trace t("vector<T>::vector(int)");
            std::cout << "  count = " << ++countv << endl;
        }
        T& elem(int i) { return v[i]; }     //get element
        T& operator[](int i) { return v[i]; }       //get element
        ~vector()       //destructor
        {
            Trace l("vector<T>::~vector");
            std::cout << "  count = " << countv-- << endl;
            delete v;
        }
};

template<> class vector<void*>      //base pointer class, used to point to any type
{
    static int countpv;     //count if the used the same base
    public:
        void **p;       //doube pointer to store data, which *p store each tpye pointer
        vector()
        {
            Trace t("vector<void*>::vector(int)");
            std::cout << "  count = " << ++countpv << endl;
        }
        void*& operator[](int i) { return p[i]; }       //get element
        void*& elem(int i) {return p[i]; }      //get element
        ~vector()
        {
            Trace l("vector<void*>::~vector");
            std::cout << "  count = " << countpv-- << endl;
        }
};

template<class T> class vector<T*> : private vector<void*>      //pointer type class
{
    int sz;
    public:
        typedef vector<void*> Base;
        vector(int size) : sz(size), Base()       //class the base constructor
        {
            p = new void* [size];
            for(int i = 0; i < size; i++)
                p[i] = new T;
            Trace t("vector<T*>::vector(int)");
        }
        T*& operator[](int i) { return (T*&)(Base::elem(i)); }      //get element
        T*& elem(int i) { return (T*&)(Base::operator[](i)); }      //get element
        ~vector()
        {
            Trace l("vector<T*>::~vector");
            delete [] p;
        }
};

#endif