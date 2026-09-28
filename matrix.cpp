#include <iostream>

class Matrix
{
private:
    int value[10][10];

public:
    Matrix();

    void read(std::istream& in);

    Matrix mat_add(const Matrix& other) const;

    void write(std::ostream& out) const;
};


// init matrix all to 0
Matrix::Matrix()
{
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            value[row][column] = 0;
        }
    }
}


// read matrix values in
void Matrix::read(std::istream& in)
{
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            in >> value[row][column];
        }
    }
}


// add the two matricies 
Matrix Matrix::mat_add(const Matrix& other) const
{
    Matrix result;

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            result.value[row][column] =
                value[row][column] + other.value[row][column];
        }
    }

    return result;
}


// display matrix output
void Matrix::write(std::ostream& out) const
{
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            out << value[row][column];

            if (column < 9)
            {
                out << ' ';
            }
        }

        out << '\n';
    }
}


int main()
{
    // use the public methods to read A, B, add then write output
    Matrix A;
    Matrix B;

    A.read(std::cin);
    B.read(std::cin);

    Matrix sum = A.mat_add(B);

    sum.write(std::cout);

    return 0;
}
