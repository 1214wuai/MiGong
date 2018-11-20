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
	int _top; //ջ�� 
	int _capacity;//����
}Stack, *pStack;
void StackPop(Stack* s);//��ջ

DataType StackTop(Stack* s);//����ջ��
//size_t StackSize(Stack* s);//��ջ�ĳ���
int StackEmpty(Stack* s);//�п�
void StackDestroy(Stack* s);//���ջ
size_t StackSize(Stack* s);//ջ�ĳ���

void MazePrint(int maze[][6]);

int MazeGetPath(Pos entry,Pos exit);
int MazeCheckIsAccess(Pos pos);

//���� 
//�����·��
//������������������ʵ�֣�ֻ��ı������ʼ��
int MazeGetPathR(Pos entry, Pos exit);
int MazeCheckIsAccessR(Pos cur, Pos next);


TestGetPath();
TestMazeGetPathR();
#endif // !__MAZE_H__
