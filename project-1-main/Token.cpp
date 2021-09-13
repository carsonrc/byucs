#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
        this->type = type;
        this->description = description;
        this->lineNumber = line;
}
std::ostream& operator<<(std::ostream& os,const Token& token) {
    std::string tokenType;
    switch (token.type) {
        case TokenType::COLON:       tokenType = "COLON";
        case TokenType::COLON_DASH:  tokenType = "COLON_DASH";
        case TokenType::END_OF_FILE: tokenType = "EOF";
        case TokenType::UNDEFINED:   tokenType = "UNDEFINED";
    }
    os << "(" << tokenType << ",\"" << token.description << "\"," << token.lineNumber << ")" << std::endl;
} ;
