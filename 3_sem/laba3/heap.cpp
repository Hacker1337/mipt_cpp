#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::swap;

#include <vector>
using std::vector;



template <typename T>
struct Comparator {
    virtual bool operator()(T const &, T const &) const = 0;
};
struct IntComparator final : Comparator<int> {
    bool operator()(int const &lha, int const &rha) const override {
        return lha < rha;
    }
};

//template<typename T>
//struct Queued {
//    T element;
//    int priority;
//};
//
//template<typename T>
//struct QueuedCmp final : Comparator<Queued<T>> {
//    bool operator()(Queued<T> const &lha, Queued<T> const &rha) const override {
//        return lha.priority < rha.priority;
//    }
//};

template<typename T>
class PriorityQueue {
    int size;
    int capacity;
    T* massive;
    const Comparator<T> &cmp;

    void double_capacity() {
        change_capacity(2*capacity);
    }
    void half_capacity(){
        if (size+1 > capacity/2) {
            cerr << "Error! Losing data!\n";
        }
        change_capacity(capacity/2);
    }

    void change_capacity(int new_capacity) {
        T* new_massive = new T[new_capacity];
        for (int i = 1; i < size+1; ++i) {
            new_massive[i] = massive[i];
        }
        capacity = new_capacity;
        delete[] massive;
        massive = new_massive;
    }
public:
    PriorityQueue(Comparator<T> const &cmp): cmp(cmp) {
        size = 0;
        capacity = 1;
        massive = new T[capacity];
    }

    ~PriorityQueue() {
        delete[] massive;
    };

    bool is_empty() {
        return size == 0;
    }
    void push(T const & el) {
        cout << "Pushing " << el << endl;
        if (capacity == size+1) {
            double_capacity();
        }
        massive[++size] = el;
        int i = size;
        while (i > 1) {
            if (cmp(massive[i/2], massive[i])) {
                break;
            }
            std::swap(massive[i/2], massive[i]);
            i /= 2;
        }
    }
    T peek() {   // returns value without deletion;
        return massive[1];
    }
    T poll() {   // returns value with deletion;
        T value = massive[1];
        massive[1] = massive[size];
        --size;
        int i = 1;
        while (true) {
            if (2*i+1 <= size) {
                if (cmp(massive[2*i], massive[2*i+1])) {
                    swap(massive[i], massive[2*i]);
                    i = 2*i;
                }
                else {
                    swap(massive[i], massive[2*i+1]);
                    i = 2*i+1;
                }
            }
            else if (2*i <= size) {
                swap(massive[i], massive[2*i]);
                break;
            }
            else {
                break;
            }
        }
        if (size+1 < capacity/4) {
            half_capacity();
        }
        return value;
    }

    void print_massive() {
        for (int i = 1; i < capacity; i<<=1) {
            for (int j = i; j < 2 * i and j <= size; ++j) {
                cout << massive[j] << ' ';
            }
            cout << endl;
        }
    };

};

int main()
{

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); // изменить стандартный поток ввода вывода
    IntComparator cmp;
    PriorityQueue<int> queue(cmp);
    cout << std::boolalpha << queue.is_empty() << endl;
    queue.print_massive();

    queue.push(19);
    queue.print_massive();
    queue.push(5);
    queue.print_massive();
    queue.push(3);
    queue.print_massive();
    queue.push(20);
    queue.print_massive();
    while (! queue.is_empty()) {
        cout << "Took from queue " << queue.poll() << endl;
        queue.print_massive();
    }
}
