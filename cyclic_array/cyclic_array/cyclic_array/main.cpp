#include <iostream>
#include <vector>
#include <time.h>
#include <malloc.h>

using namespace std;
template <int size, typename SomeValueType>
class CyclicStaticArray
{
private:
	SomeValueType* array = new SomeValueType[size];
	
public:
	~CyclicStaticArray()
	{
		delete array;
	}

	void set_elements()
	{
		for (int i = 0; i < size; i++)
		{
			array[i] = rand() % 10;
		}
	}

	void get_cycle_array()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
	}

	SomeValueType operator[](int index)
	{
		if (index > size)
		{
			index %= size;
		}
		else
		{
			if (index > (-size))
			{
				index += size;
			}
			else
			{
  				index = (index % size) * (-1);
			}
		}
		return array[index];
	}
};

template <typename SomeValueType>
class CyclicArray
{
private:
	vector<SomeValueType> array1;
	int size_array = 0;
public:

	void add_element(SomeValueType i)
	{
		array1.push_back(i);
		size_array++;
	}

	void get_cycle_dynamic_array()
	{
		for (int n : array1)
			cout << n << " ";
	}

	SomeValueType operator[](int index)
	{
		if (index > size_array)
		{
			index %= size_array;
		}
		else
		{
			if (index > (-size_array))
			{
				index += size_array;
			}
			else
			{
				index = (index % size_array) * (-1);
			}
		}
		return array1[index];
	}
};

int main(void)
{
	srand(time(NULL));
	CyclicStaticArray<13,int> cycle;
	cycle.set_elements();
	cout << endl;
	cycle.get_cycle_array();
	cout << endl;
	int index = -10;
	cout << "cycle[" << index << "]==" << cycle[index] << endl;
	system("pause");
	system("cls");
	CyclicArray<int> ca;
	for (int i=0 ; i < 10; i++)
	ca.add_element(i);
	ca.get_cycle_dynamic_array();
	index = -55;
	cout << endl << "cycle[" << index << "]==" << ca[index] << endl;
	return 0;
}


