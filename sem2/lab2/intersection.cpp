#include "intersection.h"
#include "intersection.h"
using namespace std;

bool bracketsBalance(const std::string& line) {
    std::stack<char> bracketStack;

    for (char ch : line) {
        if (ch == '{' || ch == '<') {
            bracketStack.push(ch);
        }
        else if (ch == '}' || ch == '>') {
            if (bracketStack.empty() || (ch == '}' && bracketStack.top() != '{') || (ch == '>' && bracketStack.top() != '<')) {
                return false;
            }
            else {
                bracketStack.pop();
            }
        }
    }

    return bracketStack.empty();
}

void print(const std::vector<Set>& all_sets) {
    for (const auto& set : all_sets) {
        std::cout << set.name << " set" << std::endl;

        for (const auto& subset : set.all_subsets) {
            std::cout << subset.notoriented << " subset: ";

            for (const auto& element : subset.all_elements) {
                std::cout << element << " ";
            }

            std::cout << std::endl;
        }
    }
}

void elementsOfSubset(const std::string& ss, std::stack<char>& check, SubSet& SUBSET) {
    for (size_t j = 0; j < ss.size(); j++) {
        size_t posInside = j;
        if (ss[j] == '<' || ss[j] == '{') {
            check.push(ss[j]);
            while (!check.empty() && posInside < ss.size()) {
                posInside++;
                if (ss[posInside] == '<' || ss[posInside] == '{') {
                    check.push(ss[posInside]);
                }
                if ((ss[posInside] == '>' && check.top() == '<') || (ss[posInside] == '}' && check.top() == '{')) {
                    check.pop();
                }
            }
            if ((j - posInside) > 1) {
                SUBSET.all_elements.push_back(ss.substr(j, posInside - j + 1));
            }
            else {
                SUBSET.all_elements.push_back(ss.substr(j, 2));
            }

            j = posInside;
        }
        if ((ss[j] != ',' && ss[j] != '{' && ss[j] != '<' && ss[j] != '>' && ss[j] != '}') && posInside < ss.size()) {
            while (ss[posInside] != ',' && posInside < ss.size()) {
                posInside++;
            }
            SUBSET.all_elements.push_back(ss.substr(j, posInside - j));
            j = posInside;
        }
    }
}

void processSubsets(const std::string& line, size_t& i, Set& SET) {
    for (i; i < line.size(); i++) {
        std::stack<char> check;
        if (line[i] == '{') {
            SubSet SUBSET;

            size_t startPos = i;
            check.push(line[i]);
            size_t pos = startPos;
            while (!check.empty() && pos < line.size()) {
                pos++;
                if (line[pos] == '{') {
                    check.push(line[pos]);
                }
                if (line[pos] == '}' && check.top() == '{') {
                    check.pop();
                }
            }

            if ((pos - startPos) == 1) {
                SUBSET.notoriented = 0;
                std::string ss = line.substr(startPos, 2);

                SUBSET.all_elements.push_back(ss);
            }
            else {
                SUBSET.notoriented = 1;
                std::string ss = line.substr(startPos + 1, pos - startPos - 1);

                elementsOfSubset(ss, check, SUBSET);
            }

            SET.all_subsets.push_back(SUBSET);

            i = pos++;
        }
        else if (line[i] != ','){
            size_t posInside = i;
            if (line[i] == '<') {
                SubSet SUBSET;
                check.push(line[i]);
                while (!check.empty() && posInside < line.size()) {
                    posInside++;
                    if (line[posInside] == '<') {
                        check.push(line[posInside]);
                    }
                    if (line[posInside] == '>' && check.top() == '<') {
                        check.pop();
                    }
                }
                if ((i - posInside) > 0)  {
                    SUBSET.all_elements.push_back(line.substr(i, posInside - i + 1));
                }
                else {
                    SUBSET.all_elements.push_back(line.substr(i, 2));
                }

                SET.all_subsets.push_back(SUBSET);
                i = posInside;
            }
            else
            {
                SubSet SUBSET;
                while (line[posInside] != ',' && posInside < line.size()) {
                    posInside++;
                }
                SUBSET.all_elements.push_back(line.substr(i, posInside - i));
                SET.all_subsets.push_back(SUBSET);
                i = posInside;
            }
        }
    }
}

