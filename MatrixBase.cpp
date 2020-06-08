#include "MatrixBase.h"
#include <string>
#include <cassert>

void MatrixBase::operator*=(int iMult) 
{
    for (int x = 0; x < m_size; ++x) 
        for (int y = 0; y < m_size; ++y) 
            element(x, y) *= iMult;
}

void MatrixBase::operator+=(MatrixBase &iAdd) 
{
    assert(iAdd.size() == m_size);
    for (int x = 0; x < iAdd.m_size; ++x) 
        for (int y = 0; y < iAdd.m_size; ++y)
            element(x, y) += iAdd.element(x, y);
}

std::ostream &operator<<(std::ostream &out, const MatrixBase &iMatrix) 
{
    for (int x = 0; x < iMatrix.size(); x++) 
    {
        for (int y = 0; y < iMatrix.size(); y++)
            out << iMatrix.element(x, y) << ' ';
        out << "\n";
    }
    return out;
}
