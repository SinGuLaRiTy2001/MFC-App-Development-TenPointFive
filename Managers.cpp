// Managers.cpp: implementation of the CManagers class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Legend.h"
#include "Managers.h"
#include "player.h"
#include"People.h"
#include"Sign.h"
#ifdef _DEBUG
#undef THIS_FILE

#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Managers::Managers()
{
	count=0;
	int i,temp;
	int suit1;
	suit1=1;
    for(i=0;i<52;i++)                //生成52张牌 
    {
        if(i%13==0)
            suit1++;                //改变花色 
        card1[i].Suit=suit1;           //保存花色 
        temp=i%13;
        if(temp==0)
            card1[i].Number='A';
        else if(temp==9)
            card1[i].Number='T';
        else if(temp==10)
            card1[i].Number='J';
        else if(temp==11)
            card1[i].Number='Q';
        else if(temp==12)
            card1[i].Number='K';
        else 
            card1[i].Number=temp+'1';//以上没有问题
        if(temp>=9)                      //牌点
            card1[i].Num=0.5;
        else
            card1[i].Num=temp+1.0;
    }

	for(i=0;i<4;i++)
		play[i].add=i;
	Player=0;

}

Managers::~Managers()
{

}



//////////////////////////////////////////////////////////////////////
// Managers Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void Managers::GameStart(){
//	if(ready)
//	{
	Shuffle();
//	Deal();
//	RankShow();

//	}
}

