#include "intersect.h"

using namespace std;

int main()
{
	vector<string> sets, final_res;
	vector<vector<string>> sets_n_elem;

	string pathway;

	int k = 0;

	cout << "Input path to .txt file (for e.g. D:\\Work\\list.txt): " << endl;
	cin >> pathway;
	pathway = "NEW2.txt";

	sets = get_f_file(sets, pathway);

	cout << endl;


	for (int i = 0; i < sets.size(); i++)
	{
		for (int j = 0; j < sets[i].length(); j++)
		{
			if (sets[i][j] == '{' || sets[i][j] == '<')
			{
				++k;
			}
			if (sets[i][j] == '}' || sets[i][j] == '>')
			{
				--k;
			}
		}

		if (k)
		{
			cout << "ERROR. SET No." << i + 1 << " IS INCORRECT. (Check for amount of \"{\"\"}\")" << endl;
			exit(-1);
		}
		sets[i] = clean_kratn(sets[i]);
	}

	sets_n_elem = divide_on_elements(sets);

	for (int i = 0; i < sets_n_elem.size(); i++)
	{
		cout << "Set " << i + 1 << ": {";

		for (int j = 0; j < sets_n_elem[i].size(); j++)
		{
			cout << sets_n_elem[i][j];

			if (j < sets_n_elem[i].size() - 1)
			{
				cout << ",";
			}
		}

		cout << "}" << endl << endl;
	}

	final_res = intersect(sets_n_elem);

	cout << "Final set: {";
	for (int i = 0; i < final_res.size(); i++)
	{
		cout << final_res[i];
		if(i < final_res.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "}";
}