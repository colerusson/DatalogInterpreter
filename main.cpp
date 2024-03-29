#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter .h"
#include "DatalogProgram.h"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile(argv[1]);
    string stringFile;
    stringFile.assign((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));

    vector<Token> tokens;
    Lexer lexer;

    try {
        tokens = lexer.run(stringFile);
        Parser parser = Parser(tokens);
        DatalogProgram program = parser.run();
        Interpreter interpreter = Interpreter(program);
        interpreter.run();
    }
    catch(Token errorToken) {
        cout << "Failure!" << endl << " " << errorToken.toString();
    }
    catch(const char* errorMsg) {
        cout << "Failure!" << endl << errorMsg;
    }

    return 0;
}

