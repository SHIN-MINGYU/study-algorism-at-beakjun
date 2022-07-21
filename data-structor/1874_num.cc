#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n, amx;
int cnt = 0;
int seq[100001];
vector<int> stack;
vector<char> answer;

int main()
{	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i]; 

	for (int i = 1; i <= n; i++)
	{
		stack.push_back(i);
		answer.push_back('+');

		while (!stack.empty() && stack.back() == seq[cnt])
		{
			stack.pop_back();
			answer.push_back('-');
			cnt++;
		}
	}

	if (!stack.empty()) cout << "NO"; 
	else for (int i = 0; i < answer.size(); i++) cout << answer[i] << '\n';
	

}