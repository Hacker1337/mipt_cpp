#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

#include <vector>
using std::vector;

// lector gcode

using State = int;

class InterfaceState {  // universal class with virtual fuction contains
   public:
    virtual bool contains(State s) const = 0;
};

class DiscreteState : public InterfaceState {
   private:
    State const s0;

   public:
    DiscreteState(State s0) : s0(s0) {}
    bool contains(State s) const override { return s == s0; }
};

class SegmentState : public InterfaceState {
   private:
    State const begin_s0, end_s0;

   public:
    SegmentState(State begin_s0, State end_s0)
        : begin_s0(begin_s0), end_s0(end_s0) {}
    bool contains(State s) const override {
        return begin_s0 <= s and end_s0 >= s;
    }
};

class PairState : public InterfaceState {
    // реализует функции, необходимые для класса
    // объединяющего каким-либо образом два состояния
   protected:
    InterfaceState const &a, &b;

   public:
    PairState(InterfaceState const &a, InterfaceState const &b) : a(a), b(b) {}
    
};

class UnionState : public PairState {
    public:
    bool contains(State s) const override {
        return a.contains(s) || b.contains(s);
    }
    using PairState::PairState;
};
class InterceptState : public PairState {
    bool contains(State s) const override {
        return a.contains(s) && b.contains(s);
    }
    using PairState::PairState;
};
class InversState : public InterfaceState {
   private:
    InterfaceState const &a;

   public:
    InversState(InterfaceState const &a) : a(a) {}

    bool contains(State s) const override { 
        return ! a.contains(s); 
    }
};

#include <random>
class ProbabilityTest {
   private:
    State const E_min, E_max;

   public:
    ProbabilityTest(State E_min, State E_max) : E_min(E_min), E_max(E_max) {}
    // float test(DiscreteState system, unsigned test_count, unsigned seed)
    // const {
    //     std::default_random_engine reng(seed);
    //     std::uniform_int_distribution<int> dstr(E_min, E_max);
    //     unsigned good = 0;
    //     for (unsigned cnt = 0; cnt != test_count; ++cnt)
    //         if (system.contains(dstr(reng))) ++good;
    //     return static_cast<float>(good) / static_cast<float>(test_count);
    // }
    // float test(SegmentState system, unsigned test_count, unsigned seed) const
    // {
    //     std::default_random_engine reng(seed);
    //     std::uniform_int_distribution<int> dstr(E_min, E_max);
    //     unsigned good = 0;
    //     for (unsigned cnt = 0; cnt != test_count; ++cnt)
    //         if (system.contains(dstr(reng))) ++good;

    //     return static_cast<float>(good) / static_cast<float>(test_count);
    // }

    /*
        переделал две функции принимающие разные системы на одну функцию,
        которая принимает объект, реализующий контракт, задаваемый общим
       интерфейсом InterfaceState. Интерфейс определяет pure virtual функцию
       count, которые наследующие классы реализуют. Так как объект state
       принимается по ссылке, вызывается правильная версия функции,
       реализованная у наследника.
    */

    float test(InterfaceState &system, unsigned test_count,
               unsigned seed) const {
        std::default_random_engine reng(seed);
        std::uniform_int_distribution<int> dstr(E_min, E_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (system.contains(dstr(reng))) ++good;

        return static_cast<float>(good) / static_cast<float>(test_count);
    }
};

// int main() {
//     freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout); // изменить стандартный поток
//     // ввода вывода
// }

// int main() {
//     DiscreteState d(0);
//     SegmentState s(0, 100);
//     ProbabilityTest pt(-1000, 1000);
//     std::cout << pt.test(d, 2000000, 1) << std::endl;
//     std::cout << pt.test(s, 2000000, 1) << std::endl;

//     SegmentState s2(200, 300);

//     UnionState u1(s, s2);

//     std::cout << pt.test(u1, 20000, 1) << endl;

// }