#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <chrono>

// FACTORIAL
template<int N>
class Factorial {
public:
    enum { value = N * Factorial<N - 1>::value }; // N! == N * (N-1)!
};

template<>
class Factorial<1> {
public:
    enum { value = 1 }; // N! == 1
};

// IF/ELSE
template<bool C>
class IfElseCondition { };
template<>
class IfElseCondition<true> {
public:
    static inline void f()
    {
        std::cout << "True \n";
    }
};
template<>
class IfElseCondition<false> {
public:
    static inline void f()
    {
        std::cout << "False \n";
    }
};

// SWITCH CASE
template<int I>
class SwitchCase {
public:
    static inline void f()
    {
        std::cout << "Default statement \n";
    }
};
template<>
class SwitchCase<1> { // value1
public:
    static inline void f()
    {
        std::cout << "Value is 1 \n"; // statement1
    }
};
template<>
class SwitchCase<2> { // value2
public:
    static inline void f()
    {
        std::cout << "Value is 2 \n"; // statement2
    }
};

// LOOPS
template<int I>
class DoWhileLoop {
private:
    enum { go = (I - 1) != 0 };
public:
    static inline void f()
    {
        std::cout << "Loop variable value is " << I << "\n"; // statement
        DoWhileLoop<go ? (I - 1) : 0>::f();
    }
};
// Base case for recursion
template<>
class DoWhileLoop<0> {
public:
    static inline void f()
    {
        std::cout << "Loop variable value is 0"; //recursion stop
    }
};

//generic metafunction calls itself (template recursion)
template<int IIn, int ISum = 1>
struct Factorial2 : Factorial2<IIn - 1, IIn* ISum> {
};
//specialized metafiction sets value
template<int ISum>
struct Factorial2<1, ISum> {
    enum { value = ISum };
};


// BUBBLE SORT
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

template<int I, int J>
class IntSwap {
public:
    static inline void compareAndSwap(int* data)
    {
        if (data[I] > data[J])
            swap(data[I], data[J]);
    }
};

template<int I, int J>
class IntBubbleSortLoop {
private:
    enum { go = (J <= I - 2) };
public:
    static inline void loop(int* data)
    {
        IntSwap<J, J + 1>::compareAndSwap(data);
        IntBubbleSortLoop<go ? I : 0, go ? (J + 1) : 0>::loop(data);
    }
};
template<>
class IntBubbleSortLoop<0, 0> { // to stop template recursion
public:
    static inline void loop(int*)
    { }
};

template<int N> // N is the size of array
class IntBubbleSort {
public:
    static inline void sort(int* data)
    {
        IntBubbleSortLoop<N - 1, 0>::loop(data); // replaces for loop
        IntBubbleSort<N - 1>::sort(data);
    }
};
template<> // template specialisation to stop recursion
class IntBubbleSort<1> {
public:
    static inline void sort(int* data) // does nothing
    { }
};


// SINUS

// Compute J terms in series expansion. K is the loop variable.
template<int N, int I, int J, int K>
class SineSeries {
public:
    enum { go = (K + 1 != J) };
    static inline float accumulate()
    {
        return 1 - (I * 2 * M_PI / N) * (I * 2 * M_PI / N) / (2 * K + 2) / (2 * K + 3) *
            SineSeries<N* go, I* go, J* go, (K + 1)* go>::accumulate();
    }
};
// Specialization to terminate loop
template<>
class SineSeries<0, 0, 0, 0> {
public:
    static inline float accumulate()
    {
        return 1;
    }
};
template<int N, int I>
class Sine {
public:
    static inline float sin()
    {
        return (I * 2 * M_PI / N) * SineSeries<N, I, 10, 0>::accumulate();
    }
};


// DOT PRODUCT
template <size_t N, class T>
class DotProduct {
public:
    static T eval(T* a, T* b) {
        return DotProduct<1, T>::eval(a, b)
            + DotProduct<N - 1, T>::eval(a + 1, b + 1);
    }
};
template <class T>
class DotProduct<1, T> {
public:
    static T eval(T* a, T* b)
    {
        return (*a) * (*b);
    }
};

template <size_t N, class T>
inline T dot(T* a, T* b) {
    return DotProduct<N, T>::eval(a, b);
}

void compareFactorial() {
    std::cout << "Factorial time comparison";
    //METAPROGRAM
    auto startFactorial2 = std::chrono::high_resolution_clock::now();
    int fact = Factorial2<15>::value;
    std::cout << "\nMetaprogram Factorial<15>: " << fact << "\n";

    auto finishFactorial2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishFactorial2 - startFactorial2).count() << "ns\n"; // Print measured time, in nanoseconds

    //DO WHILE
    auto startFactorialLoop = std::chrono::high_resolution_clock::now();
    int i = 15;
    int result = 1;

    do {
        result *= i;
    } while (--i > 0);

    std::cout << "\nDoWhile Factorial<15>: " << result << "\n";
    auto finishFactorialLoop = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishFactorialLoop - startFactorialLoop).count() << "ns\n"; // Print measured time, in nanoseconds
}

