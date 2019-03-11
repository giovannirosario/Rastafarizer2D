#ifndef _SCANLINEFILL_H_
#define _SCANLINEFILL_H_

#include "Point2D.h"
#include "Canvas.h"
#include <vector>

class ScanlineFill {
    private:
        struct Edge {
            Point2D start;
            Point2D end;
            int slope;
        };

        int y_min;
        int y_max;
        
        Canvas * canvas;
        std::vector<Point2D> vertices;
        std::vector<Edge> Edges;

    public:
        ScanlineFill(Canvas& canvas, std::vector<Point2D> points);
        ~ScanlineFill();
        void initEdges();
        void fill();
};

#endif