#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
 
int sudo[9][9], hole[9][9];
void clear()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			sudo[i][j]=0;
			hole[i][j]=0;
		}
	}
 } 
bool set(int x, int y, int val)
{
    if (sudo[y][x] != 0)        //�ǿ�
        return false;
    int x0, y0;
    for (x0=0; x0<9; x0++)
    {
        if (sudo[y][x0] == val) //�г�ͻ
            return false;
    }
    for (y0=0; y0<9; y0++)
    {
        if (sudo[y0][x] == val) //�г�ͻ
            return false;
    }
    for (y0=y/3*3; y0<y/3*3+3; y0++)
    {
        for (x0=x/3*3; x0<x/3*3+3; x0++)
        {
            if (sudo[y0][x0] == val) //���ͻ
                return false;
        }
    }
    sudo[y][x] = val;
    return true;
}
 
void reset(int x, int y)
{
    sudo[y][x] = 0;
}
 
void initXOrd(int* xOrd)    //0~9�������
{
    int i, k, tmp;
    for (i=0; i<9; i++)
    {
        xOrd[i] = i;
    }
    for (i=0; i<9; i++)
    {
        k = rand() % 9;
        tmp = xOrd[k];
        xOrd[k] = xOrd[i];
        xOrd[i] = tmp;
    }
}
 
bool fillFrom(int y, int val)
{
    int xOrd[9];
    initXOrd(xOrd);     //���ɵ�ǰ�е�ɨ������
    for (int i=0; i<9; i++)
    {
        int x = xOrd[i];
        if (set(x, y, val))
        {
            if (y == 8)                 //�������һ��
            {
                //��ǰ��9�����, ����ӵ�һ������һ����
                if (val == 9 || fillFrom(0, val+1)) 
                    return true;
            } 
            else
            {
                if (fillFrom(y+1, val)) //��һ�м����ǰ��
                    return true;
            }
            reset(x, y);    //����
        }
    }
    return false;
}
 
void digHole(int holeCnt)
{
    int idx[81];
    int i, k;
    for (i=0; i<81; i++)
    {
        hole[i / 9][i % 9] = 0;
        idx[i] = i;
    }
    for (i=0; i<holeCnt; i++)    //����ڶ�λ��
    {
        k = rand() % 81;
        int tmp = idx[k];
        idx[k] = idx[i];
        idx[i] = tmp;
    }
    for (i=0; i<holeCnt; i++)
    {
        hole[idx[i] / 9][idx[i] % 9] = 1;
    }
}
 
void printSudo(int n)
{
	string s=to_string(n);
	ofstream outfile;
    string a;
    a="test"+s;
	outfile.open(a,ios::app);
    for (int y=0; y<9; y++)
    {
        
        for (int x=0; x<9; x++)
        {
            if(hole[y][x] == 0) outfile<<"0"; 
			else outfile<< sudo[y][x] ;
            
        } 
    }
    outfile<<endl;
    outfile.close();
}
 
int main(int argc, char* argv[])
{   
    int n;
    cin>>n;
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
    {
    

    while (!fillFrom(0, 1)) ;

    digHole(51);

    printSudo(n);
    clear();
	}
    return 0;
}
