#ifndef _SCANLINEFILL_H_
#define _SCANLINEFILL_H_

#include "Point2D.h"
#include "Canvas.h"
#include <vector>

struct Edge {
    int y_max;
    int y_min;
    float x;
    int d_x;
    int d_y;
};

class ScanlineFill {
    private:
        Canvas * canvas;
        std::vector<Point2D> points;
        std::vector<Edge> edges;
        std::vector<Edge> active_list;
        Color color;

    public:
        ScanlineFill(Canvas& canvas, std::vector<Point2D> points, Color color);
        ~ScanlineFill();
        void initEdges();
        void fill();
};

#endif