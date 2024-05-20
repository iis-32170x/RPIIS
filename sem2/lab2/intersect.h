#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> get_f_file(vector<string> empt, string path)
{
	ifstream in_file;
	string oneline;
	in_file.open(path);

	if (!in_file.is_open())
	{
		cout << "Error occured, while opening file." << endl;
		exit(-1);
	}
	else
	{
		cout << "File is opened." << endl;

		while (getline(in_file, oneline))
		{
			empt.push_back(oneline);
		}
	}

	in_file.close();

	return empt;
}

bool are_equal(string a1, string b2)
{
	return b2 == a1;
}

string clean_kratn(string init)
{
	int k = 0;

	bool chk = false, is_cort = false;

	vector<string> temp_vec;

	string temp_str, str, res_str;

	for (int i = 0; i < init.length(); i++)
	{

		if (k >= 2 || (k == 1 && (init[i] == '{' || init[i] == '<')))
		{
			temp_str += init[i];
		}

		if (((init[i] == '{' || init[i] == '<') && k == 0) || (k == 1 && init[i] != '{' && init[i] != '<'))
		{
			str.push_back(init[i]);
		}

		if (k == 2 && (init[i] == '}' || init[i] == '>'))
		{
			temp_str = clean_kratn(temp_str);
			str += temp_str;
			temp_str.clear();
		}
		if (init[i] == '{' || init[i] == '<')
		{
			k++;
		}
		if (init[i] == '}' || init[i] == '>')
		{
			k--;
		}
	}

	k = 0;
	temp_str.clear();

	if (str[0] == '{')
	{
		res_str.push_back('{');
	}
	else
	{
		res_str.push_back('<');
		is_cort = true;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (k > 0)
		{
			if (k == 1 && str[i] != ',' && str[i] != ' ' && str[i] != '}' && str[i] != '>')
			{
				temp_str += str[i];
			}
			if (k >= 2)
			{
				temp_str += str[i];
			}
			if ((str[i] == ',' && k == 1 && temp_str != "") || ((str[i] == '}' || str[i] == '>') && k == 1 && temp_str != ""))
			{
				if (!is_cort)
				{
					for (int j = 0; j < temp_vec.size(); j++)
					{
						if (are_equal(temp_vec[j], temp_str))
						{
							chk = true;
						}
					}
				}
				if (!chk)
				{
					temp_vec.push_back(temp_str);
				}
				temp_str.clear();
				chk = false;
			}
		}
		if (str[i] == '{' || str[i] == '<')
		{
			k++;
		}
		if (str[i] == '}' || str[i] == '>')
		{
			k--;
		}
	}

	string mmm;

	if(!is_cort)
	{
		for (int i = 0; i < temp_vec.size() - 1; i++)
		{
			for (int j = 1; j < temp_vec.size(); j++)
			{
				if (temp_vec[i] > temp_vec[j])
				{
					mmm = temp_vec[i];
					temp_vec[i] = temp_vec[j];
					temp_vec[j] = mmm;
				}
			}
		}
	}

	for (int i = 0; i < temp_vec.size(); i++)
	{
		res_str += temp_vec[i];
		if (i < temp_vec.size() - 1)
		{
			res_str.push_back(',');
		}
	}
	if (str[0] == '{')
	{
		res_str.push_back('}');
	}
	else
	{
		res_str.push_back('>');
	}
	return res_str;
}

vector<vector<string>> divide_on_elements(vector<string> init)
{
	vector<vector<string>> reworked;
	vector<string> temp_vec;

	string temp_str;


	int k = 0;

	for (int i = 0; i < init.size(); i++)
	{
		for (int j = 0; j < init[i].length(); j++)
		{
			if (k > 0)
			{
				if (k == 1 && init[i][j] != ',' && init[i][j] != ' ' && init[i][j] != '}')
				{
					temp_str += init[i][j];
				}
				if (k >= 2)
				{
					temp_str += init[i][j];
				}
				if ((init[i][j] == ',' && k == 1 && temp_str != "") || (init[i][j] == '}' && k == 1 && temp_str != ""))
				{
					temp_vec.push_back(temp_str);
					temp_str.clear();
				}
			}
			if (init[i][j] == '{' || init[i][j] == '<')
			{
				k++;
			}
			if (init[i][j] == '}' || init[i][j] == '>')
			{
				k--;
			}
		}
		reworked.push_back(temp_vec);
		temp_vec.clear();
		temp_str.clear();
		k = 0;
	}

	return reworked;
}

vector<string> intersect(vector<vector<string>> init)
{
	vector<string> t_vector = init[0];
	vector<string> res;

	int temp = 0, chk = 0;

	for (int k = 0; k < t_vector.size(); k++)
	{

		for (int i = 1; i < init.size(); i++)
		{
			for (int j = 0; j < init[i].size(); j++)
			{
				if (are_equal(t_vector[k], init[i][j]) && temp < i)
				{
					temp++;
				}
			}
		}

		if (temp == init.size() - 1)
		{
			for (int y = 0; y < res.size(); y++)
			{
				if (t_vector[k] == res[y])
				{
					chk++;
				}
			}

			if (!chk)
			{
				res.push_back(t_vector[k]);
			}
			else
			{
				chk = 0;
			}
		}

		temp = 0;
	}
	return res;
}
