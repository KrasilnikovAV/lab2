#pragma once
#include "../TVector/TVector.h"

const int MAX_MATRIX_SIZE = 10000;

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix<T>& m);
	TMatrix(const TVector<TVector<T>>& m);

	bool operator==(const TMatrix<T>& m);
	TMatrix<T>& operator= (const TMatrix<T>& m);
	TMatrix<T> operator+ (const TMatrix<T>& mt);
	TMatrix<T> operator- (const TMatrix<T>& mt);

	friend ostream& operator<<(ostream& ostr, const TMatrix <T>& m) {
		for (int i = 0; i < m.size; i++) {
			for (int j = 0; j < i; j++) {
				cout << "      ";
			}
			cout << m.pVector[i] << '\n';
		}
		return ostr;
	}
};


template<class T>
TMatrix<T>::TMatrix(int s) : TVector<TVector<T>>(s)
{
	if (s <= 0 || s > MAX_MATRIX_SIZE)
		throw "Invalid argument value";
	for (int i = 0; i < s; i++) {
		this->pVector[i] = TVector<T>(s - i, i);
	}
}

template<class T>
TMatrix<T>::TMatrix(const TMatrix<T>& m) : TVector<TVector<T>>(m)
{}

template<class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>>& m) : TVector<TVector<T>>(m)
{}

template<class T>
bool TMatrix<T>::operator==(const TMatrix<T>& m)
{
	return TVector<TVector<T>>::operator==(m);
}

template<class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m) {
	if (this != &m) {
		if (this->size != m.size) {
			delete[] this->pVector;
			this->size = m.size;
		}
		this->startIndex = m.startIndex;
		this->pVector = new TVector<T>[this->size];
		for (int i = 0; i < this->size; ++i)
			this->pVector[i] = m.pVector[i];
	}
	return *this;
}

template<class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
	return TVector<TVector<T>>::operator+(mt);
}

template<class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
	return TVector<TVector<T>>::operator-(mt);
}

