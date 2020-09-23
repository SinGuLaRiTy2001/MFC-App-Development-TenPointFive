// Card.cpp: implementation of the CCard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Legend.h"
#include "Card.h"

#ifdef _DEBUG
#undef THIS_FILE
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCard::CCard()
{
	Num=0;
	Number='0';
	Suit=0;
	
}

CCard::~CCard()
{

}
void CCard::operator =(CCard a){
	Num=a.Num;
	Number=a.Number;
	Suit=a.Suit;
}

