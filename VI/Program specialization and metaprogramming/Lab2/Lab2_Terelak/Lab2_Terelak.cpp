#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

template <class A>
class DExpr
{
private: A a_;
public: DExpr() {}
      DExpr(const A& x) : a_(x) {}
      double operator()(double x) const
      {
          return a_(x);
      }
};

class DExprLiteral {
private:
    double value_;
public:
    DExprLiteral(double value)
    {
        value_ = value;
    }
    double operator()(double x) const
    {
        return value_;
    }
};

template<class Expr>
void evaluate(DExpr<Expr> expr, double start, double end)
{
    const double step = 1.0;
    for (double i = start; i < end; i += step)
        std::cout << expr(i) << std::endl;
};

class DExprIdentity {
public:
    DExprIdentity()
    { }
    double operator()(double x) const
    {
        return x;
    }
};

template<class A, class B, class Op>
class DBinExprOp {
    A a_;
    B b_;
public:
    DBinExprOp(const A& a, const B& b)
        : a_(a), b_(b)
    { }
    double operator()(double x) const
    {
        return Op::apply(a_(x), b_(x));
    }
};

template<class A, class Op>
class DUnExprOp {
    A a_;
public:
    DUnExprOp(const A& a)
        : a_(a)
    { }
    double operator()(double x) const
    {
        return Op::apply(a_(x));
    }
};

class DApAdd {
public:
    DApAdd() { }
    static inline double apply(double a, double b)
    {
        return a + b;
    }
};

class DApDivide {
public:
    DApDivide() { }
    static inline double apply(double a, double b)
    {
        return a / b;
    }
};

class DApLog {
public:
    DApLog() { }
    static inline double apply(double a)
    {
        return log(a);
    }
};

class DApMinus
{
public: DApMinus() {}
      static inline double apply(double a, double b)
      {
          return a - b;
      }
};

class DApSqrt
{
public: DApSqrt() {}
      static inline double apply(double a, double xd)
      {
          return sqrt(a);
      }
};

class DApSqr
{
public: DApSqr() {}
      static inline double apply(double a)
      {
          return pow(a, 2);
      }
};

class DApExp
{
public: DApExp() {}
      static inline double apply(double a, double xd)
      {
          return exp(a);
      }
};

class DApMul
{
public: DApMul() {}
      static inline double apply(double a, double b)
      {
          return a * b;
      }
};

template<class A>
DExpr<DBinExprOp<DExprLiteral, DExpr<A>, DApAdd> >
operator+(double x, const DExpr<A>& a)
{
    typedef DBinExprOp<DExprLiteral, DExpr<A>, DApAdd> ExprT;
    return DExpr<ExprT>(ExprT(DExprLiteral(x), a));
}

template<class A, class B>
DExpr<DBinExprOp<DExpr<A>, DExpr<B>, DApDivide> >
operator/(const DExpr<A>& a, const DExpr<B>& b)
{
    typedef DBinExprOp<DExpr<A>, DExpr<B>, DApDivide> ExprT;
    return DExpr<ExprT>(ExprT(a, b));
}

template <class A>
DExpr<DUnExprOp<DExpr<A>, DApLog>>
log(const DExpr<A>& a)
{
    typedef DUnExprOp<DExpr<A>, DApLog> ExprT;
    return DExpr<ExprT>(ExprT(a));
}

// Operators for the Challenge
template <class A>
DExpr<DBinExprOp<DExpr<A>, DExprLiteral, DApDivide>>
operator/(const DExpr <A>& a, double x)
{
    typedef DBinExprOp <DExpr<A>, DExprLiteral, DApDivide> ExprT;
    return DExpr < ExprT >(ExprT(a, DExprLiteral(x)));
}

template <class A>
DExpr<DBinExprOp<DExprLiteral, DExpr<A>, DApMul>>
operator*(double x, const DExpr <A>& a)
{
    typedef DBinExprOp <DExprLiteral, DExpr<A>, DApMul> ExprT;
    return DExpr < ExprT >(ExprT(DExprLiteral(x), a));
}

template <class A>
DExpr<DBinExprOp<DExpr<A>, DExprLiteral, DApMinus>>
operator-(const DExpr<A>& a, double x)
{
    typedef DBinExprOp <DExpr<A>, DExprLiteral, DApMinus> ExprT;
    return DExpr<ExprT>(ExprT(a, DExprLiteral(x)));
}

template <class A>
DExpr<DBinExprOp<DExpr<A>, DExprLiteral, DApSqrt>>
sqrt(const DExpr<A>& a)
{
    typedef DBinExprOp <DExpr<A>, DExprLiteral, DApSqrt> ExprT;
    return DExpr < ExprT >(ExprT(a, DExprLiteral(0)));
}

template <class A>
DExpr<DUnExprOp<DExpr<A>, DApSqr>>
sqr(const DExpr<A>& a)
{
    typedef DUnExprOp<DExpr<A>, DApSqr> ExprT;
    return DExpr<ExprT>(ExprT(a));
}

template <class A>
DExpr<DBinExprOp<DExpr<A>, DExprLiteral, DApExp>>
exp(const DExpr<A>& a)
{
    typedef DBinExprOp <DExpr<A>, DExprLiteral, DApExp> ExprT;
    return DExpr < ExprT >(ExprT(a, DExprLiteral(0)));
}


int main()
{
    DExpr<DExprIdentity> x; // Placeholder
    //evaluate( (11.0 + x) / x, 0.0, 5.0);

    //evaluate(log(x), 5.0, 15.0);

    cout << "Challenge: \n";
    double mean = 10.0, sigma = 7.0; // math constants

    evaluate(1.0 / (sqrt(2 * M_PI) * sigma) * exp(sqr(x - mean) /
        (-2 * sigma * sigma)), 0.0, 10.0);
}