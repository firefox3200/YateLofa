#include <iostream>
#include "Figures.hpp"


int main() {
	SVG s("picture1.svg");
    Point point(80, 80);
    Point point1(200, 200);

	Rectangle rSecond(point, 80, 60);
	Rectangle rFirst(point, 50, 40);
    DoubleRectangle dr = DoubleRectangle(point, 80, 60);
    RectanleWithCircles drwc = RectanleWithCircles(point1, 80, 60);
	Circle cc{ 20, 30, 50 };
	Figure &f = cc;
	//Circle c(90, 90, 20);

	rFirst.SetFill(YELLOW);
	rSecond.SetFill(GREEN);
	//c.SetFill(YELLOW);
	//Figure::DrawCircle(s, 200,100,30, BLACK, GREEN);
    //Figure::DrawRectangle(s, 0, 0, 20, 20, BLACK, GREEN);

	rSecond.AddTo(s);
    dr.AddTo(s);
    drwc.AddTo(s);
	//rFirst.AddTo(s);
	//c.AddTo(s);
	//f.AddTo(s);
	
	s.Save(); // чтобы файл можно было считывать
	system("start picture1.svg");
	return 0;
}