void Managers::Shuffle()               //洗牌
{ 
    int i,j;
    CCard tempcard;
    srand(time(NULL));
    for(i=0;i<52;i++)
    {
        j=rand()%52;              
        tempcard=card1[j];
        card1[j]=card1[i];
        card1[i]=tempcard;        //两两交换卡牌，执行52次，相当于洗牌
    }
}
bool Managers::Deal(){              //按顺序发牌 
	int i,j;
	      //若52张牌没发完就一直发牌
		CSign sign;
		sign.DoModal();           //弹出对话框
		play[0].num=sign.Num;
		j=(count+play[0].num);
		if(j<=52){  //判断一个人要的牌张数超过了剩下的牌张数
			for(i=0;i<play[0].num;i++){
				j=i+count;
				play[0].a[i]=card1[j];
			}
			count=count+play[0].num;
			for(;i<5;i++){
				play[0].a[i].Num =0;
				play[0].a[i].Number='0';
				play[0].a[i].Suit=0;
			}
			play[0].Dian();
		}
		else {
			MessageBox(NULL,TEXT("牌不够啦，游戏结束了！"),TEXT("HALF PAST TEN"),MB_OK);//MessageBox("牌不够啦，游戏结束了！");
			//MessageBox(NULL,"牌不够啦，游戏结束了！","OK",MB_ABORTRETRYIGNORE);              //牌不够，游戏结束
			int flag=MessageBox(NULL,TEXT("是否再来一局"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
			if(flag==IDOK){
				count=0;
				return 1;
				//DoPreparePrinting(pInfo);
			}//此处添加是否重来一局
			else return 0;
		}
		sign.DoModal();           //弹出对话框
		play[1].num=sign.Num;
		j=(count+play[1].num);
		if(j<=52){
			for(i=0;i<play[1].num;i++){
				j=i+count;
				play[1].a[i]=card1[j];
			}
			count=count+play[1].num;
			for(;i<5;i++){
				play[1].a[i].Num =0;
				play[1].a[i].Number='0';
				play[1].a[i].Suit=0;
			}
			play[1].Dian();

		}
		else {
			MessageBox(NULL,TEXT("牌不够啦，游戏结束了！"),TEXT("HALF PAST TEN"),MB_OK);
		//MessageBox(NULL,"牌不够啦，游戏结束了！","OK",MB_ABORTRETRYIGNORE);             //牌不够，游戏结束;
			int flag=MessageBox(NULL,TEXT("是否再来一局"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
			if(flag==IDOK){
				count=0;
				return 1;
				//DoPreparePrinting(pInfo);
			}
			//此处添加是否重来一局
			else return 0;
		}

		if(Player>=3){ 		
			sign.DoModal();           //弹出对话框
			play[2].num=sign.Num;
			j=(count+play[2].num);
			if(j<=52){
				for(i=0;i<play[2].num;i++){
					j=i+count;
					play[2].a[i]=card1[j];
				}
				count=count+play[2].num;
				for(;i<5;i++){
					play[2].a[i].Num =0;
					play[2].a[i].Number='0';
					play[2].a[i].Suit=0;
				}
				play[2].Dian();

			}
			else {
				MessageBox(NULL,TEXT("牌不够啦，游戏结束了！"),TEXT("HALF PAST TEN"),MB_OK);
				//MessageBox(NULL,"牌不够啦，游戏结束了！","OK",MB_ABORTRETRYIGNORE);              //牌不够，游戏结束
				int flag=MessageBox(NULL,TEXT("是否再来一局"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//此处添加是否重来一局
				else return 0;
			}
		}

		if(Player>=4){            
			CSign dlg;                          //弹出对话框
			dlg.DoModal();
			play[3].num=dlg.Num;
			j=(count+play[3].num);
			if(j<=52){
				for(i=0;i<play[3].num;i++){
					j=i+count;
					play[3].a[i]=card1[j];
				}
				count=count+play[3].num;
				for(;i<5;i++){
					play[3].a[i].Num=0;
					play[3].a[i].Number='0';
					play[3].a[i].Suit=0;
				}
				play[3].Dian();
			}
			else {
				MessageBox(NULL,TEXT("牌不够啦，游戏结束了！"),TEXT("HALF PAST TEN"),MB_OK);
			//MessageBox(NULL,"牌不够啦，游戏结束了！","OK",MB_ABORTRETRYIGNORE);             //牌不够，游戏结束
				int flag=MessageBox(NULL,TEXT("是否再来一局"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//此处添加是否重来一局
				else return 0;
			}
		}

		if(count==52)
		{
			MessageBox(NULL,"牌不够啦，游戏结束了！","HALF PAST TEN",MB_OK);              //牌不够，游戏结束
			int flag=MessageBox(NULL,TEXT("是否再来一局"),TEXT("HALF PAST TEN"),MB_OKCANCEL);
				if(flag==IDOK){
					count=0;
					return 1;
					//DoPreparePrinting(pInfo);
				}
				//此处添加是否重来一局
				else return 0;
		}
		Calculate();            //每一局都实时计算得分
		//MessageBox(NULL,"显示牌：","HALF PAST TEN",MB_OK); 
	//	CardShow();
	//	RankShow();
}
//降序

void Managers::BubbleSort(){                   
	bool noswap;
	int i,j;
	player temp;
	for(i=0;i<Player-1;i++){
		noswap=true;
		for(j=Player-1;j>i;j--){
			if(play[j].Power>play[j-1].Power){
				temp=play[j];
				play[j]=play[j-1];
				play[j-1]=temp;
				noswap=false;
			}
		}
		if(noswap)break;
	}
}

void Managers::Add_BubbleSort(){
	bool noswap;
	int i,j;
	player temp;
	for(i=0;i<Player-1;i++){
		noswap=true;
		for(j=Player-1;j>i;j--){
			if(play[j].add<play[j-1].add){
				temp=play[j];
				play[j]=play[j-1];
				play[j-1]=temp;
				noswap=false;
			}
		}
		if(noswap)break;
	}
}

void Managers::Ranking(){
	int rank1 = 1;	
	//输出第一名 
	play[0].rank=rank1;
	for(int i = 1;i< Player;i++){		
		if( i>=1 && play[i].Power == play[i-1].Power){
			play[i].rank=rank1;
		}
		else{
			rank1 = i+1;
			play[i].rank=rank1;
		}
	} 
}

void Managers::Calculate(){
	if(Player==2){//两个人游戏
		double aa=0,bb=0;
		if(play[1] <10.5&&play[0]<10.5 ){//两方均不足10.5
			if(play[1]  >play[0]  ) { aa =2;bb=1;}
			else if(play[1]==play[0] ) { 
				aa =0.5;
				bb =0.5;
			}
			else  {aa =1;bb=2;}
		}
		else if(play[1]>=10.5&&play[0]<10.5){
			if(play[1]==10.5){aa=3;
			bb=1;}
			else {aa=0;bb=2;}
		}
		if(play[0]>=10.5&&play[1]<10.5){
			if(play[0]==10.5) {bb=3;
			aa=1;}
			else {bb=0;aa=2;}
		}//只有一方不足10.5
		if(play[1].num==5&&play[1]==2.5)
			aa=5;
		if(play[0].num==5&&play[0]==2.5)
			bb=5;
		if(play[1]>10.5&&play[0]>10.5){
			aa=0;
			bb=0;
		}
		if(play[1]==10.5&&play[0]==10.5){
			aa=3;
			bb=3;
		}
		play[1].Power+=aa;
		play[0].Power+=bb;
		play[1].score=aa;
		play[0].score=bb;
	}
	if(Player>=3){
		bool noswap;
		int i,j;
		player temp;
		for(i=0;i<Player;i++)
		{
			if(play[i].dian>10.5)
				play[i].dian=-1;
		}
		for(i=0;i<Player-1;i++){
			noswap=true;
			for(j=Player-1;j>i;j--){
				if(play[j].dian>play[j-1].dian){
					temp=play[j];
					play[j]=play[j-1];
					play[j-1]=temp;
					noswap=false;
				}
			}
			if(noswap)break;
		}

		int rank1 = 1;	
		play[0].rank=rank1;
		for(i = 1;i< Player;i++){
			if( i>=1 && play[i].dian == play[i-1].dian){
				play[i].rank=rank1;
			}
			else{
				rank1 = i+1;
				play[i].rank=rank1;
			}
		} 

	for(i=0;i<Player;i++){
			play[i].score=4-play[i].rank;
			if(play[i].dian==-1){
				play[i].score=0;
			}
			play[i].Power+=play[i].score;
			
		}

		BubbleSort();
		Ranking();
		Add_BubbleSort();
	}
}

