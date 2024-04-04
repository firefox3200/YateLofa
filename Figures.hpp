#pragma once
#include <fstream>
#include <string>

using namespace std;


class SVG {
	public:
		SVG(const string& n);
		~SVG();

		void AddElement(const string& e, const string& ps);
		void Save();
	private:
		const string name;
		ofstream f;
};

class Point {
    public:
        Point() = default;
        Point(int x, int y);
        int GetX() const;
        int GetY() const;
    private:
        int x = 0;
        int y = 0;
};

class Figure {
	public:
		Figure() = default;
		Figure(Point point, string fill, string stroke);

		void SetFill(string color_background);
		void SetStroke(string color_border);

        virtual void AddTo(SVG& s) = 0;
		static void DrawCircle(SVG& s, int x, int y, int r, const string& stroke, const string& fill);
		static void DrawRectangle(SVG& s, int x, int y, int w, int h, const string& stroke, const string& fill);

	private:
	protected:
        string stroke = "black";
        string fill = "yellow";
        int x = 50;
        int y = 50;
};


class Circle : public Figure {
	public:
		Circle(Point point, int r);
		void AddTo(SVG& s) override;
	private:
		int r = 10;
};


class Rectangle : public Figure {
	public:
        Rectangle() = default;
		Rectangle(Point point, int w, int h);
		void AddTo(SVG& s) override;
    private:
    protected:
        int w = 70, h = 70;
};

//Добавить класс DoubleRectangle - наследник прямоугольника, рисующий 2 вложенных прямоугольника на расстоянии 10px друг от друга.
class DoubleRectangle : public Rectangle {
    public:
        DoubleRectangle(Point point, int w, int h);
        void AddTo(SVG& s) override;
    private:
    protected:
};

class RectanleWithCircles : public Rectangle {
    public:
        RectanleWithCircles(Point point, int w, int h);
        void AddTo(SVG& s) override;
    private:
    protected:
};

extern const string BLACK;
extern const string YELLOW;
extern const string GREEN;