std::vector<Set> read(const std::string& filename) {
    try {
        using namespace std;

        ifstream file(filename);
        if (!file) {
            throw invalid_argument("invalid file path");
        }

        vector<Set> all_sets;

        regex patternSet(R"(^[A-Za-z0-9_,=\{\}<>]+$)");

        string line;

        while (getline(file, line)) {
            size_t first_non_space = line.find_first_not_of(' ');
            size_t last_non_space = line.find_last_not_of(' ');
            line = line.substr(first_non_space, last_non_space - first_non_space + 1);

            if (!line.empty()) {
                Set SET;
                if (!regex_match(line, patternSet)) {
                    throw invalid_argument("invalid input: unresolved characters.");
                }

                size_t equalSignPos = line.find('=');
                SET.name = line.substr(0, equalSignPos);

                line.erase(0, equalSignPos + 1);

                if (line[0] == '<' && line[line.size() - 1] == '>') {
                    throw invalid_argument("invalid input: set must be undirected.");
                }
                else if (!(line[0] == '{' && line[line.size() - 1] == '}')) {
                    throw invalid_argument("invalid input: incorrect set brackets.");
                }

                line.erase(0, 1);
                line.erase(line.size() - 1, 1);

                if (!bracketsBalance(line)) {
                    throw invalid_argument("invalid input: incorrect subset brackets.");
                }

                size_t i = 0;

                processSubsets(line, i, SET);

                all_sets.push_back(SET);
            }
        }
        file.close();
        return all_sets;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        throw e;
    }
}

Set intersectionCalc(Set temp_result, Set set1, Set set2) {

    for (size_t i = 0; i < set1.all_subsets.size(); i++) {
        for (size_t j = 0; j < set2.all_subsets.size(); j++) {
            if ((set1.all_subsets[i].notoriented == 1 && set2.all_subsets[j].notoriented == 1) && (set1.all_subsets[i].all_elements.size() == set2.all_subsets[j].all_elements.size())) {
                
                size_t elements_count = 0;
                std::vector<std::string>temp_elements = set2.all_subsets[j].all_elements;

                for (size_t k = 0; k < set1.all_subsets[i].all_elements.size(); k++) {
                    for (size_t n = 0; n < temp_elements.size(); n++) {
                        if (set1.all_subsets[i].all_elements[k] == temp_elements[n]) {
                            elements_count++;
                            temp_elements[n] = " ";
                        }
                        if (elements_count == set1.all_subsets[i].all_elements.size()) {
                            temp_result.all_subsets.push_back(set1.all_subsets[i]);
                            break;
                        }
                    }
                }
            }
            else if (set1.all_subsets[i].notoriented != 1 && set2.all_subsets[j].notoriented != 1) {
                if (set1.all_subsets[i].all_elements[0] == set2.all_subsets[j].all_elements[0]) {
                    temp_result.all_subsets.push_back(set1.all_subsets[i]);
                    break;
                }
            }
        }
    }

    return (temp_result);
}

std::vector<std::string> intersection(const std::string& filename){
    std::vector<Set> sets = read(filename);
    
    Set temp_result;
    temp_result.name = "RESULT";

    for (size_t i = 0; i + 1 < sets.size(); i++) {
        sets[i+1] = intersectionCalc(temp_result, sets[i], sets[i+1]);
        temp_result = {};
    }

    std::vector<std::string> result;

    for (size_t i = 0; i < sets[sets.size() - 1].all_subsets.size(); i++) {
        if (sets[sets.size() - 1].all_subsets[i].notoriented == 1) {
            string ss = "{";
            for (size_t j = 0; j < sets[sets.size() - 1].all_subsets[i].all_elements.size(); j++) {
                ss += (sets[sets.size() - 1].all_subsets[i].all_elements[j]);
            }
            ss += "}";
            result.push_back(ss);
        }
        else if (sets[sets.size() - 1].all_subsets[i].notoriented == 0) {
            result.push_back(sets[sets.size() - 1].all_subsets[i].all_elements[0]);
        }
    }


    return result;
}
