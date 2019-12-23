#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;

template <class  T>
class TVector
{
protected:
	T* pVector;
	unsigned int size;
	unsigned int startIndex;

public:
	TVector(int s = 10, int startin = 0);
	TVector(const TVector& v);
	~TVector();

	unsigned int GetSize() const;
	unsigned int GetStartIndex() const;
	T& GetValue(int pos) const;
	T& operator[](int pos);

	bool operator==(const TVector<T>& v) const;
	TVector<T>& operator=(const TVector<T>& v);

	TVector<T> operator+(const TVector<T>& v) const;
	TVector<T> operator-(const TVector<T>& v) const;
	TVector<T> operator*(const TVector<T>& v) const;


	TVector<T> operator+(const T& val) const;
	TVector<T> operator-(const T& val) const;
	TVector<T> operator*(const T& val) const;

	friend istream& operator>>(istream& istr, TVector<T>& v) {
		for (int i = 0; i < v.size; i++)
			istr >> v.pVector[i];
		return istr;
	};
	friend ostream& operator<<(ostream& ostr, const TVector<T>& v) {
		for (int i = 0; i < v.size; i++)
			ostr << setw(5) << v.pVector[i]  << ' ';
		return ostr;
	};
};


template<class T>
TVector<T>::TVector(int s, int startin)
{
	if (s < 0 || s > MAX_VECTOR_SIZE || startin < 0)
		throw "Invalid arguments value";
	size = s;
	startIndex = startin;
	pVector = new T[size];
	for (int i = 0; i < size; i++)
		pVector[i] = 0;

}

template<class T>
TVector<T>::TVector(const TVector& v) :
	size(v.size), startIndex(v.startIndex)
{
	pVector = new T[size];

	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];
}

template<class T>
TVector<T>::~TVector()
{
	if (pVector != nullptr)
		delete[] pVector;
}

template<class T>
unsigned int TVector<T>::GetSize() const
{
	return size;
}

template<class T>
unsigned int TVector<T>::GetStartIndex() const
{
	return startIndex;
}

template<class T>
T& TVector<T>::GetValue(int pos) const
{
	if (pos - startIndex < 0 || pos - startIndex >= size)
		throw "Invalid argument value";
	return pVector[pos - startIndex];
}

template<class T>
T& TVector<T>::operator[](int pos)
{
	if (pos < startIndex || pos - startIndex >= size)
		throw "Invalid argument value";
	return pVector[pos - startIndex];
}

template<class T>
bool TVector<T>::operator==(const TVector<T>& v) const
{
	if (this == &v)
		return true;
	if (size != v.size || startIndex != v.startIndex)
		return false;
	for (int i = 0; i < size; i++)
		if (!(pVector[i] == v.pVector[i]))
			return false;
	return true;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& v)
{
	if (this == &v)
		return *this;
	if (size != v.size) {
		delete[] pVector;
		size = v.size;
		pVector = new T[size];
	}
	startIndex = v.startIndex;
	for (int i = 0; i < size; i++)
		pVector[i] = v.pVector[i];
	return *this;
}

template<class T>
TVector<T> TVector<T>::operator+(const TVector<T>& v) const
{
	if (size != v.size || startIndex != v.startIndex)
		throw "Invalid argument value";

	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] = tmp.pVector[i] + v.pVector[i];
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector<T>& v) const
{
	if (size != v.size || startIndex != v.startIndex)
		throw "Invalid argument value";

	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] = tmp.pVector[i] - v.pVector[i];
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator*(const TVector<T>& v) const
{
	if (size != v.size || startIndex != v.startIndex)
		throw "Invalid argument value";

	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] = tmp.pVector[i] * v.pVector[i];
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator+(const T& val) const
{
	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] += val;
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& val) const
{
	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] -= val;
	}
	return tmp;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& val) const
{
	TVector<T> tmp(*this);
	for (int i = 0; i < size; i++) {
		tmp.pVector[i] *= val;
	}
	return tmp;
}