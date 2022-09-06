#ifndef MATH_VECTOR // avoid redefined : if not define, define the following
#define MATH_VECTOR

#include <cmath>
#include <vector>

class MathVector
{

private:
    /* This does not work */
    // double x, y, z;
    // double _vec[3];  -> double _vec[_dim] X:can't use verious
    int _dim;
    // double *_vec; // pointer
    std::vector<double> _vec;

public:
    /* Constructor */
    MathVector() // Default constructor
    {
        _dim = 0; // *initialization
        //(change to vector<>) _vec = NULL;
    }
    void init(int dim, double *ptr)
    {
        _dim = dim; // make dim can use in all class, not just in this function

        for (int i = 0; i < _dim; i++)
        {
            _vec.push_back(ptr[i]);
        }

        /* (change to vector<>)
            if (_vec != NULL) // return used memory space
            {
                delete _vec;
            }
            _vec = new double[_dim]; // new : allocate memory according to _dim, return 'address'
            // _vec=ptr -> Wrong!!
            for (int i = 0; i < _dim; i++)
            {
                _vec[i] = ptr[i]; // Data copy for array
            }
        */
    }
    MathVector(int dim, double *ptr) // Self-defined constructor
    {
        // avoid residual garbage in memory -> initialization
        _dim = 0;
        // (change to vector<>) _vec = NULL;
        // convert double pointer to vector X
        init(dim, ptr);
    }
    // Destructor
    ~MathVector()
    {
        /* (change to vector<>)
            if (_vec != NULL)
            {
                delete[] _vec;
            }
        */
    }

    /*  If data contain pointer, we should have "Copy constructor" and "Copy assignment"
        avoid pass by reference  */

    // Copy constructor
    MathVector(MathVector const &input)
    {
        // std::cout << "Copy constructor\n";
        /* (change to vector<>)
            _dim = 0; // *initialization
            _vec = NULL;
            init(input._dim, input._vec);
        */
        _dim = input._dim;
        _vec.clear(); // clear all element
        for (int i = 0; i < _dim; i++)
        {
            _vec.push_back(input._vec[i]);
        }
    }
    // Copy assignment
    MathVector &operator=(MathVector const &input)
    {
        // std::cout << "Copy assignment\n";
        // (change to vector<>) init(input._dim, input._vec);

        _dim = input._dim;
        _vec.clear(); // clear all element
        for (int i = 0; i < _dim; i++)
        {
            _vec.push_back(input._vec[i]);
        }
        return *this;
        // &: make change to self object
    }
    // Copy assignment2: (=double)
    MathVector &operator=(double const &input)
    {
        this->_dim = input;
        return *this;
    }

    // Define operator notation
    MathVector operator+(MathVector const &input)
    {
        // result: first object(augend)
        MathVector result = *this;
        for (int i = 0; i < (*this)._dim; i++)
        {
            result._vec[i] += input._vec[i];
        }
        return result;
        // make change to new object(result)
    }
    MathVector operator-(MathVector const &input)
    {
        // result: first object(minuend)
        MathVector result = *this;
        for (int i = 0; i < _dim; i++)
        {
            result._vec[i] -= input._vec[i];
        }
        return result;
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
    void setDim(int dim) // passed by value
    {
        _dim = dim; // change _dim
    }
    double length()
    {
        // a^2 + b^2 = c^2
        // a^2 + b^2 + c^2 = d^2
        double sum = 0;
        for (int i = 0; i < _dim; i++)
        {
            sum += _vec[i] * _vec[i];
        }
        return sqrt(sum);
    }
    // use "const" we can't change the variable value
    void add(MathVector const &input) // & -> passed by reference (no call copy constructor)
    {
        if (input._dim == _dim) // when the dimensions are same
        {
            for (int i = 0; i < _dim; i++)
            {
                _vec[i] += input._vec[i];
            }
        }
        // input._dim = 1000;
    }
    void add(MathVector *input) // * -> passed by pointer
    {
        if (input->_dim == _dim) // pointer: object -> data
        {
            for (int i = 0; i < _dim; i++)
            {
                _vec[i] += input->_vec[i];
            }
        }
    }
    void expand(double input)
    {
        _dim += 1;
        _vec.push_back(input);
        /* (change to vector<>)
            double *tmp = new double[_dim];
            for (int i = 0; i < _dim; i++)
            {
                tmp[i] = _vec[i];
            }
            tmp[_dim - 1] = input;
            delete[] _vec;
            _vec = tmp;
        */
    }
};

#endif