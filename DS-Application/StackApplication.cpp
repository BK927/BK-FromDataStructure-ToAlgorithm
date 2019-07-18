#include "StackApplication.h"

void algorithm::StackApplication::CheckMatching(const char* filename)
{
	cout << '[' << filename << ']' << ": 파일 괄호 오류 검사" << endl;
	ifstream ifs(filename);

	if (!ifs.is_open())
	{
		cout << "파일을 여는데 실패했습니다." << endl;
		return;
	}

	bkDS::Stack<char> stack;
	unsigned int nLine = 0;
	unsigned int nChar = 0;

	while (!ifs.eof())
	{
		char c = ifs.get();
		//new line check
		if (c == '\n')
		{
			nLine++;
			continue;
		}
		else
		{
			nChar++;
		}

		//single quotation marks check
		if (c == '\'')
		{
			c = ifs.get();
			while (!(c == '\''))
			{
				if (ifs.eof())
				{
					CheckMatchingErrMsg(nLine, nChar, eCheckMatchingError::Missing_Single_Quotation_Mark);
					ifs.close();
					return;
				}

				if (c == '\n')
				{
					nLine++;
				}
				else
				{
					nChar++;
				}
				c = ifs.get();
			}
			nChar++;
			continue;
		}

		//double quotation marks check
		if (c == '\"')
		{
			c = ifs.get();
			while (!(c == '\"'))
			{
				if (ifs.eof())
				{
					CheckMatchingErrMsg(nLine, nChar, eCheckMatchingError::Missing_Double_Quotation_Mark);
					ifs.close();
					return;
				}

				if (c == '\n')
				{
					nLine++;
				}
				else
				{
					nChar++;
				}
				c = ifs.get();
			}
			nChar++;
			continue;
		}

		//Comment
		if (c == '/')
		{
			c = ifs.get();
			if (c == '\n')
			{
				nLine++;
				continue;
			}
			else
			{
				nChar++;
			}

			if (c == '/')
			{
				while (!(c == '\n'))
				{
					c = ifs.get();
					if (ifs.eof())
					{
						ifs.close();
						return;
					}
					nChar++;
				}
				continue;
			}

			if (c == '*')
			{
				while (true)
				{
					c = ifs.get();
					if (ifs.eof())
					{
						ifs.close();
						return;
					}
					nChar++;
					if (c == '*')
					{
						c = ifs.get();
						if (ifs.eof())
						{
							ifs.close();
							return;
						}
						nChar++;
						if (c == '/')
						{
							break;
						}
					}
				}
				continue;
			}
		}
		
		//bracket check
		switch (c)
		{
		case '[':
			stack.Push(c);
			break;

		case '{':
			stack.Push(c);
			break;

		case '(':
			stack.Push(c);
			break;

		default:
			break;
		}

		switch (c)
		{
		case ']':
			if (stack.IsEmpty() || !(stack.Peek() == '['))
			{
				CheckMatchingErrMsg(nLine, nChar, eCheckMatchingError::Missing_Bracket);
				ifs.close();
				return;
			}
			else
			{
				stack.Pop();
			}
			break;

		case '}':
			if (stack.IsEmpty() || !(stack.Peek() == '{'))
			{
				CheckMatchingErrMsg(nLine, nChar, eCheckMatchingError::Missing_Bracket);
				ifs.close();
				return;
			}
			else
			{
				stack.Pop();
			}
			break;

		case ')':
			if (stack.IsEmpty() || !(stack.Peek() == '('))
			{
				CheckMatchingErrMsg(nLine, nChar, eCheckMatchingError::Missing_Bracket);
				ifs.close();
				return;
			}
			else
			{
				stack.Pop();
			}
			break;

		default:
			break;
		}
	}

	cout << "오류 미검출" << endl << endl;
	ifs.close();
}

void algorithm::StackApplication::CheckMatchingErrMsg(const unsigned int nLine, const unsigned int nChar, const eCheckMatchingError err)
{
	switch (err)
	{
	case eCheckMatchingError::Missing_Bracket:
		cout << "괄호 불일치 발생." << endl;
		break;

	case eCheckMatchingError::Missing_Single_Quotation_Mark:
		cout << "작은 따옴표를 찾지 못했습니다." << endl;
		break;

	case eCheckMatchingError::Missing_Double_Quotation_Mark:
		cout << "큰 따옴표를 찾지 못했습니다." << endl;
		break;

	default:
		break;
	}

	cout << nLine << "번째 줄 " << nChar << "번째 글자에 오류 발생" << endl << endl;
}
