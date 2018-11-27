#include "SimpleList.h"

template<class T>
SimpleList<T>::SimpleList()
{
	elements = new T[CAPACITY];
	numElements = 0;
}

template<class T>
SimpleList<T>::~SimpleList()
{
	for (int i = 0; i <= numElements; i++)
	{
		destroy(elements[i]);
	}
	delete[] elements;
	numElements = 0;
}

template<class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException)
{
	if (index > numElements - 1)
	{
		throw InvalidIndexException();
	}
	else if (index < 0 || index >= CAPACITY)
	{
		throw InvalidIndexException();
	}
	else
	{
		return elements[index];
	}

}

template<class T>
bool SimpleList<T>::empty() const
{
	if (numElements == 0)
		return true;
	return false; 
}

template<class T>
T SimpleList<T>::first() const throw(EmptyListException)
{
	if (numElements==0)
	{
		throw EmptyListException();
	}
	return elements[0];
}

template<class T>
T SimpleList<T>::last() const throw (EmptyListException)
{
	if (numElements==0)
	{
		throw EmptyListException();
	}
	return elements[numElements - 1];
}

template<class T>
int SimpleList<T>::getNumElements() const
{
	return numElements;
}

template<class T>
void SimpleList<T>::insert(T item) throw (FullListException)
{
	if (numElements < CAPACITY)
	{
		elements[numElements] = item;
		numElements++;
	}
	else
	{
		throw FullListException();
	}
}

template<class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException)
{
	if (index >= numElements || index < 0)
	{
		throw InvalidIndexException();
	}
	else if (numElements == 0)
	{
		throw EmptyListException();
	}
	else
	{
		destroy(elements[index]);
		while (index < numElements - 1)
		{
			elements[index] = elements[index + 1];
			index++;
		}
		numElements--;
	}
}

template<class T>
void SimpleList<T>::destroy(T element)
{

}

template<class T>
void SimpleList<T>::destroy(T* element)
{
	delete element;
}
	
