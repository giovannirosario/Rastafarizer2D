#ifndef _POINT2D_H_
#define _POINT2D_H_

class Point2D {
	private:
		unsigned int x;
		unsigned int y;

	public:
		Point2D();
		Point2D(unsigned int x, unsigned int y);
		void set(unsigned int x, unsigned int y);
		~Point2D();
		unsigned int get_x();
		unsigned int get_y();
		bool operator==(const Point2D &Point2D);	
};

#endif