#include <graphics.h>   
#include <conio.h> 
#include <stdio.h> 

#include <graphics.h>   
#include <conio.h> 
#include <stdio.h> 

int main()
{
	float width, height, gravity; // 游戏画面大小、重力加速度 
	float ball_x, ball_y, ball_vy, radius; // 小球圆心坐标、y方向速度、半径大小 
	float rect_left_x, rect_top_y, rect_width, rect_height, rect_vx; // 方块障碍物的相关参数 
	float rect_left_x1, rect_top_y1, rect_width1, rect_height1, rect_vx1; // 方块障碍物1的相关参数 
	float rect_left_x2, rect_top_y2, rect_width2, rect_height2, rect_vx2; // 方块障碍物2的相关参数
	int score = 0; // 得分 	

	width = 600;  // 游戏画面宽度  
	height = 800; // 游戏画面高度 
	gravity = 0.6;  // 重力加速度 

	initgraph(width, height); // 新建一个画布 	
	radius = 20; // 小球半径	 
	ball_x = width / 4; // 小球x位置 
	ball_y = height / 2;  // 小球y位置 
	ball_vy = -17;  // 小球初始y速度为-17
	rect_height = 100; // 方块高度 
	rect_width = 20; // 方块宽度 
	rect_left_x = width * 3 / 4; // 方块左边x坐标 
	rect_top_y = height - rect_height; // 方块顶部y坐标 
	rect_vx = -3; // 方块x方向速度 	
	ball_vy = -10;  // 小球初始y速度为-10

	rect_height1 = 200; // 方块1高度 
	rect_width1 = 20; // 方块1宽度 
	rect_left_x1 = width * 3 / 4; // 方块1左边x坐标 
	rect_top_y1 = height - rect_height1; // 方块1顶部y坐标 
	rect_vx1 = -3; // 方块1x方向速度 

	rect_height2 = 200; // 方块2高度 
	rect_width2 = 20; // 方块2宽度 
	rect_left_x2 = width * 3 / 4; // 方块2左边x坐标 
	rect_top_y2 = 0; // 方块2顶部y坐标 
	rect_vx2 = -3; // 方块2x方向速度 

	while (1) // 一直循环 
	{
		if (_kbhit()) // 当按键时 	
		// 当按键时
		if (_kbhit())  	
		{
			char input = _getch(); // 获得输入字符 		
			if (input == ' ') // 当按下空格键		
			{
				ball_vy = -17; // 给小球一个向上的速度 			
						
				ball_vy = -10; // 给小球一个向上的速度 			
			}
		}

		ball_vy = ball_vy + gravity;  // 根据重力加速度更新小球y方向速度 	
		ball_y = ball_y + ball_vy;    // 根据小球y方向速度更新其y坐标 	

		if (ball_y >= height - radius)  // 如果小球落到地面上 	
		// 如果小球落到地面上
		if (ball_y >= height - radius)   	
		{
			ball_vy = -5;  // y速度为0 		
			ball_vy = -5;  // y速度为-5 		
			ball_y = height - radius;  // 规范其y坐标，避免落到地面下 		
			
			score = 0;
		}

		rect_left_x = rect_left_x + rect_vx; // 方块向左移 	
		rect_left_x1 = rect_left_x1 + rect_vx1; // 方块1向左移 
		rect_left_x2 = rect_left_x2 + rect_vx2; // 方块2向左移 

		if (rect_left_x <= 0) // 如果方块跑到最左边 	
		// 如果方块跑到最左边 
		if (rect_left_x1 <= 0  && rect_left_x2 <= 0) 	
		{
			rect_left_x = width; // 在最右边重新出现 		
			rect_left_x1 = width; // 在最右边重新出现
			rect_left_x2 = width; // 在最右边重新出现
			score = score + 1; // 得分+1 		
			rect_height = rand() % int(height / 4) + height / 4; // 设置随机高度 		
			rect_vx = rand() / float(RAND_MAX) * 4 - 7; // 设置方块随机速度 	
		} 	// 如果小球碰到方块 	

		if ((rect_left_x <= ball_x + radius) && (rect_left_x + rect_width >= ball_x - radius) && (height - rect_height <= ball_y + radius))
			rect_height1 = rect_height2 = rand() % int(height / 4) + height / 4; // 设置随机高度 		
			rect_vx1 = rect_vx2 = rand() / float(RAND_MAX) * 4 - 9; // 设置方块随机速度 	
		} 	
		
		// 如果小球碰到方块 	
		if ( 
			((rect_left_x1 <= ball_x + radius) && (rect_left_x1 + rect_width1 >= ball_x - radius) && (height - rect_height1 <= ball_y + radius)) ||
			((rect_left_x2 <= ball_x + radius) && (rect_left_x2 + rect_width2 >= ball_x - radius) && (rect_height2 >= ball_y - radius))
			)
		{
			Sleep(50); // 慢动作效果 		
			score = 0; // 得分清零 	
		}

		cleardevice();  // 清空画面 	

		fillcircle(ball_x, ball_y, radius);  // 绘制小球 	 	
		fillrectangle(rect_left_x, height - rect_height, rect_left_x + rect_width, height); 	// 画方块1
		fillrectangle(rect_left_x, 0, rect_left_x + rect_width, rect_height); 	// 画方块2
		fillrectangle(rect_left_x1, height - rect_height1, rect_left_x1 + rect_width1, height); 	// 画方块1
		fillrectangle(rect_left_x2, 0, rect_left_x2 + rect_width2, rect_height2); 	// 画方块2
		TCHAR s[20]; // 定义字符串数组 	
		swprintf_s(s, _T("%d"), score); // 将score转换为字符串 	
		settextstyle(40, 0, _T("宋体")); // 设置文字大小、字体 	
		outtextxy(50, 30, s); // 输出得分文字 	
		Sleep(10);  // 暂停10毫秒 
	}
	closegraph();
	system("pause");
	return 0;
}