void compareSine() {
    std::cout << "\nSine time comparison";
    //METAPROGRAM
    auto startSinus = std::chrono::high_resolution_clock::now();
    std::cout << "\nMetaprogram Sinus: ";
    float f = Sine<32, 5>::sin();
    std::cout << f << "\n";

    auto finishSinus = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishSinus - startSinus).count() << "ns\n"; // Print measured time, in nanoseconds

    //BUILT-IN FUNCTION
    auto startSinus2 = std::chrono::high_resolution_clock::now();
    std::cout << "\nSinus using built-in sin(): " << sin(5 * 2 * M_PI / 32) << "\n";

    auto finishSinus2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishSinus2 - startSinus2).count() << "ns\n"; // Print measured time, in nanoseconds
};

void compareDot() {
    std::cout << "\nDot time comparison";
    //METAPROGRAM
    auto startDot = std::chrono::high_resolution_clock::now();
    std::cout << "\nMetaprogram Dot Product<4>: ";
    int a[4] = { 1,100,0,-1 };
    int b[4] = { 2,2,2,2 };
    std::cout << dot<4>(a, b);

    auto finishDot = std::chrono::high_resolution_clock::now();
    std::cout << "\n" << std::chrono::duration_cast<std::chrono::nanoseconds>(finishDot - startDot).count() << "ns\n"; // Print measured time, in nanoseconds

    //FOR LOOP
    auto startDotLoop = std::chrono::high_resolution_clock::now();
    int result = 0;
    for (int i = 0; i < std::size(a); i++) {
        result += a[i] * b[i];
    }
    std::cout << "\nDot Product using For loop: " << result;

    auto finishDotLoop = std::chrono::high_resolution_clock::now();
    std::cout << "\n" << std::chrono::duration_cast<std::chrono::nanoseconds>(finishDotLoop - startDotLoop).count() << "ns\n"; // Print measured time, in nanoseconds
};


void labExamples() {
    auto startFactorial = std::chrono::high_resolution_clock::now();
    std::cout << "Factorial<5>: ";
    std::cout << Factorial<5>::value << "\n";

    auto finishFactorial = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishFactorial - startFactorial).count() << "ns\n"; // Print measured time, in nanoseconds

    std::cout << "\n";

    auto startIfElse = std::chrono::high_resolution_clock::now();
    std::cout << "1 == 2 ? ";
    IfElseCondition<1 == 2>::f();
    std::cout << "1 != 2 ? ";
    IfElseCondition<1 != 2>::f();
    std::cout << "1 ? ";
    IfElseCondition<1>::f();

    auto finishIfElse = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishIfElse - startIfElse).count() << "ns\n"; // Print measured time, in nanoseconds

    std::cout << "\n";

    auto startSwitchCase = std::chrono::high_resolution_clock::now();
    std::cout << "Switch case for 1: ";
    SwitchCase<1>::f();
    std::cout << "Switch case for 2: ";
    SwitchCase<2>::f();
    std::cout << "Switch case for 10: ";
    SwitchCase<10>::f();

    auto finishSwitchCase = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishSwitchCase - startSwitchCase).count() << "ns\n"; // Print measured time, in nanoseconds

    auto startBubbleSort = std::chrono::high_resolution_clock::now();
    std::cout << "\nBubble sorting an array { 9,2,7,6 }:\n";

    int array[4] = { 9,2,7,6 };
    IntBubbleSort<4>::sort(array);
    std::cout << "Sorted array:\n";
    for (int i = 0; i < 4; i++)
        std::cout << array[i] << '\n';

    auto finishBubbleSort = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishBubbleSort - startBubbleSort).count() << "ns\n"; // Print measured time, in nanoseconds

    auto startSinus = std::chrono::high_resolution_clock::now();
    std::cout << "\nSinus: ";
    float f = Sine<32, 5>::sin();
    std::cout << f << "\n";

    auto finishSinus = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finishSinus - startSinus).count() << "ns\n"; // Print measured time, in nanoseconds

    auto startDot = std::chrono::high_resolution_clock::now();
    std::cout << "\nDot Product<4>: ";
    int a[4] = { 1,100,0,-1 };
    int b[4] = { 2,2,2,2 };
    std::cout << dot<4>(a, b);

    auto finishDot = std::chrono::high_resolution_clock::now();
    std::cout << "\n" << std::chrono::duration_cast<std::chrono::nanoseconds>(finishDot - startDot).count() << "ns\n"; // Print measured time, in nanoseconds

}

int main()
{
    //LAB WORK
    labExamples();

    std::cout << "\n---------------CHALLENGES----------------\n";

    //CHALLENGES
    compareFactorial();
    compareSine();
    compareDot();

    return 0;
}