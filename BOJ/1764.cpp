#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n, m;
	vector<string> a;
	cin >> n >> m;

	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	vector<string> b;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (binary_search(a.begin(), a.end(), temp))
			b.push_back(temp);
	}
	sort(b.begin(),b.end());

	cout << b.size() << endl;
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << endl;

	return 0;
}