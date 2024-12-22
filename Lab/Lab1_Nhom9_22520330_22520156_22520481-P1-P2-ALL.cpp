#include<iostream>

using namespace std;

// 1.1
int bitOr(int x, int y)
{
    return ~((~x)&(~y)); /* Dùng công thức Demorgan: A+B = -((-A).(-B))*/
}
 
//1.2
int negative(int x){
    return ~x + 1;// đảo dấu của 1 số là bù 2 của số đó cộng cho 1;
}

//1.3
int getHexcha(int x, int n)
{
    n = n << 2; /*n=n*4*/
    x = x >> n; /*dịch n*4 bit để lấy mask quan tâm, đẩy mask đó về mask cuối*/
    return x&15; /* 15 là 1111 hệ nhị phân, ta and nó lại để hiện được mask cuối*/
}

//1.4
int flipByte(int x, int n)
{
    n = n << 3; /*n=n*8 */
    int z = x >> n; /* dịch sang phải n*8 bit để đẩy byte về byte thấp nhất*/
    z = ~z; /*đảo bit*/
    z = z&255; /*and với 255 để chỉ lấy 8 bit cuối*/
    z = z << n; /* dịch byte cần đảo về vị trí ban đầu*/
    int t = 255 << n; /*dịch 8 bit 1 về vị trí của byte cần đảo*/
    t = ~t;
    x = x & t; /* Khuyết byte cần đảo trong 4 byte thành 0*/
    return (x | z); /*or phàn đảo và phần khuyết lại để được số yêu cầu*/
}

//1.5
int divpw2(int x, int n)
{
return ((n>>31)&(x << (~n + 1))) | ((~(n>>31))&(x >> n)); /*ta sẽ tận dụng bit dấu, nếu là âm thì dịch 31 bit sẽ ra 31 bit 1, khi đảo lại là 32 bit 0, dùng and và or lại để ra kết quả. Nếu n dương thì ngược lại*/
}


//2.1
int isEqual(int x, int y){
    return !(x^y); 
}
//2.2
int is16x(int x){
    return !(x&15);
}
//2.3
int isPositive(int x){
    return !(x>>31) ^ !x;
}
//2.4
int isGE2n(int x,int n){
    return isPositive(x>>n);
}



int main()
{
	int score = 0;
	printf("Your evaluation result:");
	printf("\n1.1 bitOr");
	if (bitOr(3, -9) == (3 | -9))
	{
		printf("\tPass.");
		score += 1;
	}
	else
		printf("\tFailed.");

	printf("\n1.2 negative");
	if (negative(0) == 0 && negative(9) == -9 && negative(-5) == 5)
	{
		printf("\tPass.");
		score += 1;
	}
	else
		printf("\tFailed.");

	//1.3
	printf("\n1.3 getHexcha");
	if (getHexcha(26, 0) == 0xa && getHexcha(0x11223344, 1) == 0x4)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	printf("\n1.4 flipByte");
	if (flipByte(10, 0) == 245 && flipByte(0, 1) == 65280 && flipByte(0x5501, 1) == 0xaa01)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");
	//1.5
	printf("\n1.5 divpw2");
	if (divpw2(10, -1) == 20 && divpw2(15, -2) == 60 && divpw2(2, -4) == 32)
	{
		if (divpw2(10, 1) == 5 && divpw2(50, 2) == 12)
		{
			printf("\tAdvanced Pass.");
			score += 4;
		}
		else
		{
			printf("\tPass.");
			score += 3;
		}
	}
	else
		printf("\tFailed.");

    printf("\n2.1 isEqual");
	if (isEqual(4, 2) == 0 && isEqual(-4, -4) == 1 && isEqual(0, 10) == 0)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	//2.2
	printf("\n2.2 is16x");
	if (is16x(16) == 1 && is16x(23) == 0 && is16x(0) == 1)
	{
		printf("\tPass.");
		score += 2;
	}
	else
		printf("\tFailed.");

	printf("\n2.3 isPositive");
	if (isPositive(10) == 1 && isPositive(-5) == 0 && isPositive(0) == 0)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");


	//2.4
	printf("\n2.4 isGE2n");
	if (isGE2n(12, 4) == 0 && isGE2n(8, 3) == 1 && isGE2n(15, 2) == 1)
	{
		printf("\tPass.");
		score += 3;
	}
	else
		printf("\tFailed.");

	printf("\n--- FINAL RESULT ---");
	printf("\nScore: %.1f", (float)score / 2);
	if (score < 5)
		printf("\nTrouble when solving these problems? Contact your instructor to get some hints :)");
	else
	{
		if (score < 8)
			printf("\nNice work. But try harder.");
		else
		{
			if (score >= 10)
				printf("\nExcellent. We found a master in bit-wise operations :D");
			else
				printf("\nYou're almost there. Think more carefully in failed problems.");
		}
	}

	printf("\n\n\n");
}