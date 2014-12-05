/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PROTO.cpp
*
******************************************************************/

#include <cybergarage/x3d/PROTO.h>
#include <cybergarage/x3d/VRML97Fields.h>

#define FIELD_SEPARATOR_TOKENS	" \t\n"
#define MFIELD_SEPARATOR_TOKENS	" \t\n"
#define PROTO_IGONRE_TOKENS			" \t"
#define PROTO_SEPARATOR_TOKENS	"{}[]\n"

using namespace CyberX3D;

////////////////////////////////////////////////
//	Parse Functions
////////////////////////////////////////////////

static bool IsFieldAccessTypeString(char *token)
{
	if(token == NULL)
		return false;
		
	if(strcmp(token, "field") == 0)
		return true;
	if(strcmp(token, "exposedField") == 0)
		return true;
	if(strcmp(token, "eventIn") == 0)
		return true;
	if(strcmp(token, "eventOut") == 0)
		return true;
		
	return false;
}

static int GetFieldTypeFromString(char *typeString)
{
	SFBool	field;
	field.setType(typeString);
	return field.getType();
}

static bool IsTokenChar(char c, char *tokenChars)
{
	if(tokenChars == NULL)
		return false;
		
	int tokenLen = strlen(tokenChars);
	for(int n = 0; n < tokenLen; n++)
	{
		if(c == tokenChars[n])
			return true;
	}
	
	return false;
}

static bool IsTokenChar(char c)
{
	if('a' <= c && c <= 'z')
		return true;
	if('A' <= c && c <= 'Z')
		return true;
	if('0' <= c && c <= '9')
		return true;
	if('_' == c)
		return true;
	return false;
}

static char *GetFirstFieldToken(char *fieldString)
{
	return strtok(fieldString, FIELD_SEPARATOR_TOKENS);
}

static char *GetNextFieldToken()
{
	return strtok(NULL, FIELD_SEPARATOR_TOKENS);
}

static char *GetNextMFieldToken()
{
	return strtok(NULL, MFIELD_SEPARATOR_TOKENS);
}

static bool isTokenEOL(char *value)
{
	if(value == NULL)
		return false;
	if(strlen(value) != 1)
		return false;
	if(value[0] == '\n')
		return true;
	return false;
}

static char *currentStringPos = NULL;

static char *GetStringToken(
    char	*string,
    char	*ignoreToken,
    char	*separatorToken,
    char	*buffer)
{
	if(string == NULL)
		string = currentStringPos;
		
	int stringLen = (int)strlen(string);
	int tokenLen = 0;
	
	int pos = 0;
	while(pos < stringLen && IsTokenChar(string[pos], ignoreToken))
		pos++;
		
	int startPos = pos;
	
	for(; pos < stringLen; pos++)
	{
		if(IsTokenChar(string[pos], ignoreToken) == true)
			break;
		if(IsTokenChar(string[pos], separatorToken) == true)
		{
			if(tokenLen == 0)
				tokenLen = 1;
			break;
		}
		tokenLen++;
	}
	
	if(tokenLen == 0)
		return NULL;
		
	strncpy(buffer, string + startPos, tokenLen);
	buffer[tokenLen] = '\0';
	currentStringPos = string + (pos + 1);
	
	return buffer;
}

////////////////////////////////////////////////
//	PROTO
////////////////////////////////////////////////

PROTO::PROTO(char *name, char *string, char *fieldString)
{
	setName(name);
	setString(string);
	addDefaultFields(fieldString);
}

PROTO::~PROTO(void)
{
}

void PROTO::setName(char *name)
{
	mName.setValue(name);
}

char *PROTO::getName(void)
{
	return mName.getValue();
}

void PROTO::setString(char *string)
{
	mString.setValue(string);
}

char *PROTO::getString()
{
	return mString.getValue();
}

void PROTO::addDefaultField(Field *field)
{
	mDefaultFieldVector.addElement(field);
}

void PROTO::addField(Field *field)
{
	mFieldVector.addElement(field);
}

int PROTO::getNDefaultFields()
{
	return mDefaultFieldVector.size();
}

int PROTO::getNFields()
{
	return mFieldVector.size();
}

Field *PROTO::getDefaultField(int n)
{
	return (Field *)mDefaultFieldVector.elementAt(n);
}

Field *PROTO::getField(int n)
{
	return (Field *)mFieldVector.elementAt(n);
}

void PROTO::addDefaultFields(char *fieldString)
{
	deleteDefaultFields();
	addFieldValues(fieldString, 1);
}

void PROTO::addFields(char *fieldString)
{
	deleteFields();
	addFieldValues(fieldString, 0);
}

