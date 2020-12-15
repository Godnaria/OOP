#ifndef __FORM_H_INCLUDE__
#define __FORM_H_INCLUDE__

#include <iostream>
#include <sstream>
#include <iomanip>

using std::ostream;

class boundForm         //data object
{
    public:
        double val;
        int format, preci;
        boundForm(int f, int pp, double v) : format(f), preci(pp), val(v) {}
};

class Form      //Form for getting data initializing
{
    public:
        int fmt, prc;       //format decide what kind of tpye u wanna print out, prc for precision after dot
        Form(int temp) : prc(temp), fmt(0) {}       //constructor
        friend ostream& operator<<(ostream&, boundForm);        //operator overloading
        Form& precision(int p) { prc = p; return *this; }       //return precsion
        Form& scientific() { fmt = std::ios_base::scientific; return *this; }       //change format to scitentific
        Form& fixed() { fmt = std::ios_base::fixed; return *this; }         //change format to fixed
        boundForm operator()(double d) { return boundForm(this->fmt, this->prc, d); }       //operator overloading used to recognize (), eg. gen4()
};

ostream& operator<<(ostream& o, boundForm bf)       //output
{
    std::ios init(NULL);        //get the initial format to restore
    init.copyfmt(std::cout);

    if(bf.format == std::ios_base::fixed)               //output data which type is decide by format
        std::cout << std::fixed << std::setprecision(bf.preci) << bf.val;
    else if(bf.format == std::ios_base::scientific)
        std::cout << std::setprecision(bf.preci) << std::scientific << bf.val;
    else
        std::cout << std::setprecision(bf.preci) << bf.val;
    
    std::cout.copyfmt(init);
    return o;           //return ostream
}

#endif