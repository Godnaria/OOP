#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__

#include "Trace.h"

template<class T> class vector
{
    T* v;
    int sz;
    static int countv;
    public:
        vector(int size) : sz(size)
        {
            v = new T [size];
            Trace t("vector<T>::vector(int)");
            std::cout << "  count = " << ++countv << endl;
        }
        T& elem(int i) { return v[i]; }
        T& operator[](int i) { return v[i]; }
        ~vector()
        {
            Trace l("vector<T>::~vector");
            std::cout << "  count = " << countv-- << endl;
        }
};

template<> class vector<void*>
{
    static int countpv;
    public:
        void **p;
        vector()
        {
            Trace t("vector<void*>::vector(int)");
            std::cout << "  count = " << ++countpv << endl;
        }
        void*& operator[](int i) { return p[i]; }
        void*& elem(int i) {return p[i]; }
        ~vector()
        {
            Trace l("vector<void*>::~vector");
            std::cout << "  count = " << countpv-- << endl;
        }
};

template<class T> class vector<T*> : private vector<void*>
{
    public:
        typedef vector<void*> Base;
        vector(int size) : Base()
        {
            p = new void* [size];
            for(int i = 0; i < size; i++)
                p[i] = new T;
            Trace t("vector<T*>::vector(int)");
        }
        T*& operator[](int i) { return (T*&)(Base::elem(i)); }
        T*& elem(int i) { return (T*&)(Base::operator[](i)); }
        ~vector()
        {
            Trace l("vector<T*>::~vector");
        }
};

#endif