#include<iostream>
using namespace std;

char output[1000] = {'0'};
int num = 0; 
void step1();
void step2();
void step3();
void step4();
void step5();
void step6();
void step7();
void step8(); 
void mianxin();
void R();
void Ri();
void L();
void Li();
void B();
void Bi();
void D();
void Di();
void F();
void Fi();
void U();
void Ui();
void hand(int dir, int times);
void midl(int dir);
void yizi();
void guaijiao();
void xiaoyv(int dir);
void print();
int isfish();
char cube[6][3][3] = {};
char front, back, left1, right1, top, bottom;
char *lf1 = &cube[0][0][1],
	 *lf2 = &cube[0][1][2],
	 *lf3 = &cube[0][2][1], 
	 *lf4 = &cube[0][1][0],
	 *lb1 = &cube[1][0][1],
	 *lb2 = &cube[1][1][2],
	 *lb3 = &cube[1][2][1],
	 *lb4 = &cube[1][1][0],
	 *ll1 = &cube[2][0][1],
	 *ll2 = &cube[2][1][2],
	 *ll3 = &cube[2][2][1],
	 *ll4 = &cube[2][1][0],
	 *lr1 = &cube[3][0][1],
	 *lr2 = &cube[3][1][2],
	 *lr3 = &cube[3][2][1],
	 *lr4 = &cube[3][1][0],
	 *lt1 = &cube[4][0][1],
	 *lt2 = &cube[4][1][2], 
	 *lt3 = &cube[4][2][1],
	 *lt4 = &cube[4][1][0],
	 *lbo1 = &cube[5][0][1],
	 *lbo2 = &cube[5][1][2],
	 *lbo3 = &cube[5][2][1],
	 *lbo4 = &cube[5][1][0],
	 *jf1 = &cube[0][0][0],
	 *jf2 = &cube[0][0][2],
	 *jf3 = &cube[0][2][2], 
	 *jf4 = &cube[0][2][0],
	 *jb1 = &cube[1][0][0],
	 *jb2 = &cube[1][0][2],
	 *jb3 = &cube[1][2][2], 
	 *jb4 = &cube[1][2][0],
	 *jl1 = &cube[2][0][0],
	 *jl2 = &cube[2][0][2],
	 *jl3 = &cube[2][2][2], 
	 *jl4 = &cube[2][2][0],
	 *jr1 = &cube[3][0][0],
	 *jr2 = &cube[3][0][2],
	 *jr3 = &cube[3][2][2], 
	 *jr4 = &cube[3][2][0],
	 *jt1 = &cube[4][0][0],
	 *jt2 = &cube[4][0][2],
	 *jt3 = &cube[4][2][2], 
	 *jt4 = &cube[4][2][0],
	 *jbo1 = &cube[5][0][0],
	 *jbo2 = &cube[5][0][2],
	 *jbo3 = &cube[5][2][2], 
	 *jbo4 = &cube[5][2][0];
	 
int main()
{
	for(int i = 0; i < 6; i ++)
	{
		for(int k = 0; k < 3; k ++)
		{
			for(int j = 0; j < 3; j ++)
			cin >> cube[i][k][j];
		}
	}
	mianxin();
	step1();
	step2();
	step3();
	step4();
	step5();
	step6();
	step7();
	step8();
	print();
	return 0;
}

