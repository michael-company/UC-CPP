#ifndef MATRIX_H
#  define MATRIX_H
#include <initializer_list>
#include <algorithm>
#include <array>
#include <memory>
#include <numeric>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

#undef minor

using std::initializer_list;
using std::array;
using std::unique_ptr;
using std::max_element;
using std::accumulate;
using std::inner_product;
using std::ostream;
using std::ostringstream;
using std::streamsize;
using std::setw;
using std::endl;
using std::cerr;
using std::invalid_argument;

//10/10

namespace mpcs51044 {

    template<int rows, int cols = rows>
    class Matrix {
    public:
        Matrix() : data{} {}
        Matrix(initializer_list<initializer_list<double>> init) {
            try {
                if (data.size() != init.size())
                    throw invalid_argument("Matrices have to have the same size.");
                for (auto row : init) {
                    if (row.size() != cols)
                        throw invalid_argument("Matrices have to have the same number of rows and columns.");
                }
            }
            catch (const invalid_argument& inval_argument) {
                cerr << inval_argument.what() << endl;
            }
            auto dp = data.begin();
            for (auto row : init) {
                std::copy(row.begin(), row.end(), dp->begin());
                dp++;
            }
        }
        Matrix(Matrix<rows, cols> && other) {
            data = std::move(other.data);
        }
        Matrix& operator=(Matrix<rows, cols> && other) {
            data = std::move(other.data);
        }

        double &operator()(int x, int y) {
            return data[x][y];
        }

        double operator()(int x, int y) const {
            return data[x][y];
        }

        inline friend
        ostream &
        operator<<
        (ostream &os, const Matrix<rows, cols> &m) {
            size_t width = m.longestElementSize() + 2;
            os << "[ " << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    os << setw(static_cast<streamsize>(width)) << m(i, j);
                }
                os << endl;
            }
            os << "]" << endl;
            return os;
        }

        Matrix<rows - 1, cols - 1> minor(int r, int c) const {
            Matrix<rows - 1, cols - 1> result;
            for (int i = 0; i < rows; i++) {
                if (i == r) {
                    continue;
                }
                for (int j = 0; j < cols; j++) {
                    if (j == c) {
                        continue;
                    }
                    result(i < r ? i : i - 1, j < c ? j : j - 1) = data[i][j];
                }
            }
            return result;
        }

        double determinant() const {
            double val = 0;
            for (int i = 0; i < rows; i++) {
                val += (i % 2 ? -1 : 1)
                * data[i][0]
                * minor(i, 0).determinant();
            }
            return val;
        }

    private:
        static size_t accumulateMax(size_t acc, double d) {
            ostringstream ostr;
            ostr << d;
            return std::max(acc, ostr.str().size());
        }
        static size_t accumulateMaxRow(size_t acc, array<double, cols> row) {
            return std::max(acc,
                            accumulate(row.begin(), row.end(), static_cast<size_t>(0), accumulateMax)
                            );
        }
        size_t longestElementSize() const {
            return accumulate(data.begin(), data.end(), 0, accumulateMaxRow);
        }
        array<array<double, cols>, rows> data;
    };

    template<>
    double
    Matrix<1, 1>::determinant() const
    {
        return data[0][0];
    }

    template<>
    double
    Matrix<2, 2>::determinant() const
    {
        return data[0][0]*data[1][1] - data[1][0]*data[0][1];
    }

    template<int a, int b, int c>
    inline Matrix<a, c>
    operator*(Matrix<a, b> const &l, Matrix<b, c> const &r)
    {
        Matrix<a, c> result;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < c; j++) {
                double total = 0;
                for (int k = 0; k < b; k++)
                    total += l(i, k) * r(k, j);
                result(i, j) = total;
            }
        }
    }

    template<int a, int b>
    inline Matrix<a, b>
    operator+(Matrix<a, b> const &l, Matrix<a, b> const &r)
    {
        Matrix<a, b> result;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                result(i, j) = l(i, j) + r(i, j);
            }
        }
        return result;
    }

}
#endif
