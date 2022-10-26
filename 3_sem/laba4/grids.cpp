
template <typename T, int dim = 2>
class Grid {  // if dim != 2, create massive of dim-1 dimensional Grids
    using size_type = unsigned;

   private:
    Grid<T, dim - 1>* data;
    size_type z_size;

   public:
    template <typename... Args>
    T& operator()(size_type z_idx,
                  Args... args) {  // () multidimensional indexing
        return data[z_idx](args...);
    }

    template <typename... Args>
    T const& operator()(
        size_type z_idx,
        Args... args) const {  // () multidimensional const indexing
        return data[z_idx](args...);
    }

    template <typename... Args>
    Grid(size_type z_size,
         Args... args)  // multidimensional constructor by dimensions.
        : z_size(z_size) {
        data = new Grid<T, dim - 1>(args...);
        for (int i = 1; i < z_size; i++) {
            data[i] = Grid<T, dim - 1>(args...);
        }
    }
    Grid<T, dim - 1>& operator[](size_type z_idx) { return data[z_idx]; }

    Grid<T, dim - 1> const& operator[](size_type z_idx) const {
        return data[z_idx];
    }

    size_type get_z_size() const { return z_size; }
};

template <typename T>
class Grid<T, 2> final {
   public:
    using value_type = T;
    using size_type = unsigned;

   private:
    T* data;
    size_type y_size, x_size;

   public:
    Grid(T* data, size_type y_size, size_type x_size)
        : data(data), y_size(y_size), x_size(x_size) {}

    Grid(size_type y_size, size_type x_size)
        : y_size(y_size), x_size(x_size), data(new T[y_size * x_size]) {}

    Grid(size_type y_size, size_type x_size, T const& t)
        : Grid(y_size, x_size) {
        for (size_type y_idx = 0; y_idx != y_size; ++y_idx)
            for (size_type x_idx = 0; x_idx != x_size; ++x_idx)
                (*this)(y_idx, x_idx) = t;
    }

    ~Grid() { delete[] data; }

    Grid(Grid<T> const& grid) : Grid(grid.z_size, grid.y_size) {
        for (size_type y_idx = 0; y_idx != y_size; ++y_idx)
            for (size_type x_idx = 0; x_idx != x_size; ++x_idx)
                (*this)(y_idx, x_idx) = grid(y_idx, x_idx);
    }

    Grid<T>& operator=(Grid<T> const& grid) {
        this->x_size = grid.x_size;
        this->y_size = grid.y_size;
        delete[] data;
        data = new T[y_size * x_size];
        for (size_type y_idx = 0; y_idx != y_size; ++y_idx)
            for (size_type x_idx = 0; x_idx != x_size; ++x_idx)
                (*this)(y_idx, x_idx) = grid(y_idx, x_idx);
        return *this;
    }

    Grid(Grid<T>&& grid) : x_size(grid.x_size), y_size(grid.y_size) {
        data = grid.data;
        grid.data = nullptr;
    }

    Grid<T>& operator=(Grid<T>&& grid) {
        this->x_size = grid.x_size;
        this->y_size = grid.y_size;
        delete[] data;
        data = grid.data;
        grid.data = nullptr;
        return *this;
    }

    T operator()(size_type y_idx, size_type x_idx) const {
        return data[y_idx * x_size + x_idx];
    }
    T& operator()(size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }
    Grid(T const& t) : Grid<T>(1, 1) { *this = t; }
    Grid<T>& operator=(T const& t) {
        for (auto it = data, end = data + x_size * y_size; it != end; ++it)
            *it = t;
        return *this;
    }

    T* operator[](size_type y_idx) { return data + y_idx * x_size; }
    T const* operator[](size_type y_idx) const { return data + y_idx * x_size; }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }
};
