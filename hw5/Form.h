#ifndef __FORM_H_INCLUDE__
#define __FORM_H_INCLUDE__

#include <iostream>
#include <sstream>
#include <iomanip>

using std::ostream;

class boundForm
{
    public:
        double val;
        int format, preci;
        boundForm(int f, int pp, double v) : format(f), preci(pp), val(v) {}
};

class Form
{
    public:
        int fmt, prc;
        Form(int temp) : prc(temp), fmt(0) {}
        friend ostream& operator<<(ostream&, boundForm);
        Form& precision(int p) { prc = p; return *this; }
        Form& scientific() { fmt = std::ios_base::scientific; return *this; }
        Form& fixed() { fmt = std::ios_base::fixed; return *this; }
        boundForm operator()(double d) { return boundForm(this->fmt, this->prc, d); }
};

ostream& operator<<(ostream& o, boundForm bf)
{
    std::ios init(NULL);
    init.copyfmt(std::cout);

    if(bf.format == std::ios_base::fixed)
        std::cout << std::fixed << std::setprecision(bf.preci) << bf.val;
    else if(bf.format == std::ios_base::scientific)
        std::cout << std::setprecision(bf.preci) << std::scientific << bf.val;
    else
        std::cout << std::setprecision(bf.preci) << bf.val;
    
    std::cout.copyfmt(init);
    return o;
}

#endif