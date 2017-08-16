#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<iterator>

int main(int argc,char* argv[])
{
	std::vector<int> elements;
	int count = 0;
	
        for(int i=0;i<10;i++) elements.push_back(i);
	auto trace_lambda = [] (int i) { std::cout << i << " ";};

	for (auto &ee : elements) trace_lambda(ee);
	std::cout << std::endl;

	auto lambda_gen = [] (int i)  -> std::function<int (int)>
	{
		return [i](int n) -> int { return i + n;};
	};


	std::cout << (lambda_gen(10))(5) << std::endl;

	auto lll = lambda_gen(1000);

	std::transform(elements.begin(),elements.end(),elements.begin(),lll);
	for (auto &ee : elements) trace_lambda(ee);

        
	std::cout << std::endl;

	return 0;

}