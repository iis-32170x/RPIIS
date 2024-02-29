#include "intersection.h"

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

void print(const std::vector<Set>& sets) {
    for (const auto& set : sets) {
        std::cout << set.name << " set " << set.oriented << std::endl;

        for (const auto& subset : set.subsets) {
            
            std::cout << subset << " ";

        }

        std::cout << std::endl;
    }
}

void processSubsets(const std::string& line, size_t& i, Set& SET) {
    std::stack<char> check;
    for (size_t j = 0; j < line.size(); j++) {
        size_t posInside = j;
        if (line[j] == '<' || line[j] == '{') {
            check.push(line[j]);
            while (!check.empty() && posInside < line.size()) {
                posInside++;
                if (line[posInside] == '<' || line[posInside] == '{') {
                    check.push(line[posInside]);
                }
                if ((line[posInside] == '>' && check.top() == '<') || (line[posInside] == '}' && check.top() == '{')) {
                    check.pop();
                }
            }
            if ((j - posInside) > 0) {
                SET.subsets.push_back(line.substr(j, posInside - j + 1));
            }
            else {
                SET.subsets.push_back(line.substr(j, 2));
            }

            j = posInside;
        }
        if ((line[j] != ',' && line[j] != '{' && line[j] != '<' && line[j] != '>' && line[j] != '}') && posInside < line .size()) {
            while (line[posInside] != ',' && posInside < line .size()) {
                posInside++;
            }
            SET.subsets.push_back(line.substr(j, posInside - j));
            j = posInside;
        }
    }
}

std::vector<Set> read(const std::string& filename) {
    try {
        using namespace std;

        ifstream file(filename);
        if (!file) {
            throw invalid_argument("Invalid file path");
        }

        vector<Set> sets;

        regex patternSet(R"(^[A-Za-z0-9_,=\{\}<>]+$)");

        string line;

        while (getline(file, line)) {
            size_t first_non_space = line.find_first_not_of(' ');
            size_t last_non_space = line.find_last_not_of(' ');
            line = line.substr(first_non_space, last_non_space - first_non_space + 1);

            if (!line.empty()) {
                
                if (!bracketsBalance(line)) {
                    throw invalid_argument("Invalid input: incorrect set brackets.");
                }

                if (!regex_match(line, patternSet)) {
                    throw invalid_argument("Invalid input: unresolved characters.");
                }

                Set SET;

                size_t equalSignPos = line.find('=');
                SET.name = line.substr(0, equalSignPos);

                line.erase(0, equalSignPos + 1);


                if (line[0] == '<' && line[line.size() - 1] == '>') {
                    throw invalid_argument("Invalid input: set must be undirected.");
                }
                else if (!(line[0] == '{' && line[line.size() - 1] == '}')) {
                    throw invalid_argument("Invalid input: incorrect set brackets.");
                }

                line.erase(0, 1);
                line.erase(line.size() - 1, 1);

                size_t i = 0;

                processSubsets(line, i, SET);

                sets.push_back(SET);
            }
        }
        // FUNCTION PRINT ALL SETS
        // print(sets);

        file.close();

        return sets;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Exception! " << e.what() << std::endl;
        throw;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception! " << e.what() << std::endl;
        throw;
    }
}

void intersectionCalc(std::vector<std::string>& result, Set set1, Set set2) {
    result.clear();
    for (size_t i = 0; i < set1.subsets.size(); i++) {
        for (size_t j = 0; j < set2.subsets.size(); j++) {
            if (set1.subsets[i] == set2.subsets[j]) {
                result.push_back(set1.subsets[i]);
                break;
            }
        }
    }
}

std::vector<std::string> intersection(const std::string& filename){
    
    std::vector<Set> sets = read(filename);
    
    std::vector<std::string> result;

    for (size_t i = 0; i + 1 < sets.size(); i++) {
        intersectionCalc(result, sets[i], sets[i+1]);
        sets[i+1].subsets = result;
    }

    return result;
}

