#include "TextInput.h"

TextInput::TextInput()
{
	this->ctrl = false;
	this->shift = false;
	this->input = "";
}



bool TextInput::manageKeyDown(SDL_Event event)
{
	std::string strKey = SDL_GetKeyName((&event.key)->keysym.sym);

	checkCtrl(strKey, event);
	checkShift(strKey, event);
	
	if (isSpace(strKey))
	{
		input +=" ";
		return true;
	}
	
	
	if (isEnter(strKey))
	{
		//if is enter, remeber the username and return from reading chars from keyboard
		return false;
	}
	
	if (isBackspace(strKey))
	{
		if (input != "")
		{
			input.pop_back();
		}
		
		return true;
	}

	if (!isValid(strKey))
	{
		return true;
	}

	if (this->input.length() < this->MAXLENGTH)
	{
		//std::cout << ">>>>> " << this->MAXLENGTH << "\n";
		if ((this->ctrl && this->shift)
			|| (!this->ctrl && !this->shift))
		{
			// ctrl + shift => tolower
			// !ctrl + !shift => tolower
			this->input += strKey;
			return true;
		}
		else if (this->ctrl)
		{
			//or ctrl is set or shift is pressed => toupper
			this->input += toupper(strKey[0]);
			return true;
		}
		else if (this->shift)
		{
			std::string numbers = "0123456789";
			std::size_t found = numbers.find(strKey);

			if (found != std::string::npos)
			{
				//shift+nuber => special char ( so we don.t want it:) )
				return true;
			}
			this->input += toupper(strKey[0]);
			return true;
		}
	}
	else
	{
		//the user introduced sth longer than usernameMaxLength charsso just 
		//do nothing
		return true;
	}

}

bool TextInput::manageKeyUp(SDL_Event event)
{
	
	std::string strKey = SDL_GetKeyName((&event.key)->keysym.sym);

	checkCtrl(strKey, event);
	checkShift(strKey, event);

	return true;
}



void TextInput::setInput(std::string input)
{
	this->input = input;
}

std::string TextInput::getInput()
{
	return this->input;
}



bool TextInput::isValid(std::string strKey)
{
	//remember the fact that strKey is a key from your keyboard ("a", "b", "1" etc)
	//or a special key such as ("caps lock") 
	//but for that spacial keys we don't have to verify nothing so we'll return false

	if (strKey.size() != 1)
	{
		//not "a" "b" ....
		return false;
	}


	std::size_t found = acceptedChars.find(strKey);
	if (found == std::string::npos)
	{
		//not one of the accepted chars
		return false;
	}
	
	return true;
}



bool TextInput::isEnter(std::string strKey)
{
	if (strcmp(strKey.c_str(), "return") == 0)
	{
		return true;
	}
	return false;
}


bool TextInput::isSpace(std::string strKey)
{
	
	if (strcmp(strKey.c_str(), "space") == 0)
	{
		return true;
	}
	return false;
}


bool TextInput::isBackspace(std::string strKey)
{
	if (strcmp(strKey.c_str(), "backspace") == 0)
	{
		return true;
	}
	return false;
}

void TextInput::checkCtrl(std::string strKey,SDL_Event event)
{
	if (strcmp(strKey.c_str(), "caps lock") == 0)
	{
		if (event.type == SDL_KEYDOWN)
		{
			//1st press=>toUpper letters
			this->ctrl = true;
		}
		else if (event.type == SDL_KEYUP)
		{
			this->ctrl = false;
		}
	}

}

void TextInput::checkShift(std::string strKey, SDL_Event event)
{
	std::size_t found = strKey.find("shift");
	if (found != std::string::npos)
	{
		if (event.type == SDL_KEYDOWN)
		{
			//"shift" found
			this->shift = true;
		}
		else if (event.type == SDL_KEYUP)
		{
			this->shift = false;
		}
	}
	
}

