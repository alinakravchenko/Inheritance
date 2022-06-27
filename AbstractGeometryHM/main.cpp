#include<iostream>
#include<Windows.h>
#include<math.h>
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//enum - перечисление. перечисление - это набор целочисленных констант
//так же является типом данных 
namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};
	enum Defaults
	{
		min_start_x = 10,
		max_start_x = 800,
		min_start_y = 10,
		max_start_y = 500,
		min_line_width = 5,
		max_line_width = 20,
		min_line_length = 10,
		max_line_length = 500,
	};

	class Shape
	{
	protected:
		Color color;
		//начальные координаты
		int start_x;
		int start_y;
		//ширина линии
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < Defaults::min_line_width)line_width = Defaults::min_line_width;
			else if (line_width > Defaults::max_line_width)this->line_width = Defaults::max_line_width;
			else this->line_width = line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < Defaults::min_start_x)start_x = Defaults::min_start_x;
			else if (start_x > Defaults::max_start_x)this->start_x = Defaults::max_start_x;
			else this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Defaults::min_start_y)start_y = Defaults::min_start_y;
			else if (start_y > Defaults::max_start_y)this->start_y = Defaults::max_start_y;
			else this->start_y = start_y;
		}

		Shape(int start_x, int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_line_width(line_width);
			set_start_x(start_x);
			set_start_y(start_y);

		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "площадь фигуры: " << get_area() << endl;
			cout << "периметр фигуры: " << get_perimeter() << endl;
			cout << typeid(*this).name() << endl;
			draw();
		}

	};
	class Square :public Shape
	{
		double side; //длина стороны
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 10;
			this->side = side;
		}
		Square(double side, int start_x, int start_y, unsigned int line_width, Color color) :Shape(line_width, start_x, start_y, color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side*side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			//Handle указатель на ноль
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//в перменную hConsole сохраняем стандaртный вывод текущего окна консоли
			SetConsoleTextAttribute(hConsole, get_color());
			//для стандартного вывода текущего окна задаём цвет текста и фона
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "длина стороны квадрата: " << get_side() << endl;
			Shape::info();

		}
	};
	class Rectangle :public Shape
	{
		double side_a, side_b;
	public:
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		void set_side_a(double side_a)
		{
			if (side_a <= 0)side_a = 20;
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			if (side_b <= 0)side_b = 10;
			this->side_b = side_b;
		}
		Rectangle(double side_a, double side_b, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}
		double get_area()const
		{
			return side_a*side_b;
		}
		double get_perimeter()const
		{
			return (side_a + side_b) * 2;
		}
		void draw()const
		{
			//1) Получаем окно консоли: 
			//HWND - Handler to Window (обработка окна консоли)
			HWND hwnd = GetConsoleWindow();
			//2) для того чтобы рисовать, нужно создать контекст устройства: 
			HDC hdc = GetDC(hwnd); //HDC - Handler to Device Context
			//Грубо говоря, hdc - это то, на чём мы будем рисовать

			//3) создадим инструменты, которыми мы будем рисовать: 
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); //карандаш рисует контур фигуры
			//для того чтобы применить заливку, нужна кисть
			HBRUSH hBrush = CreateSolidBrush(color);
			//4) создать карандаш недостаточно, его ещё нужно выбрать,
			//и только тогда мы сможем им рисовать 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5) рисуем прямоугольник
			::Rectangle(hdc, start_x, start_y, start_x + side_a, side_b + start_y);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "сторона А: " << side_a << endl;
			cout << "сторона Б: " << side_b << endl;
			Shape::info();
		}
	};
	class Circle :public Shape
	{
		double radius;
		CONST double PI = 3.141592653589793;
	public:
		double get_radius()const
		{
			return radius;
		}

		void set_radius(double radius)
		{
			if (radius >= 10 && radius <= 500) this->radius = radius;
			else if (radius < 10)this->radius = 10;
			else this->radius = 500;
		}
		Circle(double radius, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const
		{
			return PI * (radius * 2);
		}
		double get_perimeter()const
		{
			return 2 * PI * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			SelectObject(hdc, hPen);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << radius << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{

	public:
		Triangle(int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)this->side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length)this->side = Defaults::max_line_length;
			else this->side = side;
		}
		EquilateralTriangle(double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle(){}
		double get_height()const
		{
			//pow - возведение в степень
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const
		{
			return side * get_height()/2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{ start_x, start_y + side },        //2
				{ start_x + side, start_y + side }, //3
				{ start_x + side / 2, start_y+side-get_height()}
			};
			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class IsoscalesTriangle :public Triangle
	{
		double base;
		double side;
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base < Defaults::min_line_length)base = Defaults::min_line_length;
			else if (base > Defaults::max_line_length)base = Defaults::max_line_length;
			if (base >= side * 2)base /= 2;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length)side = Defaults::max_line_length;
			if (side*2<=base)side*= 2;
			this->side = side;
		}
		IsoscalesTriangle& operator()(double base, double side)
		{
			if (base <= side * 2)base = side;
			set_base(base);
			set_side(side);
			return *this;
		}
		IsoscalesTriangle(double base, double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			operator()(base, side);
		}
		~IsoscalesTriangle(){}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base*get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{ start_x, start_y + side },        //2
				{ start_x + base, start_y + side }, //3
				{ start_x + base / 2, start_y + base - get_height() }
			};
			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основание треугольника: " << base << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
}
void main()
{
	setlocale(LC_ALL, "");
	/*Shape shape(Color::console_blue);*/
	Geometry::Square square(5, 50, 10, 5, Geometry::Color::console_red);
	/*cout << "Длина стороны квадрата:     " << square.get_side() << endl;
	cout << "Площадь квадрата:           " << square.get_area() << endl;
	cout << "Периметр квадрата:          " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();
	/*Geometry::Rectangle rect(500, 300,500, 100, 5, Geometry::Color::green);
	rect.info();*/
	Geometry::Circle circle(50,700, 150, 15, Geometry::Color::yellow);
	circle.info();
	circle.draw();
	Geometry::EquilateralTriangle qtri(50, 500, 300, 5, Geometry::Color::green);
	qtri.info();

	Geometry::IsoscalesTriangle itri1(100, 150, 200, 200, 5, Geometry::Color::blue);
	itri1.info();
	Geometry::IsoscalesTriangle itri2(100, 75, 300, 200, 5, Geometry::Color::green);
	itri2.info();
}