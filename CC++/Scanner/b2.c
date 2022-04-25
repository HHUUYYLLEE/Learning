

void skipBlank() {
  while (currentChar != -1 && charCodes[currentChar] == CHAR_SPACE)
	readChar();
}


void skipComment() {
  while (1) {
    readChar();

    if (currentChar == -1) { 
      error(ERR_ENDOFCOMMENT, lineNo, colNo); 
    } else if (charCodes[currentChar] == CHAR_TIMES) { 
      readChar(); 

      if (currentChar == -1) { 
        error(ERR_ENDOFCOMMENT, lineNo, colNo); 
      } else if (charCodes[currentChar] == CHAR_RPAR) { 
        
        readChar();
        return;
      }
    }
  }
}


Token* readIdentKeyword(void) {
  int count = 0;
  Token* token = makeToken(TK_IDENT, lineNo, colNo);

  while (charCodes[currentChar] == CHAR_LETTER || charCodes[currentChar] == CHAR_DIGIT) {
    token->string[count] = currentChar;

    count++;
    readChar();
  }
  token->string[count] = '\0';

  if (count > MAX_IDENT_LEN) {
    error(ERR_IDENTTOOLONG, lineNo, colNo - count);
  } else {
    TokenType type = checkKeyword(token->string);
    if (type != TK_NONE) {
      token->tokenType = type;
    }
  }

  return token;
}


Token* readNumber(void) {
  int count = 0;
  Token* token = makeToken(TK_NUMBER, lineNo, colNo);

  while (charCodes[currentChar] == CHAR_DIGIT) {
	if (count > 9) {
		error(ERR_NUMBERTOOLONG, token->lineNo, token->colNo);
	}

    token->string[count] = currentChar;

    count++;

    readChar();
  }

  token->string[count] = '\0';

  token->value = atoi(token->string);

  return token;
}

Token* readConstChar(void) {
  Token* token = makeToken(TK_CHAR, lineNo, colNo);

  readChar();

  if (currentChar == -1) { // End of File
    error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
  } else {
	switch(charCodes[currentChar]) {
	case CHAR_SINGLEQUOTE:
		readChar();

		if (charCodes[currentChar] == CHAR_SINGLEQUOTE) {
		    token->string[0] = currentChar;

		    readChar();
		    if (charCodes[currentChar] == CHAR_SINGLEQUOTE) {
		        token->string[1] = '\0';

		        readChar();
		        return token;
		    } else {
		        error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
		    }

		} else {
			error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
		}
		break;
	default:
	   
        token->string[0] = currentChar;

		readChar();

		switch(charCodes[currentChar]) {
		case CHAR_SINGLEQUOTE:
			
			token->string[1] = '\0';

			readChar();
			return token;
		default:
			error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
			break;
		}
		break;
	}

  }
  return token;
}


Token* getToken(void) {
  Token *token;
//   int ln, cn;

  if (currentChar == EOF)
    return makeToken(TK_EOF, lineNo, colNo);

  switch (charCodes[currentChar]) {
  case CHAR_SPACE: skipBlank(); return getToken();
  case CHAR_LETTER: return readIdentKeyword();
  case CHAR_DIGIT: return readNumber();
  case CHAR_PLUS:
    // Token Plus
    token = makeToken(SB_PLUS, lineNo, colNo);
    readChar();
    return token;
  case CHAR_MINUS:
    // Token Minus
    token = makeToken(SB_MINUS, lineNo, colNo);
    readChar();
    return token;
  case CHAR_TIMES:
    // Token Times
    token = makeToken(SB_TIMES, lineNo, colNo);
    readChar();
    return token;
  case CHAR_SLASH:
    // Token Slash
    token = makeToken(SB_SLASH, lineNo, colNo);
    readChar();
    return token;
  case CHAR_EQ:
    // Token Equal
    token = makeToken(SB_EQ, lineNo, colNo);
    readChar();
    return token;
  case CHAR_COMMA:
    // Token Comma
    token = makeToken(SB_COMMA, lineNo, colNo);
    readChar();
    return token;
  case CHAR_SEMICOLON:
    // Token Semicolon
    token = makeToken(SB_SEMICOLON, lineNo, colNo);
    readChar();
    return token;
  case CHAR_RPAR:
    // Token Right Parenthesis
    token = makeToken(SB_RPAR, lineNo, colNo);
    readChar();
    return token;
  case CHAR_LPAR:
    // Empty token
    token = makeToken(TK_NONE, lineNo, colNo);
    // Get next character first
    readChar();

    switch(charCodes[currentChar]) {
    case CHAR_PERIOD:
      // This is token LSEL
      token->tokenType = SB_LSEL;
      readChar();
      return token;
    case CHAR_TIMES:
      // This is a comment so free the allocated token first then skip comments
      free(token);
      skipComment();
      return getToken();
    case CHAR_SPACE:
      readChar();
      return getToken();
    default:
      // Token Left Parenthesis
      token->tokenType = SB_LPAR;
//       readChar();
      return token;
    }
  case CHAR_GT:
    // Token Greater
    token = makeToken(SB_GT, lineNo, colNo);

    // If next character is '='
    readChar();
    if (charCodes[currentChar] == CHAR_EQ) {
      // Token is Greater Than
      token->tokenType = SB_GE;
      readChar();
    }
    return token;
  case CHAR_LT:
    // Empty token
    token = makeToken(TK_NONE, lineNo, colNo);

    // Check next character
    readChar();
    switch(charCodes[currentChar]) {
    case CHAR_EQ:
      // Token Lest Than or Equal
      token->tokenType = SB_LE;
      readChar();
      return token;
    default:
      // Token Lest Than
      token->tokenType = SB_LT;
      return token;
    }
  case CHAR_EXCLAIMATION:
    // Make empty token
    token = makeToken(TK_NONE, lineNo, colNo);

    // If next character is not '='
    readChar();
    if (charCodes[currentChar] != CHAR_EQ) {
      // it is an invalid token
      error(ERR_INVALIDSYMBOL, token->lineNo, token->colNo);
    } else {
      // else, it's token Not Equal
      token->tokenType = SB_NEQ;
    }
    return token;
  case CHAR_PERIOD:
    // Token Period
    token = makeToken(SB_PERIOD, lineNo, colNo);

    // If next character is Right Parenthesis
    readChar();
    if (charCodes[currentChar] == CHAR_RPAR) {
      // it is token Right Parenthesis
      token->tokenType = SB_RSEL;
      readChar();
    }
    return token;
  case CHAR_COLON:
    // Token Semicolon
    token = makeToken(SB_SEMICOLON, lineNo, colNo);

    // If next character is Equal
    readChar();
    if (charCodes[currentChar] == CHAR_EQ) {
      // it is token Assignment
      token->tokenType = SB_ASSIGN;
      readChar();
    }
    return token;
  case CHAR_SINGLEQUOTE:
    return readConstChar();
  default:
    token = makeToken(TK_NONE, lineNo, colNo);
    error(ERR_INVALIDSYMBOL, lineNo, colNo);
    readChar();
    return token;
  }
}

