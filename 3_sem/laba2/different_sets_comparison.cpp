#include <iomanip>
#include <string>

#include "heritage_probability_test.cpp"

using std::stoi;

int main(int argc, char* argv[]) {
    cout << std::setprecision(4);

    int rand_seed = 3;

    int number_of_experiments = 50000;

    SegmentState s(0, 9);
    ProbabilityTest pt(-100, 100);

    DiscreteState d0(0);
    DiscreteState d1(10);
    UnionState t(d0, d1);

    UnionState** partial_unions = new UnionState*[9];
    DiscreteState** dis_st = new DiscreteState*[8];
    partial_unions[0] = &t;
    for (int i = 0; i < 8; i += 1) {
        dis_st[i] = new DiscreteState((i + 2) * 10);
        UnionState* p = new UnionState(*partial_unions[i], *dis_st[i]);
        partial_unions[i + 1] = p;
    }

    // comparing range(0, 10, 1) and range(0, 100, 10) results

    cout << pt.test(s, number_of_experiments, rand_seed) << " with segment\n";
    cout << pt.test(*partial_unions[8], number_of_experiments, rand_seed)
         << " with union of discrete points \n";
    cout << "Standard deviation is about " << 1 / sqrt(number_of_experiments)
         << endl;

    // for (int i = 0; i < 30; i++)
    // {
    //     cout << i << " " << std::boolalpha << partial_unions[7]->contains(i)
    //     << endl;
    // }

    // SegmentState s1(0, 30);
    // SegmentState s2(90, 150);
    // SegmentState s3(200, 300);
    // UnionState u1(s1, s2);
    // UnionState u2(u1, s3);
    // for (int i = 0; i < 300; i+=20)
    // {
    //     cout << i << " " << std::boolalpha << u2.contains(i) << endl;
    // }

    // DiscreteState d1(0);
    // DiscreteState d2(1);
    // DiscreteState d3(2);
    // UnionState u1(d1, d2);
    // UnionState u2(u1, d3);
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << i << " " << std::boolalpha << u2.contains(i) << endl;
    // }

    // DiscreteState d1(0);
    // DiscreteState d2(1);
    // DiscreteState d3(2);
    // UnionState u1(DiscreteState(0), DiscreteState(1));
    // UnionState u2(u1, DiscreteState(2));
    // for (int i = 0; i < 10; i++) {
    //     cout << i << " " << std::boolalpha << u2.contains(i) << endl;
    // }

    for (int i = 1; i < 9; i++) {
        delete partial_unions[i];
    }
    delete[] partial_unions;

    for (int i = 0; i < 8; i++) {
        delete dis_st[i];
    }
    delete[] dis_st;

}