void PROTO::deleteDefaultFields(void)
{
	mDefaultFieldVector.removeAllElements();
}

void PROTO::deleteFields(void)
{
	mFieldVector.removeAllElements();
}

void PROTO::addFieldValues(
    char		*fieldString,
    int			bDefaultField)
{
	char	fieldAccessType[256];
	char	fieldTypeName[256];
	char	fieldName[256];
	
	bool	mustReadNextToken;
	
	char *token;
	String fieldToken;
	String tokenStr;
	
	token = GetFirstFieldToken(fieldString);
	
	while(token != NULL)
	{
	
		mustReadNextToken = true;
		
		if(bDefaultField)
		{
			sscanf(token, "%s", fieldAccessType);
			if(IsFieldAccessTypeString(fieldAccessType) == false)
				continue;
			/* Get field type */
			token = GetNextFieldToken();
			sscanf(token, "%s", fieldTypeName);
			token = GetNextFieldToken();
		}
		else
			fieldTypeName[0] = '\0';
			
		/* Get field name */
		sscanf(token, "%s", fieldName);
		
		int fieldType;
		if(bDefaultField)
			fieldType = GetFieldTypeFromString(fieldTypeName);
		else
			fieldType = getFieldType(fieldName);
			
		Field *field = NULL;
		
		switch(fieldType)
		{
		case fieldTypeSFString:
		{
			field = new SFString();
			token = GetNextFieldToken();
			((SFString *)field)->setValue(token);
		}
		break;
		case fieldTypeSFFloat:
		{
			field = new SFFloat();
			token = GetNextFieldToken();
			float value = (float)atof(token);
			((SFFloat *)field)->setValue(value);
		}
		break;
		case fieldTypeSFInt32:
		{
			field = new SFInt32();
			token = GetNextFieldToken();
			int value = atoi(token);
			((SFInt32 *)field)->setValue(value);
		}
		break;
		case fieldTypeSFVec2f:
		{
			field = new SFVec2f();
			float	vec2f[2];
			for(int n = 0; n < 2; n++)
			{
				token = GetNextFieldToken();
				vec2f[n] = (float)atof(token);
			}
			((SFVec2f *)field)->setValue(vec2f);
		}
		break;
		case fieldTypeSFVec3f:
		{
			field = new SFVec3f();
			float	vec3f[3];
			for(int n = 0; n < 3; n++)
			{
				token = GetNextFieldToken();
				vec3f[n] = (float)atof(token);
			}
			((SFVec3f *)field)->setValue(vec3f);
		}
		break;
		case fieldTypeSFColor:
		{
			field = new SFColor();
			float color[3];
			for(int n = 0; n < 3; n++)
			{
				token = GetNextFieldToken();
				color[n] = (float)atof(token);
			}
			((SFColor *)field)->setValue(color);
		}
		break;
		case fieldTypeSFBool:
		{
			field = new SFBool();
			token = GetNextFieldToken();
			bool btrue = !strcmp(token, "TRUE") ? true : false;
			((SFBool *)field)->setValue(btrue);
		}
		break;
		case fieldTypeSFRotation:
		{
			field = new SFRotation();
			float rot[4];
			for(int n = 0; n < 4; n++)
			{
				token = GetNextFieldToken();
				rot[n] = (float)atof(token);
			}
			((SFRotation *)field)->setValue(rot);
		}
		break;
		case fieldTypeSFTime:
		{
			field = new SFTime();
			token = GetNextFieldToken();
			double time = atof(token);
			((SFTime *)field)->setValue(time);
		}
		break;
		case fieldTypeSFNode:
		{
			field = new SFNode();
			token = GetNextFieldToken();
			//((SFNode *)field)->setValue(token);
		}
		break;
		case fieldTypeMFFloat:
		case fieldTypeMFInt32:
		case fieldTypeMFVec2f:
		case fieldTypeMFVec3f:
		case fieldTypeMFString:
		case fieldTypeMFColor:
		case fieldTypeMFTime:
		case fieldTypeMFRotation:
		case fieldTypeMFNode:
		{
			int	bigBracket = 0;
			int	smallBracket = 0;
			bool emptyField = false;
			
			fieldToken = "";
			
			token = GetNextMFieldToken();
			
			while(token != NULL)
			{
			
				if(IsFieldAccessTypeString(token) == true)
				{
					mustReadNextToken = false;
					break;
				}
				
				tokenStr = token;
				
				if(tokenStr.compareTo("[]") == 0)
				{
					fieldToken.append("[]");
					emptyField = true;
					break;
				}
				if(tokenStr.compareTo("[") == 0)
				{
					bigBracket++;
					fieldToken.append("[ ");
					break;
				}
				if(tokenStr.compareTo("{") == 0)
				{
					smallBracket++;
					fieldToken.append("{ ");
					break;
				}
				
				fieldToken.append(token);
				fieldToken.append(" ");
				
				token = GetNextMFieldToken();
			}
			
			if(emptyField == false && mustReadNextToken == true)
				token = GetNextMFieldToken();
				
			while(token != NULL && emptyField == false && mustReadNextToken == true)
			{
			
				if(IsFieldAccessTypeString(token) == true)
				{
					mustReadNextToken = false;
					break;
				}
				
				tokenStr = token;
				if(tokenStr.compareTo("]") == 0)
				{
					bigBracket--;
					if(bigBracket == 0 && smallBracket == 0)
					{
						fieldToken.append("]");
						break;
					}
				}
				
				if(tokenStr.compareTo("}") == 0)
				{
					smallBracket--;
					if(smallBracket == 0 && bigBracket == 0)
					{
						fieldToken.append("}");
						break;
					}
				}
				
				if(tokenStr.compareTo("[") == 0)
					bigBracket++;
					
				if(tokenStr.compareTo("{") == 0)
					smallBracket++;
					
				fieldToken.append(token);
				fieldToken.append(" ");
				
				token = GetNextMFieldToken();
			}
			
			if(fieldToken.length() == 0)
				fieldToken.append("[]");
				
			char *fieldValue = fieldToken.getValue();
			field = new MFString();
			((MFString *)field)->addValue(fieldValue);
			
			//cout << fieldTypeName << " " << fieldName << " " << fieldValue << endl;
		}
		break;
		}
		
		//assert(field);
		
		if(field)
		{
			field->setName(fieldName);
			if(bDefaultField)
				addDefaultField(field);
			else
				addField(field);
		}
		
		if(mustReadNextToken == true)
			token = GetNextFieldToken();
	}
	
}

