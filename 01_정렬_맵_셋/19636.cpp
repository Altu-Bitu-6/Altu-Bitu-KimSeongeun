#include <stdio.h>

int _w, _l0, _t, _d, _l, _a;
void metabolicRate1(int w, int l0, int t, int d, int l, int a)
{
	for (int i = 1; i <= d; i++)
	{
		//일일 에너지 소비량
		int consumption = l0 + a;
		//일일 에너지 섭취량- 일일 에너지 소비량
		int del = l - consumption;
		//체중변화
		w += del;
		//기초 대사량 변화
		if (del < t * -1)
		{
			if (del % 2 == 0)
				l0 += del / 2;
			else
				l0 += del / 2 - 1;
		}
		else if (del > t)
		{
			if (del % 2 == 0)
				l0 += del / 2;
		}
		//체중이 0 이하이거나 기초대사량이 0 이하인 경우
		if (w <= 0 || l0 <= 0)
		{
			printf("Danger Diet\n");
			return;
		}
	}
	printf("%d %d ", w, l0);

	//요요 체크
	if (_l0 - (l0 + 0) > 0)
		printf("YOYO");
	else
		printf("NO");
}
void metabolicRate2(int w, int l0, int t, int d, int l, int a)
{
	for (int i = 1; i <= d; i++)
	{
		//일일 에너지 소비량
		int consumption = l0 + a;
		//일일 에너지 섭취량- 일일 에너지 소비량
		int del = l - consumption;
		//체중변화
		w += del;
		//체중이 0 이하이거나 기초대사량이 0 이하인 경우
		if (w <= 0 || l0 <= 0)
		{
			printf("Danger Diet\n");
			return;
		}
	}
	printf("%d %d\n", w, l0);
}
int main(void)
{
	scanf("%d %d %d %d %d %d", &_w, &_l0, &_t, &_d, &_l, &_a);

	metabolicRate2(_w, _l0, _t, _d, _l, _a);
	metabolicRate1(_w, _l0, _t, _d, _l, _a);
	
	return 0;
}