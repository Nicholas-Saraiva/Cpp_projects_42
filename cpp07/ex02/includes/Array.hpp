#pragma once

template	<typename T>
class Array
{
private:
	
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);

	Array&	operator=(const Array& other);
	Array&	operator[](int index);
	~Array();
};