void PROTO::getString(String  &returnBuffer)
{
	char tokenBuffer[512];
	
	returnBuffer.clear();
	
	char *string = getString();
	if(!string || !strlen(string))
		return;
		
	char *defaultString = new char[strlen(string)+1];
	strcpy(defaultString, string);
	
	//char *token = strtok(defaultString, PROTO_IGONRE_TOKENS);
	char *token = GetStringToken(defaultString, PROTO_IGONRE_TOKENS, PROTO_SEPARATOR_TOKENS, tokenBuffer);
	
	while(token != NULL)
	{
		if(!strcmp(token, "IS"))
		{
			//token = strtok( NULL, PROTO_IGONRE_TOKENS  );
			token = GetStringToken(NULL, PROTO_IGONRE_TOKENS, PROTO_SEPARATOR_TOKENS, tokenBuffer);
			Field *field = getField(token);
			if(field)
			{
				String fieldValue;
				field->getValue(fieldValue);
				returnBuffer.append(fieldValue.getValue());
				returnBuffer.append("\n");
			}
			else
			{
				int bufferLen = returnBuffer.length();
				for(int n = (bufferLen - 1 - 1); 0 <= n; n--)
				{
					int c = returnBuffer.charAt(n);
					if(IsTokenChar(c) == false)
						break;
				}
			}
		}
		else
		{
			returnBuffer.append(token);
			returnBuffer.append(" ");
		}
		
		//token = strtok( NULL, PROTO_IGONRE_TOKENS  );
		token = GetStringToken(NULL, PROTO_IGONRE_TOKENS, PROTO_SEPARATOR_TOKENS, tokenBuffer);
	}
	
//	cout << "==== DEFAULT STRING ====" << endl;
//	cout << defaultString << endl;
//	cout << "==== REPLACE STRING ====" << endl;
//	cout << returnBuffer.getValue() << endl;

	delete[] defaultString;
}

Field *PROTO::getField(char *name)
{
	Field	*field;
	int		n;
	
	int nField = getNFields();
	for(n = 0; n < nField; n++)
	{
		field = getField(n);
		if(!strcmp(field->getName(), name))
			return field;
	}
	
	int nDefaultField = getNDefaultFields();
	for(n = 0; n < nDefaultField; n++)
	{
		field = getDefaultField(n);
		if(!strcmp(field->getName(), name))
			return field;
	}
	
	return NULL;
}

int PROTO::getFieldType(char *name)
{
	int nDefaultField = getNDefaultFields();
	for(int n = 0; n < nDefaultField; n++)
	{
		Field *field = getDefaultField(n);
		if(!strcmp(field->getName(), name))
			return field->getType();
	}
	return fieldTypeNone;
}
