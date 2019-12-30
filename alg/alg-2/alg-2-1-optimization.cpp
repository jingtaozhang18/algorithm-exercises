// from yirui li
// 先使用狄杰斯特拉计算所有点到城市乙的最短距离
// 从城市甲开始寻找最短路径
// 当前最优路径的长度为 R
// 若城市甲的cost满足条件，找到了最短路径
// 不满足条件，找城市的邻居，若cost满足，更新R，不满足cost的，路径长度大于R的剪枝，小于R继续向后计算

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#define LENGTH 50
#define MAX_SPEND 1500

int m1[LENGTH][LENGTH]; //这里邻接表表示的是一个有向图
int m2[LENGTH][LENGTH];
int pathLenToEnd[LENGTH][3]; //这个矩阵第一列用来保存某一个点到终点的最短距离，
						     //第二列用来保存该点的最短路径的上一个点
							 //第三列用来保存这一点到终点的最短路径的花费

int minPathPart[LENGTH][2]; //用来最终的结果中哪一段道路是最小值
						    //比如 0,8; 8,49 则说明是由两段组合起来的
int minPathLen = 0x7fffffff;  //用来存放当前最优解的最短路径长
int* minPath = NULL; //用来存放这条最短路径的数组
int minPathN = 0; //用来存放这个数组的长度 
int minPreCost = 0; //用来存放这个数组的花费

//同文件中读入矩阵到全局变量中，没有返回值
void getInputMatrix() {
	FILE* input_m1 = fopen("m1.txt", "r");
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			fscanf(input_m1, "%d", &m1[i][j]);
		}
	}
	fclose(input_m1);
	FILE* input_m2 = fopen("m2.txt", "r");
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			fscanf(input_m2, "%d", &m2[i][j]);
		}
	}
	fclose(input_m2);
}

void flood(int point) {
	for (int i = 0; i < LENGTH; i++) {
		if (m1[i][point] != 9999) {
			int newPathLen = pathLenToEnd[point][0] + m1[i][point];
			if (newPathLen < pathLenToEnd[i][0]) {
				pathLenToEnd[i][0] = newPathLen;
				pathLenToEnd[i][1] = point;
				pathLenToEnd[i][2] = pathLenToEnd[point][2] + m2[i][point];
				flood(i);
			}
		}
	}
}

//将最短路径存到全局变量中，没有返回值
void dijkstra() {
	for (int i = 0; i < LENGTH; i++) {
		pathLenToEnd[i][0] = 0x7fffffff;
	}
	pathLenToEnd[LENGTH - 1][0] = 0;
	for (int i = 0; i < LENGTH; i++) {
		if (m1[i][LENGTH - 1] != 9999) {
			pathLenToEnd[i][0] = m1[i][LENGTH - 1];
			pathLenToEnd[i][1] = LENGTH - 1;
			pathLenToEnd[i][2] = m2[i][LENGTH - 1];
			flood(i);
		}
	}
}

//输入需要找最小值的区间
int findCheapPath(int begin, int preCost, int preLen, int *prePath, int ppn) {
	//这次需要倒着找回去，在此之前，先更新一下当前最优的情况
	for (int i = begin; i < LENGTH - 1; i++) {
		if (m1[begin][i] != 9999) {
			int thisLen = m1[begin][i] + pathLenToEnd[i][0] + preLen;
			int thisCost = m2[begin][i] + pathLenToEnd[i][2] + preCost;
			if (thisCost <= 1500 && minPathLen > thisLen) {
				int* minPathNew = (int*)malloc(sizeof(int) * (ppn + 1));
				minPathLen = thisLen;
				for (int j = 0; j < ppn-1; j++) {
					minPathNew[j] = prePath[j];
				}
				minPathNew[ppn-1] = i;
				minPathNew[ppn] = prePath[ppn - 1];
				minPath = minPathNew;
				minPathN = ppn + 1;
				minPreCost = m2[begin][i] + preCost;
			}
		}
	}
	//然后向满足可能比当前最优还优的可能的方向继续递归
	for (int i = begin; i < LENGTH -1; i++) {
		if (m1[begin][i] != 9999) {
			int thisLen = m1[begin][i] + pathLenToEnd[i][0] + preLen;
			int thisCost = m2[begin][i] + pathLenToEnd[i][2] + preCost;
			if (minPathLen >= thisLen) {
				int* prePathNew = (int*)malloc(sizeof(int) * (ppn + 1));
				for (int j = 0; j < ppn-1; j++) {
					prePathNew[j] = prePath[j];
				}
				prePathNew[ppn - 1] = i;
				prePathNew[ppn] = prePath[ppn - 1];
				findCheapPath(i, preCost + m2[begin][i], preLen + m1[begin][i], prePathNew, ppn+1);
			}
		}
	}
	return 0;
}

int main() {
	getInputMatrix();
	dijkstra();
	if (pathLenToEnd[0][2] <= MAX_SPEND) {
		printf("1 ");
		int pt = 0;
		while (1) {
			printf("%d ", pathLenToEnd[pt][1] + 1);
			pt = pathLenToEnd[pt][1];
			if (pt == LENGTH - 1)
				break;
		}
		printf("\nminLen: %d\n", pathLenToEnd[0][0]);
		printf("\nminCost: %d\n", pathLenToEnd[0][2]);
		return 0;
	}
	else {
		int* prePath = (int*)malloc(sizeof(int) * 2);
		prePath[0] = 0;
		prePath[1] = LENGTH - 1;
		findCheapPath(0, 0, 0, prePath, 2);
	}

	if (minPath != NULL) {
		for (int i = 0; i < minPathN-1; i++) {
			printf("%d ", minPath[i]+1);
		}
		int pt = minPath[minPathN - 2];
		while (1) {
			printf("%d ", pathLenToEnd[pt][1]+1);
			pt = pathLenToEnd[pt][1];
			if (pt == LENGTH-1)
				break;
		}
		printf("\nminLen: %d", minPathLen);
		printf("\nminCost: %d", minPreCost + pathLenToEnd[minPath[minPathN - 2]][2]);
	}
	else {
		printf("Can't find a satisfied path!\n");
	}
	
	return 0;
}
