using namespace std;

// ------------------------------ Forward Declarations --------------------------

vector<string>splitByEmpty(string);
vector<string> collectNonTerminals();
void printNonTerminals(vector<string>);
bool itemExistsInVector(vector<string>, string);
bool inputContainsHash(string user_input_string);

// ------------------------------ Parser functions ------------------------------

//Boolean check to cross-reference whether or not an item exists in a currently entered vector or not
bool itemExistsInVector(vector<string> checkList, string item) {

    if (find(checkList.begin(), checkList.end(), item)!=checkList.end()) {return true;}
    else {return false;}
}

vector<string> parseNonTerminals() {

    vector<string> inputParsedWithoutSpaces, nonTerminals;

    string input_stream;

    //Read in data until you hit the first hash symbol
    getline(cin, input_stream, '#');

    inputParsedWithoutSpaces = splitByEmpty(input_stream);

    //Persist all non-terminals into their own space into a non-terminal vector
    for (int i = 0; i < int(inputParsedWithoutSpaces.size()-1); i++) {

        if (!inputParsedWithoutSpaces.empty()) {

            nonTerminals.push_back(inputParsedWithoutSpaces[i]);
        }
    }

    return nonTerminals;
}

vector<string> parseTerminals() {

    vector<string> productionRules;

    string input_stream;

    getchar();

    //while the user correct
    while (cin.peek() != -1)
    {
        if (char(cin.peek()) == '#')
        {
            getchar();

            if (char(cin.peek()) == '#') {
                break;
            }

                productionRules.push_back(input_stream);
                input_stream = "";
        }

        char currentChar = getchar();
        if (currentChar != '\n')
        input_stream += currentChar;
    }

    return productionRules;
}

//Function designed to take in the string entered by the getLine and get rid of all the excess white space that is entered by the user
vector<string> splitByEmpty(string input_list) {

   vector<string> subtractExcessWhiteSpace;
   stringstream s(input_list);

   while(!s.eof()) {
      string tmp;
      s >> tmp;
      subtractExcessWhiteSpace.push_back(tmp);
   }

   return subtractExcessWhiteSpace;
}

//Parsing out reserved symbols to segregate the production rules that are in the list of prod rules
vector<string> eraseDoubleOctothorpe(vector<string> terminalList)
{
    for (int i = 0; i < int(terminalList.size()); i++) {
            if (terminalList[i] == "##") {
                    terminalList.erase(terminalList.begin() + i);
            }
    }
    return terminalList;
}

//Function designed to remove the duplicates that are pushed to the associated string vectors
vector<string> vectorIntersection(vector<string> removeDupesList)
{
    sort( removeDupesList.begin(), removeDupesList.end() );
    removeDupesList.erase( unique( removeDupesList.begin(), removeDupesList.end() ), removeDupesList.end() );
    return removeDupesList;
}