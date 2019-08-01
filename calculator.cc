#include <bits/stdc++.h>

std::unordered_map<char, std::function<int(int,int)>> ops = {
	{'+', std::plus<int>()},
	{'-', std::minus<int>()},
	{'*', std::multiplies<int>()},
	{'/', std::divides<int>()}
};

int reduce(const std::string& s, int& n);

int eval(const std::string& s, int& parentheses)
{
	if(s.empty())
		return 0;

	int lhs = reduce(s, parentheses);

	int p = 0;
	int _n = parentheses;
	while(_n != 0)
	{
		p = s.find(')', p) + 2;
		--_n;
	}
	if(p == s.size() + 1)
		return lhs;

	if(lhs < 0)
		++p;

	p = s.find_first_of("+-*/", p);
	char op = s[p];

	int rhs_parentheses = 0;

	int rhs = reduce(s.substr(p + 2), rhs_parentheses);
	int r = ops[op](lhs,rhs);
	parentheses += rhs_parentheses;

	return r;
}

int reduce(const std::string& s, int &n)
{
	int r;
	bool minus = s[0] == '-';
	int offset = minus ? 2 : 0;
	if(s[offset] == '(')
	{
		r = eval(s.substr(offset + 2), n);
		++n;
	}
	else if(s[offset] == '-')
		r = eval(s.substr(offset), n);
	else
		r = s[offset] - '0';
		
	return minus ? -r : r;
}

// "3 + ( 3 + 1 )"
// "( ( 3 + 2 ) + 1 )"
// ( ( ( 3 + ( 2 + 1 ) ) + ( 2 + 1 ) ) + 3 ) + 2)

int main()
{
	// const std::string s = "- ( - 3 + ( 2 - 1 ) )";
	const std::string s = "( ( ( 3 + ( 2 + 1 ) ) + ( 2 + 1 ) ) + 3 ) + 2)";
	// const std::string ss = "- ( ( 3 + ( 2 - 1 ) ) + ( 2 - 1 ) )";

	int n = 0;
	std::cout << eval(s,n) << std::endl;
}