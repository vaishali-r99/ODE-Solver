#ifndef SCHEME_H
#define SCHEME_H

enum class SchemeType {
    Explicit,
    Implicit,
};


class scheme
{
    protected:

    double _y0;         // y(0)
    double _h;          //time step
    double _t_end;      //end time
    SchemeType _type;   //method

    public:
    scheme(double,double,double,SchemeType);
    virtual void Solver() const = 0;        

    virtual ~scheme() = default;
};
#endif //