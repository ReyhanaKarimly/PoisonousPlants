#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int N;
	cin >> N;
	stack<pair<int, int>>s;

	//vector<int> v(N);
	int a;
	int maxi = 0;
	int day = 0;
	cin >> a;
	s.push(make_pair(a, 0));
	for (size_t i = 1; i < N; i++)
	{
		cin >> a;
		if (!s.empty() && a< s.top().first && s.top().second == 0)
		{
			s.push(make_pair(a, 0));
		}
		else if (!s.empty() && a > s.top().first)
		{

			s.push(make_pair(a, 1));
			maxi = max(maxi, 1);
		}
		else if (!s.empty() && s.top().first >= a)
		{


			day = s.top().second + 1;
			while (!s.empty() && s.top().first >= a)
			{

				day = max(s.top().second + 1, day);
				s.pop();

			}


			if (s.empty())
			{
				s.push(make_pair(a, 0));

			}
			else
			{

				maxi = max(maxi, day);
				s.push(make_pair(a, day));


			}


		}


	}


	cout << maxi << endl;
	system("pause");

	return 0;
}

