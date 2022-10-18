#include "heritage_probability_test.cpp"

#include <string>
#include <iomanip>

using std::stoi;

int main(int argc, char* argv[]) {
    // not for manual run!! Runs from jupyter notebook code

    cout << std::setprecision(10);

    if (argc < 2) {
        cout << "Add number of experiment in the end of running command\n";
        return 0;
    }
    // cout << stoi(argv[1]) << endl;

    int rand_seed = 1;
    if (argc >= 3) {
        rand_seed = stoi(argv[2]);
    }
    int number_of_experiments = stoi(argv[1]);
    
    SegmentState s(0, 100);
    ProbabilityTest pt(-1000, 1000);
    std::cout << pt.test(s, number_of_experiments, rand_seed) << std::endl;

}