void mianxin()
{
	front = cube[0][1][1];
	back = cube[1][1][1];
	left1 = cube[2][1][1];
	right1 = cube[3][1][1];
	top = cube[4][1][1];
	bottom = cube[5][1][1];
	return;
}
void hand(int dir, int times)		// dir = 1 ~ 4为左手 5 ~ 8为右手，从正面开始顺时针旋转。 
{
	if(dir == 1)
	{
		for(int i = 0; i < times; i ++)
		{
			Ui();
			Li();
			U();
			L();
		}
		return;
	}
	if(dir == 2)
	{
		for(int i = 0; i < times; i ++)
		{
			Ui();
			Bi();
			U();
			B();
		}
		return;
	}
	if(dir == 3)
	{
		for(int i = 0; i < times; i ++)
		{
			Ui();
			Ri();
			U();
			R();
		}
		return;
	}
	if(dir == 4)
	{
		for(int i = 0; i < times; i ++)
		{
			Ui();
			Fi();
			U();
			F();
		}
		return;
	}
	if(dir == 5)
	{
		for(int i = 0; i < times; i ++)
		{
			U();
			R();
			Ui();
			Ri();
		}
		return;
	}
	if(dir == 6)
	{
		for(int i = 0; i < times; i ++)
		{
			U();
			F();
			Ui();
			Fi();
		}
		return;
	}
	if(dir == 7)
	{
		for(int i = 0; i < times; i ++)
		{
			U();
			L();
			Ui();
			Li();
		}
		return;
	}
	if(dir == 8)
	{
		for(int i = 0; i < times; i ++)
		{
			U();
			B();
			Ui();
			Bi();
		}
		return;
	}
	return;
}
void midl(int dir)					// dir = 1 ~ 4为中棱归左 5 ~ 8为中棱归右，从正面开始顺时针旋转。 
{
	if(dir == 1)
	{
		hand(1, 1);
		hand(6, 1);
		return;
	}
	if(dir == 2)
	{
		hand(2, 1);
		hand(7, 1);
		return;
	}
	if(dir == 3)
	{
		hand(3, 1);
		hand(8, 1);
		return;
	}
	if(dir == 4)
	{
		hand(4, 1);
		hand(5, 1);
		return;
	}
	if(dir == 5)
	{
		hand(5, 1);
		hand(4, 1);
		return;
	}
	if(dir == 6)
	{
		hand(6, 1);
		hand(1, 1);
		return;
	}
	if(dir == 7)
	{
		hand(7, 1);
		hand(2, 1);
		return;
	}
	if(dir == 8)
	{
		hand(8, 1);
		hand(3, 1);
		return;
	}
	return;
}
void xiaoyv(int dir)				//dir = 1 为左小鱼， dir = 2 为右小鱼。 
{
	if(dir == 1)
	{
		Li();
		Ui();
		L();
		Ui();
		Li();
		Ui();
		Ui();
		L();
	}
	if(dir == 2)
	{
		R();
		U();
		Ri();
		U();
		R();
		U();
		U();
		Ri();
	}
	return;
}
int isfish()
{
	for(int i = 0; i < 4; i ++)
	{
		if(*jt1 != top && *jt2 != top && *jt3 != top && *jt4 == top && *jf2 == top)
		{
			xiaoyv(2);
			return 1;
		}
		if(*jt1 != top && *jt2 != top && *jt3 == top && *jt4 != top && *jf1 == top)
		{
			xiaoyv(1);
			return 1;
		}
		U();
	}
	return 0;
}
void yizi()
{
	R();
	U();
	Ri();
	Ui();
	Ri();
	F();
	R();
	Fi();
	return;
}
void guaijiao()
{
	F();
	R();
	Ui();
	Ri();
	Ui();
	R();
	U();
	Ri();
	Fi();
	return; 
}
void step1()			// 小白花 
{
	while(cube[4][0][1] != bottom || cube[4][1][0] != bottom || cube[4][1][2] != bottom || cube[4][2][1] != bottom)
	{
		if(*lf1 == bottom)
			F();
		if(*lb1 == bottom)
			B();
		if(*ll1 == bottom)
			L();
		if(*lr1 == bottom)
			R();

		if(*lf4 == bottom)
		{
			while(*lt4 == bottom)
				U();
			Li();
        }
        if(*lf2 == bottom)
        {
			while(*lt2 == bottom)
				U();
	       	R();
		}
		if(*lb4 == bottom)
		{
			while(*lt2 == bottom)
				U();
			Ri();
        }
        if(*lb2 == bottom)
        {
			while(*lt4 == bottom)
				U();
        	L();
		}
		if(cube[2][1][0] == bottom)
		{
			while(cube[4][0][1] == bottom)
				U();
			Bi();
        }
        if(cube[2][1][2] == bottom)
        {
			while(cube[4][2][1] == bottom)
				U();
        	F();
		}
		if(cube[3][1][0] == bottom)
		{
			while(cube[4][2][1] == bottom)
				U();
			Fi();
        }
        if(cube[3][1][2] == bottom)
        {
			while(cube[4][0][1] == bottom)
				U();
        	B();
		}
		if(cube[5][0][1] == bottom)
		{
			while(cube[4][2][1] == bottom)
				U();
			Fi();
			Fi();
        }
        if(cube[5][1][0] == bottom)
        {
			while(cube[4][1][0] == bottom)
				U();
        	L();
        	L();
		}
		if(cube[5][1][2] == bottom)
		{
			while(cube[4][1][2] == bottom)
				U();
			Ri();
			Ri();
        }
        if(cube[5][2][1] == bottom)
        {
			while(cube[4][0][1] == bottom)
				U();
        	B();
            B();
		}
		if(*lf3 == bottom)
		{
			while(*lt3 == bottom)
				U();
			F();
		}
		if(*lb3 == bottom)
		{
			while(*lt1 == bottom)
				U();
			B();
		}
		if(*ll3 == bottom)
		{
			while(*lt4 == bottom)
				U();
			L();
		}
		if(*lr3 == bottom)
		{
			while(*lt2 == bottom)
				U();
			R();
		}
	}
	return;
}
void step2()			//底棱归位 
{
	while(*lbo1 != bottom || *lbo2 != bottom || *lbo3 != bottom || *lbo4 != bottom)
	{
		if(*lf1 == front && *lt3 == bottom)
		{
			F();
			F();
		}
		if(*lb1 == back && *lt1 == bottom)
		{
			B();
			B();
		}
		if(*lr1 == right1 && *lt2 == bottom)
		{
			R();
			R();
		}
		if(*ll1 == left1 && *lt4 == bottom)
		{
			L();
			L();
		}
		U();
	}
	return;
}
void step3()			//地角归位 
{
	char cen[4] = {front, left1, back, right1};
	char tmp1, tmp2;
	while(*jbo1 != bottom || *jbo2 != bottom || *jbo3 != bottom || *jbo4 != bottom || *jf3 != front || *jf4 != front || *jl3 != left1 || *jl4 != left1 || *jb3 != back || *jb4 !=back || *jr3 != right1 || *jr4 != right1)
	{
		while(*jf1 == bottom || *jl1 == bottom || *jb1 == bottom || *jr1 == bottom || *jf2 == bottom || *jl2 == bottom || *jb2 == bottom || *jr2 == bottom)		//做到四面上一层没有底块 
		{
			U();
			if(*jf1 == bottom)
			{
				tmp1 = *jt4;
				tmp2 = *jl2;
				for(int i = 1; i <= 4; i ++)
				{
					if((tmp1 == cen[i % 4] && tmp2 == cen[(i - 1) % 4]) || (tmp1 == cen[(i - 1) % 4] && tmp2 == cen[i % 4]))
					{
						hand(i, 1);
						break;
					}
					U();
				}
			}
			if(*jf2 == bottom)
			{
				tmp1 = *jt3;
				tmp2 = *jr1;
				for(int i = 1; i <= 4; i ++)
				{
					if((tmp1 == cen[(i + 3) % 4] && tmp2 == cen[(i + 2) % 4]) || (tmp1 == cen[(i + 3) % 4] && tmp2 == cen[(i + 2) % 4]))
					{
						hand(i + 4, 1);
						break;
					}
					U();
				}
			}
			
		}
		while(*jt1 == bottom || *jt2 == bottom || *jt3 == bottom || *jt4 == bottom)
		{
			U();
			if(*jt4 == bottom)
			{
				tmp1 = *jf1;
				tmp2 = *jl2;
				for(int i = 1; i <= 4; i ++)
				{
					if((tmp1 == cen[i % 4] && tmp2 == cen[(i - 1) % 4]) || (tmp1 == cen[(i - 1) % 4] && tmp2 == cen[i % 4]))
					{
						hand(i, 3);
						break;
					}
					U();
				}
			}
			if(*jt3 == bottom)
			{
				tmp1 = *jf2;
				tmp2 = *jr1;
				for(int i = 1; i <= 4; i ++)
				{
					if((tmp1 == cen[(i + 3) % 4] && tmp2 == cen[(i + 2) % 4]) || (tmp1 == cen[(i + 3) % 4] && tmp2 == cen[(i + 2) % 4]))
					{
						hand(i + 4, 3);
						break;
					}
					U();
				}
			}
		}
		if(*jf4 == bottom)
			hand(1, 1);
		if(*jl4 == bottom)
			hand(2, 1);
		if(*jb4 == bottom)
			hand(3, 1);
		if(*jr4 == bottom)
			hand(4, 1);
		if(*jf3 == bottom)
			hand(5, 1);
		if(*jl3 == bottom)
			hand(6, 1);
		if(*jb3 == bottom)
			hand(7, 1);
		if(*jr3 == bottom)
			hand(8, 1);
		if(*jbo1 == bottom && *jf4 != front)
			hand(1, 1);
		if(*jbo4 == bottom && *jl4 != left1)
			hand(2, 1);
		if(*jbo3 == bottom && *jb4 != back)
			hand(3, 1);
		if(*jbo2 == bottom && *jr4 != right1)
			hand(4, 1);
	}
	return;
}
void step4()			//中棱归位 
{
	char cen[4] = {front, left1, back, right1};
	char tmp1, tmp2;
	while(*lf2 != front || *lf4 != front || *ll2 != left1 || *ll4 != left1 || *lb2 != back || *lb4 != back || *lr2 != right1 || *lr4 != right1)
	{
		while((*lt1 != top && *lb1 != top) || (*lt2 != top && *lr1 != top) || (*lt3 != top && *lf1 != top) || (*lt4 != top && *ll1 != top))
		{
			U();
			if(*lt3 != top && *lf1 != top)
			{
				tmp1 = *lf1;
				tmp2 = *lt3;
				for(int i = 1; i <= 4; i ++)
				{
					if(tmp1 == cen[i - 1] && tmp2 == cen[i % 4])
					{
						midl(i);
						break;
					}
					if(tmp1 == cen[i - 1] && tmp2 == cen[(i + 2) % 4])
					{
						midl(i + 4);
						break;
					}
					U();
				}
				
			}
		}
		if(*lf4 != front && *lf4 != top && *ll2 != top)
			midl(1);
		if(*ll4 != left1 && *lb2 != top && *ll4 != top)
			midl(2);
		if(*lb4 != back && *lb4 != top && *lr2 != top)
			midl(3);
		if(*lr4 != right1 && *lr4 != top && *lf2 != top)
			midl(4);
	}
	return;
}
void step5()			//顶棱面位 
{
	while(*lt1 != top || *lt2 != top || *lt3 != top || *lt4 != top)
	{
		if(*lt1 != top && *lt2 != top && *lt3 != top && *lt4 != top)
			yizi();
		if(*lt1 == top && *lt3 == top)
		{
			U();
			yizi();
			break;
		}
		if(*lt2 == top && *lt4 == top)
		{
			yizi();
			break;
		}
		while(*lt1 != top || *lt4 != top)
			U();
		guaijiao();
	}
	return;
}
void step6()			//顶角面位 
{
	while(*jt1 != top || *jt2 != top || *jt3 != top || *jt4 != top)
	{
		if(isfish())
			return;

		do{		
			while(*jf1 != top)
			{
				U();
			}
			xiaoyv(2);
		}while(!isfish());
	}
	return;
}
void step7()			//顶角归位 
{
	int flag = 0;
	while(*jf1 != *jf2 || *jl1 != *jl2 || *jb1 != *jb2 || *jr1 != *jr2)
	{
		for(int i = 0; i < 4; i ++)
		{
			if(*jl1 == *jl2)
			{
				yizi();
				guaijiao();
				flag = 1;
				break;
			}
			U();
		}
		if(flag == 1)
			break;
		for(int i = 0; i < 4; i ++)
		{
			if(*jl1 != *jf1 && *jl1 != *jf2 && *jf1 != *jf2)
			{
				guaijiao();
				yizi();
				flag = 1;
				break;
			}
			U();
		}
		if(flag == 1)
			break;
	}
	while(*jf1 != front)
		U();
	return;
}
void step8()			//顶棱归位 
{
	if(*lf1 != front && *ll1 != left1 && *lb1 != back && *lr1 != right1)
	{
		xiaoyv(1);
		Ui();
		xiaoyv(2);
		U();
	}
	while(*lb1 != *jb1)
		U();
	if(*ll1 == *jf1)
	{
		xiaoyv(1);
		Ui();
		xiaoyv(2);
		U();
	}
	if(*lr1 == *jf1)
	{
		xiaoyv(2);
		U();
		xiaoyv(1);
		Ui();
	}
	while(*lb1 != back)
		U();
	return;
}
void R()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[0][k][2];
        cube[0][k][2] = cube[5][k][2];
        cube[5][k][2] = cube[1][2 - k][0];
        cube[1][2 - k][0] = cube[4][k][2];
        cube[4][k][2] = a;
    }
    a = cube[3][0][0];
    cube[3][0][0] = cube[3][2][0];
    cube[3][2][0] = cube[3][2][2];
    cube[3][2][2] = cube[3][0][2];
    cube[3][0][2] = a;
    a = cube[3][0][1];
    cube[3][0][1] = cube[3][1][0];
    cube[3][1][0] = cube[3][2][1];
    cube[3][2][1] = cube[3][1][2];
    cube[3][1][2] = a;
    output[num++] = 'R';
    return;
}
void Ri()
{
	for(int i = 0; i < 3; i ++)
		R();
	return;
}
void L()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[0][k][0];
        cube[0][k][0] = cube[4][k][0];
        cube[4][k][0] = cube[1][2 - k][2];
        cube[1][2 - k][2] = cube[5][k][0];
        cube[5][k][0] = a;
    }
    a = cube[2][0][0];
    cube[2][0][0] = cube[2][2][0];
    cube[2][2][0] = cube[2][2][2];
    cube[2][2][2] = cube[2][0][2];
    cube[2][0][2] = a;
    a = cube[2][0][1];
    cube[2][0][1] = cube[2][1][0];
    cube[2][1][0] = cube[2][2][1];
    cube[2][2][1] = cube[2][1][2];
    cube[2][1][2] = a;
    output[num++] = 'L';
    return;
}
void Li()
{
	for(int i = 0; i < 3; i ++)
		L();
	return;
}
void B()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[4][0][k];
        cube[4][0][k] = cube[3][k][2];
        cube[3][k][2] = cube[5][2][2 - k];
        cube[5][2][2 - k] = cube[2][2 - k][0];
        cube[2][2 - k][0] = a;
    }
    a = cube[1][0][0];
    cube[1][0][0] = cube[1][2][0];
    cube[1][2][0] = cube[1][2][2];
    cube[1][2][2] = cube[1][0][2];
    cube[1][0][2] = a;
    a = cube[1][0][1];
    cube[1][0][1] = cube[1][1][0];
    cube[1][1][0] = cube[1][2][1];
    cube[1][2][1] = cube[1][1][2];
    cube[1][1][2] = a;
    output[num++] = 'B';
    return;
}
void Bi()
{
	for(int i = 0; i < 3; i ++)
		B();
	return;
}
void F()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[4][2][k];
        cube[4][2][k] = cube[2][2 - k][2];
        cube[2][2 - k][2] = cube[5][0][2 - k];
        cube[5][0][2 - k] = cube[3][k][0];
        cube[3][k][0] = a;
    }
    a = cube[0][0][0];
    cube[0][0][0] = cube[0][2][0];
    cube[0][2][0] = cube[0][2][2];
    cube[0][2][2] = cube[0][0][2];
    cube[0][0][2] = a;
    a = cube[0][0][1];
    cube[0][0][1] = cube[0][1][0];
    cube[0][1][0] = cube[0][2][1];
    cube[0][2][1] = cube[0][1][2];
    cube[0][1][2] = a;
    output[num++] = 'F';
    return;
}
void Fi()
{
	for(int i = 0; i < 3; i ++)
		F();
	return;
}
void U()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[0][0][k];
        cube[0][0][k] = cube[3][0][k];
        cube[3][0][k] = cube[1][0][k];
        cube[1][0][k] = cube[2][0][k];
        cube[2][0][k] = a;
    }
    a = cube[4][0][0];
    cube[4][0][0] = cube[4][2][0];
    cube[4][2][0] = cube[4][2][2];
    cube[4][2][2] = cube[4][0][2];
    cube[4][0][2] = a;
    a = cube[4][0][1];
    cube[4][0][1] = cube[4][1][0];
    cube[4][1][0] = cube[4][2][1];
    cube[4][2][1] = cube[4][1][2];
    cube[4][1][2] = a;
    output[num++] = 'U';
    return;
}
void Ui()
{
	for(int i = 0; i < 3; i ++)
		U();
	return;
}
void D()
{
	char a;
    for(int k = 0;k < 3;k ++)
    {
        a = cube[0][2][k];
        cube[0][2][k] = cube[2][2][k];
        cube[2][2][k] = cube[1][2][k];
        cube[1][2][k] = cube[3][2][k];
        cube[3][2][k] = a;
    }
    a = cube[5][0][0];
    cube[5][0][0] = cube[5][2][0];
    cube[5][2][0] = cube[5][2][2];
    cube[5][2][2] = cube[5][0][2];
    cube[5][0][2] = a;
    a = cube[5][0][1];
    cube[5][0][1] = cube[5][1][0];
    cube[5][1][0] = cube[5][2][1];
    cube[5][2][1] = cube[5][1][2];
    cube[5][1][2] = a;
    output[num++] = 'D';
    return;
}
void Di()
{
	for(int i = 0; i < 3; i ++)
		D();
	return;
}

void print(){
	int i = 0;
	do{
		if((output[i] == output[i + 1])
		&& (output[i] == output[i + 2])
		&& (output[i] == output[i + 3]))
			i += 4;
		else if((output[i] == output[i + 1])
		&& (output[i] == output[i + 2])){
			cout << output[i] << 'i' << ' ';
			i += 3;
		}
		else{
			cout << output[i] << ' ';
			i++;
		}
	}while (i < num);
}
