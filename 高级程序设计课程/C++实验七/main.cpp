#include <iostream>
#include <cmath>

using namespace std;
const float PI = 3.1415926;
//定义point类
class Point
{
public:
	float x, y;
	Point(float x=0,float y=0):x(x),y(y){}
	float distance(const Point& other) const
	{
		float dx = x - other.x;
		float dy = y - other.y;
		return sqrt(dx * dx + dy * dy);
	}
};

//定义平面图形类
class Plane
{
public:
	virtual float area() const = 0;
	virtual float girth() const = 0;
	virtual ~Plane(){}
};

//长方形类
class Rectangle : public Plane
{
private:
	float length, width;
public:
	Rectangle(float l=0,float w=0):length(l),width(w){}
	float area()const
	{
		return width * length;
	}
	float girth()const
	{
		return 2 * (length + width);
	}
	float getLength()const { return length; }
	float getWidth()const { return width; }
};
//圆类
class Circle : public Plane
{
private:
	float r;
public:
	Circle(float r=0):r(r){}
	float area() const
	{
		return PI * r * r;
	}
	float girth()const
	{
		return 2 * PI * r;
	}
	float getR()const { return r; }

};
//三角形类
class Triangle :public Plane
{
private:
	Point A, B, C;
public:
	Triangle (Point a=Point(), Point b = Point(), Point c = Point()):A(a),B(b),C(c){}
	float area()const
	{
		float S = 0.5 * fabs(A.x * B.y + A.y * C.x + B.x * C.y - A.x * C.y - A.y * B.x - B.y * C.x);
		return S;
	}

	float girth()const
	{
		return A.distance(B) + B.distance(C) + C.distance(A);
	}
	//获取顶点
	Point getA()const { return A; }
	Point getB()const { return B; }
	Point getC()const { return C; }

};
//主题类
class Body
{
private:
	Plane* pbasic;
	float high;
public:
	Body(Plane* base=nullptr,float h=0):pbasic(base),high(h){}
	void setBase(Plane* base) { pbasic=base; }
	void setHeight(float h) { high = h; }
	//计算体积
	float volume()const
	{
		if (pbasic == nullptr) { return 0; }
		return pbasic->area() * high;
	}
	//表面积
	float surfaceArea()const
	{
		if (pbasic == nullptr) { return 0; }
		return 2 * pbasic->area() + pbasic->girth() * high;
	}
	//析构
	~Body(){}
};
//主函数
int main()
{
	int choice;
	do
	{
		cout << "请选择：" << endl;
		cout << "1.圆柱"<< endl;
		cout << "2.四棱柱" << endl;
		cout << "3.三棱柱" << endl;
		cout << "0.退出" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				float r, height;
				cout << "\n请输入底面半径：" ;
				cin >> r;
				cout << "\n请输入高度：";
				cin >> height;
				Circle circle(r);
				Body yuanzhu(&circle, height);
				cout << "\nbyuanzhu的体积为：" << yuanzhu.volume() << endl;
				cout << "yuanzhu的表面积为：" << yuanzhu.surfaceArea() << endl;
				break;
			}
			case 2:
			{
				float width, height,length;
				cout << "\n请输入长：";
				cin >> length;
				cout << "\n请输入宽：";
				cin >> width;
				cout << "\n请输入搞：";
				cin >> height;
				Rectangle rectangle(length, width);
				Body silengzhu(&rectangle, height);
				cout << "silengzhu体积为：" << silengzhu.volume() << endl;
				cout << "silengzhu表面积为：" << silengzhu.surfaceArea() << endl;
				break;
			}
			case 3:
			{
				float xA, yA, xB, yB, xC, yC, height;
				cout << "\n请输入地面顶点A的坐标(x,y): ";
				cin >> xA >> yA;
				cout << "\n请输入地面顶点B的坐标(x,y): ";
				cin >> xB >> yB;
				cout << "\n请输入地面顶点BC的坐标(x,y): ";
				cin >> xC >> yC;
				cout << "\n请输入高度: ";
				cin >> height;
				Point A(xA, yA);
				Point B(xB, yB);
				Point C(xC, yC);
				Triangle triangle(A, B, C);
				Body triangularPrism(&triangle, height);
				cout << "体积: " << triangularPrism.volume() << endl;
				cout << "表面积: " << triangularPrism.surfaceArea() << endl;
				break;
			}
			case 0:
			{
				break;
			}
			default:
				cout << "error!" << endl<<endl;
		}		
	} while (choice != 0);
		return 0;
}