#pragma once



/*
coded by UPO33

using FORIF[N] macros u can remove redundant branches inside a loop, it seems that compilers usually don't do that

take the following for instance:

const bool	cbAdd = ..;
const bool	cbSub = ..;
const bool	cbMul = ..;

for (unsigned i = 0; i < NumElement; i++)
{
	unsigned value = Elements[i];

	if (cbAdd) value += Add();
	if (cbSub) value -= Sub();
	if (cbMul) value *= Mul();

	Elements[i] = value;
}

because the conditions are constant during the loop we can make indivial loops for each state as follow:

#define BS \
		for (unsigned i = 0; i < NumElement; i++)\
		{\
			unsigned value = Elements[i];\


#define BE  Elements[i] = value;}


#define AC value += Add();
#define BC value -= Sub();
#define CC value *= Mul();

FORIF4(BS, BE, bAdd, AC, {}, bSub, BC, {}, bMul, CC, {}, false, {}, {});
*/


/*
Generator:
std::string ZZ_GetIfElse(int n, int i = 0, std::string inner = std::string(), bool isT = true)
{
	std::stringstream str;
	std::stringstream Innerstr;

	if (i == 0)
		Innerstr << "StartBody  ";
	if (i != 0)
		Innerstr << inner << (isT ? "T" : "F") << i - 1 << " ";

	if (i == n)
	{
		Innerstr << "  EndBody";
		return Innerstr.str();

	}

	str << "if(C" << i << "){\\\n" << ZZ_GetIfElse(n, i + 1, Innerstr.str(), true) << "\\\n}else{\\\n " << ZZ_GetIfElse(n, i + 1, Innerstr.str(), false) << "\\\n}";


	return str.str();
}

std::string GenFORIF(int n)
{
	return ZZ_GetIfElse(n);
}
*/


#define FORIF8(StartBody, EndBody, C0,T0,F0,   C1,T1,F1, 	C2,T2,F2,	 C3,T3,F3,  C4,T4,F4,  C5,T5,F5,   C6,T6,F6,   C7,T7, F7)\
if (C0) {\
	if (C1) {\
		if (C2) {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 T2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 T2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
		else {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 T1 F2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 T1 F2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
	}\
	else {\
		if (C2) {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 T2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 T2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
		else {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  T0 F1 F2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  T0 F1 F2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
	}\
}\
else {\
	if (C1) {\
		if (C2) {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 T2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 T2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
		else {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 T1 F2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 T1 F2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
	}\
	else {\
		if (C2) {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 T2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 T2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
		else {\
			if (C3) {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 T3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 T3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
			else {\
				if (C4) {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 T4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 T4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 T4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 T4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 T4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 T4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 T4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 T4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
				else {\
					if (C5) {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 F4 T5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 F4 T5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 F4 T5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 F4 T5 F6 F7   EndBody\
							}\
						}\
					}\
					else {\
						if (C6) {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 F4 F5 T6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 F4 F5 T6 F7   EndBody\
							}\
						}\
						else {\
							if (C7) {\
								StartBody  F0 F1 F2 F3 F4 F5 F6 T7   EndBody\
							}\
							else {\
								StartBody  F0 F1 F2 F3 F4 F5 F6 F7   EndBody\
							}\
						}\
					}\
				}\
			}\
		}\
	}\
}\

#define FORIF6(StartBody, EndBody, C0,T0,F0,   C1,T1,F1, 	C2,T2,F2,	 C3,T3,F3,  C4,T4,F4,  C5,T5,F5)\
	FORIF8(StartBody, EndBody, C0,T0,F0,   C1,T1,F1, 	C2,T2,F2,	 C3,T3,F3,  C4,T4,F4,  C5,T5,F5, false,{},{}, false, {}, {})

#define FORIF4(StartBody, EndBody, C0,T0,F0,   C1,T1,F1, 	C2,T2,F2,	 C3,T3,F3)\
	FORIF6(StartBody, EndBody, C0,T0,F0,   C1,T1,F1, 	C2,T2,F2,	 C3,T3,F3, false,{},{}, false, {}, {})





