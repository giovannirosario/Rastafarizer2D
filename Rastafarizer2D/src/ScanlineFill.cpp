#include "ScanlineFill.h"

ScanlineFill::ScanlineFill(Canvas& canvas, std::vector<Point2D> points) {
    this->vertices = points;
    initEdges();
    fill();
}


void ScanlineFill::initEdges() {
    for(unsigned int i = 0; i < points.size(); i++){
        Edge edge;
        if (i == points.size()-1) {
            edge.start = points.back();
            edge.end = points[0];
        } else {
            edge.start = points[i];
            edge.end = points[i+1];
        }

        if (edge.start.get_y() < y_min) {
            y_min = edge.start.get_y();
        }
        if (edge.start.get_y() > y_max) {
            y_max = edge.start.get_y();
        }

        if (edge.start.get_x() - edge.end.get_x() != 0) {
            edge.slope = (edge.start.get_y() - edge.end.get_y() / (edge.start.get_x() - edge.end.get_x()  )
        } else {
            edge.slope = 10000000000000;
        }

        Edges.push_back(edge);
    }
}

void ScanlineFill::fill() {
    int y_pos = 0;

    //scanline
    for(int i = y_min; i <= y_max; i++) {
        std::vector<Point2D> intersections;
        
    }
    

}