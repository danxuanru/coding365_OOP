#include <math.h>

class MathVector
{

private:
    /* This does not work */
    // double x, y, z;
    // double _vec[3];  -> double _vec[_dim] X:can't use verious
    int _dim;
    double *_vec; // pointer

public:
    /* Constructor */
    MathVector() // Default constructor
    { 

    }
    void init(int dim, double *ptr)
    {
        _dim = dim;              // make dim can use in all class, not just in this function
        _vec = new double[_dim]; // new : allocate memory according to _dim, return 'address'
        // _vec=ptr -> Wrong!!
        for (int i = 0; i < _dim; i++)
        {
            _vec[i] = ptr[i]; // Data copy for array
        }
    }
    MathVector(int dim, double *ptr) // Self-defined constructor
    {
        init(dim, ptr);
    }
    // If data contain pointer, we should have "Copy constructor" and "Copy assignment"
    // avoid pass by reference
    // Copy constructor
    MathVector(MathVector const &input)
    {
        init(input._dim, input._vec);
    }
    // Copy assignment
    MathVector &operator=(MathVector const &input)
    {
        init(input._dim, input._vec);
        return *this;
    }

    // Getter: direct return
    int getDim()
    {
        return _dim;
    }
    double getAt(int index)
    {
        return _vec[index];
    }
    // Setter
    void setDim(int dim)
    {
        _dim = dim; // change _dim
    }
    double length()
    {
        // a^2+b^2 = c^2
        // a^2+b^2+c^2 = d^2
        double sum = 0;
        for (int i = 0; i < _dim; i++)
        {
            sum += _vec[i] * _vec[i];
        }
        return sqrt(sum);
    }
};