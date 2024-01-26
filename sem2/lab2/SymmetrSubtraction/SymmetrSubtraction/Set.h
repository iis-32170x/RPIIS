#pragma once
#include <set>
#include <vector>

using namespace std;

namespace Algorithm {
	class Set
	{
	protected:
		set <int> arr;
	public:
		Set() {
			this->arr = {};
		}
		Set(set<int> container) {
			this->arr = container;
		}

		static set<int> subtract(Set a, Set b) {
			set<int> result;

			bool flag = true;

			for (auto i : a.getArr()) {
				for (auto j: b.getArr()) {
					if (i == j++) {
						flag = false;
						break;
					}
				}

				if (flag) {
					result.insert(i);
				}

				i++;
				flag = true;
			}

			return result;
		}

		static set<int> symmetrSubtract(Set setA, Set setB) {
			set<int> resultAB = subtract(setA, setB);
			set<int> resultBA = subtract(setB, setA);
			resultAB.insert(resultBA.begin(), resultBA.end());

			return resultAB;
		};

		static set<int> symmetrSubtractAll(vector<Set> sets) {
			set<int> result = {};
			Set temp(result);

			for (int i = 0; i < sets.size(); i++) {
				set<int> tempResult = symmetrSubtract(sets[i], result);
				result = tempResult;
			}

			return result;
		};

		set<int> getArr() {
			return this->arr;
		}
	};

	ostream& operator << (ostream& os, Set& set) {
		for (auto i : set.getArr()) {
			os << i++ << ' ';
		}

		return os;
	}
}