// Managers.h: interface for the CManagers class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_)
#define AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"player.h"
#include "stdafx.h"

#include"People.h"
#include"Sign.h"
#include"LegendDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class Managers  
{
public:
	Managers();
	int Player;
	virtual ~Managers();
	CCard card1[52];
	void GameStart();   //游戏初始化，发牌。
	player play[4];
	void Shuffle();               //洗牌 
	bool Deal();                   //按顺序发牌
	void BubbleSort();       //降序
	void Add_BubbleSort();    //还原顺序
	void Ranking();          //排名
	void Calculate();         //计算得分
	int count;
	

};

#endif // !defined(AFX_MANAGERS_H__146340EA_9401_403F_AFAF_09AB1C0559DA__INCLUDED_)
