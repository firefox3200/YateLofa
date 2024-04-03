#include "Figures.hpp"
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;


SVG::SVG(const string& name) : name(name) {
	f = ofstream(name);
	f << R"(<svg width="500" height="500")"
		<< " xmlns=\"http://www.w3.org/2000/svg\">\n";
}

SVG::~SVG() {
	if (f.is_open()) {
		Save();
	}
}

// добавляет к файлу запись типа <rect x='5' y='7' />
// по переданным параметрам elem="rect", params="x='5' y='7'"
void SVG::AddElement(const string& elem, const string& params) {
	f << "<" << elem << " " << params << " />\n";
}

// дописывает закрывающий тег и закрывает файл f
void SVG::Save() {
	f << "</svg>";
	f.close();
}

Point::Point(int x, int y) {
    Point::x = x;
    Point::y = y;
}

int Point::GetX() const {
    return x;
}

int Point::GetY() const {
    return y;
}


Figure::Figure(Point point, string fill, string stroke) {
	Figure::x = point.GetX();
	Figure::y = point.GetY();
	SetFill(std::move(fill));
	SetStroke(std::move(stroke));
}


Rectangle::Rectangle(Point point, int w, int h) {
	Rectangle::x = point.GetX(), Rectangle::y = point.GetY(), Rectangle::w = w, Rectangle::h = h;
}

void Rectangle::AddTo(SVG& s) {
    DrawRectangle(s, x, y, w, h, stroke, fill);
}

RectanleWithCircles::RectanleWithCircles(Point point, int w, int h) : Rectangle(point, w, h) {
    RectanleWithCircles::x = point.GetX(), RectanleWithCircles::y = point.GetY(), RectanleWithCircles::w = w, RectanleWithCircles::h = h;
}

void RectanleWithCircles::AddTo(SVG &s) {
    Rectangle::AddTo(s);
    DrawCircle(s, x - w / 2, y - h / 2, 10, stroke, fill);
    DrawCircle(s, x + w / 2, y - h / 2, 10, stroke, fill);
    DrawCircle(s, x - w / 2, y + h / 2, 10, stroke, fill);
    DrawCircle(s, x + w / 2, y + h / 2, 10, stroke, fill);
}

void DoubleRectangle::AddTo(SVG &s) {
    //add two nested rectangles at a distance of 10 px from each other
    stringstream p, p1;
    p << "x='" << x - (w / 2) << "' ";
    p << "y='" << y - (h / 4) << "' ";
    p << "width='" << w / 4 << "' ";
    p << "height='" << h / 2<< "' ";
    p << "stroke='" << stroke << "' ";
    p << "fill='" << fill << "' ";
    s.AddElement("rect", p.str());

    p1 << "x='" << x - (w / 2) + (w / 4) + 10 << "' ";
    p1 << "y='" << y - (h / 4) << "' ";
    p1 << "width='" << w / 4 << "' ";
    p1 << "height='" << h / 2 << "' ";
    p1 << "stroke='" << stroke << "' ";
    p1 << "fill='" << fill << "' ";
    s.AddElement("rect", p1.str());


}

DoubleRectangle::DoubleRectangle(Point point, int w, int h) : Rectangle(point, w, h) {
    DoubleRectangle::x = point.GetX(), DoubleRectangle::y = point.GetY(), DoubleRectangle::w = w, DoubleRectangle::h = h;
}

Circle::Circle(Point point, int r) {
	Circle::x = point.GetX(), Circle::y = point.GetY(), Circle::r = r;
}

void Circle::AddTo(SVG& s) {
    DrawCircle(s, x, y, r, stroke, fill);
}


void Figure::DrawCircle(SVG& s, int x, int y, int r, const string& stroke, const string& fill) {
	stringstream p;
	p << "cx='" << x - r / 2 << "' ";
	p << "cy='" << y - r / 2 << "' ";
	p << "r='" << r << "' ";
	p << "stroke='" << stroke << "' ";
	p << "fill='" << fill << "' ";
	s.AddElement("circle", p.str());
}

void Figure::DrawRectangle(SVG& s, int x, int y, int w, int h, const string& stroke, const string& fill) {
    stringstream p;
    p << "x='" << x - w / 2 << "' ";
    p << "y='" << y - h / 2 << "' ";
    p << "width='" << w << "' ";
    p << "height='" << h << "' ";
    p << "stroke='" << stroke << "' ";
    p << "fill='" << fill << "' ";
    s.AddElement("rect", p.str());
}

void Figure::SetFill(string color_background) {
	fill = std::move(color_background);
}

void Figure::SetStroke(string color_border) {
	stroke = std::move(color_border);
}


const string BLACK = "black";
const string YELLOW = "yellow";
const string GREEN = "green";