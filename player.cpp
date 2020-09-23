// player.cpp: implementation of the player class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Legend.h"
#include "player.h"


#ifdef _DEBUG
#undef THIS_FILE

#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

player::player()
{
	dian=0;
	Power=0;
	rank=0;
	score=0;
	num=0;

}

player::~player()
{

}
void player::Dian(){              //计算点数
	dian=0;
	int n=0;
	char temp ='0';
	while(n<=4){
		if((a[n].Number==temp))break;
		dian+=a[n].Num;
		n++;
	}
	if(dian>10.5) MessageBox(NULL,TEXT("点数已经超过10.5"),TEXT("友情提示"),MB_OK);//MessageBox(NULL,"爆了！！","OK",MB_ABORTRETRYIGNORE);
}
bool player::operator>(player a){               
	return (dian>a.dian);
}

bool player::operator>(double a){
	return (dian>a);
}

bool player::operator<(player a){   //<重载
	return (dian<a.dian);
}

bool player::operator<(double a){
	if(dian<a) return true;
	else return false;
}

bool player::operator==(player a){        //==重载
	return (dian==a.dian);
}

bool player::operator==(double a){
	return (dian==a);
}
bool player::operator>=(double a){
	return (dian>=a);
}	
void player::operator=(player c){
	for(int i=0;i<5;i++){
		a[i]=c.a[i];
	}
	dian=c.dian;
	name=c.name;
	num=c.num;
	Power=c.Power;
	rank=c.rank;
	add=c.add;
	score=c.score;
}



