#ifndef __MAZE_H__
#define __MAZE_H__

#include<stdio.h>
#include<assert.h>

#define N 6 
static int maze[N][N] =
{
	{ 0,0,0,0,0,0 },
	{ 0,0,0,0,0,0 },
	{ 0,0,1,1,1,0 },
	{ 0,0,1,0,1,0 },
	{ 0,0,1,1,1,1 },
	{ 0,0,1,0,0,0 },
};
typedef struct Pos 
{
	int _row;
	int _col;

}Pos;
///////////////////////////////////////////
typedef Pos DataType;
typedef struct Stack
{
	DataType* _array;
	int _top; //栈顶 
	int _capacity;//容量
}Stack, *pStack;
void StackPop(Stack* s);//弹栈

DataType StackTop(Stack* s);//返回栈顶
//size_t StackSize(Stack* s);//求栈的长度
int StackEmpty(Stack* s);//判空
void StackDestroy(Stack* s);//清空栈
size_t StackSize(Stack* s);//栈的长度

void MazePrint(int maze[][6]);

int MazeGetPath(Pos entry,Pos exit);
int MazeCheckIsAccess(Pos pos);

//带环 
//求最短路线
//均可用下面两个函数实现，只需改变数组初始化
int MazeGetPathR(Pos entry, Pos exit);
int MazeCheckIsAccessR(Pos cur, Pos next);


TestGetPath();
TestMazeGetPathR();
#endif // !__MAZE_H__
