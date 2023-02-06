#include <iostream>
#include <string>
#include <list>
#include "modules/error.h"
#include "modules/Token.h"
#include "modules/Validator.h"
#include "modules/ValidatorToExpression.h"
#include "modules/Parser.h"

using namespace std;


int main() {
    string expression = string();
    cout << "Input Expression:\t";
    getline(cin, expression);
    Parser *parser = new Parser(expression, new FormatterToExpression(), new ShuntingYardAlgorithm());
    try {
        parser->parse();
    } catch (Lexical_error &e) {
        cerr << "Error: " << e << endl;
    }
    catch (Syntax_error &e) {
        cerr << "Error: " << e << endl;
    }
    catch (Runtime_error &e) {
        cerr << "Error: " << e << endl;
    }
    cout << "Result: " << parser->gerResult() << endl;
    delete parser;
    return 0;
}
