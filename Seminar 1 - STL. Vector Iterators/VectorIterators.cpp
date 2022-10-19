#include<iostream>
#include<vector>

bool validMatrix(const std::vector<std::vector<int> >& container)
{
	for (int row = 0; row < container.size() - 1; row++)
	{
		if (container[row].size() != container[row + 1].size())
			return false;
	}
	return true;
}

std::vector<std::vector<int> > sum(
	const std::vector<std::vector<int> >& a,
	const std::vector<std::vector<int> >& b)
{
	if (!(validMatrix(a) && validMatrix(b)))
		throw std::invalid_argument("The matrix is not valid");

	if (a.size() != b.size || a[0].size != b[0].size())
		throw "not campatable";

	std::vector<std::vector<int> > result;
	for (int row = 0; row < a.size(); row++)
	{
		for (int col = 0; col < a[0].size(); col++)
		{
			result[row].push_back(a[row][col] + b.at(row).at(col));
		}
	}
	for (std::vector<std::vector<int>>::const_iterator ita = a.cbegin(), itb = b.cbegin(); 
		ita != a.cend(); ita++, itb++)
	{
		std::vector<int> row;
		for (std::vector<int>::const_iterator ja = (*ita).cbegin(), jb = (*itb).cbegin();
			ja != (*ita).cend(); ja++, jb++)
		{
			row.push_back(*ja + *jb);
		}
		result.push_back(row);
	}
}


int main()
{
	std::vector<int> fmi;
	fmi.push_back(19);
	fmi.push_back(12);
	fmi.push_back(17);

	//range based loop 
	for (int data : fmi)
		std::cout << data << std::endl;
	
	//????????? 
	std::vector<int>::iterator it = fmi.begin();
	std::vector<int>::iterator itEnd = fmi.end();
	//????? ????? ?? ??????
	while (it != fmi.end()) 
	{
		std::cout << *it << std::endl;
		it++;
	}
	//????? ????? 
	for (std::vector<int>::iterator it = fmi.begin(); it != fmi.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	// vector insert
	fmi.insert(fmi.begin() + 3, 26);

	for (std::vector<int>::reverse_iterator it = fmi.rbegin(); it != fmi.rend(); it++)
	{
		//std::cout<<*(it-1)<<std::endl;
		std::cout << *it << std::endl;
	}

	//?????????? ????????? 
	for (std::vector<int>::const_iterator it = fmi.cbegin(); it != fmi.cend(); it++)
	{
		std::cout << *it << std::endl;
	}

	//reverse const iterator
	for (std::vector<int>::const_reverse_iterator it = fmi.crbegin(); it != fmi.crend(); it++)
	{
		//std::cout<<*(it-1)<<std::endl;
		std::cout << *it << std::endl;
	}

	//Open fest !!!
	//???


}