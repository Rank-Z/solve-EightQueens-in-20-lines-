#include<iostream>
int counter = 0;
void foo(int y){
	static bool mark[3][15] = { false };
	for (int x = 1; x != 9; ++x){
		if(mark[1][x - y + 7] || mark[2][(9 - x) - y + 7] || mark[0][x])
			continue;
		if (y == 8)
			++counter;
		else{
			mark[1][x - y + 7] = mark[2][(9 - x - y + 7)] = mark[0][x] = true;
			foo(y + 1);
			mark[1][x - y + 7] = mark[2][(9 - x - y + 7)] = mark[0][x] = false;
		}
	}
}
int main(){
	foo(1);
	std::cout << counter;
}




// 20 lines with K&R  styles
