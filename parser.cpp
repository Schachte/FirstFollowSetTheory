#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "parser.h"

using namespace std;

int main()
{

    vector<string> nonTerminals, productionRules;

    nonTerminals = parseNonTerminals();

    productionRules = parseTerminals();


    cout << "*********** PRODUCTION RULES ***********" << endl;
    for (int i = 0; i < int(productionRules.size()); i++) {


        cout << productionRules[i] << endl;
    }

    cout << "*********** NON-TERMINALS ***********" << endl;
    cout << "{";
    for (int i = 0; i < int(nonTerminals.size()); i++) {
        cout << nonTerminals[i] << ", ";
    }

    cout << "}" << endl;
    return 0;

}