#include"Maze.h"
/////////////////////////////
void StackInit(Stack* s)
{
	s->_array = (DataType*)malloc(sizeof(DataType)*N);
	s->_top = 0;
	s->_capacity = N;//6
	return;
}
void StackPush(Stack* s, DataType x)
{
	if (s->_top == s->_capacity)
	{
		s->_array = (DataType*)realloc(s->_array, (s->_capacity + N) * sizeof(DataType));
	}

	s->_array[s->_top] = x;
	s->_top++;
	return;
}
void StackPop(Stack* s)
{
	if (s->_top == -1)
	{
		return 0;
	}
	//int pop = s->_top-1;

	s->_top = s->_top - 1;
}
DataType StackTop(Stack* s)
{
	return s->_array[s->_top - 1];
}
int StackEmpty(Stack* s)//判空
{
	if (s->_top == 0)
		return 0;
	else
		return 1;
}
void StackDestroy(Stack* s)//清空栈
{
	assert(s);
	free(s->_array);
	s->_array = NULL;
	s->_top = s->_capacity = 0;
}
size_t StackSize(Stack* s)//求栈的长度
{
	return s->_top;
}


void MazePrint(int maze[][6])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}
int MazeCheckIsAccess(Pos pos)
{
	if (pos._col > N - 1 || pos._col < 0 || pos._row> N - 1 || pos._row < 0)
		return 0;
	if (maze[pos._row][pos._col] == 1 )
		return 1;
	else
		return 0;
}
int MazeCheckIsAccessR(Pos cur, Pos next)
{
	if (next._col > N - 1 || next._col < 0 || next._row> N - 1 || next._row < 0)
		return 0;
	if (maze[next._row][next._col] == 1
		|| maze[next._row][next._col] > maze[cur._row][cur._col] + 1)
		return 1;
	else
		return 0;
}
int MazeGetPath(Pos entry,Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);
	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		maze[cur._row][cur._col] = 2;
		if (cur._row == exit._row
			&&cur._col == exit._col)
		{
			;
			StackDestroy(&path);
			return 1;
		}
		Pos next;//探测下一个地方
		//上
		next = cur;
		next._row -= 1;
		if (MazeCheckIsAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccess(next))
		{
			StackPush(&path, next);
			continue;
		}//左
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccess(next))
		{
			StackPush(&path, next);
			continue;
		}//右
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccess(next))
		{
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);
		if (cur._row == entry._row
			&&cur._col == entry._col)
		{
			StackDestroy(&path);
			return 0;
		}
	}
}
int MazeGetPathR(Pos entry, Pos exit)
{
	Stack path;
	size_t sz = 0;
	StackInit(&path);
	StackPush(&path, entry);
	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		maze[entry._row][entry._col] = 2;
		if (cur._col == exit._col)
		{
			if (sz == 0 || sz > StackSize(&path))
			{
				sz = StackSize(&path);
			}
			/*return 1;*/
		}
		Pos next;//探测下一个地方
				 //上
		next = cur;
		next._row -= 1;
		if (MazeCheckIsAccessR(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (MazeCheckIsAccessR(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}//左
		next = cur;
		next._col -= 1;
		if (MazeCheckIsAccessR(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}//右
		next = cur;
		next._col += 1;
		if (MazeCheckIsAccessR(cur,next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}
		StackPop(&path);
		if (cur._row == entry._row
			&&cur._col == entry._col)
		{
			StackDestroy(&path);
			if (sz == 0)
				return 0;
			else
				return sz;
		}
	}
}
/////////////////////////////////////////////////////
TestGetPath()
{
	Pos entry;
	Pos exit;
	entry._row = 5;
	entry._col = 2;
	exit._row = 4;
	exit._col = 5;
	MazePrint(maze);
	int get = MazeGetPath(entry, exit);
	if (get == 1)
	{
		printf("找到了出口\n");
		MazePrint(maze);
	}
	else
	{
		printf("没有出口\n");
		MazePrint(maze);
	}
}
TestMazeGetPathR()
{
	Pos entry;
	Pos exit;
	entry._row = 5;
	entry._col = 2;
	exit._row = 4;
	exit._col = 5;
	MazePrint(maze);
	int get = MazeGetPathR(entry, exit);
	if (get == 0)
	{
		printf("没有出口\n");
		MazePrint(maze);
	}
	else
	{
		printf("有出口\n");
		printf("最短出口：%d\n",get);

		MazePrint(maze);
	}
}
