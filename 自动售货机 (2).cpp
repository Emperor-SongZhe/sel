#include<bits/stdc++.h>
using namespace std;
void view(int d,int a,int b,int e)
	{
		char c;
		int g=a+64;
		c=g;
		cout<<d<<": ";
		for(int f=b;f>0;f--)cout<<c;cout<<" "<<e;
		printf("\n");
	}//定义VIEW来查看货架
int main()
{
	int num,step,no,stop,i,j;//step检测当前步骤，no检测商品序号，stop使工作停止，i用于循环，num检测通道
	int price[7]={0},t[6]={0},n[6]={0},p[6][6]={0},bb[6]={0},top[7]={0};//p,prize记录价格，n记录通道，bb记录花销
	int type[7]={0},buy,pay,money,mon;//type记录商品类别
	step=0;stop=0;pay=0;mon=0;
	string goods;
	while(stop==0){
		if(step==0){
			printf("please put goods(include A B C D E)\n");
			for(i=1;i>=0;i++){
				cin>>goods;
				if(goods=="NEXT"){printf(" Operation Done\n");break;}//输入NEXT下一步
				if(goods=="END"){printf(" Operation Done\n");return 0;}//输入END直接退出
				if(goods=="VIEW"){for(j=1;j<=5;++j)view(j,type[j],top[j],price[type[j]]);continue;}//定义VIEW来查看货架
				if(goods=="BACK"){printf(" Operation Done\n");top[n[1]]=top[n[1]]-t[1];price[type[n[1]]]=p[type[n[1]]][2];
				for(j=0;j<=4;j++){
					t[j]=t[j+1];
					n[j]=n[j+1];
					p[type[n[1]]][j]=p[type[n[1]]][j+1];
				}
				continue;
			}//输入BACK回退
				no=goods[0];
				no=no-64;
				if(no<=0||no>=6){printf("Goods don't exist\n");continue;}//其他商品不存在
				cin>>num>>price[no];
				p[no][0]=price[no];
				n[0]=num;
				cin>>t[0];
				top[num]=top[num]+t[0];
				for(j=6;j>0;j--){
					t[j+1]=t[j];
					n[j+1]=n[j];
					p[no][j+1]=p[no][j];
				}
				t[0]=0;n[0]=0;p[no][0]=0;
				type[num]=no;
			}
			step++;
		}//第一步：放入商品
		if(step==1){
			for(i=1;i>=0;i++){
				cin>>goods;
				if(goods=="NEXT"){printf(" Operation Done\n");break;}//输入NEXT下一步
				else if(goods=="END"){printf(" Operation Done\n");return 0;}//输入END直接退出
				else if(goods=="VIEW"){for(j=1;j<=5;++j)view(j,type[j],top[j],price[type[j]]);continue;}//定义VIEW来查看货架
				else if(goods=="BACK"){printf(" Operation Done\n");top[num]=top[num]+bb[0];pay=pay-price[no]*bb[0];
				for(j=0;j>=4;++j){
					bb[j]=bb[j+1];
					}
				continue;
				}//BACK返回上一步
				else if(goods=="RETURN"){printf(" Operation Done\n");step=0;break;}//输入RETURN返回上一步放商品操作
				no=goods[0];
				no=no-64;
				cin>>num>>bb[0];
				if(no!=type[num]){printf("Wrong\n");continue;}//买错货架输出 Wrong
				if(top[num]<bb[0]){printf("Not enough\n");continue;}//货源不足输出 Not enough
				buy=bb[0];
				for(j=5;j<=0;--j){
					bb[j+1]=bb[j];
				}
				top[num]=top[num]-buy;
				pay=pay+price[no]*buy;
			}
			step++;
		}//第二步：购买商品
		if(step==2){
			for(i=1;i>=1;i++){
				if(goods=="RETURN"){printf(" Operation Done\n");step=1;break;}//输入RETURN返回上一步买商品操作
				cin>>money;
				mon=mon+money;
				
				if(mon>pay){printf("Give change %d\n",mon-pay);step=1;mon=0;pay=0;break;}
				if(mon==pay){printf("Well Done\n");step=1;mon=0;pay=0;break;}
				}
		}//第三步：给钱
	}
	return 0;
}