#include "Vector.h"

template<> int vector<int>::countv = 0;
template<> int vector<float>::countv = 0;
template<> int vector<char>::countv = 0;
int vector<void *>::countpv = 0;